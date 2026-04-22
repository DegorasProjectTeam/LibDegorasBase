/***********************************************************************************************************************
 *   LibDegorasBase (Degoras Project SLR Library): A libre base library for Degoras Project developments.                        *                                      *
 *                                                                                                                     *
 *   Copyright (C) 2023 Degoras Project Team                                                                           *
 *                      < Ángel Vera Herrera, avera@roa.es - angeldelaveracruz@gmail.com >                             *
 *                      < Jesús Relinque Madroñal >                                                                    *
 *                                                                                                                     *
 *   This file is part of LibDegorasBase.                                                                                    *
 *                                                                                                                     *
 *   Licensed under the European Union Public License (EUPL), Version 1.2 or subsequent versions of the EUPL license   *
 *   as soon they will be approved by the European Commission (IDABC).                                                 *
 *                                                                                                                     *
 *   This project is free software: you can redistribute it and/or modify it under the terms of the EUPL license as    *
 *   published by the IDABC, either Version 1.2 or, at your option, any later version.                                 *
 *                                                                                                                     *
 *   This project is distributed in the hope that it will be useful. Unless required by applicable law or agreed to in *
 *   writing, it is distributed on an "AS IS" basis, WITHOUT ANY WARRANTY OR CONDITIONS OF ANY KIND; without even the  *
 *   implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the EUPL license to check specific   *
 *   language governing permissions and limitations and more details.                                                  *
 *                                                                                                                     *
 *   You should use this project in compliance with the EUPL license. You should have received a copy of the license   *
 *   along with this project. If not, see the license at < https://eupl.eu/ >.                                         *
 **********************************************************************************************************************/

/** ********************************************************************************************************************
 * @file matrix.tpp
 * @brief This file contains the implementation of the mathematical class Matrix.
 * @author Degoras Project Team
 * @copyright EUPL License
 2305.1
***********************************************************************************************************************/

// =====================================================================================================================
#pragma once
// =====================================================================================================================

// C++ INCLUDES
// =====================================================================================================================
#include <vector>
#include <cstddef>
#include <algorithm>
#include <omp.h>
#include <numeric>
#include <cmath>
#include <optional>
#include <string>
// =====================================================================================================================

// LIBRARY INCLUDES
// =====================================================================================================================
// #include "LibDegorasBase/Mathematics/types/matrix.h"
// =====================================================================================================================

