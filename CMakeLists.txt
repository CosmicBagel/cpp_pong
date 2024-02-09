cmake_minimum_required(VERSION 3.28.3)

# ## Include cmake modules
include(FetchContent)

project(cpp_pong VERSION 0.1.0 LANGUAGES C CXX)

add_executable(cpp_pong) 

#ie if this is the top most level script
#   these options should only be set if not being used by another project
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
    # all of these compiler options are effectively global

    target_compile_options(cpp_pong PRIVATE -Wall -Wextra -Wpedantic -Wconversion -Wsign-conversion)

    if (CMAKE_BUILD_TYPE STREQUAL "Debug")
        # To get nicer stack traces in error messages add -fno-omit-frame-pointer. 
        # To get perfect stack traces you may need to disable inlining (just use -O1) and 
        # tail call elimination (-fno-optimize-sibling-calls).
        target_compile_options(cpp_pong PRIVATE -fsanitize=address)
        target_link_options(cpp_pong PRIVATE -fsanitize=address)
        # disable crash signal handler (at least segv handler) so that asan catches it
        # asan provides more useful info than just a stacktrace
        target_compile_definitions(cpp_pong PRIVATE DISABLE_CRASH_SIGNAL_HANDLER)
    endif()

    # this will give us a soft enforcement of the c17 cpp20 standard, project won't error out, but 
    # because of our warning flags, we will still be told when we're using non-standard c    
    # mixing c / c++ standard can cause weird ABI issues when linking
    target_compile_features(cpp_pong PRIVATE c_std_17 cxx_std_20)
endif()

# ## Include dependencies' source code
FetchContent_Declare(
  cpptrace
  GIT_REPOSITORY https://github.com/jeremy-rifkin/cpptrace.git
  GIT_TAG        v0.3.1 # <HASH or TAG>
)
FetchContent_MakeAvailable(cpptrace)
add_compile_definitions(CPPTRACE_STATIC=On)
target_link_libraries(cpp_pong PRIVATE cpptrace::cpptrace)

# ## Declare dependencies
add_subdirectory(external/)
target_link_libraries(cpp_pong PRIVATE raylib)

# CONFIGURE_DEPENDS flag makes it so that we don't have to run cmake when a new cpp file is added
file(GLOB cpp_pong_SRC CONFIGURE_DEPENDS "src/*.cpp" "src/*.c")
target_sources(cpp_pong PRIVATE ${cpp_pong_SRC})
target_include_directories(cpp_pong PRIVATE src)

# symlink the compile_commands.json so tools can easily see it
execute_process(
    COMMAND ${CMAKE_COMMAND} -E create_symlink
        ${CMAKE_BINARY_DIR}/compile_commands.json
        ${CMAKE_SOURCE_DIR}/compile_commands.json
)
