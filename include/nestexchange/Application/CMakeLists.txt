
project(NestExchange)

file (GLOB APPLICATION_INCLUDE_FILES *.h)
target_sources(Application PUBLIC ${APPLICATION_INCLUDE_FILES})

target_include_directories(Application PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
