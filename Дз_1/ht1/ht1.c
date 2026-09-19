#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int MIN_N = 2, MIN_M = 2, MAX_N = 10, MAX_M = 10;
    int n, m, match, find = 0;
    int pattern[2][2];
    srand(time(NULL));
    n = MIN_N + rand() % (MAX_N - MIN_N + 1);
    m = MIN_N + rand() % (MAX_M - MIN_M + 1);
    
    //* создание и заполнение основной карты
    int **map = malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
        map[i] = malloc(n * sizeof(int));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            map[i][j] = rand() % 2; //* max - min + 1

    //* заполнение паттерна
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            pattern[i][j] = rand() % 2;
    
    printf("Map:\n");  
    for (int i = 0; i < m; i++)
    {       
        for (int j = 0; j < n; j++)
            printf("%3d", map[i][j]);
        printf("\n");
    }

    printf("Pattern:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            printf("%3d", pattern[i][j]);
        printf("\n");
    }

    for (int i = 0; i < m-1; i++)
        for (int j = 0; j < n-1; j++)
        {
            match = 0;
            if(map[i][j] == pattern[0][0]) match +=1;
            if(map[i][j+1] == pattern[0][1]) match +=1;
            if(map[i+1][j] == pattern[1][0]) match +=1;
            if(map[i+1][j+1] == pattern[1][1]) match +=1;
            if (match == 4) {
                if (!find) find = 1;
                map[i][j] = 2;
                map[i][j+1] =2;
                map[i+1][j] = 2;
                map[i+1][j+1] = 2;
            }
        }
    
    if (find)
    {    
        printf("New map:\n"); 
        for (int i = 0; i < m; i++)
        {       
            for (int j = 0; j < n; j++)
                printf("%3d", map[i][j]);
            printf("\n");
        }
    }
    else printf("Not found");

    for (int i = 0; i < n; i++)
        free(map[i]);
    free(map);

    return 0;
}