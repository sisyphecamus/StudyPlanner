#ifndef RECORD_H
#define RECORD_H

#include "../include/Task.h"
#include <fstream>
#include <optional>

class RecordManager; // 前向声明RecordManager类
/*
    相当于日期对象，存放在DateEntry中  
*/

class Record
{
    private:
        int id; //记录的唯一标识符
        string title;
        string content;
        bool completed; //记录是否已完成
    public:
        //第一个构造函数用于从json中恢复数据,id不由RecordManager分配
        Record(int r_id = 0, Task t = Task(), bool is_completed = false)
            : id(r_id), title(t.getTitle()), content(t.getContent()), completed(is_completed) {}

        //第二个构造函数创建新记录,id由RecordManager分配
        Record(Task &t, RecordManager &r);

        static json toJson(const Record&);
        static Record fromJson(const json&);

        inline bool getCompletedStats() const { return completed; }
        inline string getTitle() const {return title;}
        inline int getId() const { return id; }
};

#endif
