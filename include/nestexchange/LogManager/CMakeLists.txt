
project(NestExchange)

file (GLOB LOGMANAGER_INCLUDE_FILES *.h)
target_sources(LogManager PUBLIC ${LOGMANAGER_INCLUDE_FILES})

target_include_directories(LogManager PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
