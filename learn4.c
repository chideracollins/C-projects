#include <stdio.h>
#include <stdlib.h>

int main()
{
    char charaterName[] = "Thomas";
    int characterAge = 87;
    printf("There once was a man named %s\n", charaterName);
    printf("He was %d years old.\nj", characterAge);

    characterAge = 34;
    printf("He really liked the name %s\n", charaterName);
    printf("But did not like being %d\n", characterAge);

    return 0;
}
