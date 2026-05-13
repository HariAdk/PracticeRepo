using System.Collections.Generic;
using System.Linq;
using Agent.Core.Abstractions;

namespace Agent.Core.Planners
{
    /// <summary>
    /// The simplest possible planner: runs tasks in the order they are given.
    /// Alternative planners (priority-based, dependency-aware, etc.) implement
    /// <see cref="ITaskPlanner"/> without modifying this class (OCP).
    /// </summary>
    public sealed class SequentialTaskPlanner : ITaskPlanner
    {
        /// <inheritdoc />
        public IReadOnlyList<IAgentTask> Plan(IEnumerable<IAgentTask> availableTasks)
        {
            if (availableTasks == null)
                return new List<IAgentTask>();

            return availableTasks
                .Where(t => t != null)
                .ToList()
                .AsReadOnly();
        }
    }
}
