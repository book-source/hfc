#include<stdio.h>

int main(){
    char food[5];
    printf("enter favorite food:\n");
    fgets(food, sizeof(food), stdin); 
    printf("food:%s\n", food);
    // if the size of food is 5, it can only catch 4 chars.
    printf("sizeof(food) is:%i\n", sizeof(food));
    return 0;
}
