# Copyright 2018 the NTTEC authors
#
# This file is part of the NTTEC tools.
#
# The NTTEC tools are free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# The NTTEC tools are distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with the NTTEC tools.  If not, see <http://www.gnu.org/licenses/>.

##############
# Source files
##############

set(TOOLS_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/find_pminus1_compo.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/find_primes.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/is_prime.cpp

  CACHE
  INTERNAL
  ""
  FORCE
)

##########
# Binaries
##########

set(FIND_PMINUS1_COMPO_BIN_NAME find_pminus1_compo)
add_executable(${FIND_PMINUS1_COMPO_BIN_NAME}
  ${CMAKE_CURRENT_SOURCE_DIR}/find_pminus1_compo.cpp
)

set(FIND_PRIMES_BIN_NAME find_primes)
add_executable(${FIND_PRIMES_BIN_NAME}
  ${CMAKE_CURRENT_SOURCE_DIR}/find_primes.cpp
)

set(IS_PRIMES_BIN_NAME is_prime)
add_executable(${IS_PRIMES_BIN_NAME}
  ${CMAKE_CURRENT_SOURCE_DIR}/is_prime.cpp
)

set(TOOLS_BIN_NAME
  ${FIND_PMINUS1_COMPO_BIN_NAME}
  ${FIND_PRIMES_BIN_NAME}
  ${IS_PRIMES_BIN_NAME}
)

##############
# Dependencies
##############

find_package(GMPXX REQUIRED)
find_package(NTTEC REQUIRED)

get_property(NTTEC_INCLUDE_DIRS
  TARGET   NTTEC::static
  PROPERTY INTERFACE_INCLUDE_DIRECTORIES
)

foreach(tool ${TOOLS_BIN_NAME})
  target_include_directories(${tool}
    SYSTEM PUBLIC ${GMPXX_INCLUDE_DIRS}
    SYSTEM PUBLIC ${NTTEC_INCLUDE_DIRS}
  )
  target_link_libraries(${tool}
    NTTEC::static
    ${GMPXX_LIBRARIES}
  )
endforeach()

#############
# Root target
#############

add_custom_target(${NTTEC_TOOLS}
  COMMENT "build the NTTEC tools"
)

add_dependencies(${NTTEC_TOOLS}
    ${TOOLS_BIN_NAME}
)
