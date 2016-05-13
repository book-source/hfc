// page 62, why pointer have type?

#include <stdio.h>

int main(){
    char *c = "abc";
    char d[] = "abc";
    const int a = 1;
    int nums[] = {1, 2, 3};
   
    printf("addr of const int is: %p\n", a);    
 
    printf("c's address is %p\n", c);
    printf("c + 1 address is %p\n", c + 1);
    
    printf("d's address is %p\n", d);
    printf("d + 1 address is %p\n", d + 1);
    
    printf("nums' address is %p\n", nums);
    printf("nums + 1 address is %p\n", nums + 1);
    return 0;
}

