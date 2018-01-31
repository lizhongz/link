set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories("/usr/local/include/cryptopp")
find_library(CRYPTOPP_LIB cryptopp)

find_package("boost")
find_library(BOOST_SYSTEM boost_system)

add_executable(blockchain main.cpp blockchain.cpp sha256.cpp tx.cpp server.cpp block.cpp utils.h)

target_link_libraries(blockchain "${CRYPTOPP_LIB}" "${BOOST_SYSTEM}")