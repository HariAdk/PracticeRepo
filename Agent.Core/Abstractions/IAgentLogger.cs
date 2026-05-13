namespace Agent.Core.Abstractions
{
    /// <summary>
    /// Lightweight logging abstraction that avoids a hard dependency on any
    /// concrete logging framework. Compatible with .NET 4.8 and .NET Core.
    /// ISP: kept minimal — only the methods callers actually need.
    /// </summary>
    public interface IAgentLogger
    {
        void LogInformation(string message);
        void LogWarning(string message);
        void LogError(string message);
    }
}
