#.rst:
# FindMariadbClient
# ---------------
# Finds the MariadbClient library
#
# This will will define the following variables::
#
# MARIADBCLIENT_FOUND - system has MariadbClient
# MARIADBCLIENT_INCLUDE_DIRS - the MariadbClient include directory
# MARIADBCLIENT_LIBRARIES - the MariadbClient libraries
# MARIADBCLIENT_DEFINITIONS - the MariadbClient compile definitions
#
# and the following imported targets::
#
#   MariadbClient::MariadbClient   - The MariadbClient library

# Don't find system wide installed version on Windows
if(WIN32)
  set(EXTRA_FIND_ARGS NO_SYSTEM_ENVIRONMENT_PATH)
else()
  set(EXTRA_FIND_ARGS)
endif()

find_path(MARIADBCLIENT_INCLUDE_DIR NAMES mysql.h PATH_SUFFIXES mariadb mysql)
# find_library(MARIADBCLIENT_LIBRARY_RELEASE NAMES mariadbclient mariadb
#                                          PATH_SUFFIXES lib
#                                          ${EXTRA_FIND_ARGS})
# find_library(MARIADBCLIENT_LIBRARY_DEBUG NAMES mariadbclient mariadb
#                                        PATH_SUFFIXES lib
#                                        ${EXTRA_FIND_ARGS})

include(SelectLibraryConfigurations)
select_library_configurations(MARIADBCLIENT)

find_library(MARIADBCLIENT_LIBRARY 
			 NAMES mariadb libmariadb mariadbclient
             PATH_SUFFIXES lib)

message(STATUS "MARIADBCLIENT_INCLUDE_DIR:${MARIADBCLIENT_INCLUDE_DIR} ")
message(STATUS "MARIADBCLIENT_LIBRARY:${MARIADBCLIENT_LIBRARY} ")

if(MARIADBCLIENT_INCLUDE_DIR AND EXISTS "${MARIADBCLIENT_INCLUDE_DIR}/mariadb/mysql_version.h")
  file(STRINGS "${MARIADBCLIENT_INCLUDE_DIR}/mariadb/mysql_version.h" mysql_version_str REGEX "^#define[\t ]+MARIADB_PACKAGE_VERSION[\t ]+\".*\".*")
  string(REGEX REPLACE "^#define[\t ]+MARIADB_PACKAGE_VERSION[\t ]+\"([^\"]+)\".*" "\\1" MARIADBCLIENT_VERSION_STRING "${mysql_version_str}")
  unset(mysql_version_str)
endif()


include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(MARIADBCLIENT
                                  REQUIRED_VARS MARIADBCLIENT_LIBRARY MARIADBCLIENT_INCLUDE_DIR
                                  VERSION_VAR MARIADBCLIENT_VERSION_STRING)

if(MARIADBCLIENT_FOUND)
  set(MARIADBCLIENT_LIBRARIES ${MARIADBCLIENT_LIBRARY})
  set(MARIADBCLIENT_INCLUDE_DIRS ${MARIADBCLIENT_INCLUDE_DIR})
  set(MARIADBCLIENT_DEFINITIONS -DHAS_MYSQL=1)

  if(NOT TARGET MariadbClient::MariadbClient)
    add_library(MariadbClient::MariadbClient UNKNOWN IMPORTED)
    if(MARIADBCLIENT_LIBRARY_RELEASE)
      set_target_properties(MariadbClient::MariadbClient 
                            PROPERTIES
                            IMPORTED_CONFIGURATIONS RELEASE
                            IMPORTED_LOCATION "${MARIADBCLIENT_LIBRARY_RELEASE}")
    endif()
    if(MARIADBCLIENT_LIBRARY_DEBUG)
      set_target_properties(
        MariadbClient::MariadbClient 
        PROPERTIES
            IMPORTED_CONFIGURATIONS DEBUG
            IMPORTED_LOCATION "${MARIADBCLIENT_LIBRARY_DEBUG}")
    endif()
    set_target_properties(
        MariadbClient::MariadbClient
        PROPERTIES
            INTERFACE_INCLUDE_DIRECTORIES "${MARIADBCLIENT_INCLUDE_DIR}"
            INTERFACE_COMPILE_DEFINITIONS HAS_MYSQL=1)
  endif()
endif()

mark_as_advanced(MARIADBCLIENT_INCLUDE_DIR MYSQLCLIENT_LIBRARY)