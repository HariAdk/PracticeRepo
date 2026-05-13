using System;
using System.Collections.Generic;
using Agent.Core.Abstractions;
using Agent.Core.Models;

namespace Agent.Core
{
    /// <summary>
    /// Orchestrates task planning and execution.
    ///
    /// SOLID design notes:
    /// <list type="bullet">
    ///   <item><b>SRP</b> – The agent only orchestrates; planning and execution
    ///         are delegated to collaborators.</item>
    ///   <item><b>OCP</b> – New planning or execution strategies are added via
    ///         new implementations of the injected interfaces, not by editing
    ///         this class.</item>
    ///   <item><b>LSP</b> – Any <see cref="ITaskPlanner"/> /
    ///         <see cref="ITaskExecutor"/> / <see cref="IAgentLogger"/> can be
    ///         substituted without breaking behaviour.</item>
    ///   <item><b>ISP</b> – Each collaborator interface is narrow and focused.</item>
    ///   <item><b>DIP</b> – All collaborators are injected as abstractions.</item>
    /// </list>
    /// </summary>
    public sealed class Agent : IAgent
    {
        private readonly ITaskPlanner        _taskPlanner;
        private readonly ITaskExecutor       _taskExecutor;
        private readonly IAgentLogger        _logger;
        private readonly AgentConfiguration  _configuration;

        /// <inheritdoc />
        public string Name => _configuration.AgentName;

        /// <summary>
        /// Constructs a new <see cref="Agent"/> with all required collaborators.
        /// </summary>
        public Agent(
            AgentConfiguration configuration,
            ITaskPlanner        taskPlanner,
            ITaskExecutor       taskExecutor,
            IAgentLogger        logger)
        {
            _configuration = configuration ?? throw new ArgumentNullException(nameof(configuration));
            _taskPlanner   = taskPlanner   ?? throw new ArgumentNullException(nameof(taskPlanner));
            _taskExecutor  = taskExecutor  ?? throw new ArgumentNullException(nameof(taskExecutor));
            _logger        = logger        ?? throw new ArgumentNullException(nameof(logger));
        }

        /// <inheritdoc />
        public IReadOnlyList<ITaskResult> Run(IEnumerable<IAgentTask> tasks)
        {
            if (tasks == null) throw new ArgumentNullException(nameof(tasks));

            _logger.LogInformation($"Agent '{Name}' starting.");

            var plannedTasks = _taskPlanner.Plan(tasks);
            _logger.LogInformation($"Planned {plannedTasks.Count} task(s).");

            var results = new List<ITaskResult>(plannedTasks.Count);

            foreach (var task in plannedTasks)
            {
                _logger.LogInformation($"Executing task: {task}");

                if (!_taskExecutor.CanExecute(task))
                {
                    var skipped = TaskResult.Failure(task.TaskId, "No executor available for this task type.");
                    _logger.LogWarning($"Skipped task {task.TaskId}: {skipped.Message}");
                    results.Add(skipped);
                    continue;
                }

                var result = _taskExecutor.Execute(task);
                results.Add(result);

                if (result.IsSuccess)
                {
                    _logger.LogInformation($"Task {task.TaskId} succeeded: {result.Message}");
                }
                else
                {
                    _logger.LogError($"Task {task.TaskId} failed: {result.Message}");

                    if (!_configuration.ContinueOnTaskFailure)
                    {
                        _logger.LogWarning("Stopping agent run due to task failure (ContinueOnTaskFailure = false).");
                        break;
                    }
                }
            }

            _logger.LogInformation($"Agent '{Name}' finished. {results.Count}/{plannedTasks.Count} task(s) processed.");
            return results.AsReadOnly();
        }
    }
}
