project(httpClient LANGUAGES CXX)

add_library(httpClient
    src/httpClient.cpp
)

target_link_libraries(httpClient PRIVATE
    Qt6::Core
    Qt6::Network
)
