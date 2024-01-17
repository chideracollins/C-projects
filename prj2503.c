#include <stdio.h>
#include <stdlib.h>

int main()
{
    char rpl = 'y';
    printf("Factorials(!), Permutation(p) and Combination(c)\n");
    while(1){
        char symbol = 'x';
        int num1;
        int num2;
        double result1;
        printf("Choose your operation type, !/p/c or x to terminate: ");
        scanf("%c",& symbol);
        if(symbol == 'x') break;
        int n;
        if(symbol == '!'){
            printf("Enter the number: ");
            scanf("%d", &num1);
            result1 = num1;
            for(int i=1; i<num1; i++){
                result1 = result1 * (num1-i);
            }
            printf("Answer: %lf\n", result1);
        }else if(symbol == 'p' || symbol == 'c'){
            printf("Enter the first number: ");
            scanf("%d", &num1);
            printf("and the second number: ");
            scanf("%d", &num2);
            if(num2>num1){
                printf("Your second number shouldn't be greater than the first!");
            }else{
                switch(symbol){
                    case 'p':
                        result1 = num1;
                        for(int i=1; i<num2; i++){
                            result1 = result1 * (num1-i);
                        }
                        printf("Answer: %lf\n", result1);
                        break;
                    case 'c':
                        if(num2 >= (num1-num2)) n=num1-num2;
                        else n=num2;
                        double num = n;
                        result1 = num1;
                        for(int i=1; i<n; i++){
                            result1 = result1 * (num1-i);
                            num = num * (n-i);
                        }
                        result1 = result1/num;
                        printf("Answer: %lf\n", result1);
                        break;
                    default:
                        printf("Check your inputs.\n");
                        break;
                }
            }
        }else if(symbol != ('!' || 'p' || 'c')){
            printf("Please enter the correct symbol, p/c in small letters.");
        }
    }

    return 0;
}
