using System.Collections.Generic;

namespace Agent.Core.Abstractions
{
    /// <summary>
    /// Defines the contract for the top-level agent.
    /// DIP: consumers depend on this abstraction, never on concrete agent types.
    /// </summary>
    public interface IAgent
    {
        /// <summary>Human-readable name of this agent.</summary>
        string Name { get; }

        /// <summary>
        /// Runs the agent against the supplied task list and returns one
        /// result per task.
        /// </summary>
        IReadOnlyList<ITaskResult> Run(IEnumerable<IAgentTask> tasks);
    }
}
