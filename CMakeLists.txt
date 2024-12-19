# SPDX-License-Identifier: Apache-2.0
# set(BOARD_ROOT ${CMAKE_CURRENT_LIST_DIR}/linum)
# set(DTS_ROOT ${CMAKE_CURRENT_LIST_DIR}/linum)

cmake_minimum_required(VERSION 3.20.0)

# include zephyr
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

# set the project name
project(ZPHR-STM32-0003)

#add all the source files to the build
file(GLOB src src/*.c)
target_sources(app PRIVATE ${src})
