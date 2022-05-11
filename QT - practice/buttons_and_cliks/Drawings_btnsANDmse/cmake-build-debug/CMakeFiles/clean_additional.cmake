# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Drawings_btnsANDmse_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Drawings_btnsANDmse_autogen.dir\\ParseCache.txt"
  "Drawings_btnsANDmse_autogen"
  )
endif()
