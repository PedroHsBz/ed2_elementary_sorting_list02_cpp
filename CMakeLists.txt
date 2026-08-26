cmake_minimum_required(VERSION 4.2)
project(ed2_elementary_sorting_list02_cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

add_executable(Exer01_IsSorted src/Exer01_IsSorted.cpp)
add_executable(Exer02_InsertionSortStudents src/Exer02_InsertionSortStudents.cpp)
add_executable(Exer03_FindMedianInsertionSort src/Exer03_FindMedianInsertionSort.cpp)
add_executable(Exer04_InsertSorted src/Exer04_InsertSorted.cpp)
add_executable(Exer05_TaskSchedulingSelectionSort src/Exer05_TaskSchedulingSelectionSort.cpp)

# opcional, se quiser manter o Hello World separado
add_executable(main_app main.cpp)