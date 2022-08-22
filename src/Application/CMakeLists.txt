project(NestExchange)

file (GLOB APPLICATION_SOURCE_FILES *.cpp)

add_library(Application ${APPLICATION_SOURCE_FILES} )

target_link_libraries(Application PUBLIC mongo::mongoc_shared)
target_link_libraries(Application PUBLIC Boost::boost)
target_include_directories(Application PUBLIC ${LIBMONGOC_INCLUDE_DIR})
target_include_directories(Application PUBLIC ${LIBBSON_INCLUDE_DIR})
target_include_directories(Application PUBLIC ${SPDLOG_INCLUDE_DIR})
target_include_directories(Application PUBLIC ${SPDLOG_SOURCE_DIR})

target_include_directories(Application PUBLIC ${Boost_INCLUDE_DIR})
target_include_directories(Application PUBLIC ${INCLUDE_DIR})


