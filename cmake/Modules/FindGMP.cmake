# Tries to find an install of the GNU multiple precision library
#
# Once done this will define
#  GMP_FOUND - BOOL: System has the GMP library installed
#  GMP_INCLUDE_DIRS - LIST:The GMP include directories
#  GMP_C_LIBRARIES - LIST:The libraries needed to use GMP via its C interface
#  GMP_CXX_LIBRARIES - LIST:The libraries needed to use GMP via its C++ interface

include(FindPackageHandleStandardArgs)

# Define the default search paths
set(GMP_LIBRARY_PATH "C:/msys64/mingw64/lib")
set(GMP_INCLUDE_PATH "C:/msys64/mingw64/include")

message(STATUS "Searching for GMP in:")
message(STATUS "  Library path: ${GMP_LIBRARY_PATH}")
message(STATUS "  Include path: ${GMP_INCLUDE_PATH}")

# Try to find libraries
find_library(GMP_C_LIBRARIES
  NAMES gmp
  HINTS ${GMP_LIBRARY_PATH}
  DOC "GMP C libraries"
)

find_library(GMP_CXX_LIBRARIES
  NAMES gmpxx
  HINTS ${GMP_LIBRARY_PATH}
  DOC "GMP C++ libraries"
)

# Try to find headers
find_path(GMP_C_INCLUDES
  NAMES gmp.h
  HINTS ${GMP_INCLUDE_PATH}
  DOC "GMP C header"
)

find_path(GMP_CXX_INCLUDES
  NAMES gmpxx.h
  HINTS ${GMP_INCLUDE_PATH}
  DOC "GMP C++ header"
)

# Check if the required variables were found
find_package_handle_standard_args(GMP
  REQUIRED_VARS GMP_C_LIBRARIES GMP_C_INCLUDES GMP_CXX_LIBRARIES GMP_CXX_INCLUDES)

if (GMP_FOUND)
  set(GMP_INCLUDE_DIRS "${GMP_C_INCLUDES}" "${GMP_CXX_INCLUDES}")
  list(REMOVE_DUPLICATES GMP_INCLUDE_DIRS)

  if (NOT TARGET GMP::GMP)
    add_library(GMP::GMP UNKNOWN IMPORTED)
    set_target_properties(GMP::GMP PROPERTIES
      INTERFACE_INCLUDE_DIRECTORIES "${GMP_C_INCLUDES}"
      IMPORTED_LOCATION "${GMP_C_LIBRARIES}")
  endif()
else()
  message(FATAL_ERROR "GMP library not found.")
endif()
