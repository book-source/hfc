#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

int listener_d;
void handle_shutdown(int sig)
{
if (listener_d)
close(listener_d);
fprintf(stderr, "Bye!\n");
exit(0);
}

int
main (int argc, char *argv[])
{
  if (catch_signal (SIGINT, handle_shutdown) == -1)
    error ("Can't  set the interrupt handler");
  listener_d = open_listener_socket ();
  bind_to_port (listener_d, 30000);
  if (listen (listener_d, 10) == -1)
    error ("Can't listen");
  struct sockaddr_storage client_addr;
  unsigned int address_size = sizeof (client_addr);
  puts ("Waiting for connection");
  char buf[255];
  while (1)
    {
      int connect_d =
	accept (listener_d, (struct sockaddr *) &client_addr, &address_size);
      if (connect_d == -1)
	error ("Can't open secondary socket");
      if (say (connect_d,
	       "Internet Knock -
	       Knock Protocol Server \r\n Version 1.0 \r\nKnock ! Knock !
	       \r\n>") != -1)
	{
	  read_in (connect_d, buf, sizeof (buf));
	  if (strncasecmp (¡°Who ?. there ? ¡±, buf, 12))
	    say (connect_d, "You should say who's there ?!");
	  else
	    {
	      if (say (connect_d, "Oscar \r\n> ") != -1)
		{
		  read_in (connect_d, buf, sizeof (buf));
		  if (strncasecmp ("Oscar who ? ", buf, 10))
		    say (connect_d,
			 "You should say 'Oscar who ?'!\r \n");
		  else
		    say (connect_d, "Oscar silly question,
			 you get a silly answer \r\n");
		}
	    }
	}
      close (connect_d);
    }
  return 0;
}
