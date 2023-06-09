cmake_minimum_required(VERSION 3.25)
project(Distributeur)

set(CMAKE_CXX_STANDARD 23)

set(FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR /usr/include/cppconn)
include_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/include)
include_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/include/cppconn)
link_directories(${FULL_PATH_TO_MYSQL_CONNECTOR_CPP_DIR}/lib)

add_executable(Distributeur src/main.cpp src/Database.h src/Database.cpp)

target_link_libraries(Distributeur mysqlcppconn)
target_compile_features(Distributeur PRIVATE cxx_range_for)

