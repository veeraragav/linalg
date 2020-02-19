#include "matrix.h"

int main(){


    //Transpose example

    //scalar Matrix multiplication example

    //Matrix matrix multiplication example
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    linalg::matrix<int> mat(3,3, a);
    mat.print();

    linalg::matrix<int> mat2(3,3) ;
  
    int b[] = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    linalg::matrix<int> mat3(3,3, b);
    mat3.print();

    mat2 = mat * mat3;
    mat2.print();

}