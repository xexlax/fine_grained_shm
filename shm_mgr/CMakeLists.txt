project(SHM_Manager)

file(GLOB_RECURSE HEADER_FILES "*.h")
file(GLOB_RECURSE SOURCE_FILES "*.cpp" "*.c")


add_library(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

