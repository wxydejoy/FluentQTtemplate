


# 设置要搜索的目录
set(BASE_DIR "${CMAKE_SOURCE_DIR}/Dependencies/ROS")

# 使用GLOB_RECURSE获取所有文件的路径
file(GLOB_RECURSE ALL_FILES "${BASE_DIR}/*")
foreach(_DIR ${ALL_DIRS})
    if(IS_DIRECTORY "${_DIR}")
        list(APPEND DIRECTORY_DIRS "${_DIR}")
    endif()
endforeach()
# 将文件路径列表添加到CMake变量中
# set(DIRECTORY_FILES ${ALL_FILES} CACHE INTERNAL "All files in the directory and subdirectories")

# 打印变量以验证结果
# message(STATUS "Files in directory and subdirectories: ${DIRECTORY_FILES}")




set(OTHER_LIBS  ElaWidgetTools qcustomplot2   PARENT_SCOPE)
set(OTHER_INCLUDE_DIR
    ${CMAKE_SOURCE_DIR}/Dependencies/ElaWidgetTools/include
    ${CMAKE_SOURCE_DIR}/Dependencies/ROS
    ${CMAKE_SOURCE_DIR}/Dependencies
    ${DIRECTORY_DIRS}
    PARENT_SCOPE

)

# set(OTHER_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/Dependencies/ElaWidgetTools/include ${CMAKE_SOURCE_DIR}/Dependencies PARENT_SCOPE)
# message(aaaaaaaa ${OTHER_INCLUDE_DIR})
# target_include_directories(MainLibrary PUBLIC ${PROJECT_SOURCE_DIR}/Dependencies/ElaWidgetTools/include)
