using Agent.Core.Abstractions;
using Agent.Core.Models;

namespace Agent.Tests.Fakes
{
    /// <summary>
    /// Test double executor that always returns a success result.
    /// </summary>
    internal sealed class AlwaysSucceedExecutor : ITaskExecutor
    {
        public bool CanExecute(IAgentTask task) => true;

        public ITaskResult Execute(IAgentTask task)
            => TaskResult.Success(task.TaskId, output: "ok");
    }

    /// <summary>
    /// Test double executor that always returns a failure result.
    /// </summary>
    internal sealed class AlwaysFailExecutor : ITaskExecutor
    {
        public bool CanExecute(IAgentTask task) => true;

        public ITaskResult Execute(IAgentTask task)
            => TaskResult.Failure(task.TaskId, "Simulated failure.");
    }

    /// <summary>
    /// Test double executor that declares it cannot handle any task.
    /// </summary>
    internal sealed class NeverHandleExecutor : ITaskExecutor
    {
        public bool CanExecute(IAgentTask task) => false;

        public ITaskResult Execute(IAgentTask task)
            => throw new System.InvalidOperationException("Should not be called.");
    }
}
