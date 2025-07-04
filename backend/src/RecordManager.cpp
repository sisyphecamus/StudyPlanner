#include "../include/RecordManager.h"
#include "../include/DateEntry.h"
#include "../include/Record.h"


/*
    通过.json文件进行数据存储
    约定json格式:
    {
        "nextRecordID": intType_number,
        "date_entries": [
        "YYYY-MM-DD": 
            {
                "datestr": "YYYY-MM-DD",
                "records": [
                    {"id": intType_number, "title": string_title, "content": string_content, "completed_time": intType_number},
                    ...
                ],
                "total_tasks": intType_number,
                "completedCount": intType_number,
                "completion_rate": doubleType_number
            },
            ...
        ]    
    }
    即set中有一个nextId,多个string-DateEntry对

    约定读入和导出的json文件名:
    RecordManager.json : 不考虑日期变更,程序终止时写入,启动时导出
*/

// 从json加载数据,同时处理可能的异常
void RecordManager::loadFromJson(const string& file_name) {
    ifstream i(file_name);
    if (!i.is_open()) {
        throw ios_base::failure("Failed to open " + file_name);
    }
    json j;
    i >> j;
    if (!j.contains("nextRecordID") || !j.contains("date_entries")) {
        throw std::runtime_error("Invalid JSON format: missing 'nextRecordID' or 'date_entries'");
    }
    try {
        // 清空现有数据
        date_entries.clear();
        nextRecordID = j.at("nextRecordID").get<int>();

        // 读取日期条目
        for (const auto& item : j.at("date_entries").items()) {
            string date_str = item.key();
            DateEntry entry = DateEntry::fromJson(item.value());
            date_entries[date_str] = entry;
        }
    } catch (const std::exception& e) {
        throw std::runtime_error("Error loading RecordManager from JSON: " + std::string(e.what()));
    }
}

// 将所有条目导出到json文件,处理可能的异常
void RecordManager::dumpEntries(const string& file_name) const
{
    json j;
    j["nextRecordID"] = nextRecordID;

    // 读取日期条目
    for (const auto& [date_str, entry] : date_entries) {
        j["date_entries"][date_str] = DateEntry::toJson(entry);
    }

    // 写入文件
    ofstream o(file_name);
    if (!o.is_open()) {
        throw ios_base::failure("Failed to open " + file_name);
    }
    o << j.dump(4); // 4 is the indentation level for pretty printing
}

// 根据日期删除单个条目
bool RecordManager::deleteSingleEntry(string date_str) {
    auto it = date_entries.find(date_str);
    if (it != date_entries.end()) {
        date_entries.erase(it);
        return true; // 删除成功
    }
    return false; // 未找到对应日期条目
}

DateEntry RecordManager::getDateEntry(const string& date_str) const {
    auto it = date_entries.find(date_str);
    if (it != date_entries.end()) {
        return it->second; // 返回对应的DateEntry
    }
    throw std::runtime_error("DateEntry not found for date: " + date_str);
}

