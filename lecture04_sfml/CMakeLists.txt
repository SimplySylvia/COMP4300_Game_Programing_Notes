cmake_minimum_required(VERSION 3.1)

project(DrawnShapes)

# # If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

# # In most cases better set in the CMake cache
# set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
add_executable(DrawnShapes drawn_shapes.cpp)
target_link_libraries(DrawnShapes sfml-graphics sfml-audio)