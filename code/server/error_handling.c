#include "server.h"

void handle_error(int *server_fd, char *error_msg, int exit_code) {
  printf("%s\n", error_msg);
  close(*server_fd);
  exit(exit_code);
}
