#ifndef DATAENTRY_H
#define DATAENTRY_H

#include "Record.h"
#include "Task.h"

class DateEntry
{
    private:
        string datestr;//字符串形式标记日期 YYYY-MM-DD
        vector<Record>records;
        int total_tasks;
        int completedCount;
        double completion_rate; //total_tasks > 0 时计算
    public:
        DateEntry(string d_str, vector<Record>& r,int t_tasks, int c_tasks, double c_rate);

        //json数据交互
        json toJson()const;
        DateEntry fromJson(const json&);

        DateEntry get_DateEntry_info()const;

        void recalcStats();//根据records和totalTasks重新计算completedCount和completion_rate
        
};

#endif