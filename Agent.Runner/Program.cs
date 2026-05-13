using System;
using System.Collections.Generic;
using Agent.Core;
using Agent.Core.Abstractions;
using Agent.Core.Executors;
using Agent.Core.Logging;
using Agent.Core.Models;
using Agent.Core.Planners;

namespace Agent.Runner
{
    /// <summary>
    /// Entry point demonstrating how to compose and run the agent.
    /// All concrete types are wired here (Composition Root), so the rest of the
    /// code-base stays free of concrete dependencies (DIP).
    /// </summary>
    internal static class Program
    {
        private static void Main()
        {
            // ── Composition Root ──────────────────────────────────────────────
            var configuration = new AgentConfiguration
            {
                AgentName              = "SampleAgent",
                ContinueOnTaskFailure  = true
            };

            IAgentLogger  logger   = new ConsoleLogger();
            ITaskPlanner  planner  = new SequentialTaskPlanner();
            ITaskExecutor executor = new DefaultTaskExecutor(ProcessTask);

            IAgent agent = new Agent.Core.Agent(configuration, planner, executor, logger);

            // ── Build sample tasks ────────────────────────────────────────────
            var tasks = new List<IAgentTask>
            {
                new AgentTask("T-001", "Greet the user",          payload: "Hello, World!"),
                new AgentTask("T-002", "Compute square of 7",     payload: 7),
                new AgentTask("T-003", "Simulate a task failure", payload: null),
                new AgentTask("T-004", "Reverse a string",        payload: "SOLID"),
            };

            // ── Run ───────────────────────────────────────────────────────────
            Console.WriteLine(new string('─', 60));
            IReadOnlyList<ITaskResult> results = agent.Run(tasks);
            Console.WriteLine(new string('─', 60));

            Console.WriteLine("\nSummary:");
            foreach (var result in results)
                Console.WriteLine($"  {result}");
        }

        /// <summary>
        /// Sample work-handler supplied to <see cref="DefaultTaskExecutor"/>.
        /// In a real application this would dispatch to domain-specific services.
        /// </summary>
        private static object ProcessTask(IAgentTask task)
        {
            switch (task.TaskId)
            {
                case "T-001":
                    return task.Payload?.ToString() ?? string.Empty;

                case "T-002":
                    int number = Convert.ToInt32(task.Payload);
                    return number * number;

                case "T-003":
                    throw new InvalidOperationException("Simulated task failure for demonstration purposes.");

                case "T-004":
                    var chars = task.Payload?.ToString()?.ToCharArray() ?? Array.Empty<char>();
                    Array.Reverse(chars);
                    return new string(chars);

                default:
                    return $"No specific handler for task '{task.TaskId}'.";
            }
        }
    }
}
