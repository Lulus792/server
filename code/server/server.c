#include "server.h"

int main() {
  server_var_t s_var;

  if ((s_var.server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    handle_error(&s_var.server_fd, "Failed to create socket", EXIT_FAILURE); 
  }

  if (setsockopt(s_var.server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                 &s_var.opt, sizeof(s_var.opt))) {
    handle_error(&s_var.server_fd, "setsockopt", EXIT_FAILURE);
  }

  s_var.addr.sin_family = AF_INET;
  s_var.addr.sin_addr.s_addr = INADDR_ANY;
  s_var.addr.sin_port = htons(PORT);

  if (bind(s_var.server_fd, (struct sockaddr *)&s_var.addr, sizeof(s_var.addr)) < 0) {
    handle_error(&s_var.server_fd, "bind failed", EXIT_FAILURE);
  }

  if (listen(s_var.server_fd, 3) < 0) {
    handle_error(&s_var.server_fd, "listening failed", EXIT_FAILURE);
  }

  if ((s_var.new_socket = accept(s_var.server_fd, (struct sockaddr *)&s_var.addr,
                                 (socklen_t *)&s_var.addrlen)) < 0) {
    handle_error(&s_var, "accept failed", EXIT_FAILURE);
  }

  close(s_var.new_socket);
  close(s_var.server_fd);
  return 0;
}
