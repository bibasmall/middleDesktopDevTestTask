project(textStreamHttpClient LANGUAGES CXX)

add_executable(textStreamHttpClient
  src/main.cpp
  src/textStreamHttpClient.cpp
)

include_directories(../httpClient/src)

set_target_properties(textStreamHttpClient PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(textStreamHttpClient PRIVATE
    Qt6::Core
    Qt6::Network
    httpClient
)
