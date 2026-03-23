# ─────────────────────────────────────────────────────────────
# Decodium Tools — standalone test utilities
# ─────────────────────────────────────────────────────────────
# Build (standalone):
#   PATH="/c/msys64/mingw64/bin:$PATH" cmake ../tools -B build-tools \
#     -G "MinGW Makefiles" \
#     -DCMAKE_CXX_COMPILER=C:/msys64/mingw64/bin/g++.exe \
#     -DCMAKE_Fortran_COMPILER=C:/msys64/mingw64/bin/gfortran.exe \
#     -DCMAKE_MAKE_PROGRAM=C:/msys64/mingw64/bin/mingw32-make.exe
#   PATH="/c/msys64/mingw64/bin:$PATH" mingw32-make -C build-tools
# ─────────────────────────────────────────────────────────────

cmake_minimum_required(VERSION 3.16)
project(decodium_tools CXX Fortran)

# ── Locate pre-built wsjt_fort library ──
set(WSJT_FORT_LIB "${CMAKE_CURRENT_SOURCE_DIR}/../build-w2/libwsjt_fort_omp.a"
    CACHE FILEPATH "Path to pre-built libwsjt_fort_omp.a")

if (NOT EXISTS "${WSJT_FORT_LIB}")
  set(WSJT_FORT_LIB "${CMAKE_CURRENT_SOURCE_DIR}/../build-w2/libwsjt_fort.a")
endif()

if (NOT EXISTS "${WSJT_FORT_LIB}")
  message(FATAL_ERROR "Cannot find libwsjt_fort_omp.a or libwsjt_fort.a in build-w2/. "
                      "Build the main project first.")
endif()

message(STATUS "Using Fortran lib: ${WSJT_FORT_LIB}")

# ── Fortran wrapper needs module files from the main build ──
# The .mod files are in build-w2/ (generated when wsjt_fort_omp was built)
set(WSJT_MOD_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../build-w2"
    CACHE PATH "Directory containing Fortran .mod files")

# ── Compile the Fortran C-binding wrapper ──
add_library(pack77_wrapper STATIC pack77_wrapper.f90)
target_include_directories(pack77_wrapper PRIVATE ${WSJT_MOD_DIR})

# ── Find gfortran runtime ──
find_library(GFORTRAN_LIB gfortran
  HINTS "C:/msys64/mingw64/lib" "C:/msys64/mingw64/lib/gcc/x86_64-w64-mingw32")
find_library(QUADMATH_LIB quadmath
  HINTS "C:/msys64/mingw64/lib")

# ── Build the simulator ──
add_executable(decodium_qso_sim decodium_qso_sim.cpp)

# Use --start-group/--end-group for circular Fortran deps
target_link_options(decodium_qso_sim PRIVATE -static)
target_link_libraries(decodium_qso_sim
  -Wl,--start-group
  pack77_wrapper
  ${WSJT_FORT_LIB}
  ${GFORTRAN_LIB}
  ${QUADMATH_LIB}
  -Wl,--end-group
)
