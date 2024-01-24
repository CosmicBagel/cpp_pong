cmake_minimum_required(VERSION 3.28)

project(template_project VERSION 0.1.0 LANGUAGES C CXX)

add_executable(template_project) 

#ie if this is the top most level script
#   these options should only be set if not being used by another project
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    # all of these compiler options are effectively global

    target_compile_options(template_project PRIVATE -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion)

    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        # To get nicer stack traces in error messages add -fno-omit-frame-pointer. 
        # To get perfect stack traces you may need to disable inlining (just use -O1) and 
        # tail call elimination (-fno-optimize-sibling-calls).
        target_compile_options(template_project PRIVATE -fsanitize=address)
        target_link_options(template_project PRIVATE -fsanitize=address)
    endif()

    # this will give us a soft enforcement of the c17 cpp20 standard, project won't error out, but 
    # because of our warning flags, we will still be told when we're using non-standard c    
    # mixing c / c++ standard can cause weird ABI issues when linking
    target_compile_features(template_project PRIVATE c_std_17 cxx_std_20)
endif()

# CONFIGURE_DEPENDS flag makes it so that we don't have to run cmake when a new cpp file is added
file(GLOB template_project_SRC CONFIGURE_DEPENDS "src/*.cpp")
target_sources(template_project PRIVATE ${template_project_SRC})

# symlink the compile_commands.json so tools can easily see it
execute_process(
    COMMAND ${CMAKE_COMMAND} -E create_symlink
        ${CMAKE_BINARY_DIR}/compile_commands.json
        ${CMAKE_SOURCE_DIR}/compile_commands.json
)
