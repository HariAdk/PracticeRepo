# Agent — .NET SOLID Agent Framework

A lightweight, multi-target agent framework that runs on both **.NET Framework 4.8** and **.NET Core / .NET 5+**.  
Every design decision is guided by the **SOLID** principles and standard C# naming conventions.

---

## Solution Structure

```
Agent.slnx
├── Agent.Core/          # Class library — netstandard2.0 (compatible with .NET 4.8 & .NET Core)
│   ├── Abstractions/    # Interfaces (IAgent, IAgentTask, ITaskExecutor, ITaskPlanner, …)
│   ├── Models/          # Value objects (AgentTask, TaskResult, AgentConfiguration)
│   ├── Executors/       # DefaultTaskExecutor
│   ├── Planners/        # SequentialTaskPlanner
│   ├── Logging/         # ConsoleLogger
│   └── Agent.cs         # Core orchestrator
├── Agent.Runner/        # Console host — net8.0 (add net48 for .NET Framework build)
│   └── Program.cs       # Composition Root
└── Agent.Tests/         # xUnit tests — net8.0
```

---

## SOLID Principles Applied

| Principle | Where |
|-----------|-------|
| **S**ingle Responsibility | `Agent` only orchestrates; planning → `ITaskPlanner`, execution → `ITaskExecutor`, logging → `IAgentLogger` |
| **O**pen/Closed | New task types and strategies are added via new implementations, not by editing existing classes |
| **L**iskov Substitution | Any `ITaskExecutor` / `ITaskPlanner` / `IAgentLogger` implementation is a valid substitute |
| **I**nterface Segregation | Each interface is narrow and focused on one concern |
| **D**ependency Inversion | `Agent` depends on abstractions; concrete types are wired only in the Composition Root (`Program.cs`) |

---

## .NET Version Compatibility

`Agent.Core` targets **`netstandard2.0`**, which is supported by:

- .NET Framework 4.6.1 – 4.8
- .NET Core 2.0+
- .NET 5 / 6 / 7 / 8 / 9+

To produce a .NET 4.8 binary, add `net48` to the `<TargetFrameworks>` in both
`Agent.Runner.csproj` and `Agent.Tests.csproj`:

```xml
<TargetFrameworks>net8.0;net48</TargetFrameworks>
```

---

## Running the Sample

```bash
dotnet run --project Agent.Runner
```

Expected output:

```
────────────────────────────────────────────────────────────
[INFO] Agent 'SampleAgent' starting.
[INFO] Planned 4 task(s).
[INFO] Executing task: [T-001] Greet the user
[INFO] Task T-001 succeeded: Task completed successfully.
...
────────────────────────────────────────────────────────────

Summary:
  [OK]  T-001: Task completed successfully.
  [OK]  T-002: Task completed successfully.
  [ERR] T-003: Simulated task failure for demonstration purposes.
  [OK]  T-004: Task completed successfully.
```

---

## Running the Tests

```bash
dotnet test Agent.Tests
```

---

## Naming Conventions

| Element | Convention | Example |
|---------|-----------|---------|
| Interfaces | `I` prefix + PascalCase | `IAgentTask` |
| Classes | PascalCase | `DefaultTaskExecutor` |
| Methods | PascalCase | `CanExecute`, `LogInformation` |
| Parameters | camelCase | `availableTasks`, `workHandler` |
| Private fields | `_` prefix + camelCase | `_taskPlanner`, `_logger` |
| Constants | PascalCase or ALL_CAPS | `AgentName` |
