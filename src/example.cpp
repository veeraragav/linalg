#include "matrix.h"

int main(){

    int a[] = {1, 2, 3, 4};
    linalg::matrix<int> mat(2,2, a);
    mat.print();

    std::cout<<"mat 1 no of rows: "<<mat.no_of_rows()<<std::endl;
    std::cout<<"mat 1 is  at "<<&mat<<std::endl;

    linalg::matrix<int> mat2 = mat;
    mat2.print();

    std::cout<<"mat2 no of rows: "<<mat2.no_of_rows()<<std::endl;
    std::cout<<"mat 2 is  at "<<&mat2<<std::endl;

    int b[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    linalg::matrix<int> mat3(3,3, b);
    //mat3.print();
    //std::cout<<"mat3 no of rows: "<<mat3.no_of_rows()<<std::endl;
    //std::cout<<"mat 3 is  at "<<&mat3<<std::endl;
}