#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpStrings(char* word1, char* word2){
    char alphaOrder[] = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
    int maxLenght, cmpFactor = 0, i = 0;
    if(strlen(word1)>strlen(word2)) maxLenght = strlen(word2);
    else maxLenght = strlen(word1);
    while(i<maxLenght){
        char alpha1 = word1[i];
        char alpha2 = word2[i];
        if(alpha1 == alpha2){
            i++;
            continue;
        }
        for(int i=0; i<52; i++){
            if(alpha1 == alphaOrder[i]){
                cmpFactor = -1;
                break;
            }else if(alpha2 == alphaOrder[i]){
                cmpFactor = 1;
                break;
            }
        }
        break;
    }
    if(cmpFactor==0 && (strlen(word1)>strlen(word2))) cmpFactor = 1;
    else if(cmpFactor==0 && (strlen(word1)<strlen(word2))) cmpFactor = -1;
    return cmpFactor;
}

int main()
{
    char toBeSorted[500][50];
    printf("Provide the words to be sorted.\nNote: At most only 500 words can be sorted at a go. Hit 'enter' after each!\n");
    printf("Or enter 'x' to stop adding words and sort the one's already provided.\n");

    int added;
    for(added = 0; added<500; added++){
        char word[50];
        scanf("%s", word);
        if(!strcmp(word, "x")) break;
        strcpy(toBeSorted[added], word);
    }

    for(int i=0; i<added; i++){
        for(int y=i+1; y<added; y++){
            int position = cmpStrings(toBeSorted[i], toBeSorted[y]);
            if(position>0){
                char bigWord[50];
                strcpy(bigWord, toBeSorted[i]);
                strcpy(toBeSorted[i], toBeSorted[y]);
                strcpy(toBeSorted[y], bigWord);
            }
        }
    }

    printf("Here are the words you just added in an ascending order: ");
    for(int i=0; i<added-1; i++){
        printf("%s, ", toBeSorted[i]);
    }
    printf("%s\n", toBeSorted[added-1]);

    return 0;
}
