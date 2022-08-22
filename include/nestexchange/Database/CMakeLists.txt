
project(NestExchange)

file (GLOB DATABASE_INCLUDE_FILES *.h)
target_sources(Database PUBLIC ${DATABASE_INCLUDE_FILES})

target_include_directories(Database PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
