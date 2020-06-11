cmake_minimum_required(VERSION 3.16.3)
project(example VERSION 0.1.0 DESCRIPTION "pybind11 example")

# find_package (Python 3 COMPONENTS Development)

# include_directories(${Python_INCLUDE_DIRS})

# include(CTest)
# enable_testing()

# add_library(example SHARED example.cpp)
# pybind11_add_module(<name> [MODULE | SHARED] [EXCLUDE_FROM_ALL] [NO_EXTRAS] [SYSTEM] [THIN_LTO] source1 [source2 ...])

find_package(pybind11 REQUIRED)
pybind11_add_module(example src/example.cpp)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
