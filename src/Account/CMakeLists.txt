project(NestExchange)



file (GLOB ACCOUNT_SOURCE_FILES *.cpp)

add_library(Account ${ACCOUNT_SOURCE_FILES} )

target_include_directories(Account PUBLIC ${SPDLOG_INCLUDE_DIR})
target_include_directories(Account PUBLIC ${SPDLOG_SOURCE_DIR})
target_include_directories(Account PUBLIC ${DATABASE_INCLUDE_DIR})
target_include_directories(Account PUBLIC ${Boost_INCLUDE_DIR})
target_link_libraries(Account PUBLIC Boost::boost)
target_link_libraries(Account PUBLIC mongo::mongoc_shared)
target_include_directories(Account PUBLIC ${LIBMONGOC_INCLUDE_DIR})
target_include_directories(Account PUBLIC ${LIBBSON_INCLUDE_DIR})
target_include_directories(Account PUBLIC ${INCLUDE_DIR})


