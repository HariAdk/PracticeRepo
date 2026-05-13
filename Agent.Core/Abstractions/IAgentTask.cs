namespace Agent.Core.Abstractions
{
    /// <summary>
    /// Represents a unit of work that the agent can execute.
    /// ISP: kept narrow — only task identity and payload.
    /// </summary>
    public interface IAgentTask
    {
        /// <summary>Unique identifier for this task.</summary>
        string TaskId { get; }

        /// <summary>Human-readable name describing the task.</summary>
        string Name { get; }

        /// <summary>Arbitrary input data required to execute the task.</summary>
        object Payload { get; }
    }
}
