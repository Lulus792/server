#ifndef _SERVER_
#define _SERVER_

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024

typedef struct server_variables {
  int server_fd, new_socket;
  struct sockaddr_in addr;
  int opt = 1;
  int addrlen = sizeof(addr);
  char buffer[BUFFER_SIZE] = { 0 };
} server_var_t;

void handle_error(int *server_fd, char *error_msg, int exit_code = 1);

#endif
