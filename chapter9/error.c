void error(char *msg)
{
  fprintf(stderr, "%s: %s\n", msg, strerror(errno));
  exit(1);
}


pid_t pid = fork();
if(pid == -1){
  error("can't clone process");
}

if(execle(...) == -1) {
  error("can't run the script");
}
