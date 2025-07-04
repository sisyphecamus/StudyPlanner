#include "../include/DateEntry.h"
#include "../include/Record.h"
#include "../include/RecordManager.h"
#include "../include/TaskManager.h"

/*
    约定单个DateEntry的json格式:
    {
        "datestr": "YYYY-MM-DD",
        "records": [
            {"id": intType_number, "title": string_title, "content": string_content, "completed_time": intType_number},
            ...
        ],
        "total_tasks": intType_number,
        "completedCount": intType_number,
        "completion_rate": doubleType_number
    }
*/

void DateEntry::recalcStats()
{
    //重新计算完成数和完成率
    completedCount = 0;
    for (const auto& [id, record] : records) {
        if (record.getCompletedStats()) {
            completedCount++;
        }
    }
    total_tasks = records.size();
    if (total_tasks > 0) {
        completion_rate = static_cast<double>(completedCount) / total_tasks;
    } else {
        completion_rate = 0.0; // 如果没有任务，完成率为0
    }
}

//DateEntry的构造:日期变更后,获取前一天日期,以字符串形式传入,Record信息从TaskManager中获取,同时该DateEntry自动导入RecordManager,TaskManager清空tasks
DateEntry::DateEntry(const string& s, TaskManager& tm, RecordManager& rm)
    : datestr(s), total_tasks(0), completedCount(0), completion_rate(0.0)
{
    //从TaskManager中获取前一天的记录
    map<int, Task> task_from_yesterday = tm.getAllTasks();
    for (const auto& [id,task] : task_from_yesterday) 
    {
       int new_record_id = rm.getNextId();
       records[new_record_id] = Record(new_record_id, task);
    }
    total_tasks = records.size();
    // 首次构造时计算完成数和完成率
    recalcStats();

    tm.clearTasks();
    rm.loadDateEntry(*this);
}

DateEntry::DateEntry(const json& j)
{
    datestr = j.at("datestr").get<std::string>();
    total_tasks = j.at("total_tasks").get<int>();
    completedCount = j.at("completedCount").get<int>();
    completion_rate = j.at("completion_rate").get<double>();

    // 读取records
    for (const auto& item : j.at("records")) {
        Record r = Record::fromJson(item);
        records[r.getId()] = r; // 使用记录的id作为键
    }
}

void DateEntry::deleteRecord(int recordId) {
    //根据recordId删除记录
    auto it = records.find(recordId);
    if (it != records.end()) {
        records.erase(it);
        recalcStats(); // 删除记录后重新计算统计数
    }
}

json DateEntry::toJson(const DateEntry& de) {
    json j;
    j["datestr"] = de.datestr;
    j["records"] = json::array();
    
    //将records中的每个Record转换为json格式
    for (const auto& [id, record] : de.records) {
        j["records"].push_back(Record::toJson(record));
    }
    
    j["total_tasks"] = de.total_tasks;
    j["completedCount"] = de.completedCount;
    j["completion_rate"] = de.completion_rate;
    
    return j;
}

DateEntry DateEntry::fromJson(const json& j) {
    DateEntry de(j);
    
    //读取records
    for (const auto& item : j.at("records")) {
        Record r = Record::fromJson(item);
        de.records[r.getId()] = r; // 使用记录的id作为键
    }
    
    //读取统计信息
    de.total_tasks = j.at("total_tasks").get<int>();
    de.completedCount = j.at("completedCount").get<int>();
    de.completion_rate = j.at("completion_rate").get<double>();
    
    return de;
}