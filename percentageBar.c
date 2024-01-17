#include <stdio.h>
#include <stdlib.h>

int main()
{
    double percent;
    printf("Enter the percent (0-100), that you would like to see in a bar: ");
    scanf("%lf", &percent);

    int width = 30;
    int maxHeight = 20;
    int area = width * maxHeight;
    int reqArea = floor((area * percent)/100);

    printf(" ");
    for(int i=0; i<width+2; i++){
        if(i==0 || i==width+1){
            printf("|");
            continue;
        }
        printf("-");
    }
    printf("\n");

    int currArea = 0;
    for(int i=1; i<=maxHeight; i++){
        printf(" |");
        for(int y=1; y<=width; y++){
                currArea++;
            if(currArea <= area-reqArea){
                printf(" ");
                continue;
            }
            printf("#");
        }
        printf("|\n");
    }

    printf(" ");
    for(int i=0; i<width+2; i++){
        if(i==0 || i==width+1){
            printf("|");
            continue;
        }
        printf("-");
    }

    return 0;
}
