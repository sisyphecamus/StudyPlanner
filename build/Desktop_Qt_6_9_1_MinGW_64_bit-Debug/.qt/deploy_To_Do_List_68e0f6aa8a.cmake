include("E:/QtProjects/To_Do_List/build/Desktop_Qt_6_9_1_MinGW_64_bit-Debug/.qt/QtDeploySupport.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/To_Do_List-plugins.cmake" OPTIONAL)
set(__QT_DEPLOY_I18N_CATALOGS "qtbase")

qt6_deploy_runtime_dependencies(
    EXECUTABLE E:/QtProjects/To_Do_List/build/Desktop_Qt_6_9_1_MinGW_64_bit-Debug/To_Do_List.exe
    GENERATE_QT_CONF
)
