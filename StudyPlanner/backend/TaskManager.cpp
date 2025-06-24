#include "TaskManager.h"
#include "json.hpp"
#include <fstream>
#include <sstream>
#include <iomanip>

using json = nlohmann::json;

void TaskManager::addTask(const Task& task) 
{
    tasks.push_back(task);
}

//从new_task.json中读取文件
void TaskManager::importNewTaskFromFile(const std::string& filename) 
{
    std::ifstream in(filename);
    if (!in.is_open()) return;
    json j;
    in >> j;

    //读取一个新任务并加入任务表单
    std::string title = j["title"];
    std::string ddl_str = j["deadline"];
    int priority = j["priority"];
    bool review = j["needsReview"];

    std::tm tm = {};
    std::istringstream ss(ddl_str);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    auto deadline = std::chrono::system_clock::from_time_t(std::mktime(&tm));

    Task task(title, deadline, priority, review);
    this->addTask(task);
}

void TaskManager::saveTasksToJson(const std::string& filename) 
{
    json j_array = json::array();
    for (const auto& task : tasks) {
        json j;
        j["title"] = task.getTitle();
        std::time_t t = std::chrono::system_clock::to_time_t(task.getDeadline());
        std::tm* tm = std::localtime(&t);
        std::ostringstream oss;
        oss << std::put_time(tm, "%Y-%m-%d");
        j["deadline"] = oss.str();
        j["priority"] = task.getPriority();
        j["needsReview"] = task.getNeedsReview();
        j_array.push_back(j);
    }
    std::ofstream out(filename);
    out << j_array.dump(4);
}
