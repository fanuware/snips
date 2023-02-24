cmake_minimum_required(VERSION 3.5.0)

if(WIN32)
    project(Snips CXX)
else()
    project(snips CXX)
endif()

set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 COMPONENTS Core)
if (NOT Qt6_FOUND)
    find_package(Qt5 COMPONENTS REQUIRED Core)
endif()

set(CMAKE_AUTOMOC ON)

add_executable(${PROJECT_NAME}
    src/consumer.h
    src/main_app.cpp
    src/main_app.h
    src/main.cpp
    src/producer.h)

target_link_libraries(${PROJECT_NAME} PUBLIC Qt::Core)

target_compile_definitions(${PROJECT_NAME}
  PRIVATE
    $<$<CONFIG:Debug>:
        DEBUG
    >
)

if(MSVC)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory $<TARGET_FILE_DIR:${PROJECT_NAME}>/platforms
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::QWindowsIntegrationPlugin> $<TARGET_FILE_DIR:${PROJECT_NAME}>/platforms/
        COMMAND ${CMAKE_COMMAND} -E copy_if_different $<TARGET_FILE:Qt5::Core> $<TARGET_FILE_DIR:${PROJECT_NAME}>
    )
endif()
