#include "stdio.h"
#include "encrypt.h"
#include "checksum.h"

int main(){
    char s[] = "Speak friend and enter";

// encrypt
    encrypt(s);
    printf("Encrypted to '%s'\n", s);
    printf("Checksum is '%i'\n", checksum(s));

// decrypt
    encrypt(s);
    printf("Decrypted back to  '%i'\n", s);
    printf("Checksum is '%i'\n", checksum(s));
    
    return 0;
}
