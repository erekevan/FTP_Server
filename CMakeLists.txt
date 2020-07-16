cmake_minimum_required(VERSION 3.16)
project(ftp_server)

set(CMAKE_CXX_STANDARD 20)

add_executable(ftp_server server.h server.cpp connection_error.cpp connection_error.h io.cpp io.h network_io.cpp network_io.h file.cpp file.h file_not_found_error.cpp file_not_found_error.h)
add_executable(ftp_client client.h client.cpp connection_error.cpp connection_error.h io.cpp io.h network_io.cpp network_io.h file.cpp file.h file_not_found_error.cpp file_not_found_error.h)
