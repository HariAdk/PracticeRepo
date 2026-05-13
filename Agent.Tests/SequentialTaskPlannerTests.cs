using Agent.Core.Models;
using Agent.Core.Planners;
using Xunit;

namespace Agent.Tests
{
    public sealed class SequentialTaskPlannerTests
    {
        [Fact]
        public void Plan_WithNullInput_ReturnsEmptyList()
        {
            var planner = new SequentialTaskPlanner();
            var result  = planner.Plan(null);

            Assert.Empty(result);
        }

        [Fact]
        public void Plan_WithThreeTasks_PreservesOrder()
        {
            var planner = new SequentialTaskPlanner();
            var tasks   = new[]
            {
                new AgentTask("T-1", "First",  payload: null),
                new AgentTask("T-2", "Second", payload: null),
                new AgentTask("T-3", "Third",  payload: null),
            };

            var planned = planner.Plan(tasks);

            Assert.Equal(3, planned.Count);
            Assert.Equal("T-1", planned[0].TaskId);
            Assert.Equal("T-2", planned[1].TaskId);
            Assert.Equal("T-3", planned[2].TaskId);
        }

        [Fact]
        public void Plan_WithNullTaskInList_FiltersNullsOut()
        {
            var planner = new SequentialTaskPlanner();
            var tasks   = new[]
            {
                new AgentTask("T-1", "First", payload: null),
                null,
                new AgentTask("T-2", "Second", payload: null),
            };

            var planned = planner.Plan(tasks);

            Assert.Equal(2, planned.Count);
        }
    }
}
