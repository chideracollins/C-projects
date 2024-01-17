#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int min(int a, int b, int c, int d){
    int nums[4] = {};
    nums[0] = a;
    nums[1] = b;
    nums[2] = c;
    nums[3] = d;
    for(int i=1; i<4; i++){
        if(nums[0]>nums[i]){
            int old_num = nums[0];
            nums[0] = nums[i];
            nums[i] = old_num;
        }
    }
    return nums[0];
}

int main()
{
    int size = 27;
    int n = floor(size/2);
    for(int y=0; y<size; y++){
        for(int i=0; i<size; i++){
            int y_rem = size-1-y;
            int i_rem = size-1-i;
            int num = n - min(y, i, y_rem, i_rem);
            printf("%2d  ", num);
        }
        printf("\n");
    }

    return 0;
}
