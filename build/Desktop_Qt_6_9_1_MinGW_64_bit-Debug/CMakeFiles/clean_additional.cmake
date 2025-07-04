# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\To_Do_List_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\To_Do_List_autogen.dir\\ParseCache.txt"
  "To_Do_List_autogen"
  )
endif()
