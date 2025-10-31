#pragma once
#include "Task.h"

using namespace System::Collections::Generic;
using namespace System;

public ref class TaskPriorityComparer : public IComparer<Task^>
{
public:
    virtual int Compare(Task^ x, Task^ y) sealed
    {
        if (x == nullptr && y == nullptr) return 0;
        if (x == nullptr) return 1;
        if (y == nullptr) return -1;

        // Сначала сравниваем по приоритету (меньшее число = выше приоритет)
        int priorityCompare = x->Priority.CompareTo(y->Priority);
        if (priorityCompare != 0)
            return priorityCompare;

        // Если приоритеты равны, сравниваем по длительности (меньшая длительность = выше)
        return x->Duration.CompareTo(y->Duration);
    }
};

public ref class PriorityTaskQueue
{
private:
    List<Task^>^ tasks;
    TaskPriorityComparer^ comparer;

public:
    event EventHandler<TaskEventArgs^>^ TaskAdded;
    event EventHandler<TaskEventArgs^>^ TaskStarted;
    event EventHandler<TaskEventArgs^>^ TaskCompleted;

    PriorityTaskQueue()
    {
        tasks = gcnew List<Task^>();
        comparer = gcnew TaskPriorityComparer();
    }

    void Enqueue(Task^ task)
    {
        if (task == nullptr)
            throw gcnew ArgumentNullException("task");

        task->TaskStarted += gcnew EventHandler<TaskEventArgs^>(this, &PriorityTaskQueue::OnTaskStarted);
        task->TaskCompleted += gcnew EventHandler<TaskEventArgs^>(this, &PriorityTaskQueue::OnTaskCompleted);

        tasks->Add(task);
        SortQueue();

        TaskAdded(this, gcnew TaskEventArgs(task, DateTime::Now));
    }

    Task^ Dequeue()
    {
        if (tasks->Count == 0)
            throw gcnew InvalidOperationException("Queue is empty");

        Task^ task = tasks[0];
        tasks->RemoveAt(0);
        return task;
    }

    Task^ Peek()
    {
        if (tasks->Count == 0)
            throw gcnew InvalidOperationException("Queue is empty");

        return tasks[0];
    }

    void Clear()
    {
        tasks->Clear();
    }

    bool Contains(Task^ task)
    {
        return tasks->Contains(task);
    }

    array<Task^>^ ToArray()
    {
        return tasks->ToArray();
    }

private:
    void SortQueue()
    {
        tasks->Sort(comparer);
    }

    void OnTaskStarted(Object^ sender, TaskEventArgs^ e)
    {
        TaskStarted(sender, e);
    }

    void OnTaskCompleted(Object^ sender, TaskEventArgs^ e)
    {
        TaskCompleted(sender, e);
    }

public:
    property int Count { int get() { return tasks->Count; } }
    property bool IsEmpty { bool get() { return tasks->Count == 0; } }
};