// LIBDPBASE NAMESPACES
// =====================================================================================================================
namespace dpbase{
namespace math{
namespace types{
// =====================================================================================================================

template <typename T>
Matrix<T>::Matrix(const std::initializer_list<std::initializer_list<T>>& list)
{
    std::vector<std::vector<T>> data;
    data.reserve(list.size());
    for (const auto& row : list)
        data.emplace_back(row.begin(), row.end());
    this->setDataFromContainer(data);
}

template <typename T>
Matrix<T>::Matrix(std::size_t row_size, std::size_t col_size, T value) :
    data_(row_size, std::vector<T>(col_size, value)) {}


template <typename T>
void Matrix<T>::clear() {data_.clear();}


template <typename T>
void Matrix<T>::fill(std::size_t row_size, std::size_t col_size, T value)
{
    this->data_.clear();
    this->data_.insert(data_.begin(), row_size, std::vector<T>(col_size, value));
}

template <typename T>
void Matrix<T>::fill(T value)
{
    std::size_t r_size = this->rowSize();
    std::size_t c_size = this->columnsSize();

    this->data_.clear();
    this->data_.insert(data_.begin(), r_size, std::vector<T>(c_size, value));
}

template <typename T>
template <typename Container>
bool Matrix<T>::setDataFromContainer(const Container& container)
{
    bool result = false;

    if (container.size() > 0)
    {
        // Check if every column has the same size, otherwise, the matrix is ill-formed
        std::size_t col_size = container[0].size();
        bool valid_column_size = true;
        std::size_t i = 1;
        while(i < container.size() && valid_column_size)
        {
            valid_column_size = container[i].size() == col_size;
            i++;
        }
        if (valid_column_size)
        {
            this->data_.clear();
            this->data_.reserve(container.size());
            for (const auto& row : container)
                this->data_.emplace_back(row.begin(), row.end());
            result = true;
        }
    }
    return result;
}


template <typename T>
void Matrix<T>::setColumn(std::size_t col_index, const std::vector<T>& column)
{
    assert(col_index < this->columnsSize());
    assert(column.size() == this->rowSize());

    for (std::size_t i = 0; i < this->rowSize(); ++i)
        this->data_[i][col_index] = column[i];
}

template <typename T>
template <typename Container>
bool Matrix<T>::pushBackRow(const Container& row)
{
    bool size_correct = row.size() == this->columnsSize() || this->columnsSize() == 0;
    if (size_correct)
    {
        this->data_.push_back(std::vector<T>(row.size()));
        std::copy(row.begin(), row.end(), this->data_.back().begin());
    }
    return  size_correct;
}

template <typename T>
std::size_t Matrix<T>::columnsSize() const
{
    return this->data_.size() == 0 ? 0 : this->data_[0].size();
}

template <typename T>
std::size_t Matrix<T>::rowSize() const
{
    return this->data_.size();
}

template <typename T>
bool Matrix<T>::isSquare() const
{
    return this->rowSize() == this->columnsSize();
}

template <typename T>
bool Matrix<T>::isEmpty() const
{
    return this->data_.empty();
}

template <typename T>
typename std::enable_if_t<helpers::traits::is_numeric_v<T>, bool>
Matrix<T>::isIdentity() const
{
    // Check if the matrix is square
    if(!this->isSquare())
        return false;

    // Auxiliar result.
    bool identity = true;

    // Check if the diagonal elements are 1 and all other elements are 0
    for (size_t i = 0; i < this->rowSize() && identity; i++)
        for (size_t j = 0; j < this->columnsSize(); j++)
        {
            if (i == j && compareFloating(static_cast<double>(this->data_[i][j]), 1.0))
                identity = false;
            else if (i != j && compareFloating(static_cast<double>(this->data_[i][j]), 0.0))
                identity = false;
        }

    // Return the result.
    return identity;
}

template <typename T>
bool Matrix<T>::isHermitian() const
{
    Matrix<T> M = *this;
    return M == M.transpose();
}

template <typename T>
int Matrix<T>::signature() const
{
    // Check if the matrix is valid
    if(!this->isSquare())
    {
        return 10;
    }
    // Simetrize the matrix
    Matrix<T> M = (*this + (*this).transpose())*0.5;;

    std::size_t n = this->rowSize();
    // Perform the gaussian elimination to convert the matrix into a diagonal matrix
    M = M.GaussianElimination();

    // Initialize the counters
    size_t pos = 0;
    size_t neg = 0;
    size_t zero = 0;
    // Check all diagonal elements in the matrix
    for(size_t i=0;i<n;i++)
    {   // Increase the corresponding counter
        if(M[i][i]>0)
        {
            pos += 1;
        }
        else if(M[i][i]<0)
        {
            neg += 1;
        }
        else
        {
            zero += 1;
        }
    }
    // Check the number of positive, negative and zeros elements
    if(pos == n)
    {
        return 2;
    }
    else if(pos + zero == n)
    {
        return 1;
    }
    else if(neg == n)
    {
        return -2;
    }
    else if(neg + zero == n)
    {
        return -1;
    }

    return 0;
}

template <typename T>
bool Matrix<T>::isPositiveDefinite() const
{
    int Sign = (*this).signature();
    if(Sign == 2)
    {
        return true;
    }
    return false;
}

template <typename T>
bool Matrix<T>::isNegativeDefinite() const
{
    int Sign = (*this).signature();
    if(Sign == -2)
    {
        return true;
    }
    return false;
}

template <typename T>
bool Matrix<T>::isPositiveSemidefinite() const
{
    int Sign = (*this).signature();
    if(Sign == 1)
    {
        return true;
    }
    return false;
}

template <typename T>
bool Matrix<T>::isNegativeSemidefinite() const
{
    int Sign = (*this).signature();
    if(Sign == -1)
    {
        return true;
    }
    return false;
}

template <typename T>
bool Matrix<T>::isIndefinite() const
{
    int Sign = (*this).signature();
    if(Sign == 0)
    {
        return true;
    }
    return false;
}

template <typename T>
std::vector<T>& Matrix<T>::operator[] (std::size_t row_index)  {return this->data_[row_index];}

template <typename T>
const std::vector<T>& Matrix<T>::operator[] (std::size_t row_index) const {return this->data_[row_index];}

template <typename T>
const T& Matrix<T>::operator()(std::size_t row_index, std::size_t col_index) const
{
    return this->data_[row_index][col_index];
}

template <typename T>
T& Matrix<T>::operator()(std::size_t row_index, std::size_t col_index) {return this->data_[row_index][col_index];}

template <typename T>
const std::vector<T>& Matrix<T>::getRow(std::size_t row_index) const
{
    return this->data_[row_index];
}

template <typename T>
std::vector<T> Matrix<T>::getColumn(std::size_t col_index) const
{
    std::vector<T> column;
    for (const auto& row : this->data_)
        column.push_back(row[col_index]);
    return column;
}

template <typename T>
void Matrix<T>::setElement(std::size_t row_index, std::size_t col_index, const T& value)
{
    data_[row_index][col_index] = value;
}

template <typename T>
const T& Matrix<T>::getElement(std::size_t row_index, std::size_t col_index) const
{
    return this->data_[row_index][col_index];
}

template <typename T>
std::string Matrix<T>::toString() const
{
    std::string str;
    for (std::size_t j = 0; j < this->columnsSize(); j++)
    {
        for (std::size_t i = 0; i < this->rowSize(); i++)
        {
            str += std::to_string(this->data_[i][j]) + " ";
        }
        str += '\n';
    }
    return str;
}

template <typename T>
std::enable_if_t<std::is_swappable_v<T>, bool>
Matrix<T>::swapRows(std::size_t r1, std::size_t r2)
{
    bool rows_valid = (r1 < this->rowSize()) && (r2 < this->rowSize());
    if (rows_valid)
        std::swap(this->data_[r1], this->data_[r2]);
    return rows_valid;
}

template <typename T>
std::enable_if_t<std::is_swappable_v<T>, bool>
Matrix<T>::swapColumns(std::size_t c1, std::size_t c2)
{
    bool cols_valid = (c1 < this->columnsSize()) && (c2 < this->columnsSize());
    if (cols_valid)
        for (auto& row : this->data_)
            std::swap(row[c1], row[c2]);
    return cols_valid;
}

template <typename T>
Matrix<T> Matrix<T>::transpose() const
{
    const std::size_t m = this->rowSize();
    const std::size_t n = this->columnsSize();

    Matrix<T> result(n, m, static_cast<T>(0));

    #pragma omp parallel for collapse(2) schedule(static)
    for (std::ptrdiff_t i = 0; i < static_cast<std::ptrdiff_t>(m); ++i)
    {
        for (std::ptrdiff_t j = 0; j < static_cast<std::ptrdiff_t>(n); ++j)
        {
            result.data_[static_cast<std::size_t>(j)][static_cast<std::size_t>(i)] =
                this->data_[static_cast<std::size_t>(i)][static_cast<std::size_t>(j)];
        }
    }

    return result;
}


template <typename T>
Matrix<T> Matrix<T>::eliminateRow(std::size_t row) const
{
    // Create a copy if the matrix
    Matrix<T> A = *this;
    // Assign the number of rows in matrix
    std::size_t n_row = A.rowSize();
    // Initalize the new matrix
    Matrix<T> matrix = Matrix<T>();
    // Check if the selected row is valid
    if(row > n_row - 1)
    {
        std::cout<<"Invalid index"<<std::endl;
        return A;
    }

    // Perform the row elimination
    for(size_t i=0; i < n_row; i++)
    {
        if(i!=row)
        {
            matrix.pushBackRow(A[i]);
        }
    }
    return matrix;
}

template <typename T>
Matrix<T> Matrix<T>::eliminateCol(std::size_t col) const
{
    // Transpose the matrix to eliminated the column as if it were a row
    Matrix<T> A = this->transpose();
    // Perform the column elimination
    Matrix<T> matrix = A.eliminateRow(col);
    matrix = matrix.transpose();
    return matrix;
}

template <typename T>
std::pair<std::size_t,std::size_t> Matrix<T>::pivotRow() const
{
    // Initialize the parameters
    std::size_t index = 0;
    std::size_t n_zeros = 0;
    std::size_t n = this->rowSize();
    // Create a copy of the matrix
    Matrix<T> A = *this;
    // Perform the search of optimal row, the row with the maximun number of zeros
    for(std::size_t i=0; i < n; i++)
    {
        // Initalize the current number of zeros
        std::size_t aux = 0;

        for(std::size_t j=0; j < n; j++)
        {
            if(A[i][j]==0)
            {
                aux++;
            }
        }
        // Check if the actual row is better than optimal
        if(n_zeros < aux)
        {
            index = i;
            n_zeros = aux;
        }
        // Check if all elements in the row are zeros
        if(n_zeros == n)
        {
            return std::make_pair(index,n_zeros);
        }
    }
    return std::make_pair(index,n_zeros);
}

template <typename T>
std::pair<std::size_t,std::size_t> Matrix<T>::pivotCol() const
{
    // Perform the search of optimal column, the column with the maximun number of zeros
    // Using the transpose matrix and the search of optimal row.
    Matrix<T> A = this->transpose();
    std::pair<std::size_t,std::size_t> result = A.pivotRow();
    std::size_t index = result.first;
    std::size_t n_zeros = result.second;
    return std::make_pair(index,n_zeros);

}

template <typename T>
Matrix<T> Matrix<T>::adjoint(std::size_t row,std::size_t col) const
{
    // Create a copy of the matrix
    Matrix<T> A = *this;

    // Check if the arguments of adjoint matrix are valid
    if(row > A.rowSize()-1 || col > A.columnsSize()-1)
    {
        std::cout<<"Invalid arguments to calculate the adjoint matrix"<<std::endl;
        return A;
    }

    // Perform the calculation of adjoint matrix
    A = A.eliminateRow(row);
    A = A.eliminateCol(col);
    return A;
}


// Mirar si se puede evitar hacer copias de la matriz adjunta para mejorar la eficiencia de la funcion
// Mirar si se puede mejorar el rendimiento general de la función
template <typename T>
long double Matrix<T>::determinant() const
{
    if(this->isEmpty())
    {
        std::cout<<"Invalid Matrix"<<std::endl;
        return 0;
    }
    // Create a copy of the matrix
    Matrix<T> A = *this;

    // Perform the LU descomposition
    auto LU = A.decomposeLU();
    A = LU.first;
    std::vector<size_t> pivot = LU.second;
    std::size_t n = A.rowSize();
    // Initialize the determinant
    long double det = 1.0;

    // Calculated the determinant with the values of diagonal
    for(size_t i=0;i<n;i++)
    {
        det *= A[i][i];
    }

    // Perform the calculation of determinant sign
    long double sign = 1.0;
    std::vector<bool> visited(n, false);
    size_t num_cycles = 0;

    for (size_t i = 0; i < n; i++) {
        if (!visited[i])
        {
            num_cycles++;
            size_t curr = i;

            while (!visited[curr])
            {
                visited[curr] = true;
                curr = pivot[curr];
            }
        }
    }

    if ((n - num_cycles) % 2 != 0) {
        sign = -1.0;
    }

    return sign*det;
}

template <typename T>
long double Matrix<T>::detGauss() const
{
    if(this->isEmpty())
    {
        std::cout<<"Invalid Matrix"<<std::endl;
        return 0;
    }
    std::size_t n = this->rowSize();
    // Check if it is the trivial case
    if(n==1)
    {
        return (*this)[0][0];
    }

    // To optimize the calculation of determinant check the case of dimension 2
    if(n==2)
    {
        return (*this)[0][0] * (*this)[1][1] - (*this)[0][1] * (*this)[1][0];
    }

    // To optimize the calculation of determinant check the case of dimension 3
    if(n==3)
    {
        return (*this)[0][0]*(*this)[1][1]*(*this)[2][2] + (*this)[1][0]*(*this)[2][1]*(*this)[0][2] + (*this)[2][0]*(*this)[0][1]*(*this)[1][2] - (*this)[0][2]*(*this)[1][1]*(*this)[2][0] - (*this)[1][2]*(*this)[2][1]*(*this)[0][0] - (*this)[0][1]*(*this)[1][0]*(*this)[2][2];
    }
    // Create a copy of the matrix
    Matrix<long double> A = *this;
    // Initialize the determinant
    long double det = 1.0;
    // Initialize the sign of determinant, the sign change to value all time the
    // matrix permute a row or column
    int sign = 1;
    // Initialize the pivot
    std::size_t pivot;
    // Perform the calculation of optimal pivot
    for(std::size_t i = 0; i < n; i++)
    {
        pivot = i;
        for(std::size_t j = i+1;j < n; j++)
        {
            if(std::abs(A[j][i]) > std::abs(A[pivot][i]))
            {
                pivot = j;
            }
        }
        // Check if the optimal pivot is 0.
        // The condition <1e-18 ensures that the pivot value is large
        // enough not to be considered 0
        if(std::abs(A[pivot][i]) < 1e-18)
        {
            return 0;
        }
        // Swamp the row if the optimal pivot is not the starting element
        if(pivot != i)
        {
            A.swapRows(i,pivot);
            sign *= -1;
        }

        det *= A[i][i];
        // Perform the change of all element
        for(std::size_t j = i+1;j < n; j++)
        {
            long double factor = A[j][i]/A[i][i];
            for(std::size_t k = i+1;k < n;k++)
            {
                A[j][k] -= factor*A[i][k];
            }
        }
    }

    return det*sign;
}

template <typename T>
long double Matrix<T>::norm1() const
{
    // Create a copy of the matrix
    Matrix<T> A = *this;
    // Initialize the value of the norm
    long double n = 0;
    for(std::size_t i=0; i<A.rowSize(); i++)
    {
        // Perform the calculation of sumatory
        long double sum_col = 0;
        for(std::size_t j=0; j<A.columnsSize(); j++)
        {
            sum_col += std::abs(A[i][j]);
        }
        // Assign the value of the norm 1
        n = std::max(n,sum_col);
    }
    return n;
}

template <typename T>
template <typename U>
typename std::enable_if_t<helpers::traits::is_numeric_v<U>, Matrix<T>>
Matrix<T>::operator*(const U& scalar) const
{
    Matrix<T> result(rowSize(), columnsSize());

    #pragma omp parallel for
    for (size_t i = 0; i < rowSize(); i++)
    {
        for (size_t j = 0; j < columnsSize(); j++)
            result(i, j) = static_cast<T>(this->data_[i][j]) * static_cast<T>(scalar);
    }

    return result;
}

template <typename T>
template <typename U>
typename std::enable_if_t<helpers::traits::same_arithmetic_category_v<T,U>, Matrix<T>>
Matrix<T>::operator*(const Matrix<U>& B) const
{
    // Check dimensions.
    if (this->columnsSize() != B.rowSize())
        return Matrix<T>();

    // Transpose the rhs matrix for more efficient multiplication.
    Matrix<U> B_transposed = B.transpose();

    // Prepare the result container.
    Matrix<T> result(this->rowSize(), B.columnsSize());

    // Do the multiplication.
    #pragma omp parallel for
    for (std::size_t i = 0; i < this->rowSize(); ++i)
    {
        for (std::size_t j = 0; j < B_transposed.rowSize(); ++j)
        {
            long double sum = 0;
            #pragma omp parallel for reduction(+:sum)
            for (std::size_t k = 0; k < this->columnsSize(); ++k)
            {
                sum += static_cast<long double>(this->data_[i][k]) *
                       static_cast<long double>(B_transposed.getElement(j,k));
            }
            result(i, j) = static_cast<T>(sum);
        }
    }

    // Return the result matrix.
    return result;
}

template <typename T>
template <typename U>
Matrix<T>& Matrix<T>::operator *=(const Matrix<U>& B)
{
    return *this = *this * B;
}

template <typename T>
template <typename U>
Matrix<T>& Matrix<T>::operator *=(const U& scalar)
{
    *this = *this * scalar;
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::GaussianElimination() const
{
    // Initialize the parameters
    std::size_t n = this->rowSize();
    Matrix<T> M = *this;

    std::size_t pivot;
    // Perform the calculation of optimal pivot
    for(std::size_t i = 0; i < n; i++)
    {
        pivot = i;
        for(std::size_t j = i+1;j < n; j++)
        {
            if(std::abs(M[j][i]) > std::abs(M[pivot][i]))
            {
                pivot = j;
            }
        }
        // Check if the optimal pivot is 0.
        // The condition <1e-18 ensures that the pivot value is large
        // enough not to be considered 0
        if(std::abs(M[pivot][i]) < 1e-18)
        {
            continue;
        }
        // Swamp the row and column if the optimal pivot is not the starting element
        if(pivot != i)
        {
            M.swapRows(i,pivot);
            M.swapColumns(i,pivot);
        }

        // Perform the change of all element
        for(std::size_t j = i+1;j < n; j++)
        {
            long double factor = M[j][i]/M[i][i];
            for(std::size_t k = i;k < n;k++)
            {
                M[j][k] -= factor*M[i][k];
            }
            for(std::size_t k = i; k < n; k++)
            {
                M[k][j] -= factor * M[k][i];
            }
        }
    }
    return M;
}

template <typename T>
std::pair<Matrix<long double>, std::vector<size_t>> Matrix<T>::decomposeLU() const
{
    size_t row_s = this->rowSize();
    size_t col_s = this->columnsSize();

    // Create a copy of the input matrix to preserve its values
    Matrix<long double> LU = *this;
    std::vector<size_t> pivot(col_s);

    // Initialize the pivot vector
    for (size_t i = 0; i < col_s; i++)
    {
        pivot[i] = i;
    }

    for (size_t k = 0; k < std::min(row_s, col_s); k++)
    {
        // Find the pivot element and swap rows
        size_t maxIndex = k;
        long double maxValue = std::abs(LU(k, k));

        for (size_t i = k + 1; i < row_s; i++)
        {
            if (std::abs(LU(i, k)) > maxValue)
            {
                maxIndex = i;
                maxValue = std::abs(LU(i, k));
            }
        }

        // WARNING TODO Comparacion flotante???
        if (0 == compareFloating(maxValue, 0.L))
        {
            // Matrix is singular
            return std::make_pair(LU, pivot);
        }

        if (maxIndex != k)
        {
            // Swap rows in LU matrix
            LU.swapRows(maxIndex, k);

            // Update the pivot vector
            std::swap(pivot[maxIndex], pivot[k]);
        }

        for (size_t i = k + 1; i < row_s; i++)
        {
            LU(i, k) /= LU(k, k);
            for (size_t j = k + 1; j < col_s; j++)
            {
                LU(i, j) -= LU(i, k) * LU(k, j);
            }
        }
    }

    return std::make_pair(LU, pivot);
}

template <typename T>
Matrix<long double> Matrix<T>::solveLU(
    const Matrix<long double>& LU, const std::vector<size_t>& pivot,const std::vector<long double>& b)
{
    size_t M = LU.rowSize();
    size_t N = LU.columnsSize();

    // Create a matrix from the vector b

    Matrix<long double> x(M, N);

    for (size_t col = 0; col < N; col++)
    {
        // Create a copy of the right-hand side vector for the current column
        Matrix<long double> y(M, 1);
        y.setColumn(0, b);

        // He comentado este bloque ya que a la hora de resolver la inversa por
        // habia veces que se devolvia la inversa con las columnas cambiadas pero
        // con los valores correctos, en principio eso se debia a que en este bloque
        // se hace una permutacion que no se revierte mas adelante por lo que
        // dicha permutacion aparece en la matriz final.
        // Apply row permutations to the right-hand side vector
        //for (size_t i = 0; i < M; i++)
        //{
        //    std::swap(y(i, 0), y(pivot[i], 0));
        //}

        // Solve Ly = b using forward substitution
        for (size_t i = 1; i < M; i++)
        {
            for (size_t j = 0; j < i; j++)
            {
                y(i, 0) -= LU(i, j) * y(j, 0);
            }
        }

        // Solve Ux = y using backward substitution
        for (int i = M - 1; i >= 0; i--)
        {
            for (size_t j = static_cast<size_t>(i) + 1; j < N; j++)
            {
                y(static_cast<size_t>(i), 0) -= LU(static_cast<size_t>(i), j) * y(j, 0);
            }
            y(static_cast<size_t>(i), 0) /= LU( static_cast<size_t>(i), static_cast<size_t>(i));
        }

        // Assign the solution to the corresponding column of the result matrix
        x.setColumn(pivot[col], y.getColumn(0));
    }

    return x;
}

template <typename T>
Matrix<long double> Matrix<T>::inverse() const
{
    // TODO
    // Algo esta mal, retorna los datos bien pero las columnas no estan en el orden correcto.

    // Es posible que el fallo sea causado por el metodo usado en el calculo, el que se
    // usa es el de descomposicion LU con pivote es decir se calcula una matriz/vector P
    // tal que PA = LU y al calcularse la inversa A se calcula realmente la inversa de PA
    // dado que la inversa de un pivote es otro pivote puede ser que este sea el motivo del
    // desorden de las columnas. (Revisar)

    // En principio ya esta solucionado el problema venia de la funcion solveLU, alli explico el cambio, no elimino
    // el comentario por si la solucion solo fuese aparente y se tuviese que volver a investigar.

    // Check if the matrix is square or its determinant is null.
    if(!this->isSquare() || std::abs((*this).detGauss()) < 1e-18 )
    {
        return Matrix<long double>();
    }

    size_t m = this->rowSize();
    Matrix<long double> identity = Matrix<long double>::I(m);

    // Perform LU decomposition
    Matrix<long double> lu_m = *this;
    std::vector<size_t> pivot;
    std::pair<Matrix<long double>, std::vector<size_t>> lu = lu_m.decomposeLU();

    // Solve for each column of the inverse
    Matrix<long double> inv(m, m);
    for (size_t col = 0; col < m; col++)
    {
        Matrix<long double> x = Matrix<long double>::solveLU(lu.first, lu.second, identity.getColumn(col));
        inv.setColumn(lu.second[col], x.getColumn(0));
    }

    return inv;
}

template <typename T>
std::pair<int,Matrix<long double>> Matrix<T>::invCholesky() const
{
    // Check if the matrix is square or its determinant is null.
    if(!this->isSquare() || std::abs((*this).detGauss()) < 1e-18 ||!this-> isHermitian())
    {
        return std::make_pair(1,Matrix<long double>());
    }

    // Create a copy of the matrix
    Matrix<long double> A = *this;

    // Perform the inversion with Cholesky method
    // Initialize parameters
    size_t m = this->rowSize();
    Matrix<long double> U(m,m,0);
    Matrix<long double> W(m,m,0);
    for(size_t i=0;i < m;i++)
    {
        // Perform the LU decomposition with only the upper triangular matrix
        // and its transpose matrix, U^t*U decomposition.
        long double suma_diag = 0.0;
        for(size_t k=0;k < i;k++)
        {
            suma_diag += U[k][i]*U[k][i];
        }

        U[i][i] = sqrt(A[i][i] - suma_diag);

        if(std::isnan(U[i][i]) || std::isinf(U[i][i]))
        {
            std::cout<<"The Matrix isn't positive-definite"<<std::endl;
            return std::make_pair(1,Matrix<long double>());
        }

        for(size_t j = i+1; j<m; j++)
        {
            long double suma_fuera = 0.0;
            for(size_t k=0; k < i; k++)
            {
                suma_fuera += U[k][i]*U[k][j];
            }
            U[i][j] = (A[i][j] - suma_fuera) / U[i][i];

            if(std::isnan(U[i][j]) || std::isinf(U[i][j]))
            {
                std::cout<<"The Matrix isn't positive-definite"<<std::endl;
                return std::make_pair(1,Matrix<long double>());
            }
        }
    }

    // Calculate the inverse of U matrix
    for(int j= m-1; j>=0; j--)
    {
        W[j][j] = 1.0 / U[j][j];
        for(int i=j-1; i >=0; i--)
        {
            long double suma_inv = 0.0;
            for(int k = i+1; k < j+1; k++)
            {
                suma_inv += U[i][k] * W[k][j];
            }
            W[i][j] = -suma_inv / U[i][i];
        }
    }

    // Perform the inverse matrix with Cholesky method
    auto WT = W.transpose();
    Matrix<long double> B = W * WT;
    return std::make_pair(0,B);
}

template <typename T>
Matrix<long double> Matrix<T>::invAdjoint() const
{
    // Check if the matrix is square or its determinant is null.
    if(!this->isSquare() || std::abs((*this).detGauss()) < 1e-18 )
    {
        return Matrix<long double>();
    }

    // Initialize the inverse matrix
    std::size_t n = this->rowSize();
    Matrix<long double> B(n,n,0);

    // Check the trival case
    if(n == 1)
    {
        B(0,0) = 1/(*this)[0][0];
        return B;
    }

    // Perforn the inverse matrix
    long double d = 1/(this->detGauss());

    for(std::size_t i=0; i < n; i++)
    {
        for(std::size_t j=0; j < n; j++)
        {
            Matrix<long double> C = this->adjoint(i,j);
            B[i][j] = d*C.detGauss()*pow(-1,i+j);
        }
    }
    return B.transpose();
}

template <typename T>
template <typename U>
Matrix<T> Matrix<T>::operator+(const Matrix<U>& B) const
{
    // Check dimensions.
    if (this->rowSize() != B.rowSize() || this->columnsSize() != B.columnsSize())
        return Matrix<T>();

    // Create a new matrix for the result.
    Matrix<T> result(this->rowSize(), this->columnsSize(), 0);

    // Add corresponding elements.
    omp_set_num_threads(omp_get_max_threads());
    #pragma omp parallel for
    for (size_t i = 0; i < this->rowSize(); i++)
        for (size_t j = 0; j < this->columnsSize(); j++)
            result[i][j] = this->data_[i][j] + B.data_[i][j];

    // Return the result.
    return result;
}

// He tenido que realizar unos pequeños cambios
// de orden en los operadores -, porque daba error

template <typename T>
template <typename U>
Matrix<T> Matrix<T>::operator-(const Matrix<U>& B) const
{
    return *this + (-B);
}

// Aviso: Si en la funcion operador-() se invierte el orden del
// return el programa no reconoce la multiplicacion

template <typename T>
Matrix<T> Matrix<T>::operator-() const
{
    return  (*this) * static_cast<T> (-1) ;
}

template <typename T>
template <typename U>
Matrix<T>& Matrix<T>::operator+=(const Matrix<U>& other)
{
    *this = *this + other;
    return *this;
}

template <typename T>
template <typename U>
Matrix<T>& Matrix<T>::operator-=(const Matrix<U>& other)
{
    *this = *this - other;
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::I(std::size_t n)
{
    Matrix<T> ident(n,n,0);
    omp_set_num_threads(omp_get_max_threads());
#pragma omp parallel for
    for (size_t i = 0; i < n; i++)
    {
        ident[i][i] = 1;
    }
    return ident;
}

template <typename T>
Matrix<T> Matrix<T>::fromColumnVector(const std::vector<T>& col)
{
    Matrix<T> res;
    std::transform(col.begin(), col.end(),
                   std::back_inserter(res.data_), [](const auto& e){return std::vector<T>{e};});
    return res;
}

template <typename T>
Matrix<T> Matrix<T>::fromRowVector(const std::vector<T>& row)
{
    Matrix<T> res;
    res.data_.push_back(row);
    return res;
}

template <typename T>
void Matrix<T>::euclidian3DRotation(unsigned axis, const math::units::Radians& angle)
{
    static_assert(helpers::traits::is_floating_v<T>,
                  "Matrix<T>::euclidian3DRotation requires T to be floating-point (or strong-floating).");

    // Checks.
    if (axis < 1)
    {
        std::string submodule("[LibDegorasBase,Mathematics,Matrix]");
        std::string error("Invalid axis for 3D rotation, axis must be > 1.");
        throw std::invalid_argument(submodule + " " + error);
    }
    // Generate the rotation matrix.
    Matrix<T> rotation;
    T s, c;
    unsigned caxis = axis - 1;
    rotation.fill(3,3,0);
    s = std::sin(angle);
    c = std::cos(angle);
    rotation[0][0]=c;
    rotation[1][1]=c;
    rotation[2][2]=c;
    rotation[0][1]=-s;
    rotation[1][2]=-s;
    rotation[2][0]=-s;
    rotation[1][0]=s;
    rotation[2][1]=s;
    rotation[0][2]=s;
    for (unsigned i=0; i<3; i++)
    {
        rotation[i][caxis] = static_cast<T>(0);
        rotation[caxis][i] = static_cast<T>(0);
    }
    rotation[caxis][caxis]= static_cast<T>(1);
    // Do the rotation.
    *this *= rotation;
}

template <typename T>
template <typename U>
bool Matrix<T>::same(Matrix<U> M,long double tol) const
{
    // Assign the dimensions of matrix
    std::size_t n = M.rowSize();
    std::size_t m = M.columnsSize();

    // Check the trival cases, empty matrices and diferent dimensions matrices
    if((*this).rowSize() != n || (*this).columnsSize() != m)
    {
        return false;
    }

    if((*this).isEmpty() && M.isEmpty())
    {
        return true;
    }

    // Perdorm the comparation
    for(std::size_t i = 0; i < n; i++)
    {
        for(std::size_t j = 0; j < m; j++)
        {
            if(std::abs((*this)[i][j] - M[i][j]) > tol)
            {
                return false;
            }
        }
    }
    return true;
}

// BUG SI LOS TIPOS SON DIFERENTES COMO COÑO DECIDE EL COMPARE QUE UTILIZAR...
// A ESTO HAY QUE DARLE UNA VUELTA
// PD: Paralelizar
template <typename T, typename U>
bool operator==(const Matrix<T>& A, const Matrix<U>& B)
{
    // Check if the matrices have the same dimensions
    if (A.rowSize() != B.rowSize() || A.columnsSize() != B.columnsSize())
        return false;

    // Check if both are empty.
    if(A.isEmpty() && B.isEmpty())
        return true;

    bool res = true;

    // Check element-wise equality
    for (size_t i = 0; i < A.rowSize() && res; ++i)
    {
        for (size_t j = 0; j < A.columnsSize() && res; ++j)
        {
            // BUG Checking issue
            // T aux1 = A(i, j);
            // T aux2 = B(i, j);
            T aux3 = A.getElement(i, j);
            T aux4 = B.getElement(i, j);
            if(math::compareFloating(aux3, aux4) != 0)
            {
                res = false;
            }
        }
    }

    if(!res)
    {
        res = A.same(B,1e-12);
    }

    return res;
}

template <typename T, typename U>
bool operator != (const Matrix<T>& A, const Matrix<U>& B)
{
    return !(A == B);
}

}}} // END NAMESPACES
// =====================================================================================================================
