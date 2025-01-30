#
# INSURA PRO CMR CmakeList file
#
# @author Emanuele Paiano - www.emanuelepaiano.it

cmake_minimum_required(VERSION 3.10)

project(CMR)

# find packages


# includes
include_directories(
  include
)

# find header & source
file(GLOB_RECURSE HEADER "include/*.hpp")
file(GLOB_RECURSE SOURCE "src/*.cpp")
file(GLOB DATA_FILES "data/*")


add_executable(${PROJECT_NAME} ${SOURCE} ${HEADER})

# copy all file from data folder into build folder

foreach(DATA_FILE ${DATA_FILES})
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${DATA_FILE} $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endforeach()


source_group("Header include" FILES ${HEADER})
source_group("Source src"     FILES ${SOURCE})

# link libraries
#target_link_libraries(${PROJECT_NAME} ${SOME_LIB})
