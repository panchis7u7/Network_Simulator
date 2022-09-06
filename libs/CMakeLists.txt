add_library(Platform INTERFACE
    platform.hpp
)

add_library(Logger SHARED
    Logger/include/Logger.hpp
    Logger/src/Logger.cpp
)

add_library(NetEvents SHARED
    Net/Event/include/IObserver.hpp
    Net/Event/src/IObserver.cpp
    Net/Event/include/IPublisher.hpp
    Net/Event/src/IPublisher.cpp
)

add_library(NetProtocols INTERFACE 
    Net/Protocols/Ethernet/802d3.hpp 
)

add_library(NetDevices SHARED
    Net/Devices/include/Interface.hpp
    Net/Devices/src/Interface.cpp
    Net/Devices/include/Slot.hpp
    Net/Devices/src/Slot.cpp
    Net/Devices/include/Device.hpp
    Net/Devices/src/Device.cpp
    Net/Devices/include/Types.hpp
    Net/Devices/include/Router.hpp
    Net/Devices/src/Router.cpp
)

target_include_directories(Platform INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(Logger PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Logger/include")
target_include_directories(NetProtocols INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/Net/Protocols")
target_include_directories(NetEvents PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Net/Event/include")
target_include_directories(NetDevices PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/Net/Devices/include")
target_link_libraries(NetEvents PUBLIC Platform Logger NetProtocols)
target_link_libraries(NetDevices PUBLIC Platform Logger NetProtocols NetEvents)