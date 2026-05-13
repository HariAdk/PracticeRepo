using System;
using System.Collections.Generic;
using Agent.Core;
using Agent.Core.Models;
using Agent.Core.Planners;
using Agent.Tests.Fakes;
using Xunit;

namespace Agent.Tests
{
    public sealed class AgentTests
    {
        private static Core.Agent BuildAgent(
            AgentConfiguration?    config    = null,
            AlwaysSucceedExecutor? executor  = null,
            FakeLogger?            logger    = null)
        {
            return new Core.Agent(
                config   ?? new AgentConfiguration(),
                new SequentialTaskPlanner(),
                executor ?? new AlwaysSucceedExecutor(),
                logger   ?? new FakeLogger());
        }

        [Fact]
        public void Run_WithSingleTask_ReturnsSingleResult()
        {
            var agent = BuildAgent();
            var tasks = new[] { new AgentTask("T-1", "Test task", payload: null) };

            var results = agent.Run(tasks);

            Assert.Single(results);
        }

        [Fact]
        public void Run_WithSucceedingTasks_AllResultsAreSuccess()
        {
            var agent = BuildAgent();
            var tasks = new[]
            {
                new AgentTask("T-1", "First",  payload: null),
                new AgentTask("T-2", "Second", payload: null),
            };

            var results = agent.Run(tasks);

            Assert.All(results, r => Assert.True(r.IsSuccess));
        }

        [Fact]
        public void Run_WithFailingExecutor_ResultsAreFailures()
        {
            var agent = new Core.Agent(
                new AgentConfiguration(),
                new SequentialTaskPlanner(),
                new AlwaysFailExecutor(),
                new FakeLogger());

            var results = agent.Run(new[] { new AgentTask("T-1", "Task", payload: null) });

            Assert.False(results[0].IsSuccess);
        }

        [Fact]
        public void Run_WithContinueOnFailureFalse_StopsAfterFirstFailure()
        {
            var config = new AgentConfiguration { ContinueOnTaskFailure = false };
            var agent  = new Core.Agent(
                config,
                new SequentialTaskPlanner(),
                new AlwaysFailExecutor(),
                new FakeLogger());

            var tasks = new[]
            {
                new AgentTask("T-1", "First",  payload: null),
                new AgentTask("T-2", "Second", payload: null),
                new AgentTask("T-3", "Third",  payload: null),
            };

            var results = agent.Run(tasks);

            Assert.Single(results);
        }

        [Fact]
        public void Run_WithContinueOnFailureTrue_ProcessesAllTasks()
        {
            var config = new AgentConfiguration { ContinueOnTaskFailure = true };
            var agent  = new Core.Agent(
                config,
                new SequentialTaskPlanner(),
                new AlwaysFailExecutor(),
                new FakeLogger());

            var tasks = new[]
            {
                new AgentTask("T-1", "First",  payload: null),
                new AgentTask("T-2", "Second", payload: null),
            };

            var results = agent.Run(tasks);

            Assert.Equal(2, results.Count);
        }

        [Fact]
        public void Run_WhenExecutorCannotHandle_ResultIsFailureAndTaskIsSkipped()
        {
            var agent = new Core.Agent(
                new AgentConfiguration(),
                new SequentialTaskPlanner(),
                new NeverHandleExecutor(),
                new FakeLogger());

            var results = agent.Run(new[] { new AgentTask("T-1", "Task", payload: null) });

            Assert.False(results[0].IsSuccess);
        }

        [Fact]
        public void Run_WithNullTaskList_ThrowsArgumentNullException()
        {
            var agent = BuildAgent();
            Assert.Throws<ArgumentNullException>(() => agent.Run(null));
        }

        [Fact]
        public void Agent_Name_MatchesConfiguration()
        {
            var config = new AgentConfiguration { AgentName = "MySpecialAgent" };
            var agent  = BuildAgent(config: config);

            Assert.Equal("MySpecialAgent", agent.Name);
        }

        [Fact]
        public void Run_LogsStartAndFinishMessages()
        {
            var logger = new FakeLogger();
            var agent  = new Core.Agent(
                new AgentConfiguration { AgentName = "LogTest" },
                new SequentialTaskPlanner(),
                new AlwaysSucceedExecutor(),
                logger);

            agent.Run(new[] { new AgentTask("T-1", "Task", payload: null) });

            Assert.Contains(logger.InfoMessages, m => m.Contains("starting"));
            Assert.Contains(logger.InfoMessages, m => m.Contains("finished"));
        }
    }
}
