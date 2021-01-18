#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct map MAP;

struct map{
    char **tobogganMap;
    int height;
    int width;
};

MAP *readFile(char *fileName){
    FILE *arq = fopen(fileName, "r");
    char *line = (char *)calloc(50, sizeof(char));
    MAP *map = NULL;
    map = (MAP *)calloc(1, sizeof(MAP));

    while(fgets(line, 50, arq) != NULL){
        line[strlen(line) - 1] = '\0';
        map->tobogganMap = (char **)realloc(map->tobogganMap, ++map->height * sizeof(char *));
        map->tobogganMap[map->height - 1] = line;
        line = NULL;
        line = (char *)calloc(50, sizeof(char));
    }

    map->width = strlen(map->tobogganMap[0]);
    free(line);
    fclose(arq);

    return map;
}

int checkTree(MAP *map){
    int qtTrees = 0;
    int j = 0;

    for(int i = 0; i < map->height; i++){
        if(map->tobogganMap[i][j] == '#'){
            qtTrees++;
        }
        j = (j + 3) % map->width;
    }

    return qtTrees;
}

int main(){
    char fileName[50];
    scanf("%s", fileName);

    MAP *map = NULL;
    map = readFile(fileName);

    printf("A quantidade de árvores encontradas foi: %d\n", checkTree(map));








    return 0;
}