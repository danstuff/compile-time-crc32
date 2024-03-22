#!/bin/bash

printf "\n ====================================== Debugging Project... ===================================== \n\n"
cd build/bin/
gdb -ex run compile_time_crc32_test
