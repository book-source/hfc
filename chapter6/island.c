#include <stdio.h>
#include <stdlib.h>

typedef struct island{
    char *name;
    char *opens;
    char *closes;
    struct island *next;
} island;

island* create(char *name){
    island *i = malloc(sizeof(island));
    i->opens = "09:00";
    i->closes = "17:00";
    i->next = NULL;
    return i;
}

int main(){
    char *i_name = "totyo";
    island *i = create(i_name);
    printf("%s\n", i->opens);
    free(i);
    return 0;
}
