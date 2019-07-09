#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int *M1;
int *M2;
int *M3;

#define POSITION(x, y) (x * 200000 + y)

int main(int argc, char** argv) {

    M1 = (int*) malloc(200001 * 200001 * sizeof(int));
    M2 = (int*) malloc(200001 * 200001 * sizeof(int));
    M3 = (int*) malloc(200001 * 200001 * sizeof(int));

    M1[POSITION(3, 3)] = 2;
    M2[POSITION(4, 4)] = 3;
    M3[POSITION(5, 5)] = 4;

    printf("%d\n", M1[POSITION(3, 3)]);
    printf("%d\n", M2[POSITION(4, 4)]);
    printf("%d\n", M3[POSITION(5, 5)]);

    free(M1);
    free(M2);
    free(M3);

    return (EXIT_SUCCESS);
}