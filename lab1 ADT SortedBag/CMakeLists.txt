cmake_minimum_required(VERSION 3.23)
project(ADT_SortedBag)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ADT_SortedBag
        App.cpp
        ExtendedTest.cpp
        ExtendedTest.h
        ShortTest.cpp
        ShortTest.h
        SortedBag.cpp
        SortedBag.h
        SortedBagIterator.cpp
        SortedBagIterator.h)
