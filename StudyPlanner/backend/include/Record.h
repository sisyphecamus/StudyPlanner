#ifndef RECORD_H
#define RECORD_H

#include "Task.h"

/*
    相当于日期对象，存放在DateEntry中  
*/

class Record
{
    private:
        int id;//和task一样以一个id作为唯一标识
        int task_id;//关联task id
        chrono::system_clock::time_point  completed_time;
    public:
        json toJson()const;
        Record fromJson(const json&); 
};

#endif