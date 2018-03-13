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

# - Try to find C++ binding for GMP (GNU Multiple Precision Arithmetic Library)
#
# Once done this will define
#  GMPXX_FOUND        - System has C++ binding for GMP.
#  GMPXX_INCLUDE_DIRS - The include directories for the C++ binding of GMP.
#  GMPXX_LIBRARIES    - The libraries needed to use the C++ binding of GMP.

include(LibFindMacros)

# Dependencies.
libfind_package(GMPXX GMP)

# Use pkg-config to get hints about paths.
libfind_pkg_check_modules(GMPXX_PKGCONF gmpxx)

# Include directory.
find_path(GMPXX_INCLUDE_DIR
  NAMES gmpxx.h
  PATHS ${GMPXX_PKGCONF_INCLUDE_DIRS}
)

# Finally the library itself.
find_library(GMPXX_LIBRARY
  NAMES gmpxx
  PATHS ${GMPXX_PKGCONF_LIBRARY_DIRS}
)

# Set the include dir/libraries variables and let libfind_process do the rest.
libfind_process(GMPXX)
