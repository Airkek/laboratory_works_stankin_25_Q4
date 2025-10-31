#pragma once
#include "PriorityQueue.h"

using namespace System::Collections::Generic;

public ref class ExecutionLogEntry
{
public:
    ExecutionLogEntry(DateTime timestamp, String^ message, Task^ task)
        : timestamp(timestamp), message(message), task(task) {
    }

    property DateTime Timestamp { DateTime get() { return timestamp; } }
    property String^ Message { String^ get() { return message; } }
    property Task^ Task { ::Task^ get() { return task; } }

    virtual String^ ToString() override
    {
        return String::Format("[{0:HH:mm:ss.fff}] {1} - {2}",
            timestamp, message, task != nullptr ? task->Name : "System");
    }

private:
    DateTime timestamp;
    String^ message;
    ::Task^ task;
};

public ref class TaskScheduler
{
private:
    PriorityTaskQueue^ queue;
    List<ExecutionLogEntry^>^ executionLog;
    bool isRunning;

public:
    TaskScheduler()
    {
        queue = gcnew PriorityTaskQueue();
        executionLog = gcnew List<ExecutionLogEntry^>();
        isRunning = false;

        queue->TaskAdded += gcnew EventHandler<TaskEventArgs^>(this, &TaskScheduler::OnTaskAdded);
        queue->TaskStarted += gcnew EventHandler<TaskEventArgs^>(this, &TaskScheduler::OnTaskStarted);
        queue->TaskCompleted += gcnew EventHandler<TaskEventArgs^>(this, &TaskScheduler::OnTaskCompleted);
    }

    void AddTask(Task^ task)
    {
        queue->Enqueue(task);
    }

    void RunSynchronously()
    {
        if (isRunning)
            throw gcnew InvalidOperationException("Scheduler is already running");

        isRunning = true;
        AddLogEntry("Scheduler started", nullptr);

        try
        {
            while (!queue->IsEmpty)
            {
                Task^ task = queue->Dequeue();
                AddLogEntry("Executing task", task);

                try
                {
                    task->Execute();
                }
                catch (Exception^ ex)
                {
                    AddLogEntry(String::Format("Task execution failed: {0}", ex->Message), task);
                }
            }

            AddLogEntry("All tasks completed", nullptr);
        }
        finally
        {
            isRunning = false;
        }
    }

    void DisplayQueue()
    {
        Console::WriteLine("=== CURRENT QUEUE STATE ===");
        if (queue->IsEmpty)
        {
            Console::WriteLine("Queue is empty");
            return;
        }

        array<Task^>^ tasks = queue->ToArray();
        for (int i = 0; i < tasks->Length; i++)
        {
            Console::WriteLine("{0}. {1}", i + 1, tasks[i]);
        }
        Console::WriteLine();
    }

    void DisplayExecutionLog()
    {
        Console::WriteLine("=== EXECUTION LOG ===");
        for each (ExecutionLogEntry ^ entry in executionLog)
        {
            Console::WriteLine(entry);
        }
        Console::WriteLine();
    }

    void GenerateStatistics()
    {
        Console::WriteLine("=== EXECUTION STATISTICS ===");

        int cpuTasks = 0;
        int ioTasks = 0;
        int networkTasks = 0;
        int totalDuration = 0;

        for each (ExecutionLogEntry ^ entry in executionLog)
        {
            if (entry->Task != nullptr && entry->Message->Contains("completed"))
            {
                totalDuration += entry->Task->Duration;

                if (dynamic_cast<CpuTask^>(entry->Task) != nullptr)
                    cpuTasks++;
                else if (dynamic_cast<IoTask^>(entry->Task) != nullptr)
                    ioTasks++;
                else if (dynamic_cast<NetworkTask^>(entry->Task) != nullptr)
                    networkTasks++;
            }
        }

        Console::WriteLine("CPU Tasks: {0}", cpuTasks);
        Console::WriteLine("IO Tasks: {0}", ioTasks);
        Console::WriteLine("Network Tasks: {0}", networkTasks);
        Console::WriteLine("Total execution time: {0}ms", totalDuration);
        Console::WriteLine();
    }

private:
    void AddLogEntry(String^ message, Task^ task)
    {
        ExecutionLogEntry^ entry = gcnew ExecutionLogEntry(DateTime::Now, message, task);
        executionLog->Add(entry);
        Console::WriteLine(entry);
    }

    void OnTaskAdded(Object^ sender, TaskEventArgs^ e)
    {
        AddLogEntry("Task added to queue", e->Task);
    }

    void OnTaskStarted(Object^ sender, TaskEventArgs^ e)
    {
        AddLogEntry("Task execution started", e->Task);
    }

    void OnTaskCompleted(Object^ sender, TaskEventArgs^ e)
    {
        AddLogEntry("Task execution completed", e->Task);
    }

public:
    property int QueueLength { int get() { return queue->Count; } }
    property int LogEntriesCount { int get() { return executionLog->Count; } }
};