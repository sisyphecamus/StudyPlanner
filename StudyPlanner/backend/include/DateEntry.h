#ifndef DATAENTRY_H
#define DATAENTRY_H

#include "Record.h"
#include "Task.h"

//和TaskManager的逻辑相似
class DateEntry
{
    private:
        string datestr;//字符串形式标记日期 YYYY-MM-DD  
        map<int, Record> records; //记录的map，key为taskId 
        int total_tasks;
        int completedCount;
        double completion_rate; //total_tasks > 0 时计算
    public:
        //日期变更后的构造
        DateEntry(const string& s,TaskManager& tm, RecordManager& rm);
        //从json文件中恢复时的构造
        DateEntry(const json& j);
        //json数据交互
        static json toJson(const DateEntry&);
        static DateEntry fromJson(const json&);

        DateEntry get_DateEntry_info()const;
        //删除DateEntry中记录,会重新计算统计数
        void deleteRecord(int recordId); 
        //DateEntry中内容变动后(record被用户删除),重新计算统计数
        void recalcStats();
        
};

#endif