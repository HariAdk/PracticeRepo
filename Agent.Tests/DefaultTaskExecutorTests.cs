using System;
using Agent.Core.Executors;
using Agent.Core.Models;
using Xunit;

namespace Agent.Tests
{
    public sealed class DefaultTaskExecutorTests
    {
        [Fact]
        public void CanExecute_WithNonNullTask_ReturnsTrue()
        {
            var executor = new DefaultTaskExecutor();
            var task     = new AgentTask("T-1", "Name", payload: null);

            Assert.True(executor.CanExecute(task));
        }

        [Fact]
        public void CanExecute_WithNullTask_ReturnsFalse()
        {
            var executor = new DefaultTaskExecutor();
            Assert.False(executor.CanExecute(null));
        }

        [Fact]
        public void Execute_WithHandlerThatSucceeds_ReturnsSuccessResult()
        {
            var executor = new DefaultTaskExecutor(_ => "output");
            var task     = new AgentTask("T-1", "Name", payload: null);

            var result = executor.Execute(task);

            Assert.True(result.IsSuccess);
            Assert.Equal("output", result.Output);
        }

        [Fact]
        public void Execute_WithHandlerThatThrows_ReturnsFailureResult()
        {
            var executor = new DefaultTaskExecutor(_ => throw new InvalidOperationException("boom"));
            var task     = new AgentTask("T-1", "Name", payload: null);

            var result = executor.Execute(task);

            Assert.False(result.IsSuccess);
            Assert.Equal("boom", result.Message);
        }

        [Fact]
        public void Execute_WithNullTask_ThrowsArgumentNullException()
        {
            var executor = new DefaultTaskExecutor();
            Assert.Throws<ArgumentNullException>(() => executor.Execute(null));
        }

        [Fact]
        public void Execute_WithNoHandler_ReturnsNoOpSuccessResult()
        {
            var executor = new DefaultTaskExecutor();
            var task     = new AgentTask("T-1", "Name", payload: null);

            var result = executor.Execute(task);

            Assert.True(result.IsSuccess);
        }
    }
}
