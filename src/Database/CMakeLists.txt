
project(NestExchange)

file (GLOB DATABASE_SOURCE_FILES *.cpp)
add_library(Database ${DATABASE_SOURCE_FILES} )

target_include_directories(Database PUBLIC ${SPDLOG_INCLUDE_DIR})
target_include_directories(Database PUBLIC ${SPDLOG_SOURCE_DIR})
target_include_directories(Database PUBLIC ${DATABASE_INCLUDE_DIR})
target_include_directories(Database PUBLIC ${Boost_INCLUDE_DIR})
target_link_libraries(Database PUBLIC Boost::boost)
target_link_libraries(Database PUBLIC mongo::mongoc_shared)
target_include_directories(Database PUBLIC ${LIBMONGOC_INCLUDE_DIR})
target_include_directories(Database PUBLIC ${LIBBSON_INCLUDE_DIR})

target_include_directories(Database PUBLIC ${INCLUDE_DIR})
