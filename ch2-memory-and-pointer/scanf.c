#include<stdio.h>

int main(){
    int age;
    char fname[6], lname[6];
    printf("enter:fname lname:\n");
    scanf("%s %s", fname, lname);
    //scanf("%5s %5s", fname, lname);
    printf("enter age:\n");
    scanf("%i", &age);

    printf("fname  lname  age: %s %s %i \n", fname, lname, age);
    return 0;
}
