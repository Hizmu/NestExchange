
project(NestExchange)

file (GLOB ACCOUNT_INCLUDE_FILES *.h)
target_sources(Account PUBLIC ${ACCOUNT_INCLUDE_FILES})

target_include_directories(Account PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
