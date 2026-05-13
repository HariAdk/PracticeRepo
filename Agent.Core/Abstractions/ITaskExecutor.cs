namespace Agent.Core.Abstractions
{
    /// <summary>
    /// Executes a single <see cref="IAgentTask"/> and returns its result.
    /// SRP: execution logic lives here, not in the agent or the task itself.
    /// OCP: new task types are supported via new executor implementations.
    /// </summary>
    public interface ITaskExecutor
    {
        /// <summary>
        /// Determines whether this executor can handle the given task.
        /// </summary>
        bool CanExecute(IAgentTask task);

        /// <summary>
        /// Executes the given task and returns its result.
        /// </summary>
        ITaskResult Execute(IAgentTask task);
    }
}
