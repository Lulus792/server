#!/bin/bash

gcc -o server code/server/server.c code/server/handling_error.c -std=c89 -Wall -Wextra -Wconversion -Werror -Walloca -Wpedantic -pedantic-errors -pedantic
