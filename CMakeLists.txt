cmake_minimum_required(VERSION 3.13)
project(logger C)

find_package(Threads)

set(CMAKE_C_STANDARD 11)

set(LOG_SOURCES log.c)

set(LOGGER_SOURCES logger.c)

set(SEND_SIGNAL_SOURCES send_signal.c)

add_executable(logger ${LOGGER_SOURCES} ${LOG_SOURCES})
add_executable(send_signal ${SEND_SIGNAL_SOURCES})

target_link_libraries(logger pthread)
target_link_libraries(send_signal pthread)
