namespace Agent.Core.Abstractions
{
    /// <summary>
    /// Encapsulates the outcome of executing a single <see cref="IAgentTask"/>.
    /// </summary>
    public interface ITaskResult
    {
        /// <summary>The identifier of the task that produced this result.</summary>
        string TaskId { get; }

        /// <summary>Whether the task completed successfully.</summary>
        bool IsSuccess { get; }

        /// <summary>Output data produced by the task, or null on failure.</summary>
        object Output { get; }

        /// <summary>Human-readable message describing success or failure reason.</summary>
        string Message { get; }
    }
}
