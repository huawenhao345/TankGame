cmake_minimum_required(VERSION 3.22)
project(TankGame)
include_directories(head)
aux_source_directory(./ MAINDIC)
add_executable(main ${MAINDIC})