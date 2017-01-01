
#ifndef MATRIX_H
#define MATRIX_H

#include <cstdlib>
#include <cstdio>

template<typename T>
class matrix{
public:
	T** mtrx;
private:
	int size;
	int rows;
	int cols;
public:
	matrix();
	matrix(int numRows, int numCols);
	~matrix();
	void calculateSize();
	void setRows(int numRows);
	void setCols(int numCols);
	bool resize(int numRows, int numCols);
	void fullDelete();
	void semiDelete();
	void set(int r, int c, T val);
	bool setSafe(int r, int c, T val);
	bool merge(matrix<T> aMtrx);
	bool mergeSafe(matrix<T> aMtrx);
	bool mergeSafeDelete(matrix<T> aMtrx);
	bool mergeDelete(matrix<T> aMtrx);
	bool sizeCheck(matrix<T> aMtrx);
	void printRow(int n);
	void printMatrix();
	int getCols();
	int getRows();
	int getSize();
};

template<typename T>
matrix<T>::matrix(){
	size=0;
	rows=0;
	cols=0;
}

template<typename T>
matrix<T>::~matrix(){
	fullDelete();
}

template<typename T>
void matrix<T>::semiDelete(){
	if(mtrx){
		free(mtrx);
		mtrx=NULL;
		size=0;
		rows=0;
		cols=0;
	}
}

template<typename T>
void matrix<T>::fullDelete(){
	if(mtrx){
		for(int i=0; i<rows; i++){
			free(mtrx[i]);
		}
		free(mtrx);
		mtrx=NULL;
		size=0;
		rows=0;
		cols=0;
	}
}

template<typename T>
void matrix<T>::printRow(int n){
	if(mtrx&&n<rows){
		for(int i=0; i<cols; i++){
			printf("%d ", mtrx[n][i]);
		}
	}

	printf("\nSize of row: %d\n", cols);
}

template<typename T>
void matrix<T>::printMatrix(){
	if(mtrx){
		for(int i=0; i<rows; i++){
			for(int j=0; j<cols; j++){
				printf("%d ", mtrx[i][j]);
			}
			puts("");
		}
	}

	printf("Matrix size: %d\n", size);
}

template<typename T>
matrix<T>::matrix(int numRows, int numCols){
	cols=numCols;
	rows=numRows;
	size=cols*rows;

	if(size){
		mtrx=(T**)malloc(sizeof(T*)*rows);

		if(mtrx){
			for(int i=0; i<rows; i++){
				mtrx[i]=(T*)calloc(cols, sizeof(T));
			}
		}
	}
}

template<typename T>
void matrix<T>::calculateSize(){
	size=cols*rows;
}

template<typename T>
void matrix<T>::setCols(int numCols){
	cols=numCols;
}

template<typename T>
void matrix<T>::setRows(int numRows){
	rows=numRows;
}

template<typename T>
void matrix<T>::set(int r, int c, T val){
	mtrx[r][c]=val;
}

template<typename T>
bool matrix<T>::setSafe(int r, int c, T val){
	if(r>=rows&&c>=cols)
		return false;

	mtrx[r][c]=val;
	return true;
}

template<typename T>
bool matrix<T>::resize(int numRows, int numCols){
	if((numRows-rows)<0||(numCols-cols)<0)
		return false;

	mtrx=(T**)realloc(mtrx, numRows*sizeof(T*));
	if(!mtrx)
		return false;

	if(numCols!=cols){
		for(int i=0; i<rows; i++){
			mtrx[i]=(T*)realloc(mtrx[i], sizeof(T)*numCols);
			for(int j=numCols-1; j>=cols; j--){
				mtrx[i][j]=0;
			}
		}
	}
	for(; rows<numRows; rows++){
		mtrx[rows]=(T*)calloc(numCols, sizeof(T));
	}

	cols=numCols;
	calculateSize();
	return true;
}

template<typename T>
bool matrix<T>::sizeCheck(matrix<T> aMtrx){
	int numCols=abs(aMtrx.getCols()-cols);
	int numRows=abs(aMtrx.getRows()-rows);

	if(numCols||numRows&&!(aMtrx.resize(numRows, numCols)&&resize(numRows, numCols)))
		return false;

	return true;
}

template<typename T>
bool matrix<T>::merge(matrix<T> aMtrx){
	int numRows=aMtrx.getRows();
	int numCols=aMtrx.getCols();

	if(numCols>cols){
		if(!resize(numRows, numCols))
			return false;
	}else if(numCols<cols){
		if(!aMtrx.resize(rows, cols))
			return false;
	}

	mtrx=(T**)realloc(mtrx, sizeof(T*)*(numRows+rows));
	if(!mtrx)
		return false;

	size+=aMtrx.getSize();
	for(int i=0; i<numRows; i++){
		mtrx[rows++]=aMtrx.mtrx[i];
	}

	return true;
}

template<typename T>
bool matrix<T>::mergeSafe(matrix<T> aMtrx){
	int numRows=aMtrx.getRows();
	int numCols=aMtrx.getCols();

	if(numCols>cols){
		if(!resize(numRows, numCols))
			return false;
	}else if(numCols<cols){
		if(!aMtrx.resize(rows, cols))
			return false;
	}

	mtrx=(T**)realloc(mtrx, sizeof(T*)*(numRows+rows));
	if(!mtrx)
		return false;

	size+=aMtrx.getSize();
	for(int i=0; i<numRows; i++){
		for(int j=0; j<cols; j++){
			mtrx[rows++][j]=aMtrx.mtrx[i][j];
		}
	}

	return true;
}

template<typename T>
bool matrix<T>::mergeSafeDelete(matrix<T> aMtrx){
	int numRows=aMtrx.getRows();
	int numCols=aMtrx.getCols();

	if(numCols>cols){
		if(!resize(numRows, numCols))
			return false;
	}else if(numCols<cols){
		if(!aMtrx.resize(rows, cols))
			return false;
	}

	mtrx=(T**)realloc(mtrx, sizeof(T*)*(numRows+rows));
	if(!mtrx)
		return false;

	size+=aMtrx.getSize();
	for(int i=0; i<numRows; i++){
		for(int j=0; j<cols; j++){
			mtrx[rows++][j]=aMtrx.mtrx[i][j];
		}
	}

	aMtrx.fullDelete();
	return true;
}

template<typename T>
bool matrix<T>::mergeDelete(matrix<T> aMtrx){
	int numRows=aMtrx.getRows();
	int numCols=aMtrx.getCols();

	if(numCols>cols){
		if(!resize(numRows, numCols))
			return false;
	}else if(numCols<cols){
		if(!aMtrx.resize(rows, cols))
			return false;
	}

	mtrx=(T**)realloc(mtrx, sizeof(T*)*(numRows+rows));
	if(!mtrx)
		return false;

	size+=aMtrx.getSize();
	for(int i=0; i<numRows; i++){
		mtrx[rows++]=aMtrx.mtrx[i];
	}

	aMtrx.semiDelete();
	return true;
}

template<typename T>
int matrix<T>::getCols(){
	return cols;
}

template<typename T>
int matrix<T>::getRows(){
	return rows;
}

template<typename T>
int matrix<T>::getSize(){
	return size;
}

#endif
