# - Try to locate SDL2_image
# This module defines:
#
#  SDL2_IMAGE_INCLUDE_DIR
#  SDL2_IMAGE_LIBRARY
#  SDL2_IMAGE_FOUND
#

FIND_PATH(SDL2_INCLUDE_DIR NAMES SDL.h PATH_SUFFIXES SDL2)

FIND_LIBRARY(SDL2_LIBRARY NAMES SDL2)

INCLUDE(FindPackageHandleStandardArgs)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(SDL2 REQUIRED_VARS SDL2_LIBRARY SDL2_INCLUDE_DIR)

MARK_AS_ADVANCED(SDL2_INCLUDE_DIR SDL2_LIBRARY)

