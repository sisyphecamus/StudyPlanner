#include "../include/Record.h"
#include "../include/RecordManager.h"

/*
    单挑record的json格式:
    {
        "id": 1,
        "title": "Task Title",
        "content": "Task Content",
        "completed": false
    }
*/

// 创建新记录
Record::Record(Task &t, RecordManager &r)
{
    id = r.getNextId();
    title = t.getTitle();
    content = t.getContent();
    completed = false;
}

//// 将单个记录转换为json对象
json Record::toJson(const Record& r) {
    json j;
    j["id"] = r.id;
    j["title"] = r.title;
    j["content"] = r.content;
    j["completed"] = r.completed;
    return j;
}

//从json读取单个记录
Record Record::fromJson(const json& j) {
    Record r;
    r.id = j.at("id").get<int>();
    r.title = j.at("title").get<std::string>();
    r.content = j.at("content").get<std::string>();
    r.completed = j.at("completed").get<bool>();
    return r;
}

