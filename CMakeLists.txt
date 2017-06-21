# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.


project( v.mesher_ )

cmake_minimum_required(VERSION 2.8.10)

set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} lib)

find_package(CGAL QUIET COMPONENTS Core )
find_package(CGAL COMPONENTS ImageIO)

if ( CGAL_FOUND )

  include( ${CGAL_USE_FILE} )

  include( CGAL_CreateSingleSourceCGALProgram )

  create_single_source_cgal_program( "mesh_a_3d_gray_image.cpp" )

else()
  
    message(STATUS "This program requires the CGAL library, and will not be compiled.")
  
endif()

