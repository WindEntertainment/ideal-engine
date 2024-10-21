set(CPACK_GENERATOR "ZIP")
set(CPACK_PACKAGE_FILE_NAME "wind-wasm")

install(
  DIRECTORY "build/web/build/Release"
  DESTINATION .
  FILES_MATCHING
    PATTERN "*.wasm"
    PATTERN "*.html"
    PATTERN "*.js"
    PATTERN "*.css"
)

include(CPack)
