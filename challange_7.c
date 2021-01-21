#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pass PASS;

struct pass{
    char **matrix;
    int qtPass;
};

PASS *readFile(char *fileName){
    FILE *arq = fopen(fileName, "r");
    char *line = (char *)calloc(200, sizeof(char));
    PASS *pass = (PASS *)calloc(1, sizeof(PASS));

    while (fgets(line, 200, arq) ){
        pass->matrix = (char **)realloc(pass->matrix, ++pass->qtPass * sizeof(char *));
        pass->matrix[pass->qtPass - 1] = line;
        line = NULL;
        line = (char *)calloc(200, sizeof(char));
    }

    return pass;
}

int main(){
    char fileName[50];
    scanf("%s", fileName);
    PASS *pass = NULL;

    pass = readFile(fileName);

    int notSpace = 0;
    int corrects = 0;
    int goodOnes = 0;

    int i = 0;

    for (i = 0; i < pass->qtPass; i++){
        if(strlen(pass->matrix[i]) > 1){
            notSpace++;
        }
        else{
            for(int j = 0; j < notSpace; j++){
                if(strstr(pass->matrix[i - notSpace + j], "byr")){
                    goodOnes++;

                }
                if(strstr(pass->matrix[i - notSpace + j], "iyr")){
                    goodOnes++;

                }
                if(strstr(pass->matrix[i - notSpace + j], "eyr")){
                    goodOnes++;

                }
                if(strstr(pass->matrix[i - notSpace + j], "hgt")){
                    goodOnes++;

                }
                if(strstr(pass->matrix[i - notSpace + j], "hcl")){
                    goodOnes++;

                }
                if(strstr(pass->matrix[i - notSpace + j], "ecl")){
                    goodOnes++;
                
                }
                if(strstr(pass->matrix[i - notSpace + j], "pid")){
                    goodOnes++;
                }
                

            }
            if(goodOnes == 7){
                corrects++;
            }

            goodOnes = 0;
            notSpace = 0;
        }

    }

    printf("Quantidade de pssaportes corretos: %d\n", corrects + 1);


}