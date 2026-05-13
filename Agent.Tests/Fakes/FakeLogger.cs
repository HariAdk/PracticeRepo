using System.Collections.Generic;
using Agent.Core.Abstractions;

namespace Agent.Tests.Fakes
{
    /// <summary>
    /// Test double that records all log calls for assertion.
    /// </summary>
    internal sealed class FakeLogger : IAgentLogger
    {
        public List<string> InfoMessages  { get; } = new List<string>();
        public List<string> WarnMessages  { get; } = new List<string>();
        public List<string> ErrorMessages { get; } = new List<string>();

        public void LogInformation(string message) => InfoMessages.Add(message);
        public void LogWarning(string message)     => WarnMessages.Add(message);
        public void LogError(string message)       => ErrorMessages.Add(message);
    }
}
