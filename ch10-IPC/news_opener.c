#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

/* mac os testing pass  */

void
error (char *msg)
{
  fprintf (stderr, "%s: %s\n", msg, strerror (errno));
  exit (1);
}

void
open_url (char *url)
{
  char launch[255];
  //for windows
  sprintf (launch, "cmd /c start %s", url);
  system (launch);
  //for linux
  // 
  sprintf (launch, "x-www-browser %s &", url);
  system (launch);
  //for MAC
  // the book have error, I fix it.
  sprintf (launch, "open %s", url);
  system (launch);
}

int
main (int argc, char *argv[])
{
  char *phrase = argv[1];
  char *vars[] =
    { "RSS_FEED=http://www.cnbc.com/id/21324812/device/rss/rss.xml", NULL };
  int fd[2];

  if (pipe (fd) == -1)
    {
      error ("can't create the pipe.");
    }
  pid_t pid = fork ();

  //you will go into child process.
  if (!pid)
    {
      dup2 (fd[1], 1);
      close (fd[0]);
      if (execle
	  ("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", "-u",
	   phrase, NULL, vars) == -1)
	{
	  error ("can't run script");
	}
    }
  //from here, you are in parent process.
  dup2 (fd[0], 0);
  close (fd[1]);
  char line[255];
  while (fgets (line, 255, stdin))
    {
      if (line[0] == '\t')
	{
	  open_url (line + 1);
	}
    }
  return 0;
}
