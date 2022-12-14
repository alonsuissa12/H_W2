//
// Created by alon on 11/23/22.
//
#include <stdio.h>
#include "my_mat.h"
#ifndef ARRAY_LENGTH_AND_WIDTH
#define ARRAY_LENGTH_AND_WIDTH 10
#endif
int main(){
    char flag = 's';
    int i, j;
    int m[ARRAY_LENGTH_AND_WIDTH][ARRAY_LENGTH_AND_WIDTH] = {0};
    int copy[ARRAY_LENGTH_AND_WIDTH][ARRAY_LENGTH_AND_WIDTH] = {0};
    while (flag != 'D') {
        scanf("%c", &flag);
        if (flag == 'A') {
            scanMatrix(m);
        }
        if (flag == 'B') {
            for (int k = 0; k < ARRAY_LENGTH_AND_WIDTH; k++) {
                for (int t = 0; t < ARRAY_LENGTH_AND_WIDTH; t++) {
                    copy[k][t] = m[k][t];
                }
            }
            scanf("%d%d", &i, &j);
            if(i == j){
                printf("False\n");
            }
            else {
                int exist = pathExistence(copy, i, j);
                if (exist == 1) {
                    printf("True\n");
                } else {
                    printf("False\n");
                }
            }
        }
        if (flag == 'C') {
            scanf("%d%d", &i, &j);
            if (i == j) {
                printf("%d\n", -1);
            }
            else
            {
                for (int k = 0; k < ARRAY_LENGTH_AND_WIDTH; k++) {
                    for (int t = 0; t < ARRAY_LENGTH_AND_WIDTH; t++) {
                        copy[k][t] = m[k][t];
                    }
                }
                int exist = pathExistence(copy, i, j);
                if (exist == 0) {
                    printf("%d\n", -1);
                }
                else {
                    int visited[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                    int pathLength[] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
                    pathLength[i] = 0;
                    shortestPath(i, j, m, 1, visited, pathLength);
                    printf("%d\n", pathLength[j]);
                }
            }
        }

    }

    return 0;
}
