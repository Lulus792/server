#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8000

int main() {
  int sock = 0;
  struct sockaddr_in serv_addr;
  char msg[1024];
  char buffer[1024] = {0};

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("\nSocket creation error\n");
    return -1;
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);

  // Convert IPv4 and IPv6 addresses from text to binary form
  if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
    printf("\nInvalid address/ Address not supported\n");
    return -1;
  }

  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    printf("\nConnection Failed\n");
    return -1;
  }

  int close_server = 0;
  while (!close_server) {
    scanf("%1023s", msg);
    send(sock, msg, strlen(msg), 0);
    read(sock, buffer, 1024);
    if (buffer[0] == '1') break;
  
    if (strlen(msg) >= 4) {
      if (msg[0] == 'q' &&
          msg[1] == 'u' &&
          msg[2] == 'i' &&
          msg[3] == 't') {
        close_server = 1;
      }
    }
  }
  

  close(sock);
  return 0;
}
