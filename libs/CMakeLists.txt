add_library(Logger SHARED
    Logger/include/Logger.hpp
    Logger/src/Logger.cpp
)

add_library(NetDevices SHARED
    Net/Devices/include/Device.hpp
    Net/Devices/src/Device.cpp
    Net/Devices/include/Types.hpp
    Net/Devices/include/Interface.hpp
    Net/Devices/src/Interface.cpp
    Net/Devices/include/Router.hpp
    Net/Devices/src/Router.cpp
)

target_include_directories(Logger PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Logger/include")
target_include_directories(NetDevices PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Net/Devices/include")
target_link_libraries(NetDevices PUBLIC Logger)