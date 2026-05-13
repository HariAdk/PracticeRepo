using Agent.Core.Abstractions;

namespace Agent.Core.Models
{
    /// <summary>
    /// Immutable value object carrying the outcome of an executed task.
    /// </summary>
    public sealed class TaskResult : ITaskResult
    {
        public string TaskId    { get; }
        public bool   IsSuccess { get; }
        public object Output    { get; }
        public string Message   { get; }

        private TaskResult(string taskId, bool isSuccess, object output, string message)
        {
            TaskId    = taskId;
            IsSuccess = isSuccess;
            Output    = output;
            Message   = message;
        }

        /// <summary>Creates a successful result.</summary>
        public static TaskResult Success(string taskId, object output, string message = "Task completed successfully.")
            => new TaskResult(taskId, true, output, message);

        /// <summary>Creates a failed result.</summary>
        public static TaskResult Failure(string taskId, string message)
            => new TaskResult(taskId, false, null, message);

        public override string ToString()
            => IsSuccess ? $"[OK]  {TaskId}: {Message}" : $"[ERR] {TaskId}: {Message}";
    }
}
