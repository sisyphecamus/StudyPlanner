#include "../include/TaskManager.h"
#include "../include/Task.h"

/*
    通过.json文件进行数据存储
    约定json格式:
    {
        tasks: [
           {"id": intType_number , "priority" : intType_number, "title":stringType, "content":stringType,
            "time_point": ddl, "completed" : boolType, "needs_review": boolType},                                                                            }
           ...
        ],
        "next_taskId" : intType_number
        "current_date": "YYYY-MM-DD" //当前日期字符串,用于日期变更时清空tasks
    }
    约定读入和导出的json文件名:
    saved_json_file/TaskManager.json : 不考虑日期变更,程序终止时写入,启动时导出
    saved_json_file/reviewTasks.json : 用于日期变更后仅导入和写出复习任务
*/

//程序启动时从json读入数据:
//当日期变更,应先读取所有数据至TaskManager,将前一天任务通过TaskManager导入到DateEntry中,然后清空tasks,再导入复习任务
void TaskManager::loadTaskfromJson(string file_name)
{
    ifstream i(file_name);
    if(!i.is_open())
    {
        throw ios_base::failure("Failed to open file: " + file_name);
    }
    json j;
    i>>j;
    //导入前清空tasks
    tasks.clear();

    //读取task至map
    for(const auto& item:j.at("tasks"))
    {
        try {
            Task t = Task::fromJson(item);//读取单个task
            tasks[t.getId()] = t; // 使用任务的id作为键
        } catch (const std::exception& e) {
            throw std::runtime_error("Error loading task from JSON: " + std::string(e.what()));
        }
    }

    //读取next_taskId & current_date
    try {
        next_taskId = j.at("next_taskId").get<int>();
        current_date = j.at("current_date").get<string>();
    } catch (const std::exception& e) {
        throw std::runtime_error("Error loading next_taskId from JSON: " + std::string(e.what()));
    }
}

//程序终止时导出到json文件,约定格式同上
// mode为0,导出所有任务;为1,导出复习任务
void TaskManager::dumpTask(string file_name, int mode)
{
    json j;
    j["tasks"] = json::array();

    //将tasks中的每个task转换为json格式
    for(const auto& [id, task] : tasks)
    {
        if(mode == 0 || (mode && task.getReviewStats()))
            j["tasks"].push_back(Task::toJson(task));
    }

    //保存next_taskId
    j["next_taskId"] = next_taskId;
    j["current_date"] = current_date;

    //写入文件
    ofstream o(file_name);
    if(!o.is_open())
    {
        throw ios_base::failure("Failed to open file: " + file_name);
    }
    o << j.dump(4); // 4 is the indentation level for pretty printing
}

//导入新任务
void TaskManager::loadTask(Task& t)
{
    tasks[t.getId()] = t; // 使用任务的id作为键
}

//修改任务
bool TaskManager::updateTask(int id, const TaskContent new_content, const chrono::system_clock::time_point new_ddl, const int new_p,
                             const bool new_n_review)
{
    auto it = tasks.find(id);
    if (it == tasks.end()) {
        return false; // 任务未找到
    }
    Task& task = it->second;

    // 更新任务内容
    task.updateContent(new_content);
    task.updateDeadline(new_ddl);
    task.updatePriority(new_p);
    task.updateNeedsReview(new_n_review);
    return true;
}

//将特定id的任务从tasks中移除
bool TaskManager::deleteTask(int id)
{
    auto it = tasks.find(id);
    if (it == tasks.end()) {
        return false; // 任务未找到
    }
    tasks.erase(it); // 从map中删除任务
    return true;
}

//获取当日任务完成数:遍历map
int TaskManager::getCompletedTasks()const
{
    int count = 0;
    for(const auto& [id, task] : tasks)
    {
        if(task.getCompletedStats())
            count++;
    }
    return count;
}

//初步实现,会更改
bool TaskManager::completeTask(int id)
{
    auto it = tasks.find(id);
    if (it == tasks.end()) {
        return false; // 任务未找到
    }
    Task& task = it->second;
    task.markCompleted();
    return true;
}
