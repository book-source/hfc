gcc -S encrypt.c
ls
gcc -S message_hider.c
ls
gcc -c encrypt.s 
ls
gcc -c message_hider.c
ls
rm message_hider
ls
gcc -o message_hider *.o

./message_hider 
stat encrypt.o 
stat encrypt.c
vi encrypt.c
stat encrypt.c
stat encrypt.s
stat message_hider
file message_hider
file encrypt.c
file encrypt.o
file encrypt.s
history 
