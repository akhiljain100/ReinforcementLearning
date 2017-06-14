cmake_minimum_required(VERSION 2.6) 
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=gnu++0x")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(“Learning”)
set(EIGEN3_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/lib/Eigen)

IF( NOT EIGEN3_INCLUDE_DIR )
    MESSAGE( FATAL_ERROR "Please point the environment variable EIGEN3_INCLUDE_DIR to the include directory of your Eigen3 installation.")
ENDIF()
INCLUDE_DIRECTORIES ( "${EIGEN3_INCLUDE_DIR}" )


set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)



add_executable(ZLearning ${PROJECT_SOURCE_DIR}/src/main.cc ${PROJECT_SOURCE_DIR}/src/Gridworld.cc ${PROJECT_SOURCE_DIR}/src/Agent.cc ${PROJECT_SOURCE_DIR}/src/TestZlearning.cc ${PROJECT_SOURCE_DIR}/src/TestQlearning.cc)
                   

set_property(TARGET ZLearning PROPERTY CXX_STANDARD 11)
       