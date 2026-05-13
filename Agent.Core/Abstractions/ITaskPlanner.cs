using System.Collections.Generic;

namespace Agent.Core.Abstractions
{
    /// <summary>
    /// Plans which tasks the agent should execute and in what order.
    /// OCP: new planning strategies are added by implementing this interface,
    ///      not by modifying existing planners.
    /// </summary>
    public interface ITaskPlanner
    {
        /// <summary>
        /// Produces an ordered sequence of tasks that the agent should execute.
        /// </summary>
        /// <param name="availableTasks">Pool of candidate tasks.</param>
        /// <returns>Ordered list of tasks to execute.</returns>
        IReadOnlyList<IAgentTask> Plan(IEnumerable<IAgentTask> availableTasks);
    }
}
