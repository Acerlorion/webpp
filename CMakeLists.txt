cmake_minimum_required(VERSION 3.11)
project(webpp)
set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE all LIST_DIRECTORIES true src/*)
file(GLOB_RECURSE source_files src/*.cpp)
file(GLOB_RECURSE header_files src/*.hpp)

foreach (file ${all})
  get_filename_component(dir ${file} DIRECTORY)
  list(APPEND include_dirs ${dir})
endforeach()

list(REMOVE_DUPLICATES include_dirs)

if (EMSCRIPTEN)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O1 -s SAFE_HEAP=1")
  set(CMAKE_EXECUTABLE_SUFFIX .html)
else()
  find_package(OpenGL REQUIRED)
  file(GLOB GLFW3 vanilla/*)
endif()

file(GLOB SOIL_SRC src/soil/*.c)

include_directories(${include_dirs} include)
if (EMSCRIPTEN)
  add_executable(webpp ${source_files} ${header_files} ${SOIL_SRC} ./examples/emscripten/main.cpp)
else()
  add_executable(webpp ${source_files} ${header_files} ${SOIL_SRC} ./examples/vanilla/main.cpp)
endif()

if (EMSCRIPTEN)
  set_target_properties(webpp PROPERTIES LINK_FLAGS "-s FULL_ES3=1 -s USE_GLFW=3 --preload-file ../shaders --preload-file ../assets --bind --shell-file ../assets/shell.html")
else()
  target_link_libraries(webpp ${OPENGL_LIBRARY} ${GLFW3})
endif()
