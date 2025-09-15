#!/bin/bash

# Simple test of the command interpreter

in="abbabaq"
out="0,3,5;"

[[ $(./cmd_int <<< "$in") == "$out"* ]] && echo "PASSED" || echo "FAILED"


in="abccbaabcq"
out="5;"

[[ $(./cmd_int <<< "$in") == "$out"* ]] && echo "PASSED" || echo "FAILED"




in="aaabccabaacaq"
out="0,6,8,11;"

[[ $(./cmd_int <<< "$in") == "$out"* ]] && echo "PASSED" || echo "FAILED"