#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */



/*
====================
TrianguloPascal
 Recebe uma quantidade de linhas X e retorna um ponteiro pra um ponteiro, assim formando um triangulo de pascal de tamanho X.
====================
*/

int** TrianguloPascal( int numRows, int* returnSize, int** returnColumnSizes ) {
    *returnSize = numRows;
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));
    
    if (*returnColumnSizes == NULL) {
        return NULL;
    }

    int** resultadoTriangulo = (int**)malloc(numRows * sizeof(int*));
    if (resultadoTriangulo == NULL) {
        free(*returnColumnSizes);
        return NULL;
    }

    int* vetor = (int*)malloc(sizeof(int) * numRows * (numRows + 1) / 2);
    if ( vetor == NULL ) {
        free(*returnColumnSizes);
        free(resultadoTriangulo);
        return NULL;
    }

    int k = 0;

    for (int i = 0; i < numRows; i++) {
        (*returnColumnSizes)[i] = i + 1;
        resultadoTriangulo[i] = &vetor[k];

        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                vetor[k] = 1;
            } else {
                vetor[k] = vetor[k - i] + vetor[k - i - 1];
            }
            k++;
        }
    }

    return resultadoTriangulo;
}

int main() {
    int numRows = 1;
    int* returnColumnSizes;
    int returnSize;

    int** resultadoTriangulo = TrianguloPascal(numRows, &returnSize, &returnColumnSizes);
    if ( resultadoTriangulo == NULL ) {
        return EXIT_FAILURE;
    }

    int i = 0;
    while  ( i < returnSize ) {
        printf("LINHA %d:", returnColumnSizes[i]);
        printf("[");
        int j = 0;
       while  ( j < returnColumnSizes[i] ) {
            printf("%d", resultadoTriangulo[i][j]);
            if ( j < returnColumnSizes[i] - 1 ) {
                printf(",");
            }
            j++;
        }
        printf("]");
        printf("\n");
        i++;
    }


    free(resultadoTriangulo);
    free(returnColumnSizes);

    return 0;
}
