#ifndef MATRIX_H_
#define MATRIX_H_
#include <stdexcept>
#include <iostream>
#include <boost/shared_ptr.hpp>
namespace linalg{

template<typename T>
class matrix {
    private:
        boost::shared_ptr<T[]> data{new T};
        size_t rows;
        size_t cols;

    public:
         matrix(){
             rows = 0;
             cols = 0;
         }

        matrix(size_t n_rows, size_t n_cols){
            rows = n_rows;
            cols = n_cols;
        }

        matrix(size_t n_rows, size_t n_cols, T* input_data){
            rows = n_rows;
            cols = n_cols;
            for(size_t i = 0; i < rows*cols; i++){
                this->data[i] = input_data[i];
            } 
        }

        matrix<T>& operator = (const matrix<T>& m);
        
        T& at(size_t i, size_t j);

        matrix<T> transpose();

        matrix<T> operator * (const T scalar);
        matrix<T> operator * (matrix<T> mat);

        
        template<T> friend matrix<T> operator* (  T scalar,  const matrix<T>& mat) ;

        void print();

        void check_range(size_t i, size_t j);

        size_t no_of_rows();
        size_t no_of_cols();

};



template <typename T> 
size_t matrix<T>::no_of_rows(){
    std::cout<<"No of rows is stored at:"<<&(this->rows)<<std::endl;
    return this->rows;
}

template <typename T> 
size_t matrix<T>::no_of_cols(){
    return this->cols;
}

template <typename T>
matrix<T> matrix<T>::operator*(const T scalar){
    matrix<T> result_matrix(this->rows, this->cols);
    for(size_t i = 0; i < rows*cols; i++){
       result_matrix.data[i] = this->data[i] * scalar;
   }
   std::cout<<"*: "<<&result_matrix<<std::endl;
   return result_matrix;
}

template <typename T>
matrix<T> operator*( T scalar,  matrix<T> mat){
    //matrix<T> result_matrix(mat.no_of_rows(), mat.no_of_cols());
//     for(size_t i = 0; i < mat.rows*mat.cols; i++){
//        result_matrix.data[i] = mat.data[i] * scalar;
//    }
   return mat.operator*(scalar);
}

template <typename T>
void matrix<T>::check_range(size_t i, size_t j){
            if(rows <= i) throw std::range_error("Matrix Row index out of range");
            if(cols <= j) throw std::range_error("Matrix Column index out of range");
}

template <typename T>
matrix<T>& matrix<T>::operator = (const matrix<T>& m){  
    //TODO: std::copy?? check self assignemnt and skip
    //std::cout<<"==============\n"<<std::endl;
    std::cout<<"= called"<<std::endl;
   this->rows = m.rows;
   this->cols = m.cols; 
   for(size_t i = 0; i < rows*cols; i++){
       this->data[i] = m.data[i];
   } 
  
   return *this; 
}

template <typename T>
T& matrix<T>::at(size_t i, size_t j){
    this->check_range(i, j);
    return data[i*rows + j];
}

template <typename T>
matrix<T> matrix<T>::transpose(){
    matrix<T> transposed_matrix(rows, cols);
    //matrix<T>* transposed_matrix = new matrix<T>(rows, cols);
    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < cols; j++){
            transposed_matrix.at(j , i) = this->at(i, j);
        }
    }
    return transposed_matrix;
}

template <typename T>
void matrix<T>::print(){
    std::cout<<data<<std::endl;
    for(int i = 0; i < rows*cols; i++){
        std::cout<<data[i]<<" ";
    }
    std::cout<<std::endl;
}

}
#endif