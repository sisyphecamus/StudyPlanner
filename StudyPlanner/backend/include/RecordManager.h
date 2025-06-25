#ifndef RECORDMANAGER_H
#define RECORDMANAGER_H

#include "Record.h"
#include "DateEntry.h"

class RecordManager
{
    private:
       map<string,DateEntry>date_entries;
       int nextRecordID;
    public:
        void loadFromJson(const json&);
        json dumpToJson()const;
        
        Record createRecord(int taskId);
        bool deleteRecord(int recordId);//根据recordId在对应DateEntry中删除记录

        //查询
        vector<DateEntry>getAllDateEntries()const;
        DateEntry getDateEntry(const string& data_str)const;//根据日期str获得单个DateEntry
};

#endif