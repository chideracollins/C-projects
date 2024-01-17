#include <stdio.h>
#include <stdlib.h>

int main()
{
    int side = 3;
    int space = side-1;
    int col = side;
    for(int i=1; i<(3*side-1); i++){
        for(int y=0; y<space; y++) printf("  ");
        for (int y=0; y<col; y++) printf("* ");
        printf("\n");
        if(i>2*side-2){
            space++;
            col -= 2;
            continue;
        }else if(space>0){
            space = space-1;
            col = col+2;
        }
    }
    return 0;
}
