cmake_minimum_required(VERSION 3.10)  # 设置 CMake 最低版本
project(toolkit)         

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 头文件目录
include_directories(include)

# 添加主库
add_library(data_convert src/data_convert.cpp)

# 添加测试可执行文件
add_executable(test_data_convert test/test.cpp)
target_link_libraries(test_data_convert data_convert)

###### for toolkit
add_library(tool_kit STATIC
    src/data_convert.cpp
)

# 包含头文件目录
target_include_directories(tool_kit PUBLIC include)

# 导出库
install(TARGETS tool_kit
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)
install(DIRECTORY include/ DESTINATION include)