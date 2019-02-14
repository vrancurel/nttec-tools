# Copyright 2018 the QUADIRON authors
#
# This file is part of the QUADIRON tools.
#
# The QUADIRON tools are free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# The QUADIRON tools are distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with the QUADIRON tools.  If not, see <http://www.gnu.org/licenses/>.

# - Try to find GMP (GNU Multiple Precision Arithmetic Library)
#
# Once done this will define
#  GMP_FOUND        - System has GMP.
#  GMP_INCLUDE_DIRS - The GMP include directories.
#  GMP_LIBRARIES    - The libraries needed to use GMP.

include(LibFindMacros)

# Use pkg-config to get hints about paths.
libfind_pkg_check_modules(GMP_PKGCONF gmp)

# Include directory.
find_path(GMP_INCLUDE_DIR
  NAMES gmp.h
  PATHS ${GMP_PKGCONF_INCLUDE_DIRS}
)

# Finally the library itself.
find_library(GMP_LIBRARY
  NAMES gmp
  PATHS ${GMP_PKGCONF_LIBRARY_DIRS}
)

# Set the include dir/libraries variables and let libfind_process do the rest.
libfind_process(GMP)
