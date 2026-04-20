#include <stdio.h>
#include <stdlib.h>

#include "sparseMatrix.h"

int main() {
  
    sparseMatrix* sm1 = createSparseMatrix(10, 10);

    for (int i = 1; i < 21; i++) {
        addElementSparseMatrix(sm1, 0, i, 1);
    }//테스트

    printf("original:\n");
    printSparseMatrix(sm1);

    int moveCount = 0;
    sparseMatrix* smTransposed = transposeSparseMatrix(sm1, &moveCount);

    printf("\nafter transpose:\n");
    printSparseMatrix(smTransposed);//정상작동 확인

    // 데이터 이동 횟수 출력
    printf("data move: %d\n", moveCount);


    return 0;
    
}