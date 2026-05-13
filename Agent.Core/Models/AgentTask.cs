using Agent.Core.Abstractions;

namespace Agent.Core.Models
{
    /// <summary>
    /// Immutable value object representing a task the agent should process.
    /// </summary>
    public sealed class AgentTask : IAgentTask
    {
        public string TaskId { get; }
        public string Name { get; }
        public object Payload { get; }

        public AgentTask(string taskId, string name, object payload)
        {
            TaskId = taskId ?? throw new System.ArgumentNullException(nameof(taskId));
            Name   = name   ?? throw new System.ArgumentNullException(nameof(name));
            Payload = payload;
        }

        public override string ToString() => $"[{TaskId}] {Name}";
    }
}
