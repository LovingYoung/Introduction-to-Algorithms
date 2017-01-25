#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

class SquareMatrix{
    private:
        int * values;
        int rows;
        int cols;
    public:
        SquareMatrix(int n, int * list = NULL){
            values = (int*) malloc (sizeof(int) * n * n);
            rows = n;
            cols = n;
            if(list != NULL){
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        values[i*n+j] = list[i*n+j];
                    }
                }
            }
        }

        int getValue(int row, int col){
            row = row - 1;
            col = col - 1;
            return values[row * cols + col];
        }

        void setValue(int row, int col, int key){
            if(row <= rows && col <= cols){
                row = row - 1;
                col = col - 1;
                values[row * cols + col] = key;
            } else {
                throw range_error("Rows & Cols are out of range in this matrix");
            }
        }

        int getRows(){
            return this->rows;
        }

        int getCols(){
            return this->cols;
        }
};
ostream& operator<<(ostream &strm, SquareMatrix &a) {
    for(int i = 0; i < a.getRows(); i++){
        for(int j = 0; j < a.getCols(); j++)
            strm << a.getValue(i+1, j+1) << ' ';
        cout << endl;
    }
    return strm;
}

SquareMatrix& squareMatrixMultiplication(SquareMatrix& mat1, SquareMatrix& mat2){
    int rows = mat1.getRows();
    SquareMatrix* result = new SquareMatrix(rows);
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < rows; j++){
            int cell = 0;
            for(int k = 0; k < rows; k++){
                cell += mat1.getValue(i+1, k+1) * mat2.getValue(k+1, j+1);
            }
            result->setValue(i+1, j+1, cell);
        }
    }
    return *result;
}

int main(){
    int list1[9] = {1,2,3,4,5,6,7,8,9};
    int list2[9] = {11,22,33,44,55,66,77,88,99};
    SquareMatrix * mat1 = new SquareMatrix(3, (int*)&list1);
    SquareMatrix * mat2 = new SquareMatrix(3, (int*)&list2);
    SquareMatrix& mat3 = squareMatrixMultiplication(*mat1, *mat2);
    cout << mat3 << endl;
}
