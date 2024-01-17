#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIRST20_LENGHT 20
#define TENS_LENGHT 20
#define OTHERS_LENGHT 20

int findInt(double num, double range){
    if(num<20) return num;
    return floor(num/range);
}

double findRange(double num, char *whichOne){
    double range = 1.0;
    int times;
    if(num == 0) return 0;
    for(int i=1; i<9; i++){
        double check = floor(num/range);
        if(check<10){
            times = i;
            break;
        }
        else if(range>=1000){
            if(check<1000){
                times = i;
                break;
            }
            range *=100.0;
        }
        range *=10.0;
    }
    if(whichOne == "range") return range;
    else if(whichOne == "times") return times;
}

int main()
{
    char *first20[FIRST20_LENGHT] = {"One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                    "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"
                };
    char *tens[TENS_LENGHT] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    char *others[OTHERS_LENGHT] = {"Thousand", "Million", "Billion", "Trillion", "Quadrillion"};

    double number;
    printf("Enter the number to print it in words: ");
    scanf("%lf", &number);

    if(number == 0) printf("Zero");
    int times = findRange(number, "times");
    while(times > 0){
        double range = findRange(number, "range");
        int num = findInt(number, range);
        double numExtract = num;
        if(number>19) numExtract = num*range;
        number -= numExtract;
        if(times>3){
            int times3 = times;
            int num3 = numExtract / range;
            while(times>0){
                range = findRange(num3, "range");
                num = findInt(num3, range);
                numExtract = num;
                if(num3>19) numExtract = num*range;
                num3 -= numExtract;
                if(numExtract<20) printf("%s",first20[num-1]);
                else if(numExtract>19 && numExtract<100){
                    printf("%s", tens[num-2]);
                    if(num3>0) printf("-");
                }else if(numExtract>99){
                    printf("%s Hundred", first20[num-1]);
                    if(num3>0) printf(" and ");
                }
                times = findRange(num3, "times");
            }
            printf(" %s ", others[times3-4]);
            times = findRange(number, "times");
            continue;
        }
        else if(numExtract<20) printf("%s",first20[num-1]);
        else if(numExtract>19 && numExtract<100){
            printf("%s", tens[num-2]);
            if(number>0) printf("-");
        }else if(numExtract>99){
            printf("%s Hundred", first20[num-1]);
            if(number>0) printf(" and ");
        }
        times = findRange(number, "times");
    }

    return 0;
}








