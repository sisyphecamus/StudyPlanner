
#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <vector>
#include <string>
#include "Task.h"

class TaskManager {
private:
    std::vector<Task> tasks;

public:
    void addTask(const Task& task);
    void importNewTaskFromFile(const std::string& filename);
    void saveTasksToJson(const std::string& filename);
};

#endif
