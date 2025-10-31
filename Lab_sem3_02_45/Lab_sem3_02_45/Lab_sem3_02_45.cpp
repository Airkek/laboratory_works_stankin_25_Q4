#include "pch.h"
#include "TaskScheduler.h"

using namespace System;

int main(array<System::String ^> ^args)
{
    TaskScheduler^ scheduler = gcnew TaskScheduler();

    Console::WriteLine("Creating tasks...");

    // Средний приоритет (2)
    scheduler->AddTask(gcnew CpuTask("Background Processing", 2, 300));
    scheduler->AddTask(gcnew IoTask("File Compression", 2, 250));
    scheduler->AddTask(gcnew NetworkTask("Data Backup", 2, 400));

    // Низкий приоритет (3)
    scheduler->AddTask(gcnew CpuTask("System Maintenance", 3, 500));
    scheduler->AddTask(gcnew IoTask("Log Cleanup", 3, 150));
    scheduler->AddTask(gcnew NetworkTask("Update Check", 3, 200));

    // Высокий приоритет (1)
    scheduler->AddTask(gcnew CpuTask("Critical Calculation", 1, 200));
    scheduler->AddTask(gcnew IoTask("Emergency Save", 1, 100));
    scheduler->AddTask(gcnew NetworkTask("Real-time Data Sync", 1, 150));

    Console::WriteLine("Created {0} tasks", scheduler->QueueLength);
    Console::WriteLine();

    scheduler->DisplayQueue();

    Console::WriteLine("Starting task execution...");
    Console::WriteLine();

    scheduler->RunSynchronously();

    Console::WriteLine();

    scheduler->GenerateStatistics();
    return 0;
}
