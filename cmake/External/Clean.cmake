#*********************************************************#
#*  File: Check.cmake                                    *
#*
#*  Copyright (C) 2002-2013 The PixelLight Team (http://www.pixellight.org/)
#*
#*  This file is part of PixelLight.
#*
#*  Permission is hereby granted, free of charge, to any person obtaining a copy of this software
#*  and associated documentation files (the "Software"), to deal in the Software without
#*  restriction, including without limitation the rights to use, copy, modify, merge, publish,
#*  distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
#*  Software is furnished to do so, subject to the following conditions:
#*
#*  The above copyright notice and this permission notice shall be included in all copies or
#*  substantial portions of the Software.
#*
#*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
#*  BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
#*  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
#*  DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
#*  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#*********************************************************#


##################################################
## CMakeTools externals - Clean script
##
## Base for 'clean'-scripts
##################################################


##################################################
## Includes
##################################################
include(${CMAKETOOLS_DIR}/External/Base.cmake)


##################################################
## Default actions
##################################################

# Set log file
set(CMAKETOOLS_CURRENT_LOG "${CMAKETOOLS_CURRENT_BUILD_DIR}/Log/Clean.log")
file(WRITE ${CMAKETOOLS_CURRENT_LOG} "")

# Remove destination directory
external_removedir(${CMAKETOOLS_CURRENT_DEST_DIR})

# Remove 'done'-files
file(REMOVE ${CMAKETOOLS_CURRENT_BUILD_DIR}/Check.done)
file(REMOVE ${CMAKETOOLS_CURRENT_BUILD_DIR}/Fetch.done)
file(REMOVE ${CMAKETOOLS_CURRENT_BUILD_DIR}/Configure.done)
file(REMOVE ${CMAKETOOLS_CURRENT_BUILD_DIR}/Build.done)
file(REMOVE ${CMAKETOOLS_CURRENT_BUILD_DIR}/Install.done)
