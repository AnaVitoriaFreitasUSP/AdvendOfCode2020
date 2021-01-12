#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct appear APPEAR;

struct appear{
    int min;
    int max;
    char *letter;
    char *password;
    int qtPasswords;
};

char *extractField(char *string, int foundPos, int stringSize) {
	char *subString = (char*)malloc(sizeof(char) * (stringSize + 1));
	
	memcpy(subString, &string[foundPos], stringSize);
	subString[stringSize] = '\0';

	return subString;
}

int findHifen(char *line){
    int posFound = 0;

    for(int i = 0; i < strlen(line); i++){
        if(line[i] == '-'){
            posFound = i;
        }
    }

    return posFound;
}

int extractMin(char *line){
    return atoi(extractField(line, 0, findHifen(line)));
}

int findSpace(char *line){
    for(int i = 0; i < strlen(line); i++){
        if(line[i] == ' '){
            return i;
        }
    }
}

int extractMax(char *line){
    return atoi(extractField(line, findHifen(line) + 1, findSpace(line) - 1));
}

char *extractLetter(char *line){
    return extractField(line, findSpace(line) + 1, 1);
}

int findTwoDots(char *line){
    for(int i = 0; i < strlen(line); i++){
        if(line[i] == ':'){
            return i;
        }
    }
}

char *extractPassword(char *line){
    return extractField(line, findTwoDots(line) + 2, strlen(line) - findTwoDots(line) - 1);
}

APPEAR *readFile(char *fileName){
    FILE *arq = fopen(fileName, "r");
    char line[70];
    APPEAR *appear = NULL;
    int qtPass = 0;


    while(fgets(line, 70, arq) != NULL){
        line[strlen(line) - 1] = '\0';
        appear = (APPEAR *)realloc(appear, ++qtPass * sizeof(APPEAR));
        appear[qtPass - 1].min = extractMin(line);
        appear[qtPass - 1].max = extractMax(line);
        appear[qtPass - 1].letter = extractLetter(line);
        appear[qtPass - 1].password = extractPassword(line);
    }

    fclose(arq);
    appear->qtPasswords = qtPass;
    return appear;


}


int main(){

    APPEAR *appear = NULL;
    char fileName[50];

    scanf("%s", fileName);

    appear = readFile(fileName);

    int equalOnes = 0;
    int according = 0;
    for(int i = 0; i < appear->qtPasswords; i++){
        for(int j = 0 ; j < strlen(appear[i].password); j++){
            if(appear[i].letter[0] == appear[i].password[j]){
                equalOnes++;
            }
        }
        if(equalOnes <= appear[i].max && equalOnes >= appear[i].min){
            printf("MIN: %d MAX: %d LETRA: %c SENHA: %s\n", appear[i].min, appear[i].max, appear[i].letter[0], appear[i].password);
            according++;
        }
        equalOnes = 0;
    }

    printf("A quantidade de senhas de acordo com a politica estabelecida é: %d\n", according);

    return 0;
}