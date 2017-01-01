
#include "matrix.h"

int main(){
	matrix<unsigned int> mtrx(6, 6);
	matrix<unsigned int> mtrxB(5, 5);
	mtrx.mtrx[2][3]=5;
	mtrx.mtrx[1][2]=1;
	mtrxB.mtrx[1][2]=5;
	mtrx.mergeDelete(mtrxB);
	mtrx.printMatrix();
	mtrx.fullDelete();
	mtrx.printMatrix();

	return 0;
}
