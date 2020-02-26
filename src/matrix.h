/**
* @file         matrix.h
* @brief        Linear Algebra library
* @author       Veera Ragav
*/
#ifndef MATRIX_H_
#define MATRIX_H_
#include <stdexcept>
#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
namespace linalg
{
/**
* @class   matrix
* @brief   Class for Matrix multiplication and transpose
*/
template <typename T>
class matrix
{
private:
    boost::shared_ptr<T[]> data; ///< @brief Matrix elements as a array 
    size_t rows;                 ///< @brief Number of Rows 
    size_t cols;                 ///< @brief Number of Columns

public:
    matrix(size_t n_rows, size_t n_cols);
    matrix(size_t n_rows, size_t n_cols, T *input_data);

    /** @brief Access Matrix Elements
    @param i Row Index.
    @param j Column Index.
    */
    T &at(size_t i, size_t j);

    /** @brief Returns Transpose of matrix */
    matrix<T> transpose();

    /** @brief Matrix and Scalar Multiplication
    @param scalar Scalar value to be multiplied with the matrix.
    */
    matrix<T> operator*(const T scalar);

    /** @brief Matrix and Matrix Multiplication
    @param mat Matrix to be multiplied.
    */
    matrix<T> operator*(matrix<T> mat);

    /** @brief Matrix and Scalar Multiplication
    @param scalar Scalar value to be multiplied with the matrix.
    */
    matrix<T> multiply(const T scalar);

    /** @brief Matrix and Matrix Multiplication
    @param mat Matrix to be multiplied.
    */
    matrix<T> multiply(matrix<T> mat);


    /** @brief Assignment operator overloaded to do deep copy*/
    matrix<T> &operator=(const matrix<T> &m);

 
    /** @brief Matrix and Scalar Multiplication
     * @param mat Matrix to be multiplied.
    @param scalar Scalar value to be multiplied with the matrix.
    */
    template <T>
    friend matrix<T> operator*(T scalar, const matrix<T> &mat);

    /** @brief Check Indices are withing bounds.
    @param i Row Index.
    @param k Column Index.
    */
    void check_range(size_t i, size_t j);

    /** @brief Returns number of rows */
    size_t no_of_rows();

    /** @brief Returns number of columns */
    size_t no_of_cols();

    /** @brief Prints all elements of this matrix */
    void print();
};

template <typename T>
matrix<T>::matrix(size_t n_rows, size_t n_cols)
{
    rows = n_rows;
    cols = n_cols;
    size_t n = rows * cols;
    data = boost::make_shared<T[]>(n);
}

template <typename T>
matrix<T>::matrix(size_t n_rows, size_t n_cols, T *input_data)
{
    rows = n_rows;
    cols = n_cols;
    size_t n = rows * cols;
    data = boost::make_shared<T[]>(n);
    for (size_t i = 0; i < rows * cols; i++)
    {
        this->data[i] = input_data[i];
    }
}

template <typename T>
size_t matrix<T>::no_of_rows()
{
    return this->rows;
}

template <typename T>
size_t matrix<T>::no_of_cols()
{
    return this->cols;
}

template <typename T>
matrix<T> matrix<T>::operator*(matrix<T> mat)
{

    if (this->cols != mat.no_of_cols())
    {
        throw std::domain_error("matrix dimension do not match");
    }

    matrix<T> res(this->rows, mat.no_of_cols());

    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < mat.no_of_cols(); j++)
        {

            for (int k = 0; k < this->cols; k++)
            {
                res.at(i, j) = res.at(i, j) + this->at(i, k) * mat.at(k, j);
            }
        }
    }

    return res;
}

template <typename T>
matrix<T> matrix<T>::operator*(const T scalar)
{
    matrix<T> result_matrix(this->rows, this->cols);
    for (size_t i = 0; i < rows * cols; i++)
    {
        result_matrix.data[i] = this->data[i] * scalar;
    }
    return result_matrix;
}

template <typename T>
matrix<T> operator*(T scalar, matrix<T> mat)
{
    return mat.operator*(scalar);
}

template <typename T>
matrix<T> matrix<T>::multiply(const T scalar)
{
    return this->operator*(scalar);
}

template <typename T>
matrix<T> matrix<T>::multiply(matrix<T> mat)
{
    return this->operator*(mat);
}

template <typename T>
void matrix<T>::check_range(size_t i, size_t j)
{
    if (rows <= i)
        throw std::range_error("Matrix Row index out of range");
    if (cols <= j)
        throw std::range_error("Matrix Column index out of range");
}

template <typename T>
matrix<T> &matrix<T>::operator=(const matrix<T> &m)
{
    if (&m == this) return *this;

    if (m.cols != this->cols || m.rows != this->rows)
    {
        throw std::domain_error("Matrices are not of same order");
    }
    this->rows = m.rows;
    this->cols = m.cols;
    for (size_t i = 0; i < rows * cols; i++)
    {
        this->data[i] = m.data[i];
    }
    
    return *this;
}

template <typename T>
T &matrix<T>::at(size_t i, size_t j)
{
    this->check_range(i, j);
    return data[i * rows + j];
}

template <typename T>
matrix<T> matrix<T>::transpose()
{
    matrix<T> transposed_matrix(rows, cols);
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            transposed_matrix.at(j, i) = this->at(i, j);
        }
    }
    return transposed_matrix;
}

template <typename T>
void matrix<T>::print()
{
    for (int i = 0; i < rows * cols; i++)
    {
        std::cout << data[i] << " ";
    }
}

} // namespace linalg
#endif