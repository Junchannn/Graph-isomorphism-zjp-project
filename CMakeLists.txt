# Set the path to the vcpkg toolchain file
if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")
else()
    message(FATAL_ERROR "Please define the VCPKG_ROOT environment variable")
endif()

# Minimum CMake version required
cmake_minimum_required(VERSION 3.15)

# Project name
project(MyZKPProject VERSION 1.0)

# Specify C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find the nlohmann_json package
find_package(nlohmann_json CONFIG REQUIRED)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add the Graph_zkp library
add_library(Graph_zkp STATIC zkp.cpp)

# Link the nlohmann_json library to the Graph_zkp library
target_link_libraries(Graph_zkp PRIVATE nlohmann_json::nlohmann_json)

# Add executable targets
add_executable(verifier_exec verifier.cpp)
add_executable(prover_exec prover.cpp)

# Link the Graph_zkp library to the executables
target_link_libraries(verifier_exec PRIVATE Graph_zkp nlohmann_json::nlohmann_json)
target_link_libraries(prover_exec PRIVATE Graph_zkp nlohmann_json::nlohmann_json)

# Set output directories for executables
set_target_properties(verifier_exec PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/verifier)
set_target_properties(prover_exec PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/prover)
