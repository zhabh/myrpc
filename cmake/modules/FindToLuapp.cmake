# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

#.rst:
# FindTOLUAPP
# ---------
#
#
#
# Locate Lua library This module defines
#
# ::
#
#   TOLUAPP_FOUND, if false, do not try to link to Lua
#   TOLUAPP_LIBRARIES
#   TOLUAPP_INCLUDE_DIR, where to find TOLUAPP.h
#   TOLUAPP_VERSION_STRING, the version of TOLUAPP found (since CMake 2.8.8)
#
#
#
# Note that the expected include convention is
#
# ::
#
#   #include "tolua++.h"
#
# and not
#
# ::
#
#   #include <tolua++/tolua++.h>
#
# This is because, the lua location is not standardized and may exist in
# locations other than lua/

find_path(TOLUAPP_INCLUDE_DIR tolua++.h PATH_SUFFIXES include)


if(TOLUAPP_INCLUDE_DIR AND EXISTS "${TOLUAPP_INCLUDE_DIR}/tolua++.h")
	message(STATUS "TOLUAPP_LIBRARY:${TOLUAPP_LIBRARY}")
	file(STRINGS "${TOLUAPP_INCLUDE_DIR}/tolua++.h" toluapp_version_str REGEX "^#define[ \t]+TOLUA_VERSION[ \t]+\"tolua\\+\\+-([0-9]+)\\.([0-9]+)\\.([0-9]+)\"$")
	message(STATUS "toluapp_version_str:${toluapp_version_str}")
    string(REGEX REPLACE "^#define[ \t]+TOLUA_VERSION[ \t]+\"tolua\\+\\+-([0-9]+).*\"$" "\\1" TOLUAPP_VERSION_MAJOR "${toluapp_version_str}")
    string(REGEX REPLACE "^#define[ \t]+TOLUA_VERSION[ \t]+\"tolua\\+\\+-[0-9]+\\.([0-9]+).*\"$" "\\1" TOLUAPP_VERSION_MINOR  "${toluapp_version_str}")
    string(REGEX REPLACE "^#define[ \t]+TOLUA_VERSION[ \t]+\"tolua\\+\\+-[0-9]+\\.[0-9]+\\.([0-9]+).*\"$" "\\1" TOLUAPP_VERSION_PATCH "${toluapp_version_str}")

    set(TOLUAPP_VERSION_STRING "${TOLUAPP_VERSION_MAJOR}.${TOLUAPP_VERSION_MINOR}.${TOLUAPP_VERSION_PATCH}")

  unset(toluapp_version_str)
endif()

include(SelectLibraryConfigurations)
select_library_configurations(toluapp)

find_library(TOLUAPP_LIBRARY NAMES toluapp tolua++ libtoluapp libtolua++ PATH_SUFFIXES lib)

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set TOLUAPP_FOUND to TRUE if
# all listed variables are TRUE
FIND_PACKAGE_HANDLE_STANDARD_ARGS(toluapp
                                  REQUIRED_VARS TOLUAPP_LIBRARY TOLUAPP_INCLUDE_DIR
                                  VERSION_VAR TOLUAPP_VERSION_STRING)

mark_as_advanced(TOLUAPP_INCLUDE_DIR TOLUAPP_LIBRARIES TOLUAPP_LIBRARY)

if(TOLUAPP_FOUND)
	set(TOLUAPP_INCLUDE_DIRS ${TOLUAPP_INCLUDE_DIR})

    if(NOT TOLUAPP_LIBRARIES)
      set(TOLUAPP_LIBRARIES ${TOLUAPP_LIBRARY})
    endif()
endif()