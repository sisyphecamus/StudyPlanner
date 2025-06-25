/*Task 任务实体*/
#ifndef TASK_H
#define TASK_H

#include<string>
#include<chrono>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

struct TaskContent{
    std::string title;
    std::string content;
};

class Task
{
    private:
        int id;//以id为唯一标识
        int priority;
        TaskContent task_content;
        chrono::system_clock::time_point deadline;
/*
    完成时刻和创建时刻，可选，主要用于打卡展示
        system_clock::time_point completed_time; 
        system_clock::time_point created_time; 
*/
        bool completed;
        bool needs_review;
    public:
        Task(int t_id, int t_priority, TaskContent &t_content, chrono::system_clock::time_point &ddl,bool n_review);
        //json交互
        json toJson()const;
        Task fromJson(const json&);
        
        Task get_task_info();//get private info

        void markCompleted();
        void updateFrom(const Task& other);//user重新编辑任务

        //提醒调度方面
        bool isOverDue()const;
        chrono::minutes minutesUntilDeadline()const;//计算距离截至还有多少分钟,用于提醒调度 
};


#endif