project(foodAcceptance)
cmake_minimum_required(VERSION 3.11.3)
# set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++17 -pthread -lsqlite3 ")

find_package(wxWidgets REQUIRED COMPONENTS core base)
find_package(wxWidgets COMPONENTS core base adv REQUIRED)
find_package(OpenCV 4.1 REQUIRED)

include(${wxWidgets_USE_FILE})
include_directories(${OpenCV_INCLUDE_DIRS})
link_directories(${OpenCV_LIBRARY_DIRS})
add_definitions(${OpenCV_DEFINITIONS})



# Find all executables
file(GLOB project_SRCS src/*.cpp) #src/*.h

# Add project executable
add_executable(foodAcceptance ${project_SRCS})

include_directories(/usr/include)
link_directories(/usr/lib)
target_link_libraries(foodAcceptance sqlite3)

target_link_libraries(foodAcceptance ${OpenCV_LIBRARIES})
target_link_libraries(foodAcceptance ${wxWidgets_LIBRARIES})
target_include_directories(foodAcceptance PRIVATE ${wxWidgets_INCLUDE_DIRS})
