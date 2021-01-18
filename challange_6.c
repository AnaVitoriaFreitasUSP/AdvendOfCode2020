#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct map MAP;

struct map
{
    char **tobogganMap;
    int height;
    int width;
};

MAP *readFile(char *fileName)
{
    FILE *arq = fopen(fileName, "r");
    char *line = (char *)calloc(50, sizeof(char));
    MAP *map = NULL;
    map = (MAP *)calloc(1, sizeof(MAP));

    while (fgets(line, 50, arq) != NULL)
    {
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

typedef struct tree TREE;

struct tree
{
    int first;
    int second;
    int third;
    int fourth;
    int fiveth;
};

TREE *slopes(MAP *map){
    int j = 0;
    TREE *tree = (TREE *)calloc(1, sizeof(TREE));

    for (int i = 0; i < map->height; i++){
        if (map->tobogganMap[i][j] == '#'){
            tree->first++;
        }
        j = (j + 1) % map->width;
    }

    j = 0;

    for (int i = 0; i < map->height; i++){
        if (map->tobogganMap[i][j] == '#'){
            tree->second++;
        }
        j = (j + 3) % map->width;
    }

    j = 0;

    for (int i = 0; i < map->height; i++){
        if (map->tobogganMap[i][j] == '#'){
            tree->third++;
        }
        j = (j + 5) % map->width;
    }

    j = 0;

    for (int i = 0; i < map->height; i++){
        if (map->tobogganMap[i][j] == '#'){
            tree->fourth++;
        }
        j = (j + 7) % map->width;
    }

    j = 0;

    for (int i = 0; i < map->height; i += 2){
        if (map->tobogganMap[i][j] == '#'){
            tree->fiveth++;
        }
        j = (j + 1) % map->width;
    }

    return tree;


}

int main(){
    char fileName[50];
    MAP *map = NULL;
    TREE *tree = NULL;


    scanf("%s", fileName);

    map = readFile(fileName);
    tree = slopes(map);

    printf("Primeiro slope: %d\n", tree->first);
    printf("Segundo slope: %d\n", tree->second);
    printf("Terceiro slope: %d\n", tree->third);
    printf("Quarto slope: %d\n", tree->fourth);
    printf("Quinto slope: %d\n", tree->fiveth);

    return 0;
}
