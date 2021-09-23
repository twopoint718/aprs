# Specify the minimum version of CMake
cmake_minimum_required (VERSION 3.19)

# Import the Pico SDK
include(pico_sdk_import.cmake)

# Create a project
project(Serial_project)

# Initialize the SDK
pico_sdk_init()

add_executable(helloworld serial.c)

# Direct stdio to USB (CDC)
pico_enable_stdio_usb(helloworld 1)
pico_enable_stdio_uart(helloworld 0)

target_link_libraries(helloworld pico_stdlib hardware_pwm)

pico_add_extra_outputs(helloworld)
