// error.c 
// error handlling


#include <errno.h>

void error(char *msg)
{
  fprintf(stderr, "%s: %s\n", msg, strerror(errno));
  exit(1);
}

// usage : include error function and call it;
pid_t pid = fork();
if (pid == -1){
  error("can't clone process\n");
}

if (execl(...) == -1){
  error("can't run the script");
}

