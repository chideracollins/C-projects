#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* getMode(){
    char mode[2];
    printf("File modes;\n");
    printf("'w'- this will open up file in the write mode and will overwrite any already existing content. Also will create file if not already in existence.\n");
    printf("'a'- use this to append to an already existing file only.\n");
    printf("'r'- use this to read from an already existing file.\n");
    printf("Please choose the mode to open file on: ");
    scanf(" %s", &mode);
    if(!strcmp(mode, "w")) return "w";
    else if(!strcmp(mode, "r")) return "r";
    else if(!strcmp(mode, "a")) return "a";
    printf("Invalid mode, program has been terminated!");
    return "x";
}

int editFile(char filePath[300], char mode[2]){
    FILE *myFile = fopen(filePath, mode);
    char line[51];
    int sit = 1;

    if(!strcmp(mode, "r")){
        while(sit == 1){
            int start, limit;
            printf("File has been opened in read mode\n");
            printf("Please provide the lines you want read, eg; 0 3\nie; 0 standing for the first line, 3 as the number of lines to be read from the initial.)\nIndexing starts from 0.\n");
            scanf("%d %d", &start, &limit);
            for(int i=0; i<(start+limit); i++){
                fgets(line, 50, myFile);
            }
            for(int i=0; i<limit; i++){
                fgets(line, 50, myFile);
                printf("%s\n", line);
            }
            printf("Choose your next action to continue?\n'1' to continue on the read mode\n'0' to change mode\nAnd any other number to terminate program?\n");
            scanf("%d", &sit);
        }
    }
    else{
        char txt[9];
        if(!strcmp(mode, "w")) strcpy(txt, "Writing");
        else strcpy(txt, "Append");
        printf("%s mode, is on!\nRules;\n", txt);
        printf("you can write to the file, line by line only.\n");
        printf("Each line must not be more than 50 characters each, including spaces.\n");
        printf("Use '\\t' to tab, '\\#' to type in #, '\\n'to move to next line, and '#' to seek for options.\n");
        while(int i=0; i != sit; ){
            gets(line);
            /*fgets(line, 50, stdin);*/
            fprintf(myFile, line);
            printf("Choose your next action to continue?\n'1' to continue on the %s mode\n'0' to change mode\nAnd any other number to terminate program?\n", txt);
            scanf("%d", sit);
        }
    }

    fclose(myFile);

    if(sit) return 0;
    return 1;
}

int main()
{
    printf("Welcome here!\nFrom your command prompt, you can create and edit any text file (.txt) in any folder of your choice within your computer.\n");

    char path[200];
    char name[100];
    printf("Please provide the file path or enter 'c' to remain in the current folder: ");
    scanf("%s", path);
    if(!strcmp(path, "c")) strcpy(path, "");

    printf("Please provide the file name with it's extension(.txt): ");
    scanf("%s", name);

    int i;
    for(i=0; path[i] != NULL; i++);
    if(path[i-1] != '\\' && i != 0) strcat(path, "\\");

    char filePath[300];
    strcpy(filePath, path);
    strcat(filePath, name);

    int inProgress = 1;
    while(inProgress){
        char mode[2];
        strcpy(mode, getMode());
        if(!strcmp(mode, "x")) break;
        inProgress = editFile(filePath, mode);
    }
    printf("Program terminated!");

    return 0;
}







