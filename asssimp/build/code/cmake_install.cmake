# Install script for directory: G:/project/asssimp/code

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Assimp")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "G:/project/asssimp/build/code/Debug/assimp-vc140-mt.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "G:/project/asssimp/build/code/Release/assimp-vc140-mt.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "G:/project/asssimp/build/code/MinSizeRel/assimp-vc140-mt.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "G:/project/asssimp/build/code/RelWithDebInfo/assimp-vc140-mt.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "G:/project/asssimp/build/code/Debug/assimp-vc140-mt.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "G:/project/asssimp/build/code/Release/assimp-vc140-mt.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "G:/project/asssimp/build/code/MinSizeRel/assimp-vc140-mt.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "G:/project/asssimp/build/code/RelWithDebInfo/assimp-vc140-mt.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "G:/project/asssimp/code/../include/assimp/anim.h"
    "G:/project/asssimp/code/../include/assimp/ai_assert.h"
    "G:/project/asssimp/code/../include/assimp/camera.h"
    "G:/project/asssimp/code/../include/assimp/color4.h"
    "G:/project/asssimp/code/../include/assimp/color4.inl"
    "G:/project/asssimp/build/code/../include/assimp/config.h"
    "G:/project/asssimp/code/../include/assimp/defs.h"
    "G:/project/asssimp/code/../include/assimp/Defines.h"
    "G:/project/asssimp/code/../include/assimp/cfileio.h"
    "G:/project/asssimp/code/../include/assimp/light.h"
    "G:/project/asssimp/code/../include/assimp/material.h"
    "G:/project/asssimp/code/../include/assimp/material.inl"
    "G:/project/asssimp/code/../include/assimp/matrix3x3.h"
    "G:/project/asssimp/code/../include/assimp/matrix3x3.inl"
    "G:/project/asssimp/code/../include/assimp/matrix4x4.h"
    "G:/project/asssimp/code/../include/assimp/matrix4x4.inl"
    "G:/project/asssimp/code/../include/assimp/mesh.h"
    "G:/project/asssimp/code/../include/assimp/pbrmaterial.h"
    "G:/project/asssimp/code/../include/assimp/postprocess.h"
    "G:/project/asssimp/code/../include/assimp/quaternion.h"
    "G:/project/asssimp/code/../include/assimp/quaternion.inl"
    "G:/project/asssimp/code/../include/assimp/scene.h"
    "G:/project/asssimp/code/../include/assimp/metadata.h"
    "G:/project/asssimp/code/../include/assimp/texture.h"
    "G:/project/asssimp/code/../include/assimp/types.h"
    "G:/project/asssimp/code/../include/assimp/vector2.h"
    "G:/project/asssimp/code/../include/assimp/vector2.inl"
    "G:/project/asssimp/code/../include/assimp/vector3.h"
    "G:/project/asssimp/code/../include/assimp/vector3.inl"
    "G:/project/asssimp/code/../include/assimp/version.h"
    "G:/project/asssimp/code/../include/assimp/cimport.h"
    "G:/project/asssimp/code/../include/assimp/importerdesc.h"
    "G:/project/asssimp/code/../include/assimp/Importer.hpp"
    "G:/project/asssimp/code/../include/assimp/DefaultLogger.hpp"
    "G:/project/asssimp/code/../include/assimp/ProgressHandler.hpp"
    "G:/project/asssimp/code/../include/assimp/IOStream.hpp"
    "G:/project/asssimp/code/../include/assimp/IOSystem.hpp"
    "G:/project/asssimp/code/../include/assimp/Logger.hpp"
    "G:/project/asssimp/code/../include/assimp/LogStream.hpp"
    "G:/project/asssimp/code/../include/assimp/NullLogger.hpp"
    "G:/project/asssimp/code/../include/assimp/cexport.h"
    "G:/project/asssimp/code/../include/assimp/Exporter.hpp"
    "G:/project/asssimp/code/../include/assimp/DefaultIOStream.h"
    "G:/project/asssimp/code/../include/assimp/DefaultIOSystem.h"
    "G:/project/asssimp/code/../include/assimp/SceneCombiner.h"
    "G:/project/asssimp/code/../include/assimp/fast_atof.h"
    "G:/project/asssimp/code/../include/assimp/qnan.h"
    "G:/project/asssimp/code/../include/assimp/BaseImporter.h"
    "G:/project/asssimp/code/../include/assimp/Hash.h"
    "G:/project/asssimp/code/../include/assimp/MemoryIOWrapper.h"
    "G:/project/asssimp/code/../include/assimp/ParsingUtils.h"
    "G:/project/asssimp/code/../include/assimp/StreamReader.h"
    "G:/project/asssimp/code/../include/assimp/StreamWriter.h"
    "G:/project/asssimp/code/../include/assimp/StringComparison.h"
    "G:/project/asssimp/code/../include/assimp/StringUtils.h"
    "G:/project/asssimp/code/../include/assimp/SGSpatialSort.h"
    "G:/project/asssimp/code/../include/assimp/GenericProperty.h"
    "G:/project/asssimp/code/../include/assimp/SpatialSort.h"
    "G:/project/asssimp/code/../include/assimp/SkeletonMeshBuilder.h"
    "G:/project/asssimp/code/../include/assimp/SmoothingGroups.h"
    "G:/project/asssimp/code/../include/assimp/SmoothingGroups.inl"
    "G:/project/asssimp/code/../include/assimp/StandardShapes.h"
    "G:/project/asssimp/code/../include/assimp/RemoveComments.h"
    "G:/project/asssimp/code/../include/assimp/Subdivision.h"
    "G:/project/asssimp/code/../include/assimp/Vertex.h"
    "G:/project/asssimp/code/../include/assimp/LineSplitter.h"
    "G:/project/asssimp/code/../include/assimp/TinyFormatter.h"
    "G:/project/asssimp/code/../include/assimp/Profiler.h"
    "G:/project/asssimp/code/../include/assimp/LogAux.h"
    "G:/project/asssimp/code/../include/assimp/Bitmap.h"
    "G:/project/asssimp/code/../include/assimp/XMLTools.h"
    "G:/project/asssimp/code/../include/assimp/IOStreamBuffer.h"
    "G:/project/asssimp/code/../include/assimp/CreateAnimMesh.h"
    "G:/project/asssimp/code/../include/assimp/irrXMLWrapper.h"
    "G:/project/asssimp/code/../include/assimp/BlobIOSystem.h"
    "G:/project/asssimp/code/../include/assimp/MathFunctions.h"
    "G:/project/asssimp/code/../include/assimp/Macros.h"
    "G:/project/asssimp/code/../include/assimp/Exceptional.h"
    "G:/project/asssimp/code/../include/assimp/ByteSwapper.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xassimp-devx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "G:/project/asssimp/code/../include/assimp/Compiler/pushpack1.h"
    "G:/project/asssimp/code/../include/assimp/Compiler/poppack1.h"
    "G:/project/asssimp/code/../include/assimp/Compiler/pstdint.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "G:/project/asssimp/build/code/Debug/assimp-vc140-mt.pdb")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "G:/project/asssimp/build/code/RelWithDebInfo/assimp-vc140-mt.pdb")
  endif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
endif()

