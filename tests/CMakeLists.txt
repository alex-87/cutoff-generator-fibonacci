## Copyright (C) 2020 Alexis LE GOADEC.

## This file is part of the CutoffFifonacci project which is licensed under
## the European Union Public License v1.2.

## If a copy of the EUPL v1.2 was not distributed with this software,
## you can obtain one at : https://joinup.ec.europa.eu/collection/eupl/eupl-text-eupl-12


set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}")
find_package(Gecode)

include_directories(${GECODE_INCLUDE_DIR})

add_executable(CutOffFibonacci CutOffFibonacciTest.cpp)

target_link_libraries(CutOffFibonacci criterion)
target_link_libraries(CutOffFibonacci ${GECODE_LIBRARIES})

add_test(NAME "CutOffFibonacci" COMMAND CutOffFibonacci)
