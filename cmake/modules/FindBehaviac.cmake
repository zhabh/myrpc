#.rst:
# FindBehaviac
# ---------------
# Finds the  Behaviac library
#
# This will will define the following variables::
#
# Behaviac_FOUND - system has MariadbClient
# Behaviac_INCLUDE_DIRS - the MariadbClient include directory
# Behaviac_LIBRARIES - the MariadbClient libraries
#

find_path(Behaviac_INCLUDE_DIR behaviac.h PATH_SUFFIXES include behaviac )


if(Behaviac_INCLUDE_DIR AND EXISTS "${Behaviac_INCLUDE_DIR}/common/_config.h")
#	message(STATUS "Behaviac_LIBRARY:${Behaviac_LIBRARY}")
	file(STRINGS "${Behaviac_INCLUDE_DIR}/common/_config.h" Behaviac_version_str REGEX "^#define[ \t]+BEHAVIAC_VERSION_STRING[ \t]+\"([0-9]+)\\.([0-9]+)\\.([0-9]+)\"$")
	message(STATUS "Behaviac_version_str:${Behaviac_version_str}")
    string(REGEX REPLACE "^#define[ \t]+BEHAVIAC_VERSION_STRING[ \t]+\"([0-9]+).*\"$" "\\1" Behaviac_VERSION_MAJOR "${Behaviac_version_str}")
    string(REGEX REPLACE "^#define[ \t]+BEHAVIAC_VERSION_STRING[ \t]+\"[0-9]+\\.([0-9]+).*\"$" "\\1" Behaviac_VERSION_MINOR  "${Behaviac_version_str}")
    string(REGEX REPLACE "^#define[ \t]+BEHAVIAC_VERSION_STRING[ \t]+\"[0-9]+\\.[0-9]+\\.([0-9]+).*\"$" "\\1" Behaviac_VERSION_PATCH "${Behaviac_version_str}")

    set(Behaviac_VERSION_STRING "${Behaviac_VERSION_MAJOR}.${Behaviac_VERSION_MINOR}.${Behaviac_VERSION_PATCH}")

  unset(Behaviac_version_str)
endif()

include(SelectLibraryConfigurations)
select_library_configurations(Behaviac)

find_library(Behaviac_LIBRARY NAMES behaviac libbehaviac PATH_SUFFIXES lib)

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set Behaviac_FOUND to TRUE if
# all listed variables are TRUE
FIND_PACKAGE_HANDLE_STANDARD_ARGS(Behaviac
                                  REQUIRED_VARS Behaviac_LIBRARY Behaviac_INCLUDE_DIR
                                  VERSION_VAR Behaviac_VERSION_STRING)

mark_as_advanced(Behaviac_INCLUDE_DIR Behaviac_LIBRARIES Behaviac_LIBRARY)

if(Behaviac_FOUND)
	set(Behaviac_INCLUDE_DIRS ${Behaviac_INCLUDE_DIR})
	# message(STATUS "Behaviac_INCLUDE_DIRS:${Behaviac_INCLUDE_DIRS}")
    if(NOT Behaviac_LIBRARIES)
      set(Behaviac_LIBRARIES ${Behaviac_LIBRARY})
    endif()
endif()