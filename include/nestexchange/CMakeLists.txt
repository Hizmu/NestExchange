
project(NestExchange)

add_subdirectory(Application)
add_subdirectory(Database)
add_subdirectory(Account)
add_subdirectory(LogManager)
target_sources(${PROJECT_NAME} PUBLIC config.hpp)
target_sources(${PROJECT_NAME} PUBLIC core.h)

