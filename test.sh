!/bin/bash

# Simple test of the command interpreter

in="abbabaq"
out="0,3,5;"

[[ $(./cmd_int <<< "$in") == "$out"* ]] && echo "PASSED" || echo "FAILED"

# # test case 1: only "a" and "b"
# in="ababaq"
# out="0,2,4;"
# [[ $(./cmd_int <<< "$in") == "$out"* ]] && echo "test case 1 : PASSED" || echo "test case 1: FAILED"


# #test case 2: using "c" to remove previous element
# in="abcabcabq"
# out="6;"
# [[ $(./cmd_int <<< "$in") == "$out"* ]] && echo "test case 2 : PASSED" || echo "test case 2: FAILED"
