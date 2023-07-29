cmake_minimum_required(VERSION 3.16)
project(cevns_sim)
set(CMAKE_CXX_STANDARD 20)
find_package(Geant4 REQUIRED ui_all vis_all)

list(APPEND CMAKE_PREFIX_PATH "/Users/jackxu/Neutrinos/geant4-v11.1.0-install/lib")

include_directories(/Users/jackxu/Neutrinos/geant4-v11.1.0-install/include/Geant4)

include(${Geant4_USE_FILE})

# Add all cpp and h files in the project directory to SOURCE_FILES
file(GLOB_RECURSE SOURCE_FILES
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
        "${PROJECT_SOURCE_DIR}/include/*.h"
        )

# Add all directories with headers to include paths
MACRO(HEADER_DIRECTORIES return_list)
    FILE(GLOB_RECURSE new_list *.h)
    SET(dir_list "")
    FOREACH(file_path ${new_list})
        GET_FILENAME_COMPONENT(dir_path ${file_path} PATH)
        SET(dir_list ${dir_list} ${dir_path})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES dir_list)
    SET(${return_list} ${dir_list})
ENDMACRO()

HEADER_DIRECTORIES(header_list)

include_directories(${header_list})

add_executable(${PROJECT_NAME} ${SOURCE_FILES} main.cpp)
target_link_libraries(cevns_sim ${Geant4_LIBRARIES})
# Add executable using all source files

