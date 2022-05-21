# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\HW_26_05_2022_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\HW_26_05_2022_autogen.dir\\ParseCache.txt"
  "HW_26_05_2022_autogen"
  )
endif()
