#ifndef DATAENTRY_H
#define DATAENTRY_H

#include "../include/Record.h"
#include "../include/TaskManager.h"
#include "json.hpp"
#include <map>
#include <string>
#include <fstream>

//using namespace std;
//using json = nlohmann::json;

class RecordManager; // 前向声明RecordManager类
//和TaskManager的逻辑相似
class RecordShower;//edited
class DateEntry
{
    private:
        string datestr;//字符串形式标记日期 YYYY-MM-DD  
        map<int, Record> records; //记录的map，key为taskId 
        int total_tasks;
        int completedCount;
        double completion_rate; //total_tasks > 0 时计算
    public:
        friend class RecordShower;//edited
        //日期变更后的构造
        DateEntry(const string& s,TaskManager& tm, RecordManager& rm);
        //从json文件中恢复时的构造
        DateEntry(const json& j);
        //无参构造:方便stl容器使用
        DateEntry() : datestr(""), total_tasks(0), completedCount(0), completion_rate(0.0) {}
        //json数据交互
        static json toJson(const DateEntry&);
        static DateEntry fromJson(const json&);

        //删除DateEntry中记录,会重新计算统计数
        void deleteRecord(int recordId); 
        //DateEntry中内容变动后(record被用户删除),重新计算统计数
        void recalcStats();
        
        inline string getDateStr() const { return datestr; } //获取日期字符串
        inline int getTotalTasks() const { return total_tasks; } //获取总任务数
        inline int getCompletedCount() const { return completedCount; } //获取完成任务数
        inline double getCompletionRate() const { return completion_rate; } //获取完成率
};
#endif
