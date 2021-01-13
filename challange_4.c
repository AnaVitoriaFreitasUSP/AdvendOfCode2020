#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct appear APPEAR;

struct appear{
    int firstOcourrency;
    int lastOcourrency;
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

int extractfirstOcourrency(char *line){
    return atoi(extractField(line, 0, findHifen(line)));
}

int findSpace(char *line){
    for(int i = 0; i < strlen(line); i++){
        if(line[i] == ' '){
            return i;
        }
    }
}

int extractlastOcourrency(char *line){
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
        appear[qtPass - 1].firstOcourrency = extractfirstOcourrency(line);
        appear[qtPass - 1].lastOcourrency = extractlastOcourrency(line);
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

    int according = 0;
    for(int i = 0; i < appear->qtPasswords - 1; i++){

        if(appear[i].password[-1 + appear[i].firstOcourrency] == appear[i].letter[0] && appear[i].password[-1 + appear[i].lastOcourrency] != appear[i].letter[0] || appear[i].password[-1 + appear[i].firstOcourrency] != appear[i].letter[0] && appear[i].password[-1 + appear[i].lastOcourrency] == appear[i].letter[0]){
            according++;
        }   


    }

    printf("A quantidade de senhas de acordo com a nova politica estabelecida é: %d\n", according);

}