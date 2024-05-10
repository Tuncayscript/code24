cmake_minimum_required(VERSION 3.10)
project(Code24 LANGUAGES CXX)  # Specify project language

# Set the C++ compiler standard (adjust as needed)
set(CMAKE_CXX_STANDARD 20)

# Find necessary libraries
find_package(LLVM REQUIRED)

# Add source files recursively (adjust directory as needed)
set(SOURCE_FILES
  antlr-llvm/*.cpp
  antlr-llvm/codegen/*.cpp
  antlr-llvm/syntax/*.cpp
  antlr-llvm/semantic/*.cpp
  # Include additional source directories here
)
add_sources(${SOURCE_FILES})

# Create an executable target (replace with your main function file)
add_executable(my_program main.cpp)

# Link the executable with the LLVM libraries
target_link_libraries(my_program PRIVATE LLVM::LLVM)

# Optional: Add compiler flags (adjust based on your needs)
target_compile_features(my_program PRIVATE cxx17)  # Enable specific C++ features

# Optional: Set output directory (adjust as needed)
set(CMAKE_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/bin")

# Optional: Configure testing framework (adjust as needed)
enable_testing()
# Add unit tests using tools like Google Test (requires additional setup)

# Optional: Create custom targets for specific tasks
add_custom_target(clean COMMAND rm -rf bin/* *.o *.a *.lai *.lo)  # Clean build artifacts

# Optional: Package the project (consider tools like CPack)
# ...
