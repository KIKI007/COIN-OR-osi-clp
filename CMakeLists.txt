#==============================================================================                                                                                                                                                                                             

PROJECT(COIN_OR_CLP C CXX)

# CMake version control
CMAKE_MINIMUM_REQUIRED(VERSION 3.10)

# static libraries only
SET(BUILD_SHARED_LIBS OFF)

# use PIC code for link into shared lib
IF(UNIX)
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
ENDIF(UNIX)

# sources directories
INCLUDE_DIRECTORIES(.
                    ./ext/CoinUtils/src/
                    ./ext/Osi/src/Osi
                    ./Clp/src/
                    ./Clp/src/OsiClp/
                    ./Clp/test/
                    ./Clp/examples/
                   )

# optimise GNU GCC
IF(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    ADD_DEFINITIONS(-O3 -Wall -D_FILE_OFFSET_BITS=64 -D_LARGEFILE_SOURCE -ffast-math)
ENDIF(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)


# Visual Basic options
IF(MSVC)
    ADD_DEFINITIONS(
                    -D_CRT_SECURE_NO_WARNINGS
                    -D_CRT_SECURE_NO_DEPRECATE
                    #-DSAMPLEDIR="..\..\..\..\Data\Sample\\"
                    )
ENDIF(MSVC)


# Add subdirectories CMakelists
ADD_SUBDIRECTORY(ext/CoinUtils)
ADD_SUBDIRECTORY(ext/Osi)
ADD_SUBDIRECTORY(Clp)

#ADD_EXECUTABLE(hello Clp/examples/hello.cpp)
#TARGET_LINK_LIBRARIES(hello lib_Osi lib_Clp lib_CoinUtils)
#CONFIGURE_FILE(Clp/examples/hello.mps hello.mps COPYONLY)  # input needed for hello
#
#ADD_EXECUTABLE(modify Clp/examples/modify.cpp)
#TARGET_LINK_LIBRARIES(modify lib_Clp lib_CoinUtils)
#
#ADD_EXECUTABLE(minimum Clp/examples/minimum.cpp)
#TARGET_LINK_LIBRARIES(minimum lib_Clp lib_CoinUtils)
#CONFIGURE_FILE(Clp/examples/p0033.mps p0033.mps COPYONLY)  # input needed for minimum
