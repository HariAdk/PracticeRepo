using System;
using Agent.Core.Abstractions;

namespace Agent.Core.Logging
{
    /// <summary>
    /// Writes structured log messages to the console.
    /// Keeping console output here (SRP) means swapping to a file logger or
    /// a framework logger requires only a new <see cref="IAgentLogger"/>
    /// implementation (OCP / DIP).
    /// </summary>
    public sealed class ConsoleLogger : IAgentLogger
    {
        public void LogInformation(string message) => WriteColored("[INFO] ", ConsoleColor.Cyan,    message);
        public void LogWarning(string message)     => WriteColored("[WARN] ", ConsoleColor.Yellow,  message);
        public void LogError(string message)       => WriteColored("[ERR]  ", ConsoleColor.Red,     message);

        private static void WriteColored(string prefix, ConsoleColor prefixColor, string message)
        {
            var previous = Console.ForegroundColor;
            Console.ForegroundColor = prefixColor;
            Console.Write(prefix);
            Console.ForegroundColor = previous;
            Console.WriteLine(message);
        }
    }
}
