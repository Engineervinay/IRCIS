set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCES
  Ircis.cc
  HTMLVizCSS.cc
  HTMLVizJS.cc
  Runner.cc
  Grid.cc
  Logger.cc
  DirVec.cc
  RunnerStack.cc
  DataType.cc
  CharMaps.cc
  )
include_directories(.)

add_library(${BINARY}_lib STATIC ${SOURCES})
target_compile_features(${BINARY}_lib PUBLIC cxx_std_14)

add_executable(${BINARY} main.cc)
target_link_libraries(${BINARY} PRIVATE ${BINARY}_lib)
target_compile_options(${BINARY} PRIVATE -Wall -Wextra -Wpedantic -Werror)

# Have a copy of the executable in the project root
add_custom_command(TARGET ${BINARY} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:ircis> ${PROJECT_SOURCE_DIR}/
  )
