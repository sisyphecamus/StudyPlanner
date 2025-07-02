#include <iostream>
#include "../backend/include/TaskManager.h"
#include "../backend/include/Task.h"
#include "../backend/include/RecordManager.h"
#include "../backend/include/Record.h"
#include "../backend/include/DateEntry.h"

void initTask(TaskManager& tm)
{
    Task task1(1, {"Task 1", "Content of Task 1"}, false, false, tm, std::chrono::system_clock::now() + std::chrono::hours(1));
    Task task2(2, {"Task 2", "Content of Task 2"}, false, true, tm, std::chrono::system_clock::now() + std::chrono::hours(2));
    Task task3(3, {"Task 3", "Content of Task 3"}, true, false, tm, std::chrono::system_clock::now() + std::chrono::hours(3));

    tm.loadTask(task1);
    tm.loadTask(task2);
    tm.loadTask(task3);
}

void testTaskManager(TaskManager& tm)
{
    std::cout << "Total tasks: " << tm.getTotalTasks() << std::endl;
    std::cout << "Completed tasks: " << tm.getCompletedTasks() << std::endl;

    // 测试更新任务
    TaskContent new_content = {"Updated Task 1", "Updated Content of Task 1"};
    tm.updateTask(1, new_content, std::chrono::system_clock::now() + std::chrono::hours(4), 2, false);
    
    //导入新任务
    Task new_task(4, {"New Task", "Content of New Task"}, false, false, tm, std::chrono::system_clock::now() + std::chrono::hours(5));
    tm.loadTask(new_task);

    // 测试完成任务
    tm.completeTask(2);
    
    // 再次输出任务统计信息
    std::cout << "After updates:" << std::endl;
    std::cout << "Total tasks: " << tm.getTotalTasks() << std::endl;
    std::cout << "Completed tasks: " << tm.getCompletedTasks() << std::endl;
}

void testDateEntry(TaskManager& tm, RecordManager& rm)
{
    DateEntry de("2024-07-02", tm, rm);//创建一条DateEntry
    std::cout << "Date Entry created for: " << de.getDateStr() << std::endl;
    std::cout << "Total tasks in Date Entry: " << de.getTotalTasks() << std::endl;
    std::cout << "Completed tasks in Date Entry: " << de.getCompletedCount() << std::endl;
    std::cout << "Completion rate: " << de.getCompletionRate() << std::endl;

    rm.dumpEntries("../backend/saved_json_file/RecordManager.json"); // 将记录导出到json文件
}

void testDateEntryFromJson(RecordManager& rm)
{
    try {
        rm.loadFromJson("../backend/saved_json_file/RecordManager.json");
        std::cout << "Records loaded successfully from JSON." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error loading records: " << e.what() << std::endl;
    }

    DateEntry de = rm.getDateEntry("2024-07-02");
    std::cout << "Loaded Date Entry for: " << de.getDateStr() << std::endl;
    std::cout << "Total tasks in loaded Date Entry: " << de.getTotalTasks() << std::endl;
    std::cout << "Completed tasks in loaded Date Entry: " << de.getCompletedCount() << std::endl;
    std::cout << "Completion rate in loaded Date Entry: " << de.getCompletionRate() << std::endl;
}

int main()
{
    TaskManager tm;

    //initTask(tm); // 初始化任务
    //testTaskManager(tm); // 测试任务管理器

    RecordManager rm;

    //testDateEntry(tm, rm);
    testDateEntryFromJson(rm);

    return 0;
}