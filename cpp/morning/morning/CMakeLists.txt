# CMakeList.txt: morning 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

include_directories("./time")

include_directories("./3rdparty/json")

# 将源代码添加到此项目的可执行文件。
add_executable (morning "morning.cpp" "./mytime/mytime.cpp")

#找到三方静态库
find_library(jsoncpp_lib NAMES jsoncpp PATHS)
target_link_libraries(morning ${jsoncpp_lib})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET morning PROPERTY CXX_STANDARD 20)
endif()

# TODO: 如有需要，请添加测试并安装目标。
