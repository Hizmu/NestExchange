project(NestExchange)

add_subdirectory(Application)
add_subdirectory(Database)
add_subdirectory(Account)
add_subdirectory(LogManager)

set(SOURCE_LIB_NAMES Application Database Account LogManager)
target_link_libraries(${PROJECT_NAME} PUBLIC ${SOURCE_LIB_NAMES})
