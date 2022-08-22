
project(NestExchange)

file (GLOB LOGMANAGER_SOURCE_FILES *.cpp)

add_library(LogManager ${LOGMANAGER_SOURCE_FILES} )

target_include_directories(LogManager PUBLIC ${SPDLOG_INCLUDE_DIR})
target_include_directories(LogManager PUBLIC ${SPDLOG_SOURCE_DIR})

