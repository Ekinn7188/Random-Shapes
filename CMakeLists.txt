cmake_minimum_required(VERSION 3.16.3)
project(RandomShapes)

set(CMAKE_CXX_STANDARD 17)

add_executable(RandomShapes main.cpp)

# OpenGL and FreeGLUT
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
# Adds OpenGL and FreeGLUT to project.
target_link_libraries(RandomShapes ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

# Compile options for OpenGL (FreeGLUT)
add_compile_options(-lglut -lGLU -lGL)