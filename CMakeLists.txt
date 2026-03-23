cmake_minimum_required(VERSION 3.10.2)

# Name your library (this is what the Android app will look for)
project("darkfather-lib")

# Add your C++ file
add_library(darkfather-lib SHARED darkfather.cpp)

# Find the Android log and audio libraries
find_library(log-lib log)
find_package(oboe REQUIRED CONFIG)

# Link everything together
target_link_libraries(darkfather-lib oboe::oboe ${log-lib})
