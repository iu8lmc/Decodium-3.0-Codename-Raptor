# Install script for directory: C:/Users/IU8LMC/Downloads/WSJTX_3.0_Source/bundle_fixup

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/decodium")
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

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "C:/msys64/mingw64/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  
        get_filename_component (the_qt_conf "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/qt.conf" REALPATH)
        file (WRITE "${the_qt_conf}"
"[Paths]
")

endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee]|[Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll]|[Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/plugins" TYPE DIRECTORY FILES
      "C:/msys64/mingw64/share/qt5/plugins/platforms"
      "C:/msys64/mingw64/share/qt5/plugins/styles"
      "C:/msys64/mingw64/share/qt5/plugins/accessible"
      "C:/msys64/mingw64/share/qt5/plugins/audio"
      "C:/msys64/mingw64/share/qt5/plugins/imageformats"
      FILES_MATCHING REGEX "/[^/]*\\.dll$" REGEX "/[^/]*minimal[^/]*\\.dll$" EXCLUDE REGEX "/[^/]*offscreen[^/]*\\.dll$" EXCLUDE REGEX "/[^/]*quick[^/]*\\.dll$" EXCLUDE REGEX "/[^/]*d\\.dll$" EXCLUDE)
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_CONFIG_NAME MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee]|[Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll]|[Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/plugins/sqldrivers" TYPE FILE FILES "C:/msys64/mingw64/share/qt5/plugins/sqldrivers/qsqlite.dll")
  endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  
        get_filename_component (the_qt_conf "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/qt.conf" REALPATH)
        file (APPEND "${the_qt_conf}"
"Plugins = ../plugins
")

endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  
        get_filename_component (the_path "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/plugins" REALPATH)
        file (GLOB_RECURSE QTPLUGINS "${the_path}/*.dll")
        include (BundleUtilities)
        set (BU_CHMOD_BUNDLE_ITEMS ON)
        set (gp_tool objdump)
        # canonicalize path in install context
        get_filename_component (the_exe $ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/decodium.exe REALPATH)
        fixup_bundle ("${the_exe}" "${QTPLUGINS}" "C:/msys64/mingw64/bin;C:/Program Files/hamlib-w64-4.6.2/lib/gcc/../bin;C:/msys64/mingw64/lib;C:/msys64/mingw64/lib/../bin;C:/msys64/mingw64/lib")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "C:/Users/IU8LMC/Downloads/WSJTX_3.0_Source/build-w2/bundle_fixup/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
