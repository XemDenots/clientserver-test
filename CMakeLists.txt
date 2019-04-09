# Jorge Alberto Cervantes Montiel
# 20190409
# -------------------------------
# clientserver-test
#
cmake_minimum_required (VERSION 3.1)
project(clientserver-test)
add_executable(client ./src/client.c)
add_executable(server ./src/server.c)
set(EXECUTABLE_OUTPUT_PATH "./bin")
