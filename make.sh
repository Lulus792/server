#/bin/bash

if [[ "$1" == "-B" ]]; then
  mkdir build
fi

gcc -o build/client.o client.c

gcc -o build/server.o server.c
