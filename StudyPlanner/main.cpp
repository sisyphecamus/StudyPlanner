
#include "TaskManager.h"
#include <iostream>

int main() {
    TaskManager manager;
    manager.importNewTaskFromFile("data/new_task.json");
    manager.saveTasksToJson("data/tasks.json");
    std::cout << "Task imported and saved." << std::endl;
    return 0;
}
