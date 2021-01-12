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
            if(numbers[i] + numbers[j] == 2020){
                printf("Os dois números são: %d e %d\n", numbers[i], numbers[j]);
                printf("A multiplicação dos dois dá: %d\n", numbers[i] * numbers[j]);
            }
        }
    }

    return 0;

}