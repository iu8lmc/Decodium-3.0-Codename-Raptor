if (NOT EXISTS "C:/Users/IU8LMC/Downloads/WSJTX_3.0_Source/build-w2/install_manifest.txt")
  message (FATAL_ERROR "Cannot find install manifest: \"C:/Users/IU8LMC/Downloads/WSJTX_3.0_Source/build-w2/install_manifest.txt\"")
endif ()

file (READ "C:/Users/IU8LMC/Downloads/WSJTX_3.0_Source/build-w2/install_manifest.txt" files)
string (REGEX REPLACE "\n" ";" files "${files}")
foreach (file ${files})
  message (STATUS "Uninstalling \"$ENV{DESTDIR}${file}\"")
  if (EXISTS "$ENV{DESTDIR}${file}")
    exec_program (
      "C:/msys64/mingw64/bin/cmake.exe" ARGS "-E remove \"$ENV{DESTDIR}${file}\""
      OUTPUT_VARIABLE rm_out
      RETURN_VALUE rm_retval
      )
    if ("${rm_retval}" STREQUAL 0)
    else ()
      message (FATAL_ERROR "Problem when removing \"$ENV{DESTDIR}${file}\"")
    endif ()
  else ()
    message (STATUS "File \"$ENV{DESTDIR}${file}\" does not exist.")
  endif ()
endforeach ()
