using System;
using Agent.Core.Abstractions;
using Agent.Core.Models;

namespace Agent.Core.Executors
{
    /// <summary>
    /// A general-purpose executor that handles any <see cref="IAgentTask"/>.
    /// Delegates real work to a user-supplied <see cref="Func{T,TResult}"/> so
    /// the executor itself stays open for extension but closed for modification
    /// (OCP).  New behaviour is wired in from the outside without changing this
    /// class.
    /// </summary>
    public sealed class DefaultTaskExecutor : ITaskExecutor
    {
        private readonly Func<IAgentTask, object> _workHandler;

        /// <summary>
        /// Initialises the executor with an optional work handler.
        /// If no handler is provided the executor returns a no-op success result.
        /// </summary>
        /// <param name="workHandler">
        /// Function that receives the task and returns an output object.
        /// Throw an exception from this function to signal failure.
        /// </param>
        public DefaultTaskExecutor(Func<IAgentTask, object> workHandler = null)
        {
            _workHandler = workHandler ?? (_ => "No operation performed.");
        }

        /// <inheritdoc />
        public bool CanExecute(IAgentTask task) => task != null;

        /// <inheritdoc />
        public ITaskResult Execute(IAgentTask task)
        {
            if (task == null) throw new ArgumentNullException(nameof(task));

            try
            {
                var output = _workHandler(task);
                return TaskResult.Success(task.TaskId, output);
            }
            catch (Exception ex)
            {
                return TaskResult.Failure(task.TaskId, ex.Message);
            }
        }
    }
}
