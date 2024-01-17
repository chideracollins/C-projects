#include <stdio.h>
#include <stdlib.h>

char prompt(char fName[], char lName[])
{
    printf("Hello %s %s", fName, lName);
}
int main()
{
    char fName[20];
    char lName[20];

    printf("Hello User!\n");
    printf("Enter your full name: ");
    scanf("%s %s",& fName, & lName);

    prompt(fName, lName);
    return 0;
}
