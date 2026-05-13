namespace Agent.Core.Models
{
    /// <summary>
    /// Holds agent-level settings injected at construction time.
    /// Keeping configuration separate from behaviour supports the SRP.
    /// </summary>
    public sealed class AgentConfiguration
    {
        /// <summary>Display name for the agent instance.</summary>
        public string AgentName { get; set; } = "DefaultAgent";

        /// <summary>
        /// When true the agent continues processing remaining tasks after
        /// a task failure.  When false it stops at the first failure.
        /// </summary>
        public bool ContinueOnTaskFailure { get; set; } = true;
    }
}
