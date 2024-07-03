
project(Test)



file(GLOB_RECURSE HEADER_FILES "*.h")
#file(GLOB_RECURSE SOURCE_FILES "*.cpp" "*.c")


add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    
    "${SHM_MGR_SRC_DIR}"

)


link_libraries(${PROJECT_NAME} SHM_)