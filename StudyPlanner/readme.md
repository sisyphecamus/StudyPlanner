1. 文件结构
   - backend
     - include
       - DateEntry.h
       - Record.h
       - RecordManager.h
       - Task.h
       - TaskManager.h
     - src
       - DateEntry.cpp
       - Record.cpp
       - RecordManager.cpp
       - Task.cpp
       - TaskManager.cpp
   - test
     - file_IO_test.cpp

2. 注意事项
   - 请确保在使用文件读写功能时，文件路径正确。(例如：`../saved_json_file/RecordManager.json` )
   - 在进行大规模重构时，请保持各个模块间的接口一致性。
   - 测试用例应覆盖所有关键功能，包括边界情况。