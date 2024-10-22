set(CPACK_GENERATOR "ZIP")
set(CPACK_PACKAGE_FILE_NAME "wind")

install(TARGETS wind LIBRARY DESTINATION .)

file(GLOB_RECURSE CONAN_FILES "conan-deploy/app/full_deploy/host/**/*.dylib")
foreach(conan_file ${CONAN_FILES})
  message(${conan_file})
  install(FILES ${conan_file} DESTINATION .)
endforeach()

include(CPack)