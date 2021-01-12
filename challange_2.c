#include <stdio.h>
#include <stdlib.h>

typedef struct numbers NUMBERS;

struct numbers{
    int *numbers;
    int qtNumbers;
};

NUMBERS *recieveNumbers(char *fileName){
    FILE *arq = fopen(fileName, "r");
    NUMBERS *listOfNumbers = NULL;
    listOfNumbers = (NUMBERS *)calloc(1, sizeof(NUMBERS));
    listOfNumbers->qtNumbers = 0;
    char line[7];


    while(fgets(line, 6, arq) != NULL){
        listOfNumbers->numbers = (int *)realloc(listOfNumbers->numbers, ++listOfNumbers->qtNumbers * sizeof(int));
        listOfNumbers->numbers[listOfNumbers->qtNumbers - 1] = atoi(line);
    }

    fclose(arq);


    return listOfNumbers;

}


int main(){

    char fileName[50];
    NUMBERS *listOfNumbers = NULL;
    int* numbers = NULL;

    scanf("%s", fileName);

    listOfNumbers = recieveNumbers(fileName);

    numbers = listOfNumbers->numbers;


    for(int i = 0; i < listOfNumbers->qtNumbers; i++){
        for(int j = i + 1; j < listOfNumbers->qtNumbers; j++){
            for(int k = j + 1; k < listOfNumbers->qtNumbers; k++){
                if(numbers[i] + numbers[j] + numbers[k] == 2020){
                    printf("Os três números são: %d %d %d\n", numbers[i], numbers[j], numbers[k]);
                    printf("A multiplicação dos três dá: %d\n", numbers[i] * numbers[j] * numbers[k]);
                }
            }
        }
    }


    return 0;

}