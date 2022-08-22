cmake_minimum_required(VERSION 3.15 FATAL_ERROR)

project(NestExchange LANGUAGES CXX C)

if(WIN32)
	message(FATAL_ERROR "NestExchange does not support WIN32")
endif()
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose Release or Debug" FORCE)
endif()


if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
endif()
if(CMAKE_BUILD_TYPE STREQUAL "Debag")
	add_compile_definitions(NEST_DEBUG)
else()
	add_compile_definitions(NEST_RELEASE)
endif()
add_compile_definitions(_NESTEXCHANGE_)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS OFF)
set(CMAKE_BUILD_TYPE DEBUG)
set(EXECUTABLE_FILE "main.cpp")
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
set(SPDLOG_DIR ${CMAKE_SOURCE_DIR}/external/spdlog)
set(SPDLOG_INCLUDE_DIR ${SPDLOG_DIR}/include)
set(SPDLOG_SOURCE_DIR ${SPDLOG_DIR}/src)
set(ACCOUT_INCLUDE_DIR ${INCLUDE_DIR}/nestexchange/Account)
set(APPLICATION_INCLUDE_DIR ${INCLUDE_DIR}/nestexchange/Application)
set(DATABASE_INCLUDE_DIR ${INCLUDE_DIR}/nestexchange/Database)
set(LOGMANAGER_INCLUDE_DIR ${INCLUDE_DIR}/nestexchange/LogManager)
set(ALL_INCLUDE_DIRS ${ACCOUT_INCLUDE_DIR} ${APPLICATION_INCLUDE_DIR} ${DATABASE_INCLUDE_DIR} ${LOGMANAGER_INCLUDE_DIR} )
set(LIBMONGOC_INCLUDE_DIR /usr/include/libmongoc-1.0)
set(LIBBSON_INCLUDE_DIR /usr/include/libbson-1.0)
find_package(mongoc-1.0 1.17 REQUIRED CONFIG)
find_package(Boost 1.4 REQUIRED CONFIG)



add_executable(${PROJECT_NAME} ${EXECUTABLE_FILE})

add_subdirectory(src)
add_subdirectory(include/nestexchange)

target_link_libraries(${PROJECT_NAME} PUBLIC mongo::mongoc_shared)
target_link_libraries(${PROJECT_NAME} PUBLIC Boost::boost)
target_include_directories(${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${LIBMONGOC_INCLUDE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${LIBBSON_INCLUDE_DIR})

add_subdirectory(${SPDLOG_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${SPDLOG_DIR}/include)
target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_DIR})


target_sources(NestExchange PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/dbconfig.json")
