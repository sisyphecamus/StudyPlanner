#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <iostream>
#include "../include/Task.h"
#include "../include/ReminderScheduler.h"
#include <map>
#include <string>
#include <chrono>
#include <fstream>
#include <iomanip>
#include <sstream>

class TaskManager
{
    private:
        map<int,Task>tasks;
        int next_taskId;
        //添加当日日期,以"YYYY-MM-DD"格式存储,用于日期变更时清空tasks,日期检测和变更时修改current_date由前端完成
        string current_date;
        //shared_ptr<ReminderScheduler>reminder_scheduler; 
    public:
        
        TaskManager() :current_date("1999-01-01"), next_taskId(1) {}

        void loadTaskfromJson(string file_name);//程序启动时从json读入task
        void dumpTask(string file_name, int mode);//程序终止时导出到json文件

        void loadTask(Task& t);

        void clearTasks() { tasks.clear(); } //清空tasks,用于日期变更时

        //用户重新编辑某一特定任务,以id标识
        bool updateTask(int id, const TaskContent new_content, const chrono::system_clock::time_point new_ddl, const int new_p,
        const bool new_n_review);

        bool deleteTask(int id);//从tasks中移除，取消对应的提醒调度
        bool completeTask(int id);//查找task，markCompleted()后生成一个Record放入RecordManager，取消提醒调度此任务

        /*日期变更处理,清空tasks,取消已有提醒,根据传入的review创建新的task条目(复习),启动新一天的调度提醒*/
        void onDateChanged(const TaskContent & new_content, vector<Task>& review_task_from_yesterday);

        //调度提醒:由ReminderSchedule触发
        void startReminderForTask(const Task& task);
        void stopReminderForTask(int taskId);

        //获取所有任务
        map<int, Task> getAllTasks() const { return tasks; }
        //获取下一个任务
        int getNextId(){return next_taskId ++;};
        //获取当日任务总数
        int getTotalTasks()const {return tasks.size();}
        //获取当日任务完成数
        int getCompletedTasks()const;
};

#endif