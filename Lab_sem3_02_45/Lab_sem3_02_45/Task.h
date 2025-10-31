#pragma once
#include <string>

using namespace System;

ref class Task;

public ref class TaskEventArgs : public EventArgs
{
public:
    TaskEventArgs(Task^ task, DateTime timestamp)
        : task(task), timestamp(timestamp) {
    }

    property Task^ Task { ::Task^ get() { return task; } }
    property DateTime Timestamp { DateTime get() { return timestamp; } }

private:
    ::Task^ task;
    DateTime timestamp;
};

public ref class Task abstract
{
private:
    String^ name;
    int priority;
    int duration;

public:
    Task(String^ taskName, int taskPriority, int taskDuration)
        : name(taskName), priority(taskPriority), duration(taskDuration)
    {
        if (String::IsNullOrEmpty(taskName))
            throw gcnew ArgumentException("Task name cannot be null or empty");
        if (taskPriority < 1 || taskPriority > 3)
            throw gcnew ArgumentOutOfRangeException("priority", "Priority must be between 1 and 3");
        if (taskDuration <= 0)
            throw gcnew ArgumentOutOfRangeException("duration", "Duration must be positive");
    }

    event EventHandler<TaskEventArgs^>^ TaskStarted;
    event EventHandler<TaskEventArgs^>^ TaskCompleted;

    virtual void Execute() abstract;
    virtual String^ ToString() override;

protected:
    void OnTaskStarted();
    void OnTaskCompleted();

public:
    property String^ Name { String^ get() { return name; } }
    property int Priority { int get() { return priority; } }
    property int Duration { int get() { return duration; } }
};

public ref class CpuTask sealed : public Task
{
public:
    CpuTask(String^ name, int priority, int duration)
        : Task(name, priority, duration) {
    }

    virtual void Execute() override;
};

public ref class IoTask sealed : public Task
{
public:
    IoTask(String^ name, int priority, int duration)
        : Task(name, priority, duration) {
    }

    virtual void Execute() override;
};

public ref class NetworkTask sealed : public Task
{
public:
    NetworkTask(String^ name, int priority, int duration)
        : Task(name, priority, duration) {
    }

    virtual void Execute() override;
};

String^ Task::ToString()
{
    return String::Format("{0} [Priority: {1}, Duration: {2}ms]",
        Name, Priority, Duration);
}

void Task::OnTaskStarted()
{
    TaskStarted(this, gcnew TaskEventArgs(this, DateTime::Now));
}

void Task::OnTaskCompleted()
{
    TaskCompleted(this, gcnew TaskEventArgs(this, DateTime::Now));
}

void CpuTask::Execute()
{
    OnTaskStarted();
    Console::WriteLine("    [CPU] Executing: {0}", Name);
    System::Threading::Thread::Sleep(Duration);
    OnTaskCompleted();
}

void IoTask::Execute()
{
    OnTaskStarted();
    Console::WriteLine("    [IO] Executing: {0}", Name);
    System::Threading::Thread::Sleep(Duration);
    OnTaskCompleted();
}

void NetworkTask::Execute()
{
    OnTaskStarted();
    Console::WriteLine("    [NETWORK] Executing: {0}", Name);
    System::Threading::Thread::Sleep(Duration);
    OnTaskCompleted();
}