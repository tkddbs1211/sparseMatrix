#include <stdio.h>
#include <stdlib.h>

#include "sparseMatrix.h"

sparseMatrix* createSparseMatrix(int row, int col) {
	return createArrayList(row * col);
}

int addElementSparseMatrix(sparseMatrix* sm, int row, int col, int value) {
	int size;
	size = sizeArrayList(sm);

	insertArrayList(sm, size,
		(elementArrayList) {
		row, col, value
	});
}

int printSparseMatrix(sparseMatrix* sm) {
	printArrayList(sm);
}

sparseMatrix* addSparseMatrix(sparseMatrix* sm1, sparseMatrix* sm2) {
	sparseMatrix* smResult = createArrayList(100);

	for (int i = 0; i < sizeArrayList(sm1); i++) { //오류수정 i<=sizeArrayList(sm1) <=을 <로 수정했습니다.
		elementArrayList nonZeroOfSM1
			= getItemArrayList(sm1, i);

		int j;
		for (j = 0; j < sizeArrayList(sm2); j++) {//오류수정 j<=sizeArrayList(sm2) <=을 <fh 수정했습니다.
			elementArrayList nonZeroOfSM2
				= getItemArrayList(sm2, j);

			if (nonZeroOfSM1.col == nonZeroOfSM2.col &&
				nonZeroOfSM1.row == nonZeroOfSM2.row) {
				insertArrayList(smResult, sizeArrayList(smResult), (elementArrayList) {
						nonZeroOfSM1.row,
						nonZeroOfSM1.col,
						nonZeroOfSM1.value + nonZeroOfSM2.value
				});

				break;
			}
		}

		if (j == sizeArrayList(sm2)) {
			insertArrayList(smResult, sizeArrayList(smResult),
				nonZeroOfSM1);
		}
	}

	return smResult;
}

sparseMatrix* transposeSparseMatrix(sparseMatrix* sm, int* moveCount) {
	sparseMatrix* smResult = createSparseMatrix(10, 10);
	int size = sizeArrayList(sm);
	*moveCount = 0;

	for (int i = 0; i < size; i++) {
		elementArrayList item = getItemArrayList(sm, i);

		elementArrayList transposedItem;
		transposedItem.row = item.col; 
		transposedItem.col = item.row;
		transposedItem.value = item.value;

		insertArrayList(smResult, sizeArrayList(smResult), transposedItem);

		(*moveCount)++;
	}

	return smResult;
}