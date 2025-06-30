#ifndef RECORDMANAGER_H
#define RECORDMANAGER_H

#include "Record.h"
#include "DateEntry.h"

/*
    Record管理的顶层模块:
    遵循 Record -> DateEntry -> RecordManager 的层次结构
*/
class RecordManager
{
    private:
       map<string,DateEntry>date_entries;
       int nextRecordID;
    public:
        void loadFromJson();
        void dumpEntries()const;
        
        bool deleteSingleEntry(string date_str);//根据recordId在对应DateEntry中删除记录

        //查询
        DateEntry getDateEntry(const string& date_str)const;//根据日期str获得单个DateEntry

        //获取下一个记录ID
        int getNextId() { return nextRecordID++; }
};

#endif