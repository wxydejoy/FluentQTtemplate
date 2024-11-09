# link_directories(/)

# add_library(ElaWidgetTools STATIC IMPORTED) # 声明一个导入的静态库
# # set_target_properties(ElaWidgetTools PROPERTIES IMPORTED_LOCATION libElaWidgetTools.dll.a)
# message(-----------${CMAKE_SOURCE_DIR}/Dependencies/libElaWidgetTools.dll.a)
# set_target_properties(ElaWidgetTools PROPERTIES
#     IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/Dependencies/libElaWidgetTools.dll.a # For Windows
#     # IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/path/to/libElaWidgetTools.a # For Linux
# )

# list_add_prefix(SRC_EXPRESSIONS "${MAIN_DIR}/" "*.ui" "*.c" "*.cpp" "*.hpp" "*.cc")
# file(GLOB_RECURSE MAIN_SOURCES LIST_DIRECTORIES true ${SRC_EXPRESSIONS})
# list(APPEND MAIN_SOURCES "${MAIN_DIR}")
# foreach (item IN LISTS MAIN_SOURCES)
#     if (IS_DIRECTORY ${item})
#         list(APPEND MAIN_INCLUDE_DIR ${item})
#         continue()
#     endif()
#     list(APPEND MAIN_SRC ${item})
# endforeach()
set(OTHER_LIBS ElaWidgetTools PARENT_SCOPE)
# message(aaaaaaaa ${PROJECT_SOURCE_DIR}/Dependencies/ElaWidgetTools)
# target_include_directories(MainLibrary PUBLIC ${PROJECT_SOURCE_DIR}/Dependencies/ElaWidgetTools/include)
