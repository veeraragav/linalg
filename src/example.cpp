#include "matrix.h"

int main(){

    //Matrix Instantiation
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    linalg::matrix<int> matrix1(3,3, a);

    int b[] = {3, 0, 0, 0, 3, 0, 0, 0, 3};
    linalg::matrix<int> matrix2(3,3, b);

    linalg::matrix<int> matrix3(3,3);

    //Print function
    std::cout<<"\nmatrix1:\n";
    matrix1.print();
    std::cout<<"\nmatrix2:\n";
    matrix2.print();

    //Transpose example
    matrix3 = matrix2.transpose();
    std::cout<<"\nTranspose of matrix2:\n";
    matrix3.print();

    //scalar Matrix multiplication example
    std::cout<<"\nMultiplying a scalar value 2 with matrix1:\n";
    matrix3 = 2 * matrix1;
    matrix3.print();

    //Matrix matrix multiplication example
    std::cout<<"\nMultiplying matrix1 and matrix2 and assigning to matrix3:\n";
    matrix3 = matrix1 * matrix2;
    matrix3.print();

    std::cout<<"\nMultiplying matrix3 and matrix2:\n";
    matrix3 = matrix3.multiply(matrix2);
    matrix3.print();

    linalg::matrix<int> matrix5(3,3, a);
    matrix5 = std::move(matrix3);
    std::cout<<std::endl;
    matrix5.print();
    std::cout<<std::endl;
    matrix3.print();
}