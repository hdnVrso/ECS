
file(GLOB_RECURSE TESTS "*_test.cpp")
add_executable(Run_ECS_Tests ${TESTS})

target_link_libraries(Run_ECS_Tests gtest gtest_main ecs allocators)
target_include_directories(Run_ECS_Tests PRIVATE
  "${gtest_SOURCE_DIR}/include"
  "${gtest_SOURCE_DIR}"
  "${allocators_SOURCE_DIR}"
  "${ecs_SOURCE_DIR}"
  )