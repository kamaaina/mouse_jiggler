cmake_minimum_required(VERSION 3.13...3.27)

include(pico_sdk_import.cmake)

project(pico_mouse_jiggler)

pico_sdk_init()

add_executable(pico_mouse_jiggler
    main.c
    usb_descriptors.c
)

target_include_directories(pico_mouse_jiggler PUBLIC
        ${CMAKE_CURRENT_LIST_DIR})

target_link_libraries(pico_mouse_jiggler pico_stdlib pico_unique_id tinyusb_device tinyusb_board)

# enable usb
pico_enable_stdio_usb(pico_mouse_jiggler 0)

#disable uart
pico_enable_stdio_uart(pico_mouse_jiggler 0)

# create the uf2 file
pico_add_extra_outputs(pico_mouse_jiggler)
