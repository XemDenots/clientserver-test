//Client side c/c++ program to demonstrate socket programming
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 5678

int main( int argc, char const *argv[])
{
  struct sockaddr_in address;
  int sock = 0, valread;
  struct sockaddr_in serv_addr;
  char *hello = "Hello from client";
  char buffer[1024] = {0};
  if ((sock = socket(AF_INET, SOCK_STREAM, 0 )) < 0 )
  {
    printf("\n Socket creation error \n");
    return -1;
  }
  memset(&serv_addr, '0', sizeof(serv_addr));
  
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(PORT);
  
  // convert ipv4 and ipv6 addresses from text from binary form
  if (inet_pton( AF_INET, "192.168.130.100", &serv_addr.sin_addr) <= 0)
  {
    printf("\nInvalid address/ address not supported \n");
    return -1;
  }
 
  if ( connect( sock, ( struct sockaddr * )&serv_addr, sizeof(serv_addr)) < 0)
  {
    perror ("\nConnection Failed\n");
    return -1;
  }
  send( sock, hello, strlen(hello), 0);
  printf("Hello message sent\n");
  valread = read( sock,  buffer, 1024);
  printf("%s\n", buffer);
  return 0;
 
}
