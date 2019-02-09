# - Try to locate SDL2_net
# This module defines:
#
#  SDL2_NET_INCLUDE_DIR
#  SDL2_NET_LIBRARY
#  SDL2_NET_FOUND
#

FIND_PATH(SDL2_NET_INCLUDE_DIR NAMES SDL_net.h PATH_SUFFIXES SDL2)

FIND_LIBRARY(SDL2_NET_LIBRARY NAMES SDL2_net)

INCLUDE(FindPackageHandleStandardArgs)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(SDL2_net REQUIRED_VARS SDL2_NET_LIBRARY SDL2_NET_INCLUDE_DIR)

MARK_AS_ADVANCED(SDL2_NET_INCLUDE_DIR SDL2_NET_LIBRARY)