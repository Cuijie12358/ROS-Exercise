cmake_minimum_required(VERSION 2.8.3)
project(testpack)
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  message_generation
  actionlib
)

add_service_files(
   FILES
   DirAndDis.srv
)

add_action_files(
  DIRECTORY action
  FILES Fibonacci.action
)

generate_messages(
  DEPENDENCIES
  actionlib_msgs
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS message_runtime
  actionlib_msgs
)


include_directories(include ${catkin_INCLUDE_DIRS})

add_executable(talker src/talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})
add_dependencies(talker testpack_generate_messages_cpp)

add_executable(listener src/listener.cpp)
target_link_libraries(listener ${catkin_LIBRARIES})
add_dependencies(listener testpack_generate_messages_cpp)



add_executable(dir_and_dis_server src/dir_and_dis_server.cpp)
target_link_libraries(dir_and_dis_server ${catkin_LIBRARIES})
add_dependencies(dir_and_dis_server testpack_gencpp)

add_executable(dir_and_dis_client src/dir_and_dis_client.cpp)
target_link_libraries(dir_and_dis_client ${catkin_LIBRARIES})
add_dependencies(dir_and_dis_client testpack_gencpp)

add_executable(fibonacci_server src/fibonacci_server.cpp)
target_link_libraries(
  fibonacci_server
  ${catkin_LIBRARIES}
)

add_dependencies(
  fibonacci_server
  ${testpack_EXPORTED_TARGETS}
)


