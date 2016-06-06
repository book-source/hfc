#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>


int main (int argc, char *argv[]) {

    char *phrase = argv[1];
    char *vars[] = {"RSS_FEED=http://www.cnbc.com/id/21324812/device/rss/rss.xml", NULL};

    FILE *f = fopen("stories.txt", "w");
    
    if(!f) {
        error("Can't open stories.txt");
    }
    
    pid_t pid = fork();
    if(pid == -1) {
        error("Can't fork process");
    }
    // this will change subprocess. 
    if(!pid) {
        // let file des 1 point to stories.txt.
       if (dup2(fileno(f), 1) == -1) {
           error("Can't redirect Standard Output");
        }        
	  if (execle ("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", phrase,
	       NULL, vars) == -1)
	    {
	      fprintf (stderr, "can't run script: %s\n", strerror (errno));
	      return 1;
	    }
	}
    // waitpid, important setp , is this part not essential?
    int pid_status;
    if (waitpid(pid, &pid_status, 0) == -1) {
        error("error occured when waiting for subprocess.");
    }   
    return 0;
}
