
#include <cassert>
#include <iostream>
#include <chrono>

#include <LibDegorasBase/Mathematics/types/matrix.h>

using dpbase::math::types::Matrix;

void testMatrix()
{
    Matrix<long double> matrix({{1,0},{0,1}});
    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testMatrix"<<std::endl<<std::endl;
    std::cout<<"Create a matrix from an initializer list"<<std::endl<<std::endl;
    std::cout<<"The initializer list is: {{1,0},{0,1}}"<<std::endl<<std::endl;
    std::cout<<"The result matrix is:"<<std::endl;
    std::cout<<matrix.toString()<<std::endl<<std::endl;

    std::cout<<"Create a matrix with n rows, m columns and all element same"<<std::endl<<std::endl;

    Matrix<long double> matrix1(5,7,1);
    std::cout<<"The matrix to create is a matrix of 1's with 5 row and 7 col"<<std::endl<<std::endl;
    std::cout<<"The result matrix is:"<<std::endl;
    std::cout<<matrix1.toString()<<std::endl<<std::endl;

    Matrix<long double> matrix2(3,1,0);
    std::cout<<"The matrix to create is a matrix of 0's with 3 row and 1 col"<<std::endl<<std::endl;
    std::cout<<"The result matrix is:"<<std::endl;
    std::cout<<matrix2.toString()<<std::endl<<std::endl;

    std::cout<<"Clear a matrix"<<std::endl<<std::endl;
    std::cout<<"The test matrix is:"<<std::endl;
    std::cout<<matrix.toString()<<std::endl<<std::endl;

    matrix.clear();

    std::cout<<"The result matrix of clear is:"<<std::endl;
    std::cout<<matrix.toString()<<std::endl<<std::endl;

    std::cout<<"Set the dimensions of a matrix and fill with the same element"<<std::endl<<std::endl;
    std::cout<<"The number of row is 4, the number of columns is 2 and the element is 1"<<std::endl;

    matrix.fill(4,2,1);

    std::cout<<"The result matrix is:"<<std::endl;
    std::cout<<matrix.toString()<<std::endl<<std::endl;

    std::cout<<"Fill a matrix with one element"<<std::endl<<std::endl;
    std::cout<<"The test matrix is:"<<std::endl;
    std::cout<<matrix.toString()<<std::endl<<std::endl;
    std::cout<<"The element to fill the matrix is 10"<<std::endl;

    matrix.fill(10);

    std::cout<<"The result matrix is:"<<std::endl;
    std::cout<<matrix.toString()<<std::endl<<std::endl;

    std::cout<<"---------------------------------"<<std::endl<<std::endl;
}

void testMatrixSize()
{
    Matrix<long double> matrix({{1,0},{0,1},{1,1},{0,0}});
    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testMatrixSize"<<std::endl<<std::endl;
    std::cout<<"The test matrix is:"<<std::endl;
    std::cout<<matrix.toString()<<std::endl<<std::endl;
    std::cout<<"The number of rows in this matrix is: "<<matrix.rowSize()<<std::endl<<std::endl;
    std::cout<<"The number of columns in this matrix is: "<<matrix.columnsSize()<<std::endl<<std::endl;
    std::cout<<"---------------------------------"<<std::endl<<std::endl;
}

void testMatrixSquare()
{
    Matrix<long double> matrix({{1,0},{0,1},{1,1},{0,0}});
    Matrix<long double> matrix1({{1,0},{0,1}});

    bool result = matrix.isSquare();
    bool result1 = matrix1.isSquare();

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testMatrixSquare"<<std::endl<<std::endl;
    std::cout<<"The test matrix is:"<<std::endl;
    std::cout<<matrix.toString()<<std::endl<<std::endl;
    std::cout<<"The matrix isn't square"<<std::endl<<std::endl;

    if(result)
    {
        std::cout<<"The function tell us that the matrix is square"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The function tell us that the matrix isn't square"<<std::endl<<std::endl;
    }

    std::cout<<"The test matrix is:"<<std::endl;
    std::cout<<matrix1.toString()<<std::endl<<std::endl;
    std::cout<<"The matrix is square"<<std::endl<<std::endl;

    if(result1)
    {
        std::cout<<"The function tell us that the matrix is square"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The function tell us that the matrix isn't square"<<std::endl<<std::endl;
    }
    std::cout<<"---------------------------------"<<std::endl<<std::endl;
}

void testMatrixIdentity()
{
    // Test identity property.
    Matrix<unsigned> identity2 = Matrix<unsigned>::I(2);
    Matrix<unsigned> identity3 = Matrix<unsigned>::I(3);
    Matrix<unsigned> identity4 = Matrix<unsigned>::I(4);
    Matrix<unsigned> identity5 = Matrix<unsigned>::I(5);
    Matrix<long double> notIdentity1(2,2,1);
    Matrix<long double> notIdentity2(2,1,1);
    notIdentity2(1,0) = 0;
    Matrix<long double> notIdentity3(1,2,1);
    notIdentity3(0,1) = 0;

    // Check the identity matrices.
    bool is_iden_2 = identity2.isIdentity();
    bool is_iden_3 = identity3.isIdentity();
    bool is_iden_4 = identity4.isIdentity();
    bool is_iden_5 = identity5.isIdentity();
    bool isnt_iden_1 = notIdentity1.isIdentity();
    bool isnt_iden_2 = notIdentity2.isIdentity();
    bool isnt_iden_3 = notIdentity3.isIdentity();

    // Output.
    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testMatrixIdentity"<<std::endl<<std::endl;
    std::cout<<"The test matrix is:"<<std::endl;
    std::cout<<identity2.toString()<<std::endl<<std::endl;
    std::cout<<"The matrix is the identity matrix of dimension 2"<<std::endl<<std::endl;

    if(is_iden_2)
    {
        std::cout<<"The function tell us that the matrix is an identity matrix"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The function tell us that the matrix isn't an identity matrix"<<std::endl<<std::endl;
    }

    std::cout<<"The test matrix is:"<<std::endl;
    std::cout<<identity3.toString()<<std::endl<<std::endl;
    std::cout<<"The matrix is the identity matrix of dimension 3"<<std::endl<<std::endl;

    if(is_iden_3)
    {
        std::cout<<"The function tell us that the matrix is an identity matrix"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The function tell us that the matrix isn't an identity matrix"<<std::endl<<std::endl;
    }

    std::cout<<"The test matrix is:"<<std::endl;
    std::cout<<identity4.toString()<<std::endl<<std::endl;
    std::cout<<"The matrix is the identity matrix of dimension 4"<<std::endl<<std::endl;

    if(is_iden_4)
    {
        std::cout<<"The function tell us that the matrix is an identity matrix"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The function tell us that the matrix isn't an identity matrix"<<std::endl<<std::endl;
    }

    std::cout<<"The test matrix is:"<<std::endl;
    std::cout<<identity5.toString()<<std::endl<<std::endl;
    std::cout<<"The matrix is the identity matrix of dimension 5"<<std::endl<<std::endl;

    if(is_iden_5)
    {
        std::cout<<"The function tell us that the matrix is an identity matrix"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The function tell us that the matrix isn't an identity matrix"<<std::endl<<std::endl;
    }

    std::cout<<"The test matrix is:"<<std::endl;
    std::cout<<notIdentity1.toString()<<std::endl<<std::endl;
    std::cout<<"The matrix isn't a identity matrix"<<std::endl<<std::endl;

    if(isnt_iden_1)
    {
        std::cout<<"The function tell us that the matrix is an identity matrix"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The function tell us that the matrix isn't an identity matrix"<<std::endl<<std::endl;
    }

    std::cout<<"The test matrix is:"<<std::endl;
    std::cout<<notIdentity2.toString()<<std::endl<<std::endl;
    std::cout<<"The matrix isn't a identity matrix"<<std::endl<<std::endl;

    if(isnt_iden_2)
    {
        std::cout<<"The function tell us that the matrix is an identity matrix"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The function tell us that the matrix isn't an identity matrix"<<std::endl<<std::endl;
    }

    std::cout<<"The test matrix is:"<<std::endl;
    std::cout<<notIdentity3.toString()<<std::endl<<std::endl;
    std::cout<<"The matrix isn't a identity matrix"<<std::endl<<std::endl;

    if(isnt_iden_3)
    {
        std::cout<<"The function tell us that the matrix is an identity matrix"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The function tell us that the matrix isn't an identity matrix"<<std::endl<<std::endl;
    }

    std::cout<<"---------------------------------"<<std::endl<<std::endl;

    // Asserts.
    assert(is_iden_2);
    assert(is_iden_3);
    assert(is_iden_4);
    assert(is_iden_5);
}

void testMatrixGet()
{
    Matrix<long double> matrix({{1,2},{3,4}});
    long double a = matrix.getElement(1,0);
    std::vector<long double> r = matrix.getRow(0);
    std::vector<long double> c = matrix.getColumn(1);

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testMatrixGet"<<std::endl<<std::endl;
    std::cout<<"The test matrix is:"<<std::endl;
    std::cout<<matrix.toString()<<std::endl;
    std::cout<<"The element in the second row and first column is "<<a<<std::endl;
    std::cout<<"The first row of the matrix is {"<<r[0]<<" "<<r[1]<<"}"<<std::endl;
    std::cout<<"The second column of the matrix is {"<<c[0]<<" "<<c[1]<<"}"<<std::endl;
    std::cout<<"Set the value of element in the second row and the first column to 0"<<a<<std::endl;
    matrix.setElement(1,0,0);
    std::cout<<"The result matrix is:"<<std::endl;
    std::cout<<matrix.toString()<<std::endl;
    std::cout<<"---------------------------------"<<std::endl<<std::endl;
}

void testMatrixSwap()
{
    Matrix<long double> matrix({{1,2},{3,4}});

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testMatrixSwap"<<std::endl<<std::endl;
    std::cout<<"The test matrix is:"<<std::endl;
    std::cout<<matrix.toString()<<std::endl;
    std::cout<<"Let's try to swap the firs and second rows"<<std::endl;
    bool swap1 = matrix.swapRows(0,1);
    if(swap1)
    {
        std::cout<<"Swap was successfully done"<<std::endl;
        std::cout<<"The result matrix is:"<<std::endl;
        std::cout<<matrix.toString()<<std::endl;
    }
    else
    {
        std::cout<<"Swap wasn't successfully done"<<std::endl;
        std::cout<<"The result matrix is:"<<std::endl;
        std::cout<<matrix.toString()<<std::endl;
    }

    std::cout<<"Let's try to swap the firs third rows, this swap should fail because the row index is incorrect"<<std::endl;
    bool swap2 = matrix.swapRows(0,2);
    if(swap2)
    {
        std::cout<<"Swap was successfully done"<<std::endl;
        std::cout<<"The result matrix is:"<<std::endl;
        std::cout<<matrix.toString()<<std::endl;
    }
    else
    {
        std::cout<<"Swap wasn't successfully done"<<std::endl;
        std::cout<<"The result matrix is:"<<std::endl;
        std::cout<<matrix.toString()<<std::endl;
    }

    std::cout<<"Let's try to swap the firs and second columns"<<std::endl;
    bool swap3 = matrix.swapColumns(0,1);
    if(swap3)
    {
        std::cout<<"Swap was successfully done"<<std::endl;
        std::cout<<"The result matrix is:"<<std::endl;
        std::cout<<matrix.toString()<<std::endl;
    }
    else
    {
        std::cout<<"Swap wasn't successfully done"<<std::endl;
        std::cout<<"The result matrix is:"<<std::endl;
        std::cout<<matrix.toString()<<std::endl;
    }

    std::cout<<"Let's try to swap the firs and third columns, this swap should fail because the column index is incorrect"<<std::endl;
    bool swap4 = matrix.swapColumns(0,2);
    if(swap4)
    {
        std::cout<<"Swap was successfully done"<<std::endl;
        std::cout<<"The result matrix is:"<<std::endl;
        std::cout<<matrix.toString()<<std::endl;
    }
    else
    {
        std::cout<<"Swap wasn't successfully done"<<std::endl;
        std::cout<<"The result matrix is:"<<std::endl;
        std::cout<<matrix.toString()<<std::endl;
    }
    std::cout<<"---------------------------------"<<std::endl<<std::endl;
}

void testMatrixTranspose()
{
    // Create a matrix for testing
    Matrix<long double> matrix({{1.1, 2.2, 3.3},{4.4, 5.5, 6.6},{7.7, 8.8, 9.9},{10, 11, 12}});

    // Transpose the matrix
    auto transposed = matrix.transpose();

    // Output.
    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testMatrixTranspose"<<std::endl<<std::endl;
    std::cout<<"The test matrix is:"<<std::endl;
    std::cout<<matrix.toString()<<std::endl<<std::endl;
    std::cout<<"The result matrix is:"<<std::endl;
    std::cout<<transposed.toString()<<std::endl;
    std::cout<<"---------------------------------"<<std::endl<<std::endl;

    // Check the dimensions
    assert(transposed.rowSize() == matrix.columnsSize());
    assert(transposed.columnsSize() == matrix.rowSize());

    // Check the values
    assert(transposed[0][0] == 1.1);
    assert(transposed[1][0] == 2.2);
    assert(transposed[2][0] == 3.3);
    assert(transposed[0][1] == 4.4);
    assert(transposed[1][1] == 5.5);
    assert(transposed[2][1] == 6.6);
    assert(transposed[0][2] == 7.7);
    assert(transposed[1][2] == 8.8);
    assert(transposed[2][2] == 9.9);
}

void testMatrixMultiplication()
{
    // Create matrices for testing
    Matrix<long double> mat1({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    Matrix<long double> mat2({{2, 4, 6}, {1, 3, 5}, {8, 9, 7}});
    Matrix<long double> mat3({{1L, 2L, 3L}, {4L, 5L, 6L}});
    Matrix<long double> mat4({{6L, 5L, 12L, 8L}, {14L, 13L, 26L, 16L}, {22L, 21L, 40L, 24.8L}});
    Matrix<long double> bad1({{1, 2}, {3, 4, 5, 6}});
    Matrix<long double> scalar_m({{2, 0, 0}, {0, 2, 0}, {0, 0, 2}});

    // Perform matrix multiplication with scalar
    Matrix<long double> result1 = mat1 * 2;
    Matrix<long double> expected1({{2, 4, 6}, {8, 10, 12}, {14, 16, 18}});

    // Perform matrix multiplication with another matrix
    Matrix<long double> result21 = mat1 * mat2;
    Matrix<long double> result22 = mat2 * mat1;
    Matrix<long double> expected21({{28, 37, 37}, {61, 85, 91}, {94, 133, 145}});
    Matrix<long double> expected22({{60,72,84}, {48,57,66}, {93,117,141}});

    // Perform matrix multiplication with scalar matrix
    Matrix<long double> result3 = mat1 * scalar_m;
    Matrix<long double> expected3({{2, 4, 6}, {8, 10, 12}, {14, 16, 18}});

    Matrix<long double> result4 = mat3 * mat4;
    Matrix<long double> expected4({{100L, 94L, 184L, 114.4L}, {226L, 211L, 418L, 260.8L}});

    // Invalid multiplication.
    Matrix<long double> result5 = bad1 * mat1;
    Matrix<long double> result6 = mat1 * mat3;

    // Output.
    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testMatrixMultiplication"<<std::endl<<std::endl;
    std::cout<<"Matrix multiplication with scalar"<<std::endl<<std::endl;
    std::cout<<"The test matrix is:"<<std::endl<<std::endl;
    std::cout<<mat1.toString()<<std::endl;
    std::cout<<"The expected matrix result to multiplicate the test matrix with the scalar 2 is:"<<std::endl<<std::endl;
    std::cout<<expected1.toString()<<std::endl;
    std::cout<<"The result of multiplicate the test matrix with the scalar 2 is:"<<std::endl<<std::endl;
    std::cout<<result1.toString()<<std::endl;

    std::cout<<"Matrix multiplication with another matrix"<<std::endl<<std::endl;
    std::cout<<"The test matrix is:"<<std::endl<<std::endl;
    std::cout<<mat1.toString()<<std::endl;
    std::cout<<"The another matrix is:"<<std::endl<<std::endl;
    std::cout<<mat2.toString()<<std::endl;
    std::cout<<"The expected matrix result to multiplicate the test matrix with the another matrix on the right is:"<<std::endl<<std::endl;
    std::cout<<expected21.toString()<<std::endl;
    std::cout<<"The result of multiplicate the test matrix with the another matrix on the right is:"<<std::endl<<std::endl;
    std::cout<<result21.toString()<<std::endl;
    std::cout<<"The expected matrix result to multiplicate the test matrix with the another matrix on the left is:"<<std::endl<<std::endl;
    std::cout<<expected22.toString()<<std::endl;
    std::cout<<"The result of multiplicate the test matrix with the another matrix on the left is:"<<std::endl<<std::endl;
    std::cout<<result22.toString()<<std::endl;

    std::cout<<"Matrix multiplication with scalar matrix"<<std::endl<<std::endl;
    std::cout<<"The test matrix is:"<<std::endl<<std::endl;
    std::cout<<mat1.toString()<<std::endl;
    std::cout<<"The scalar matrix is:"<<std::endl<<std::endl;
    std::cout<<scalar_m.toString()<<std::endl;
    std::cout<<"The expected matrix result to multiplicate the test matrix with the scalar matrix is:"<<std::endl<<std::endl;
    std::cout<<expected3.toString()<<std::endl;
    std::cout<<"The result of multiplicate the test matrix with the scalar matrix is:"<<std::endl<<std::endl;
    std::cout<<result3.toString()<<std::endl;

    std::cout<<"Matrix multiplication with another matrix with diferent dimensions"<<std::endl<<std::endl;
    std::cout<<"The test matrix is:"<<std::endl<<std::endl;
    std::cout<<mat3.toString()<<std::endl;
    std::cout<<"The another matrix is:"<<std::endl<<std::endl;
    std::cout<<mat4.toString()<<std::endl;
    std::cout<<"The expected matrix result to multiplicate the test matrix with the another matrix is:"<<std::endl<<std::endl;
    std::cout<<expected4.toString()<<std::endl;
    std::cout<<"The result of multiplicate the test matrix with the another matrix is:"<<std::endl<<std::endl;
    std::cout<<result4.toString()<<std::endl;

    std::cout<<"Invalid multiplication"<<std::endl<<std::endl;
    std::cout<<"The test matrix is:"<<std::endl<<std::endl;
    std::cout<<mat1.toString()<<std::endl;
    std::cout<<"The another matrix is:"<<std::endl<<std::endl;
    std::cout<<mat3.toString()<<std::endl;
    std::cout<<"The expected result is an empty matrix"<<std::endl<<std::endl;
    if(result6.isEmpty())
    {
        std::cout<<"The result matrix is an empty matrix"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The result matrix is:"<<std::endl<<std::endl;
        std::cout<<result5.toString()<<std::endl;
    }
    std::cout<<"---------------------------------"<<std::endl<<std::endl;

    // Asserts.
    assert(result1 == expected1);
    assert(result21 == expected21);
    assert(result3 == expected3);

    assert(result4 == expected4); // El error puede ser debido a que en la representacion binaria
    // el 114.4 es periodico y por tanto por mas precision que se le pida este numero no puede
    // ser representado por un numero con decimales finitos en binario por lo que C++ aproximara
    // dicho numero al mas cercano con la precision que tenga, la cosa es que esta aproximacion
    // normalmente se hace a la alta pero por como hace los calculos C++ cuando el numero aparece
    // al realizar operaciones este lo aproxima a la baja, la aproximacion es en binario por lo
    // que al representarlo en decimal el resultado en ambos casos sera igual.
    assert(result5.isEmpty());
}

void testMatrixInverse()
{
    //Matrix<long double> matrixp({{0,0,0,1},{1,0,0,0},{0,1,0,0},{0,0,1,0}});
    //Matrix<long double> matrixp({{6,3,0},{4,1,2},{5,6,1}});
    //Matrix<long double> matrixp({{0,6,3,3,5},{4,3,4,3,6},{2,0,5,2,7},{0,5,6,7,8},{5,6,7,0,9}});
    //Matrix<long double> matrixp({{2,8,1,9},{0,9,1,7},{7,1,8,2},{8,4,9,1}});
    //Matrix<long double> matrixp({{7,8,1,5},{6,2,4,9},{2,1,0,4},{0,0,1,0}});
    //Matrix<long double> matrixp({{1,2,3,9,1,3},{4,2,6,5,4,5},{7,8,9,8,5,9},{9,8,1,1,9,7},{6,5,4,5,6,4},{3,2,1,9,0,1}});
    //Matrix<long double> matrixp({{0,9,0,0},{1,0,2,0},{4,1,0,3},{1,2,0,0}});
    Matrix<long double> matrixp({{0,3,4,1},{0,0,1,2},{0,0,0,9},{2,0,1,0}});
    //Matrix<long double> matrixp({{2,0,1,0},{0,3,4,1},{0,0,1,2},{0,0,0,9}});


    Matrix<long double> matrix(3, 3, 0);

    matrix(0, 0) = 1;
    matrix(0, 1) = 2;
    matrix(0, 2) = 3;
    matrix(1, 0) = 0;
    matrix(1, 1) = 0;
    matrix(1, 2) = 1;
    matrix(2, 0) = 0;
    matrix(2, 1) = 4;
    matrix(2, 2) = 0;


    Matrix<long double> inverse(3, 3, 0);

    inverse(0, 0) = 1;
    inverse(0, 1) = -3;
    inverse(0, 2) = -0.5L;
    inverse(1, 0) = 0;
    inverse(1, 1) = 0;
    inverse(1, 2) = 0.25L;
    inverse(2, 0) = 0;
    inverse(2, 1) = 1;
    inverse(2, 2) = 0;


    Matrix<long double> calculated_inv = matrix.inverse();
    Matrix<long double> prueba = matrix*calculated_inv;

    Matrix<long double> calculated_invp = matrixp.inverse();
    Matrix<long double> pruebap = matrixp*calculated_invp;


    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testMatrixInverse"<<std::endl<<std::endl;
    std::cout<<"The test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrix.toString()<<std::endl;
    std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
    std::cout<<calculated_inv.toString()<<std::endl;
    std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
    std::cout<<prueba.toString()<<std::endl;
    std::cout<<"---------------------------------"<<std::endl<<std::endl;

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"The test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp.toString()<<std::endl;
    std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
    std::cout<<calculated_invp.toString()<<std::endl;
    std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
    std::cout<<pruebap.toString()<<std::endl;
    std::cout<<"---------------------------------"<<std::endl<<std::endl;

    std::cout<<">>>>> Look at various interesting case <<<<<"<<std::endl<<std::endl;

    // Trivial case, identity matrix
    Matrix<long double> matrix00 = Matrix<long double>::I(6);

    // No square matrix with less number of rows
    Matrix<long double> matrix01({{1,0,9},{9,4,2}});

    // No square matrix with less number of columns
    Matrix<long double> matrix02({{1,0},{9,4},{9,2}});

    // Matrix with null determinant
    Matrix<long double> matrix03({{1,2,3,4,5},{2,4,6,8,10},{8,4,6,2,3},{0,3,1,6,1},{8,5,1,1,0}});

    // Matrix with negative determinant
    Matrix<long double> matrix04({{2,3,4,0},{7,4,6,1},{1,0,3,1},{9,1,1,4}});

    // Matrix with positive determinant
    Matrix<long double> matrix05({{7,4,6,1},{2,3,4,0},{9,1,0,4},{5,9,1,0}});

    // Indefinite matrix
    Matrix<long double> matrix06({{5,1,7,4,2},{9,1,0,5,6},{3,6,9,4,1},{0,9,1,2,3},{0,0,1,3,4}});

    // Positive definite matrix
    Matrix<long double> matrix07({{1,1,1,2,2},{-1,2,0,3,1},{-6,0,10,4,1},{0,-2,-4,3,0},{0,0,0,4,15}});

    // Negative definite matrix
    Matrix<long double> matrix08({{-5,1,1,2,2},{-1,-2,0,3,1},{-6,0,-3,4,1},{0,-5,1,-5,5},{0,0,1,3,-14}});

    // Positive semidefinite matrix
    Matrix<long double> matrix09({{2,1,1,3,3},{1,5,2,3,6},{1,2,6,3,3},{3,3,3,9,6},{3,6,3,6,9}});

    // Negative semidefinite matrix

    Matrix<long double> matrix10({{-10,4,2,1,-3},{4,-10,3,2,-1},{2,3,-10,4,-1},{1,2,4,-10,-3},{-3,-1,-1,-3,-8}});

    // Upper triangle matrix
    Matrix<long double> matrix11({{1,0,5,7},{0,5,1,7},{0,0,3,4},{0,0,0,2}});

    // Lower triangle matrix
    Matrix<long double> matrix12({{1,0,0,0},{3,2,0,0},{1,4,5,0},{7,2,8,5}});

    // Diagonal matrix
    Matrix<long double> matrix13 = matrix00*0.624;

    // Hermitian matrix
    Matrix<long double> matrix14({{2,1,0},{1,2,1},{0,1,2}});

    // No hermitian matrix
    Matrix<long double> matrix15({{2,1,1},{1,2,1},{2,1,2}});

    // Matrix with a lot of 0
    Matrix<long double> matrix16(7,7,0);

    for(size_t i = 0;i < matrix16.rowSize();i++)
    {
        if(i==0)
        {
            matrix16(i,i) = 2;
            matrix16(i,i+1) = 1;
        }
        else if(i==matrix16.rowSize()-1)
        {
            matrix16(i,i-1) = 1;
            matrix16(i,i) = 2;
        }
        else
        {
            matrix16(i,i-1)=1;
            matrix16(i,i) = 2;
            matrix16(i,i+1) = 1;
        }
    }

    // Matrix without 0

    Matrix<long double> matrix17(7, 7, 0);

    for(size_t i = 0;i < matrix17.rowSize();i++)
    {
        for(size_t j = 0;j < matrix17.columnsSize();j++)
        {
            matrix17[i][j] = (i+1) + j;
        }
    }

    // Matrix 13x13

    Matrix<long double> matrix18({
        { 5.000,  0.100,  0.200,  0.300,  0.400,  0.500,  0.600,  0.700,  0.800,  0.900,  1.000,  1.100,  1.200},
        {-0.100,  6.000,  0.100,  0.200,  0.300,  0.400,  0.500,  0.600,  0.700,  0.800,  0.900,  1.000,  1.100},
        {-0.200, -0.100,  7.000,  0.100,  0.200,  0.300,  0.400,  0.500,  0.600,  0.700,  0.800,  0.900,  1.000},
        {-0.300, -0.200, -0.100,  8.000,  0.100,  0.200,  0.300,  0.400,  0.500,  0.600,  0.700,  0.800,  0.900},
        {-0.400, -0.300, -0.200, -0.100,  9.000,  0.100,  0.200,  0.300,  0.400,  0.500,  0.600,  0.700,  0.800},
        {-0.500, -0.400, -0.300, -0.200, -0.100, 10.000,  0.100,  0.200,  0.300,  0.400,  0.500,  0.600,  0.700},
        {-0.600, -0.500, -0.400, -0.300, -0.200, -0.100, 11.000,  0.100,  0.200,  0.300,  0.400,  0.500,  0.600},
        {-0.700, -0.600, -0.500, -0.400, -0.300, -0.200, -0.100, 12.000,  0.100,  0.200,  0.300,  0.400,  0.500},
        {-0.800, -0.700, -0.600, -0.500, -0.400, -0.300, -0.200, -0.100, 13.000,  0.100,  0.200,  0.300,  0.400},
        {-0.900, -0.800, -0.700, -0.600, -0.500, -0.400, -0.300, -0.200, -0.100, 14.000,  0.100,  0.200,  0.300},
        {-1.000, -0.900, -0.800, -0.700, -0.600, -0.500, -0.400, -0.300, -0.200, -0.100, 15.000,  0.100,  0.200},
        {-1.100, -1.000, -0.900, -0.800, -0.700, -0.600, -0.500, -0.400, -0.300, -0.200, -0.100, 16.000,  0.100},
        {-1.200, -1.100, -1.000, -0.900, -0.800, -0.700, -0.600, -0.500, -0.400, -0.300, -0.200, -0.100, 17.000}
    });

    std::cout<<"Trivial case, identity matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix00.toString()<<std::endl;
    Matrix<long double> R00 = matrix00.inverse();

    if(R00.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R00.toString()<<std::endl;

        Matrix<long double> Check00 = matrix00 * R00;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check00.toString()<<std::endl;
    }

    std::cout<<"No square matrix with less number of rows"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix01.toString()<<std::endl;
    Matrix<long double> R01 = matrix01.inverse();

    std::cout<<"This matrix doesn't have inverse for these reason the calculated matrix must be a empty matrix"<<std::endl<<std::endl;

    if(R01.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R01.toString()<<std::endl;

        Matrix<long double> Check01 = matrix01 * R01;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check01.toString()<<std::endl;
    }

    std::cout<<"No square matrix with less number of columns"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix02.toString()<<std::endl;
    Matrix<long double> R02 = matrix02.inverse();

    std::cout<<"This matrix doesn't have inverse for these reason the calculated matrix must be a empty matrix"<<std::endl<<std::endl;

    if(R02.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R02.toString()<<std::endl;

        Matrix<long double> Check02 = matrix02 * R02;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check02.toString()<<std::endl;
    }

    std::cout<<"Matrix with null determinant"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix03.toString()<<std::endl;
    Matrix<long double> R03 = matrix03.inverse();

    std::cout<<"This matrix doesn't have inverse for these reason the calculated matrix must be a empty matrix"<<std::endl<<std::endl;

    if(R03.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R03.toString()<<std::endl;

        Matrix<long double> Check03 = matrix03 * R03;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check03.toString()<<std::endl;
    }

    std::cout<<"Matrix with negative determinant"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix04.toString()<<std::endl;
    Matrix<long double> R04 = matrix04.inverse();

    if(R04.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R04.toString()<<std::endl;

        Matrix<long double> Check04 = matrix04 * R04;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check04.toString()<<std::endl;
    }

    std::cout<<"Matrix with positive determinant"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix05.toString()<<std::endl;
    Matrix<long double> R05 = matrix05.inverse();

    if(R05.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R05.toString()<<std::endl;

        Matrix<long double> Check05 = matrix05 * R05;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check05.toString()<<std::endl;
    }

    std::cout<<"Indefinite matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix06.toString()<<std::endl;
    Matrix<long double> R06 = matrix06.inverse();

    if(R06.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R06.toString()<<std::endl;

        Matrix<long double> Check06 = matrix06 * R06;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check06.toString()<<std::endl;
    }

    std::cout<<"Positive definite matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix07.toString()<<std::endl;
    Matrix<long double> R07 = matrix07.inverse();

    if(R07.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R07.toString()<<std::endl;

        Matrix<long double> Check07 = matrix07 * R07;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check07.toString()<<std::endl;
    }

    std::cout<<"Negative definite matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix08.toString()<<std::endl;
    Matrix<long double> R08 = matrix08.inverse();

    if(R08.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R08.toString()<<std::endl;

        Matrix<long double> Check08 = matrix08 * R08;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check08.toString()<<std::endl;
    }

    std::cout<<"Positive semidefinite matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix09.toString()<<std::endl;
    Matrix<long double> R09 = matrix09.inverse();

    std::cout<<"This matrix doesn't have inverse for these reason the calculated matrix must be a empty matrix"<<std::endl<<std::endl;

    if(R09.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R09.toString()<<std::endl;

        Matrix<long double> Check09 = matrix09 * R09;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check09.toString()<<std::endl;
    }

    std::cout<<"Negative semidefinite matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix10.toString()<<std::endl;
    Matrix<long double> R10 = matrix10.inverse();

    std::cout<<"This matrix doesn't have inverse for these reason the calculated matrix must be a empty matrix"<<std::endl<<std::endl;

    if(R10.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R10.toString()<<std::endl;

        Matrix<long double> Check10 = matrix10 * R10;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check10.toString()<<std::endl;
    }

    std::cout<<"Upper triangle matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix11.toString()<<std::endl;
    Matrix<long double> R11 = matrix11.inverse();

    if(R11.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R11.toString()<<std::endl;

        Matrix<long double> Check11 = matrix11 * R11;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check11.toString()<<std::endl;
    }

    std::cout<<"Lower triangle matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix12.toString()<<std::endl;
    Matrix<long double> R12 = matrix12.inverse();

    if(R12.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R12.toString()<<std::endl;

        Matrix<long double> Check12 = matrix12 * R12;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check12.toString()<<std::endl;
    }

    std::cout<<"Diagonal matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix13.toString()<<std::endl;
    Matrix<long double> R13 = matrix13.inverse();

    if(R13.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R13.toString()<<std::endl;

        Matrix<long double> Check13 = matrix13 * R13;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check13.toString()<<std::endl;
    }

    std::cout<<"Hermitian matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix14.toString()<<std::endl;
    Matrix<long double> R14 = matrix14.inverse();

    if(R14.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R14.toString()<<std::endl;

        Matrix<long double> Check14 = matrix14 * R14;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check14.toString()<<std::endl;
    }

    std::cout<<"No hermitian matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix15.toString()<<std::endl;
    Matrix<long double> R15 = matrix15.inverse();

    if(R15.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R15.toString()<<std::endl;

        Matrix<long double> Check15 = matrix15 * R15;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check15.toString()<<std::endl;
    }

    std::cout<<"Matrix with a lot of 0"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix16.toString()<<std::endl;
    Matrix<long double> R16 = matrix16.inverse();

    if(R16.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R16.toString()<<std::endl;

        Matrix<long double> Check16 = matrix16 * R16;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check16.toString()<<std::endl;
    }

    std::cout<<"Matrix without 0"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix17.toString()<<std::endl;
    Matrix<long double> R17 = matrix17.inverse();

    std::cout<<"This matrix doesn't have inverse for these reason the calculated matrix must be a empty matrix"<<std::endl<<std::endl;

    if(R17.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R17.toString()<<std::endl;

        Matrix<long double> Check17 = matrix17 * R17;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check17.toString()<<std::endl;
    }

    std::cout<<"Matrix 13x13"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix18.toString()<<std::endl;
    Matrix<long double> R18 = matrix18.inverse();

    if(R18.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R18.toString()<<std::endl;

        Matrix<long double> Check18 = matrix18 * R18;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check18.toString()<<std::endl;
    }

    std::cout<<"---------------------------------"<<std::endl;

    assert(inverse == calculated_inv);
}

void testMatrixInverseCholesky()
{
    Matrix<long double> matrixp({{ 8.52915277829011e+23 , 0.0 , -6.553316820534138e+20 , -1.1191920332739584e+24 , 0.0 , 6.047261902484436e+21 , 1.4298591388520803e+25 , 0.0 , -5.952329686495167e+21 , 0.0 , 0.0 , 0.0 , 0.0 },
        { 0.0 , 1.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 },
        { -6.553316820534138e+20 , 0.0 , 5.559473790783668e+18 , 6.047261902484436e+21 , 0.0 , -2.0071008415894426e+18 , -5.952329686495167e+21 , 0.0 , 4.451749170326944e+19 , 0.0 , 0.0 , 0.0 , 0.0 },
        { -1.1191920332739584e+24 , 0.0 , 6.047261902484436e+21 , 1.4298592135016802e+25 , 0.0 , -5.952329686495167e+21 , -2.1124617214319102e+25 , 0.0 , 1.0870042564384951e+23 , 0.0 , 0.0 , 0.0 , 0.0 },
        { 0.0 , 0.0 , 0.0 , 0.0 , 1.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 },
        { 6.047261902484436e+21 , 0.0 , -2.0071008415894426e+18 , -5.952329686495167e+21 , 0.0 , 4.452749170326944e+19 , 1.0870042564384951e+23 , 0.0 , -2.733124374363557e+19 , 0.0 , 0.0 , 0.0 , 0.0 },
        { 1.4298591388520803e+25 , 0.0 , -5.952329686495167e+21 , -2.1124617214319102e+25 , 0.0 , 1.0870042564384951e+23 , 3.3339331395306236e+26 , 0.0 , -1.2404078986763186e+23 , 0.0 , 0.0 , 0.0 , 0.0 },
        { 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 1.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 },
        { -5.952329686495167e+21 , 0.0 , 4.451749170326944e+19 , 1.0870042564384951e+23 , 0.0 , -2.733124374363557e+19 , -1.2404078986763186e+23 , 0.0 , 8.37386242176923e+20 , 0.0 , 0.0 , 0.0 , 0.0 },
        { 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 1.0 , 0.0 , 0.0 , 0.0 },
        { 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 1.0 , 0.0 , 0.0 },
        { 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 1.0 , 0.0 },
        { 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 1.0 }});

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testMatrixInverseCholesky"<<std::endl<<std::endl;
    std::cout<<"The test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp.toString()<<std::endl;


    auto start = std::chrono::steady_clock::now();

    std::pair<int,Matrix<long double>> Cholesky = matrixp.invCholesky();

    auto stop = std::chrono::steady_clock::now();

    auto t_time = stop-start;
    auto total_us = std::chrono::duration_cast<std::chrono::microseconds>(t_time).count();

    std::cout << "Total time: " << total_us << " us" << std::endl;

    Matrix<long double> resultado = Cholesky.second;
    std::cout<<"Error: "<<Cholesky.first<<std::endl;

    std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
    std::cout<<resultado.toString()<<std::endl;

    Matrix<long double> Mt = matrixp * resultado;

    std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
    std::cout<<Mt.toString()<<std::endl;

    std::cout<<">>>>> Look at various interesting case <<<<<"<<std::endl<<std::endl;

    // Trivial case, identity matrix
    Matrix<long double> matrix00 = Matrix<long double>::I(6);

    // No square matrix with less number of rows
    Matrix<long double> matrix01({{1,0,9},{9,4,2}});

    // No square matrix with less number of columns
    Matrix<long double> matrix02({{1,0},{9,4},{9,2}});

    // Matrix with null determinant
    Matrix<long double> matrix03({{1,2,3,4,5},{2,4,6,8,10},{8,4,6,2,3},{0,3,1,6,1},{8,5,1,1,0}});

    // Matrix with negative determinant
    Matrix<long double> matrix04({{2,3,4,0},{7,4,6,1},{1,0,3,1},{9,1,1,4}});

    // Matrix with positive determinant
    Matrix<long double> matrix05({{7,4,6,1},{2,3,4,0},{9,1,0,4},{5,9,1,0}});

    // Indefinite matrix
    Matrix<long double> matrix06({{5,1,7,4,2},{9,1,0,5,6},{3,6,9,4,1},{0,9,1,2,3},{0,0,1,3,4}});

    // Positive definite matrix
    Matrix<long double> matrix07({{1,1,1,2,2},{-1,2,0,3,1},{-6,0,10,4,1},{0,-2,-4,3,0},{0,0,0,4,15}});

    // Negative definite matrix
    Matrix<long double> matrix08({{-5,1,1,2,2},{-1,-2,0,3,1},{-6,0,-3,4,1},{0,-5,1,-5,5},{0,0,1,3,-14}});

    // Positive semidefinite matrix
    Matrix<long double> matrix09({{2,1,1,3,3},{1,5,2,3,6},{1,2,6,3,3},{3,3,3,9,6},{3,6,3,6,9}});

    // Negative semidefinite matrix

    Matrix<long double> matrix10({{-10,4,2,1,-3},{4,-10,3,2,-1},{2,3,-10,4,-1},{1,2,4,-10,-3},{-3,-1,-1,-3,-8}});

    // Upper triangle matrix
    Matrix<long double> matrix11({{1,0,5,7},{0,5,1,7},{0,0,3,4},{0,0,0,2}});

    // Lower triangle matrix
    Matrix<long double> matrix12({{1,0,0,0},{3,2,0,0},{1,4,5,0},{7,2,8,5}});

    // Diagonal matrix
    Matrix<long double> matrix13 = matrix00*0.624;

    // Hermitian matrix
    Matrix<long double> matrix14({{2,1,0},{1,2,1},{0,1,2}});

    // No hermitian matrix
    Matrix<long double> matrix15({{2,1,1},{1,2,1},{2,1,2}});

    // Matrix with a lot of 0
    Matrix<long double> matrix16(7,7,0);

    for(size_t i = 0;i < matrix16.rowSize();i++)
    {
        if(i==0)
        {
            matrix16(i,i) = 2;
            matrix16(i,i+1) = 1;
        }
        else if(i==matrix16.rowSize()-1)
        {
            matrix16(i,i-1) = 1;
            matrix16(i,i) = 2;
        }
        else
        {
            matrix16(i,i-1)=1;
            matrix16(i,i) = 2;
            matrix16(i,i+1) = 1;
        }
    }

    // Matrix without 0

    Matrix<long double> matrix17(7, 7, 0);

    for(size_t i = 0;i < matrix17.rowSize();i++)
    {
        for(size_t j = 0;j < matrix17.columnsSize();j++)
        {
            matrix17[i][j] = (i+1) + j;
        }
    }

    // Matrix 13x13

    Matrix<long double> matrix18({
        { 5.000,  0.100,  0.200,  0.300,  0.400,  0.500,  0.600,  0.700,  0.800,  0.900,  1.000,  1.100,  1.200},
        {-0.100,  6.000,  0.100,  0.200,  0.300,  0.400,  0.500,  0.600,  0.700,  0.800,  0.900,  1.000,  1.100},
        {-0.200, -0.100,  7.000,  0.100,  0.200,  0.300,  0.400,  0.500,  0.600,  0.700,  0.800,  0.900,  1.000},
        {-0.300, -0.200, -0.100,  8.000,  0.100,  0.200,  0.300,  0.400,  0.500,  0.600,  0.700,  0.800,  0.900},
        {-0.400, -0.300, -0.200, -0.100,  9.000,  0.100,  0.200,  0.300,  0.400,  0.500,  0.600,  0.700,  0.800},
        {-0.500, -0.400, -0.300, -0.200, -0.100, 10.000,  0.100,  0.200,  0.300,  0.400,  0.500,  0.600,  0.700},
        {-0.600, -0.500, -0.400, -0.300, -0.200, -0.100, 11.000,  0.100,  0.200,  0.300,  0.400,  0.500,  0.600},
        {-0.700, -0.600, -0.500, -0.400, -0.300, -0.200, -0.100, 12.000,  0.100,  0.200,  0.300,  0.400,  0.500},
        {-0.800, -0.700, -0.600, -0.500, -0.400, -0.300, -0.200, -0.100, 13.000,  0.100,  0.200,  0.300,  0.400},
        {-0.900, -0.800, -0.700, -0.600, -0.500, -0.400, -0.300, -0.200, -0.100, 14.000,  0.100,  0.200,  0.300},
        {-1.000, -0.900, -0.800, -0.700, -0.600, -0.500, -0.400, -0.300, -0.200, -0.100, 15.000,  0.100,  0.200},
        {-1.100, -1.000, -0.900, -0.800, -0.700, -0.600, -0.500, -0.400, -0.300, -0.200, -0.100, 16.000,  0.100},
        {-1.200, -1.100, -1.000, -0.900, -0.800, -0.700, -0.600, -0.500, -0.400, -0.300, -0.200, -0.100, 17.000}
    });

    std::cout<<"Trivial case, identity matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix00.toString()<<std::endl;
    Matrix<long double> R00 = matrix00.invCholesky().second;

    if(R00.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R00.toString()<<std::endl;

        Matrix<long double> Check00 = matrix00 * R00;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check00.toString()<<std::endl;
    }

    std::cout<<"No square matrix with less number of rows"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix01.toString()<<std::endl;
    Matrix<long double> R01 = matrix01.invCholesky().second;

    std::cout<<"This matrix doesn't have inverse for these reason the calculated matrix must be a empty matrix"<<std::endl<<std::endl;

    if(R01.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R01.toString()<<std::endl;

        Matrix<long double> Check01 = matrix01 * R01;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check01.toString()<<std::endl;
    }

    std::cout<<"No square matrix with less number of columns"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix02.toString()<<std::endl;
    Matrix<long double> R02 = matrix02.invCholesky().second;

    std::cout<<"This matrix doesn't have inverse for these reason the calculated matrix must be a empty matrix"<<std::endl<<std::endl;

    if(R02.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R02.toString()<<std::endl;

        Matrix<long double> Check02 = matrix02 * R02;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check02.toString()<<std::endl;
    }

    std::cout<<"Matrix with null determinant"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix03.toString()<<std::endl;
    Matrix<long double> R03 = matrix03.invCholesky().second;

    std::cout<<"This matrix doesn't have inverse for these reason the calculated matrix must be a empty matrix"<<std::endl<<std::endl;

    if(R03.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R03.toString()<<std::endl;

        Matrix<long double> Check03 = matrix03 * R03;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check03.toString()<<std::endl;
    }

    std::cout<<"Matrix with negative determinant"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix04.toString()<<std::endl;
    Matrix<long double> R04 = matrix04.invCholesky().second;

    std::cout<<"The matrix isn't Hermitian for this reason the calculated matrix must be an empty matrix."<<std::endl<<std::endl;

    if(R04.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R04.toString()<<std::endl;

        Matrix<long double> Check04 = matrix04 * R04;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check04.toString()<<std::endl;
    }

    std::cout<<"Matrix with positive determinant"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix05.toString()<<std::endl;
    Matrix<long double> R05 = matrix05.invCholesky().second;

    std::cout<<"The matrix isn't Hermitian for this reason the calculated matrix must be an empty matrix."<<std::endl<<std::endl;

    if(R05.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R05.toString()<<std::endl;

        Matrix<long double> Check05 = matrix05 * R05;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check05.toString()<<std::endl;
    }

    std::cout<<"Indefinite matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix06.toString()<<std::endl;
    Matrix<long double> R06 = matrix06.invCholesky().second;

    std::cout<<"The matrix isn't Hermitian for this reason the calculated matrix must be an empty matrix."<<std::endl<<std::endl;

    if(R06.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R06.toString()<<std::endl;

        Matrix<long double> Check06 = matrix06 * R06;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check06.toString()<<std::endl;
    }

    std::cout<<"Positive definite matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix07.toString()<<std::endl;
    Matrix<long double> R07 = matrix07.invCholesky().second;

    std::cout<<"The matrix isn't Hermitian for this reason the calculated matrix must be an empty matrix."<<std::endl<<std::endl;

    if(R07.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R07.toString()<<std::endl;

        Matrix<long double> Check07 = matrix07 * R07;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check07.toString()<<std::endl;
    }

    std::cout<<"Negative definite matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix08.toString()<<std::endl;
    Matrix<long double> R08 = matrix08.invCholesky().second;

    std::cout<<"The matrix isn't Hermitian for this reason the calculated matrix must be an empty matrix."<<std::endl<<std::endl;

    if(R08.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R08.toString()<<std::endl;

        Matrix<long double> Check08 = matrix08 * R08;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check08.toString()<<std::endl;
    }

    std::cout<<"Positive semidefinite matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix09.toString()<<std::endl;
    Matrix<long double> R09 = matrix09.invCholesky().second;

    std::cout<<"This matrix doesn't have inverse for these reason the calculated matrix must be a empty matrix"<<std::endl<<std::endl;

    if(R09.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R09.toString()<<std::endl;

        Matrix<long double> Check09 = matrix09 * R09;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check09.toString()<<std::endl;
    }

    std::cout<<"Negative semidefinite matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix10.toString()<<std::endl;
    Matrix<long double> R10 = matrix10.invCholesky().second;

    std::cout<<"This matrix doesn't have inverse for these reason the calculated matrix must be a empty matrix"<<std::endl<<std::endl;

    if(R10.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R10.toString()<<std::endl;

        Matrix<long double> Check10 = matrix10 * R10;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check10.toString()<<std::endl;
    }

    std::cout<<"Upper triangle matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix11.toString()<<std::endl;
    Matrix<long double> R11 = matrix11.invCholesky().second;

    std::cout<<"The matrix isn't Hermitian for this reason the calculated matrix must be an empty matrix."<<std::endl<<std::endl;

    if(R11.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R11.toString()<<std::endl;

        Matrix<long double> Check11 = matrix11 * R11;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check11.toString()<<std::endl;
    }

    std::cout<<"Lower triangle matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix12.toString()<<std::endl;
    Matrix<long double> R12 = matrix12.invCholesky().second;

    std::cout<<"The matrix isn't Hermitian for this reason the calculated matrix must be an empty matrix."<<std::endl<<std::endl;

    if(R12.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R12.toString()<<std::endl;

        Matrix<long double> Check12 = matrix12 * R12;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check12.toString()<<std::endl;
    }

    std::cout<<"Diagonal matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix13.toString()<<std::endl;
    Matrix<long double> R13 = matrix13.invCholesky().second;

    if(R13.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R13.toString()<<std::endl;

        Matrix<long double> Check13 = matrix13 * R13;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check13.toString()<<std::endl;
    }

    std::cout<<"Hermitian matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix14.toString()<<std::endl;
    Matrix<long double> R14 = matrix14.invCholesky().second;

    if(R14.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R14.toString()<<std::endl;

        Matrix<long double> Check14 = matrix14 * R14;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check14.toString()<<std::endl;
    }

    std::cout<<"No hermitian matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix15.toString()<<std::endl;
    Matrix<long double> R15 = matrix15.invCholesky().second;

    std::cout<<"The matrix isn't Hermitian for this reason the calculated matrix must be an empty matrix."<<std::endl<<std::endl;

    if(R15.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R15.toString()<<std::endl;

        Matrix<long double> Check15 = matrix15 * R15;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check15.toString()<<std::endl;
    }

    std::cout<<"Matrix with a lot of 0"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix16.toString()<<std::endl;
    Matrix<long double> R16 = matrix16.invCholesky().second;

    if(R16.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R16.toString()<<std::endl;

        Matrix<long double> Check16 = matrix16 * R16;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check16.toString()<<std::endl;
    }

    std::cout<<"Matrix without 0"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix17.toString()<<std::endl;
    Matrix<long double> R17 = matrix17.invCholesky().second;

    std::cout<<"This matrix doesn't have inverse for these reason the calculated matrix must be a empty matrix"<<std::endl<<std::endl;

    if(R17.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R17.toString()<<std::endl;

        Matrix<long double> Check17 = matrix17 * R17;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check17.toString()<<std::endl;
    }

    std::cout<<"Matrix 13x13"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix18.toString()<<std::endl;
    Matrix<long double> R18 = matrix18.invCholesky().second;

    std::cout<<"The matrix isn't Hermitian for this reason the calculated matrix must be an empty matrix."<<std::endl<<std::endl;

    if(R18.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R18.toString()<<std::endl;

        Matrix<long double> Check18 = matrix18 * R18;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check18.toString()<<std::endl;
    }

    std::cout<<"---------------------------------"<<std::endl;

}

void testMatrixEliminate()
{
    Matrix<long double> matrixp({{4,3,2,1},{3,3,2,1},{2,2,2,1},{1,1,1,1}});


    Matrix<long double> resultado1 = matrixp.eliminateRow(0);
    Matrix<long double> resultado2 = matrixp.eliminateRow(1);
    Matrix<long double> resultado3 = matrixp.eliminateRow(2);
    Matrix<long double> resultado4 = matrixp.eliminateRow(3);

    Matrix<long double> resultado11 = matrixp.eliminateCol(0);
    Matrix<long double> resultado21 = matrixp.eliminateCol(1);
    Matrix<long double> resultado31 = matrixp.eliminateCol(2);
    Matrix<long double> resultado41 = matrixp.eliminateCol(3);

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testMatrixEliminate"<<std::endl<<std::endl;
    std::cout<<"The test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp.toString()<<std::endl;
    std::cout<<"The result of eliminate the row 0 in test matrix is:"<<std::endl<<std::endl;
    std::cout<<resultado1.toString()<<std::endl;
    std::cout<<"The result of eliminate the row 1 in test matrix is:"<<std::endl<<std::endl;
    std::cout<<resultado2.toString()<<std::endl;
    std::cout<<"The result of eliminate the row 2 in test matrix is:"<<std::endl<<std::endl;
    std::cout<<resultado3.toString()<<std::endl;
    std::cout<<"The result of eliminate the row 3 in test matrix is:"<<std::endl<<std::endl;
    std::cout<<resultado4.toString()<<std::endl;
    std::cout<<"Let's try to eliminate an incorrect row"<<std::endl<<std::endl;
    Matrix<long double> resultadoInc = matrixp.eliminateRow(4);
    std::cout<<resultadoInc.toString()<<std::endl;

    std::cout<<"The result of eliminate the column 0 in test matrix is:"<<std::endl<<std::endl;
    std::cout<<resultado11.toString()<<std::endl;
    std::cout<<"The result of eliminate the column 1 in test matrix is:"<<std::endl<<std::endl;
    std::cout<<resultado21.toString()<<std::endl;
    std::cout<<"The result of eliminate the column 2 in test matrix is:"<<std::endl<<std::endl;
    std::cout<<resultado31.toString()<<std::endl;
    std::cout<<"The result of eliminate the column 3 in test matrix is:"<<std::endl<<std::endl;
    std::cout<<resultado41.toString()<<std::endl;
    std::cout<<"Let's try to eliminate an incorrect column"<<std::endl<<std::endl;
    Matrix<long double> resultadoInc1 = matrixp.eliminateCol(4);
    std::cout<<resultadoInc1.toString()<<std::endl;
    std::cout<<"---------------------------------"<<std::endl;
}

void testMatrixPivot()
{
    Matrix<long double> matrixp({{4,3,2,1},{3,3,2,1},{2,0,2,0},{1,1,1,1}});

    Matrix<long double> matrixp1({{0,3,2,1},{3,0,2,1},{0,2,0,1},{1,1,1,1}});

    std::pair<std::size_t,std::size_t> Pivot = matrixp.pivotRow();
    std::size_t index = Pivot.first;
    std::size_t n_zeros = Pivot.second;

    std::pair<std::size_t,std::size_t> Pivot1 = matrixp1.pivotCol();
    std::size_t index1 = Pivot1.first;
    std::size_t n_zeros1 = Pivot1.second;

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testMatrixPivot"<<std::endl<<std::endl;
    std::cout<<"The test matirx is:"<<std::endl<<std::endl;
    std::cout<<matrixp.toString()<<std::endl;
    std::cout<<"The optimal row index is: "<<index<<std::endl<<std::endl;
    std::cout<<"This row have "<<n_zeros<<" zeros"<<std::endl<<std::endl;

    std::cout<<"The test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp1.toString()<<std::endl;
    std::cout<<"The optimal column index is: "<<index1<<std::endl<<std::endl;
    std::cout<<"This column have "<<n_zeros1<<" zeros"<<std::endl<<std::endl;
    std::cout<<"---------------------------------"<<std::endl;
}

void testMatrixAdjoint()
{
    Matrix<long double> matrixp({{4,3,2,1},{3,3,2,1},{2,2,2,1},{1,1,1,1}});


    Matrix<long double> resultado1 = matrixp.adjoint(0,0);
    Matrix<long double> resultado2 = matrixp.adjoint(3,1);
    Matrix<long double> resultado3 = matrixp.adjoint(2,2);
    Matrix<long double> resultado4 = matrixp.adjoint(1,3);

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testMatrixAdjoint"<<std::endl<<std::endl;
    std::cout<<"The test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp.toString()<<std::endl;
    std::cout<<"The adjoint matrix of A[0][0] is:"<<std::endl<<std::endl;
    std::cout<<resultado1.toString()<<std::endl;
    std::cout<<"The adjoint matrix of A[3][1] is:"<<std::endl<<std::endl;
    std::cout<<resultado2.toString()<<std::endl;
    std::cout<<"The adjoint matrix of A[2][2] is:"<<std::endl<<std::endl;
    std::cout<<resultado3.toString()<<std::endl;
    std::cout<<"The adjoint matrix of A[1][3] is:"<<std::endl<<std::endl;
    std::cout<<resultado4.toString()<<std::endl;
    std::cout<<"Let's try to calculated the adjoint matrix of invalid element of the row, A[1][4]:"<<std::endl<<std::endl;
    Matrix<long double> resultado5 = matrixp.adjoint(1,4);
    std::cout<<"The result matrix is:"<<std::endl<<std::endl;
    std::cout<<resultado5.toString()<<std::endl;
    std::cout<<"Let's try to calculated the adjoint matrix of invalid element of the column, A[4][1]:"<<std::endl<<std::endl;
    Matrix<long double> resultado6 = matrixp.adjoint(4,1);
    std::cout<<"The result matrix is:"<<std::endl<<std::endl;
    std::cout<<resultado6.toString()<<std::endl;
    std::cout<<"---------------------------------"<<std::endl;
}

void testMatrixDeterminant()
{
    Matrix<long double> matrixp0({{4,3,2,1},{3,3,2,1},{2,2,2,1},{1,1,1,1}});
    Matrix<long double> matrixp1({{0,0,0,1},{1,0,0,0},{0,1,0,0},{0,0,1,0}});
    Matrix<long double> matrixp2({{6,3,0},{4,1,2},{5,6,1}});
    Matrix<long double> matrixp3({{0,6,3,3,5},{4,3,4,3,6},{2,0,5,2,7},{0,5,6,7,8},{5,6,7,0,9}});
    Matrix<long double> matrixp4({{2,8,1,9},{0,9,1,7},{7,1,8,2},{8,4,9,1}});
    Matrix<long double> matrixp5({{7,8,1,5},{6,2,4,9},{2,1,0,4},{0,0,1,0}});
    Matrix<long double> matrixp6({{1,2,3,9,1,3},{4,2,6,5,4,5},{7,8,9,8,5,9},{9,8,1,1,9,7},{6,5,4,5,6,4},{3,2,1,9,0,1}});
    Matrix<long double> matrixp7({{0,9,0,0},{1,0,2,0},{4,1,0,3},{1,2,0,0}});
    Matrix<long double> matrixp8({{0,3,4,1},{0,0,1,2},{0,0,0,9},{2,0,1,0}});
    Matrix<long double> matrixp9({{2,0,1,0},{0,3,4,1},{0,0,1,2},{0,0,0,9}});

    long double resultado0 = matrixp0.determinant();
    long double resultado1 = matrixp1.determinant();
    long double resultado2 = matrixp2.determinant();
    long double resultado3 = matrixp3.determinant();
    long double resultado4 = matrixp4.determinant();
    long double resultado5 = matrixp5.determinant();
    long double resultado6 = matrixp6.determinant();
    long double resultado7 = matrixp7.determinant();
    long double resultado8 = matrixp8.determinant();
    long double resultado9 = matrixp9.determinant();

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testMatrixDeterminant"<<std::endl<<std::endl;
    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp0.toString()<<std::endl;
    std::cout<<"The determinant is: 1"<<std::endl<<std::endl;
    std::cout<<"The result of determinant function is: "<< resultado0 <<std::endl<<std::endl;

    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp1.toString()<<std::endl;
    std::cout<<"The determinant is: -1"<<std::endl<<std::endl;
    std::cout<<"The result of determinant function is: "<< resultado1 <<std::endl<<std::endl;

    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp2.toString()<<std::endl;
    std::cout<<"The determinant is: -48"<<std::endl<<std::endl;
    std::cout<<"The result of determinant function is: "<< resultado2 <<std::endl<<std::endl;

    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp3.toString()<<std::endl;
    std::cout<<"The determinant is: 976"<<std::endl<<std::endl;
    std::cout<<"The result of determinant function is: "<< resultado3 <<std::endl<<std::endl;

    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp4.toString()<<std::endl;
    std::cout<<"The determinant is: -544"<<std::endl<<std::endl;
    std::cout<<"The result of determinant function is: "<< resultado4 <<std::endl<<std::endl;

    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp5.toString()<<std::endl;
    std::cout<<"The determinant is: 45"<<std::endl<<std::endl;
    std::cout<<"The result of determinant function is: "<< resultado5 <<std::endl<<std::endl;

    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp6.toString()<<std::endl;
    std::cout<<"The determinant is: -12390"<<std::endl<<std::endl;
    std::cout<<"The result of determinant function is: "<< resultado6 <<std::endl<<std::endl;

    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp7.toString()<<std::endl;
    std::cout<<"The determinant is: -54"<<std::endl<<std::endl;
    std::cout<<"The result of determinant function is: "<< resultado7 <<std::endl<<std::endl;

    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp8.toString()<<std::endl;
    std::cout<<"The determinant is: -54"<<std::endl<<std::endl;
    std::cout<<"The result of determinant function is: "<< resultado8 <<std::endl<<std::endl;

    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp9.toString()<<std::endl;
    std::cout<<"The determinant is: 54"<<std::endl<<std::endl;
    std::cout<<"The result of determinant function is: "<< resultado9 <<std::endl<<std::endl;
    std::cout<<"---------------------------------"<<std::endl;
}

void testMatrixDeterminantGauss()
{
    Matrix<long double> matrixp0({{4,3,2,1},{3,3,2,1},{2,2,2,1},{1,1,1,1}});
    Matrix<long double> matrixp1({{0,0,0,1},{1,0,0,0},{0,1,0,0},{0,0,1,0}});
    Matrix<long double> matrixp2({{6,3,0},{4,1,2},{5,6,1}});
    Matrix<long double> matrixp3({{0,6,3,3,5},{4,3,4,3,6},{2,0,5,2,7},{0,5,6,7,8},{5,6,7,0,9}});
    Matrix<long double> matrixp4({{2,8,1,9},{0,9,1,7},{7,1,8,2},{8,4,9,1}});
    Matrix<long double> matrixp5({{7,8,1,5},{6,2,4,9},{2,1,0,4},{0,0,1,0}});
    Matrix<long double> matrixp6({{1,2,3,9,1,3},{4,2,6,5,4,5},{7,8,9,8,5,9},{9,8,1,1,9,7},{6,5,4,5,6,4},{3,2,1,9,0,1}});
    Matrix<long double> matrixp7({{0,9,0,0},{1,0,2,0},{4,1,0,3},{1,2,0,0}});
    Matrix<long double> matrixp8({{0,3,4,1},{0,0,1,2},{0,0,0,9},{2,0,1,0}});
    Matrix<long double> matrixp9({{2,0,1,0},{0,3,4,1},{0,0,1,2},{0,0,0,9}});

    Matrix<long double> matrix(13, 13, 0);

    for(size_t i = 0;i < matrix.rowSize();i++)
    {
        if(i==0)
        {
            matrix(i,i) = 2;
            matrix(i,i+1) = 1;
        }
        else if(i==matrix.rowSize()-1)
        {
            matrix(i,i-1) = 1;
            matrix(i,i) = 2;
        }
        else
        {
            matrix(i,i-1)=1;
            matrix(i,i) = 2;
            matrix(i,i+1) = 1;
        }
    }

    Matrix<long double> matrix1(13, 13, 0);

    for(size_t i = 0;i < matrix1.rowSize();i++)
    {
        for(size_t j = 0;j < matrix1.columnsSize();j++)
        {
            matrix1[i][j] = (i+1) + j;
        }
    }

    long double resultado0 = matrixp0.detGauss();
    long double resultado1 = matrixp1.detGauss();
    long double resultado2 = matrixp2.detGauss();
    long double resultado3 = matrixp3.detGauss();
    long double resultado4 = matrixp4.detGauss();
    long double resultado5 = matrixp5.detGauss();
    long double resultado6 = matrixp6.detGauss();
    long double resultado7 = matrixp7.detGauss();
    long double resultado8 = matrixp8.detGauss();
    long double resultado9 = matrixp9.detGauss();
    long double result = matrix.detGauss();
    long double result1 = matrix1.detGauss();

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testMatrixDeterminantGauss"<<std::endl<<std::endl;
    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp0.toString()<<std::endl;
    std::cout<<"The determinant is: 1"<<std::endl<<std::endl;
    std::cout<<"The result of detGauss function is: "<< resultado0 <<std::endl<<std::endl;

    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp1.toString()<<std::endl;
    std::cout<<"The determinant is: -1"<<std::endl<<std::endl;
    std::cout<<"The result of detGauss function is: "<< resultado1 <<std::endl<<std::endl;

    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp2.toString()<<std::endl;
    std::cout<<"The determinant is: -48"<<std::endl<<std::endl;
    std::cout<<"The result of detGauss function is: "<< resultado2 <<std::endl<<std::endl;

    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp3.toString()<<std::endl;
    std::cout<<"The determinant is: 976"<<std::endl<<std::endl;
    std::cout<<"The result of detGauss function is: "<< resultado3 <<std::endl<<std::endl;

    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp4.toString()<<std::endl;
    std::cout<<"The determinant is: -544"<<std::endl<<std::endl;
    std::cout<<"The result of detGauss function is: "<< resultado4 <<std::endl<<std::endl;

    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp5.toString()<<std::endl;
    std::cout<<"The determinant is: 45"<<std::endl<<std::endl;
    std::cout<<"The result of detGauss function is: "<< resultado5 <<std::endl<<std::endl;

    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp6.toString()<<std::endl;
    std::cout<<"The determinant is: -12390"<<std::endl<<std::endl;
    std::cout<<"The result of detGauss function is: "<< resultado6 <<std::endl<<std::endl;

    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp7.toString()<<std::endl;
    std::cout<<"The determinant is: -54"<<std::endl<<std::endl;
    std::cout<<"The result of detGauss function is: "<< resultado7 <<std::endl<<std::endl;

    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp8.toString()<<std::endl;
    std::cout<<"The determinant is: -54"<<std::endl<<std::endl;
    std::cout<<"The result of detGauss function is: "<< resultado8 <<std::endl<<std::endl;

    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp9.toString()<<std::endl;
    std::cout<<"The determinant is: 54"<<std::endl<<std::endl;
    std::cout<<"The result of detGauss function is: "<< resultado9 <<std::endl<<std::endl;

    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrix.toString()<<std::endl;
    std::cout<<"The determinant is: 14"<<std::endl<<std::endl;
    std::cout<<"The result of detGauss function is: "<< result <<std::endl<<std::endl;

    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrix1.toString()<<std::endl;
    std::cout<<"The determinant is: 0"<<std::endl<<std::endl;
    std::cout<<"The result of detGauss function is: "<< result1 <<std::endl<<std::endl;
    std::cout<<"---------------------------------"<<std::endl;
}

void testMatrixHermitian()
{
    Matrix<long double> matrix({{1,9,3},{9,1,2},{3,2,1}});
    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testMatrixHermitian"<<std::endl<<std::endl;
    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrix.toString()<<std::endl;

    bool resultado = matrix.isHermitian();

    std::cout<<"The test matrix is Hermitian"<<std::endl<<std::endl;

    std::cout<<"The function tell us that:"<<std::endl<<std::endl;
    if(resultado)
    {
        std::cout << "The matrix is Hermitian" << std::endl;
    }
    else
    {
        std::cout<<"The matrix isn't Hermitian"<<std::endl<<std::endl;
    }

    std::cout<<"---------------------------------"<<std::endl;

    Matrix<long double> matrixp({{5,0,7},{9,2,4},{3,0,1}});

    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp.toString()<<std::endl;

    bool resultadop = matrixp.isHermitian();

    std::cout<<"The test matrix isn't Hermitian"<<std::endl<<std::endl;

    std::cout<<"The function tell us that:"<<std::endl<<std::endl;
    if(resultadop)
    {
        std::cout << "The matrix is Hermitian" << std::endl;
    }
    else
    {
        std::cout<<"The matrix isn't Hermitian"<<std::endl<<std::endl;
    }

    std::cout<<"---------------------------------"<<std::endl;
}

void testMatrixPositiveDefinite()
{
    Matrix<long double> matrix({{4,3,2,1},{3,3,2,1},{2,2,2,1},{1,1,1,1}});
    Matrix<long double> matrixp({{2,0,1,0},{0,3,4,1},{0,0,1,2},{0,0,0,9}});

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testMatrixPositiveDefinite"<<std::endl<<std::endl;
    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrix.toString()<<std::endl;

    std::cout<<"The matrix is positive definite"<<std::endl<<std::endl;

    bool resultado = matrix.isPositiveDefinite();



    std::cout<<"The function tell us that:"<<std::endl<<std::endl;
    if(resultado)
    {
        std::cout << "The matrix is positive definite" << std::endl;
    }
    else
    {
        std::cout<<"The matrix isn't positive definite"<<std::endl<<std::endl;
    }

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp.toString()<<std::endl;

    std::cout<<"The matrix isn't positive definite"<<std::endl<<std::endl;

    bool resultadop = matrixp.isPositiveDefinite();

    std::cout<<"The function tell us that:"<<std::endl<<std::endl;
    if(resultadop)
    {
        std::cout << "The matrix is positive definite" << std::endl;
    }
    else
    {
        std::cout<<"The matrix isn't positive definite"<<std::endl<<std::endl;
    }

    std::cout<<"---------------------------------"<<std::endl;
}

void testMatrixNegativeDefinite()
{
    Matrix<long double> matrix({{-3,0,1,0},{0,-6,4,1},{1,4,-8,2},{0,1,2,-9}});
    Matrix<long double> matrixp({{4,3,2,1},{3,3,2,1},{2,2,2,1},{1,1,1,1}});

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testMatrixNegativeDefinite"<<std::endl<<std::endl;
    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrix.toString()<<std::endl;

    std::cout<<"The matrix is negative definite"<<std::endl<<std::endl;

    bool resultado = matrix.isNegativeDefinite();



    std::cout<<"The function tell us that:"<<std::endl<<std::endl;
    if(resultado)
    {
        std::cout << "The matrix is negative definite" << std::endl;
    }
    else
    {
        std::cout<<"The matrix isn't negative definite"<<std::endl<<std::endl;
    }

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp.toString()<<std::endl;

    std::cout<<"The matrix isn't negative definite"<<std::endl<<std::endl;

    bool resultadop = matrixp.isNegativeDefinite();

    std::cout<<"The function tell us that:"<<std::endl<<std::endl;
    if(resultadop)
    {
        std::cout << "The matrix is negative definite" << std::endl;
    }
    else
    {
        std::cout<<"The matrix isn't negative definite"<<std::endl<<std::endl;
    }

    std::cout<<"---------------------------------"<<std::endl;
}

void testMatrixPositiveSemidefinite()
{
    Matrix<long double> matrix({{1,0,1,0},{0,5,4,1},{1,4,5,1},{0,1,1,0.25}});
    Matrix<long double> matrixp({{4,3,2,1},{3,3,2,1},{2,2,2,1},{1,1,1,1}});

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testMatrixPositiveSemidefinite"<<std::endl<<std::endl;
    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrix.toString()<<std::endl;

    std::cout<<"The matrix is positive semidefinite"<<std::endl<<std::endl;

    bool resultado = matrix.isPositiveSemidefinite();



    std::cout<<"The function tell us that:"<<std::endl<<std::endl;
    if(resultado)
    {
        std::cout << "The matrix is positive semidefinite" << std::endl;
    }
    else
    {
        std::cout<<"The matrix isn't positive semidefinite"<<std::endl<<std::endl;
    }

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp.toString()<<std::endl;

    std::cout<<"The matrix isn't positive semidefinite"<<std::endl<<std::endl;

    bool resultadop = matrixp.isPositiveSemidefinite();

    std::cout<<"The function tell us that:"<<std::endl<<std::endl;
    if(resultadop)
    {
        std::cout << "The matrix is positive semidefinite" << std::endl;
    }
    else
    {
        std::cout<<"The matrix isn't positive semidefinite"<<std::endl<<std::endl;
    }

    std::cout<<"---------------------------------"<<std::endl;
}

void testMatrixNegativeSemidefinite()
{
    Matrix<long double> matrix({{-4,-3,-2,-1},{-3,-3,-2,-1},{-2,-2,-2,-1},{-1,-1,-1,-0.5}});
    Matrix<long double> matrixp({{1,0,1,0},{0,5,4,1},{1,4,5,1},{0,1,1,0.25}});

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testMatrixNegativeSemidefinite"<<std::endl<<std::endl;
    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrix.toString()<<std::endl;

    std::cout<<"The matrix is negative semidefinite"<<std::endl<<std::endl;

    bool resultado = matrix.isNegativeSemidefinite();



    std::cout<<"The function tell us that:"<<std::endl<<std::endl;
    if(resultado)
    {
        std::cout << "The matrix is negative semidefinite" << std::endl;
    }
    else
    {
        std::cout<<"The matrix isn't negative semidefinite"<<std::endl<<std::endl;
    }

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp.toString()<<std::endl;

    std::cout<<"The matrix isn't negative semidefinite"<<std::endl<<std::endl;

    bool resultadop = matrixp.isNegativeSemidefinite();

    std::cout<<"The function tell us that:"<<std::endl<<std::endl;
    if(resultadop)
    {
        std::cout << "The matrix is negative semidefinite" << std::endl;
    }
    else
    {
        std::cout<<"The matrix isn't negative semidefinite"<<std::endl<<std::endl;
    }

    std::cout<<"---------------------------------"<<std::endl;
}

void testMatrixIndefinite()
{
    Matrix<long double> matrix({{4,3,2,1}, {3,2,1,0}, {2,1,0,-1}, {1,0,-1,-2}});
    Matrix<long double> matrixp({{1,0,1,0},{0,5,4,1},{1,4,5,1},{0,1,1,0.25}});

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testMatrixIndefinite"<<std::endl<<std::endl;
    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrix.toString()<<std::endl;

    std::cout<<"The matrix is indefinite"<<std::endl<<std::endl;

    bool resultado = matrix.isIndefinite();



    std::cout<<"The function tell us that:"<<std::endl<<std::endl;
    if(resultado)
    {
        std::cout << "The matrix is indefinite" << std::endl;
    }
    else
    {
        std::cout<<"The matrix isn't indefinite"<<std::endl<<std::endl;
    }

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp.toString()<<std::endl;

    std::cout<<"The matrix isn't indefinite"<<std::endl<<std::endl;

    bool resultadop = matrixp.isIndefinite();

    std::cout<<"The function tell us that:"<<std::endl<<std::endl;
    if(resultadop)
    {
        std::cout << "The matrix is indefinite" << std::endl;
    }
    else
    {
        std::cout<<"The matrix isn't indefinite"<<std::endl<<std::endl;
    }

    std::cout<<"---------------------------------"<<std::endl;
}

void testMatrixNorm1()
{
    Matrix<long double> matrixp({{-4,3,-2,1},{3,-3,2,-1},{-2,-2,-2,1},{1,1,1,1}});

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testMatrixNorm1"<<std::endl<<std::endl;
    std::cout<<"Test matrix is:"<<std::endl<<std::endl;
    std::cout<<matrixp.toString()<<std::endl;

    float resultado = matrixp.norm1();

    std::cout<<"The value of norm 1 of the matrix is 10"<<std::endl<<std::endl;

    std::cout<<"The result of norm1 function is: "<< resultado <<std::endl<<std::endl;
    std::cout<<"---------------------------------"<<std::endl;
}

void testMatrixInverseAdjoint()
{
    Matrix<long double> matrix({{4L,3L,2L,1L},{3L,3L,2L,1L},{2L,2L,2L,1L},{1L,1L,1L,1L}});

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testMatrixInverseAdjoint"<<std::endl<<std::endl;
    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix.toString()<<std::endl;

    Matrix<long double> inversa({{1L,-1L,0L,0L},{-1L,2L,-1L,0L},{0L,-1L,2L,-1L},{0L,0L,-1L,2L}});

    std::cout<<"the inverse of matrix is:"<<std::endl<<std::endl;
    std::cout<<inversa.toString()<<std::endl;

    Matrix<long double> resultado = matrix.invAdjoint();

    std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
    std::cout<<resultado.toString()<<std::endl;

    Matrix<long double> Mt = matrix * resultado;

    std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
    std::cout<<Mt.toString()<<std::endl;

    std::cout<<">>>>> Look at various interesting case <<<<<"<<std::endl<<std::endl;

    // Trivial case, identity matrix
    Matrix<long double> matrix00 = Matrix<long double>::I(6);

    // No square matrix with less number of rows
    Matrix<long double> matrix01({{1,0,9},{9,4,2}});

    // No square matrix with less number of columns
    Matrix<long double> matrix02({{1,0},{9,4},{9,2}});

    // Matrix with null determinant
    Matrix<long double> matrix03({{1,2,3,4,5},{2,4,6,8,10},{8,4,6,2,3},{0,3,1,6,1},{8,5,1,1,0}});

    // Matrix with negative determinant
    Matrix<long double> matrix04({{2,3,4,0},{7,4,6,1},{1,0,3,1},{9,1,1,4}});

    // Matrix with positive determinant
    Matrix<long double> matrix05({{7,4,6,1},{2,3,4,0},{9,1,0,4},{5,9,1,0}});

    // Indefinite matrix
    Matrix<long double> matrix06({{5,1,7,4,2},{9,1,0,5,6},{3,6,9,4,1},{0,9,1,2,3},{0,0,1,3,4}});

    // Positive definite matrix
    Matrix<long double> matrix07({{1,1,1,2,2},{-1,2,0,3,1},{-6,0,10,4,1},{0,-2,-4,3,0},{0,0,0,4,15}});

    // Negative definite matrix
    Matrix<long double> matrix08({{-5,1,1,2,2},{-1,-2,0,3,1},{-6,0,-3,4,1},{0,-5,1,-5,5},{0,0,1,3,-14}});

    // Positive semidefinite matrix
    Matrix<long double> matrix09({{2,1,1,3,3},{1,5,2,3,6},{1,2,6,3,3},{3,3,3,9,6},{3,6,3,6,9}});

    // Negative semidefinite matrix

    Matrix<long double> matrix10({{-10,4,2,1,-3},{4,-10,3,2,-1},{2,3,-10,4,-1},{1,2,4,-10,-3},{-3,-1,-1,-3,-8}});

    // Upper triangle matrix
    Matrix<long double> matrix11({{1,0,5,7},{0,5,1,7},{0,0,3,4},{0,0,0,2}});

    // Lower triangle matrix
    Matrix<long double> matrix12({{1,0,0,0},{3,2,0,0},{1,4,5,0},{7,2,8,5}});

    // Diagonal matrix
    Matrix<long double> matrix13 = matrix00*0.624;

    // Hermitian matrix
    Matrix<long double> matrix14({{2,1,0},{1,2,1},{0,1,2}});

    // No hermitian matrix
    Matrix<long double> matrix15({{2,1,1},{1,2,1},{2,1,2}});

    // Matrix with a lot of 0
    Matrix<long double> matrix16(7,7,0);

        for(size_t i = 0;i < matrix16.rowSize();i++)
    {
        if(i==0)
        {
            matrix16(i,i) = 2;
            matrix16(i,i+1) = 1;
        }
        else if(i==matrix16.rowSize()-1)
        {
            matrix16(i,i-1) = 1;
            matrix16(i,i) = 2;
        }
        else
        {
            matrix16(i,i-1)=1;
            matrix16(i,i) = 2;
            matrix16(i,i+1) = 1;
        }
    }

    // Matrix without 0

    Matrix<long double> matrix17(7, 7, 0);

    for(size_t i = 0;i < matrix17.rowSize();i++)
    {
        for(size_t j = 0;j < matrix17.columnsSize();j++)
        {
            matrix17[i][j] = (i+1) + j;
        }
    }

    // Matrix 13x13

    Matrix<long double> matrix18({
        { 5.000,  0.100,  0.200,  0.300,  0.400,  0.500,  0.600,  0.700,  0.800,  0.900,  1.000,  1.100,  1.200},
        {-0.100,  6.000,  0.100,  0.200,  0.300,  0.400,  0.500,  0.600,  0.700,  0.800,  0.900,  1.000,  1.100},
        {-0.200, -0.100,  7.000,  0.100,  0.200,  0.300,  0.400,  0.500,  0.600,  0.700,  0.800,  0.900,  1.000},
        {-0.300, -0.200, -0.100,  8.000,  0.100,  0.200,  0.300,  0.400,  0.500,  0.600,  0.700,  0.800,  0.900},
        {-0.400, -0.300, -0.200, -0.100,  9.000,  0.100,  0.200,  0.300,  0.400,  0.500,  0.600,  0.700,  0.800},
        {-0.500, -0.400, -0.300, -0.200, -0.100, 10.000,  0.100,  0.200,  0.300,  0.400,  0.500,  0.600,  0.700},
        {-0.600, -0.500, -0.400, -0.300, -0.200, -0.100, 11.000,  0.100,  0.200,  0.300,  0.400,  0.500,  0.600},
        {-0.700, -0.600, -0.500, -0.400, -0.300, -0.200, -0.100, 12.000,  0.100,  0.200,  0.300,  0.400,  0.500},
        {-0.800, -0.700, -0.600, -0.500, -0.400, -0.300, -0.200, -0.100, 13.000,  0.100,  0.200,  0.300,  0.400},
        {-0.900, -0.800, -0.700, -0.600, -0.500, -0.400, -0.300, -0.200, -0.100, 14.000,  0.100,  0.200,  0.300},
        {-1.000, -0.900, -0.800, -0.700, -0.600, -0.500, -0.400, -0.300, -0.200, -0.100, 15.000,  0.100,  0.200},
        {-1.100, -1.000, -0.900, -0.800, -0.700, -0.600, -0.500, -0.400, -0.300, -0.200, -0.100, 16.000,  0.100},
        {-1.200, -1.100, -1.000, -0.900, -0.800, -0.700, -0.600, -0.500, -0.400, -0.300, -0.200, -0.100, 17.000}
    });

    std::cout<<"Trivial case, identity matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix00.toString()<<std::endl;
    Matrix<long double> R00 = matrix00.invAdjoint();

    if(R00.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R00.toString()<<std::endl;

        Matrix<long double> Check00 = matrix00 * R00;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check00.toString()<<std::endl;
    }

    std::cout<<"No square matrix with less number of rows"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix01.toString()<<std::endl;
    Matrix<long double> R01 = matrix01.invAdjoint();

    std::cout<<"This matrix doesn't have inverse for these reason the calculated matrix must be a empty matrix"<<std::endl<<std::endl;

    if(R01.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R01.toString()<<std::endl;

        Matrix<long double> Check01 = matrix01 * R01;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check01.toString()<<std::endl;
    }

    std::cout<<"No square matrix with less number of columns"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix02.toString()<<std::endl;
    Matrix<long double> R02 = matrix02.invAdjoint();

    std::cout<<"This matrix doesn't have inverse for these reason the calculated matrix must be a empty matrix"<<std::endl<<std::endl;

    if(R02.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R02.toString()<<std::endl;

        Matrix<long double> Check02 = matrix02 * R02;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check02.toString()<<std::endl;
    }

    std::cout<<"Matrix with null determinant"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix03.toString()<<std::endl;
    Matrix<long double> R03 = matrix03.invAdjoint();

    std::cout<<"This matrix doesn't have inverse for these reason the calculated matrix must be a empty matrix"<<std::endl<<std::endl;

    if(R03.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R03.toString()<<std::endl;

        Matrix<long double> Check03 = matrix03 * R03;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check03.toString()<<std::endl;
    }

    std::cout<<"Matrix with negative determinant"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix04.toString()<<std::endl;
    Matrix<long double> R04 = matrix04.invAdjoint();

    if(R04.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R04.toString()<<std::endl;

        Matrix<long double> Check04 = matrix04 * R04;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check04.toString()<<std::endl;
    }

    std::cout<<"Matrix with positive determinant"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix05.toString()<<std::endl;
    Matrix<long double> R05 = matrix05.invAdjoint();

    if(R05.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R05.toString()<<std::endl;

        Matrix<long double> Check05 = matrix05 * R05;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check05.toString()<<std::endl;
    }

    std::cout<<"Indefinite matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix06.toString()<<std::endl;
    Matrix<long double> R06 = matrix06.invAdjoint();

    if(R06.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R06.toString()<<std::endl;

        Matrix<long double> Check06 = matrix06 * R06;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check06.toString()<<std::endl;
    }

    std::cout<<"Positive definite matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix07.toString()<<std::endl;
    Matrix<long double> R07 = matrix07.invAdjoint();

    if(R07.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R07.toString()<<std::endl;

        Matrix<long double> Check07 = matrix07 * R07;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check07.toString()<<std::endl;
    }

    std::cout<<"Negative definite matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix08.toString()<<std::endl;
    Matrix<long double> R08 = matrix08.invAdjoint();

    if(R08.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R08.toString()<<std::endl;

        Matrix<long double> Check08 = matrix08 * R08;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check08.toString()<<std::endl;
    }

    std::cout<<"Positive semidefinite matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix09.toString()<<std::endl;
    Matrix<long double> R09 = matrix09.invAdjoint();

    std::cout<<"This matrix doesn't have inverse for these reason the calculated matrix must be a empty matrix"<<std::endl<<std::endl;

    if(R09.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R09.toString()<<std::endl;

        Matrix<long double> Check09 = matrix09 * R09;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check09.toString()<<std::endl;
    }

    std::cout<<"Negative semidefinite matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix10.toString()<<std::endl;
    Matrix<long double> R10 = matrix10.invAdjoint();

    std::cout<<"This matrix doesn't have inverse for these reason the calculated matrix must be a empty matrix"<<std::endl<<std::endl;

    if(R10.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R10.toString()<<std::endl;

        Matrix<long double> Check10 = matrix10 * R10;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check10.toString()<<std::endl;
    }

    std::cout<<"Upper triangle matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix11.toString()<<std::endl;
    Matrix<long double> R11 = matrix11.invAdjoint();

    if(R11.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R11.toString()<<std::endl;

        Matrix<long double> Check11 = matrix11 * R11;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check11.toString()<<std::endl;
    }

    std::cout<<"Lower triangle matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix12.toString()<<std::endl;
    Matrix<long double> R12 = matrix12.invAdjoint();

    if(R12.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R12.toString()<<std::endl;

        Matrix<long double> Check12 = matrix12 * R12;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check12.toString()<<std::endl;
    }

    std::cout<<"Diagonal matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix13.toString()<<std::endl;
    Matrix<long double> R13 = matrix13.invAdjoint();

    if(R13.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R13.toString()<<std::endl;

        Matrix<long double> Check13 = matrix13 * R13;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check13.toString()<<std::endl;
    }

    std::cout<<"Hermitian matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix14.toString()<<std::endl;
    Matrix<long double> R14 = matrix14.invAdjoint();

    if(R14.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R14.toString()<<std::endl;

        Matrix<long double> Check14 = matrix14 * R14;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check14.toString()<<std::endl;
    }

    std::cout<<"No hermitian matrix"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix15.toString()<<std::endl;
    Matrix<long double> R15 = matrix15.invAdjoint();

    if(R15.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R15.toString()<<std::endl;

        Matrix<long double> Check15 = matrix15 * R15;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check15.toString()<<std::endl;
    }

    std::cout<<"Matrix with a lot of 0"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix16.toString()<<std::endl;
    Matrix<long double> R16 = matrix16.invAdjoint();

    if(R16.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R16.toString()<<std::endl;

        Matrix<long double> Check16 = matrix16 * R16;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check16.toString()<<std::endl;
    }

    std::cout<<"Matrix without 0"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix17.toString()<<std::endl;
    Matrix<long double> R17 = matrix17.invAdjoint();

    std::cout<<"This matrix doesn't have inverse for these reason the calculated matrix must be a empty matrix"<<std::endl<<std::endl;

    if(R17.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R17.toString()<<std::endl;

        Matrix<long double> Check17 = matrix17 * R17;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check17.toString()<<std::endl;
    }

    std::cout<<"Matrix 13x13"<<std::endl<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix18.toString()<<std::endl;
    Matrix<long double> R18 = matrix18.invAdjoint();

    if(R18.isEmpty())
    {
        std::cout<<"The calculated inverse matrix is an empty matrix."<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The calculated inverse matrix is:"<<std::endl<<std::endl;
        std::cout<<R18.toString()<<std::endl;

        Matrix<long double> Check18 = matrix18 * R18;

        std::cout<<"Let's check if the inverse matrix is correct"<<std::endl<<std::endl;
        std::cout<<Check18.toString()<<std::endl;
    }

    std::cout<<"---------------------------------"<<std::endl;
}

void testMatrixSignature()
{
    // No square matrix with less number of rows
    Matrix<long double> matrix01({{1,0,9},{9,4,2}});

    // Indefinite matrix
    Matrix<long double> matrix02({{5,1,7,4,2},{9,1,0,5,6},{3,6,9,4,1},{0,9,1,2,3},{0,0,1,3,4}});

    // Positive definite matrix
    Matrix<long double> matrix03({{1,1,1,2,2},{-1,2,0,3,1},{-6,0,10,4,1},{0,-2,-4,3,0},{0,0,0,4,15}});

    // Negative definite matrix
    Matrix<long double> matrix04({{-5,1,1,2,2},{-1,-2,0,3,1},{-6,0,-3,4,1},{0,-5,1,-5,5},{0,0,1,3,-14}});

    // Positive semidefinite matrix
    Matrix<long double> matrix05({{2,1,1,3,3},{1,5,2,3,6},{1,2,6,3,3},{3,3,3,9,6},{3,6,3,6,9}});

    // Negative semidefinite matrix

    Matrix<long double> matrix06({{-10,4,2,1,-3},{4,-10,3,2,-1},{2,3,-10,4,-1},{1,2,4,-10,-3},{-3,-1,-1,-3,-8}});

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testMatrixSignature"<<std::endl<<std::endl;
    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix01.toString()<<std::endl;
    std::cout<<"This matrix isn't square"<<std::endl<<std::endl;
    std::cout<<"The function tell us that:"<<std::endl<<std::endl;
    int R01 = matrix01.signature();

    if(R01 == 2)
    {
        std::cout<<"The matrix is positive-definite"<<std::endl<<std::endl;
    }
    else if(R01 == 1)
    {
        std::cout<<"The matrix is positive-semidefinite"<<std::endl<<std::endl;
    }
    else if(R01 == 0)
    {
        std::cout<<"The matrix is indefinite"<<std::endl<<std::endl;
    }
    else if(R01 == -1)
    {
        std::cout<<"The matrix is negative-semidefinite"<<std::endl<<std::endl;
    }
    else if(R01 == -2)
    {
        std::cout<<"The matrix is negative-definite"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The matrix isn't square"<<std::endl<<std::endl;
    }

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix02.toString()<<std::endl;
    std::cout<<"This matrix is indefinite"<<std::endl<<std::endl;
    std::cout<<"The function tell us that:"<<std::endl<<std::endl;
    int R02 = matrix02.signature();

    if(R02 == 2)
    {
        std::cout<<"The matrix is positive-definite"<<std::endl<<std::endl;
    }
    else if(R02 == 1)
    {
        std::cout<<"The matrix is positive-semidefinite"<<std::endl<<std::endl;
    }
    else if(R02 == 0)
    {
        std::cout<<"The matrix is indefinite"<<std::endl<<std::endl;
    }
    else if(R02 == -1)
    {
        std::cout<<"The matrix is negative-semidefinite"<<std::endl<<std::endl;
    }
    else if(R02 == -2)
    {
        std::cout<<"The matrix is negative-definite"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The matrix isn't square"<<std::endl<<std::endl;
    }

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix03.toString()<<std::endl;
    std::cout<<"This matrix is positive-definite"<<std::endl<<std::endl;
    std::cout<<"The function tell us that:"<<std::endl<<std::endl;
    int R03 = matrix03.signature();

    if(R03 == 2)
    {
        std::cout<<"The matrix is positive-definite"<<std::endl<<std::endl;
    }
    else if(R03 == 1)
    {
        std::cout<<"The matrix is positive-semidefinite"<<std::endl<<std::endl;
    }
    else if(R03 == 0)
    {
        std::cout<<"The matrix is indefinite"<<std::endl<<std::endl;
    }
    else if(R03 == -1)
    {
        std::cout<<"The matrix is negative-semidefinite"<<std::endl<<std::endl;
    }
    else if(R03 == -2)
    {
        std::cout<<"The matrix is negative-definite"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The matrix isn't square"<<std::endl<<std::endl;
    }

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix04.toString()<<std::endl;
    std::cout<<"This matrix is negative definite"<<std::endl<<std::endl;
    std::cout<<"The function tell us that:"<<std::endl<<std::endl;
    int R04 = matrix04.signature();

    if(R04 == 2)
    {
        std::cout<<"The matrix is positive-definite"<<std::endl<<std::endl;
    }
    else if(R04 == 1)
    {
        std::cout<<"The matrix is positive-semidefinite"<<std::endl<<std::endl;
    }
    else if(R04 == 0)
    {
        std::cout<<"The matrix is indefinite"<<std::endl<<std::endl;
    }
    else if(R04 == -1)
    {
        std::cout<<"The matrix is negative-semidefinite"<<std::endl<<std::endl;
    }
    else if(R04 == -2)
    {
        std::cout<<"The matrix is negative-definite"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The matrix isn't square"<<std::endl<<std::endl;
    }

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix05.toString()<<std::endl;
    std::cout<<"This matrix is positive-semidefinite"<<std::endl<<std::endl;
    std::cout<<"The function tell us that:"<<std::endl<<std::endl;
    int R05 = matrix05.signature();

    if(R05 == 2)
    {
        std::cout<<"The matrix is positive-definite"<<std::endl<<std::endl;
    }
    else if(R05 == 1)
    {
        std::cout<<"The matrix is positive-semidefinite"<<std::endl<<std::endl;
    }
    else if(R05 == 0)
    {
        std::cout<<"The matrix is indefinite"<<std::endl<<std::endl;
    }
    else if(R05 == -1)
    {
        std::cout<<"The matrix is negative-semidefinite"<<std::endl<<std::endl;
    }
    else if(R05 == -2)
    {
        std::cout<<"The matrix is negative-definite"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The matrix isn't square"<<std::endl<<std::endl;
    }

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix06.toString()<<std::endl;
    std::cout<<"This matrix is negative-semidefinite"<<std::endl<<std::endl;
    std::cout<<"The function tell us that:"<<std::endl<<std::endl;
    int R06 = matrix06.signature();

    if(R06 == 2)
    {
        std::cout<<"The matrix is positive-definite"<<std::endl<<std::endl;
    }
    else if(R06 == 1)
    {
        std::cout<<"The matrix is positive-semidefinite"<<std::endl<<std::endl;
    }
    else if(R06 == 0)
    {
        std::cout<<"The matrix is indefinite"<<std::endl<<std::endl;
    }
    else if(R06 == -1)
    {
        std::cout<<"The matrix is negative-semidefinite"<<std::endl<<std::endl;
    }
    else if(R06 == -2)
    {
        std::cout<<"The matrix is negative-definite"<<std::endl<<std::endl;
    }
    else
    {
        std::cout<<"The matrix isn't square"<<std::endl<<std::endl;
    }

    std::cout<<"---------------------------------"<<std::endl;
}

void testMatrixInverseComparation()
{
    Matrix<long double> matrix({{ 8.52915277829011e+23 , 0.0 , -6.553316820534138e+20 , -1.1191920332739584e+24 , 0.0 , 6.047261902484436e+21 , 1.4298591388520803e+25 , 0.0 , -5.952329686495167e+21 , 0.0 , 0.0 , 0.0 , 0.0 },
                                 { 0.0 , 1.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 },
                                 { -6.553316820534138e+20 , 0.0 , 5.559473790783668e+18 , 6.047261902484436e+21 , 0.0 , -2.0071008415894426e+18 , -5.952329686495167e+21 , 0.0 , 4.451749170326944e+19 , 0.0 , 0.0 , 0.0 , 0.0 },
                                 { -1.1191920332739584e+24 , 0.0 , 6.047261902484436e+21 , 1.4298592135016802e+25 , 0.0 , -5.952329686495167e+21 , -2.1124617214319102e+25 , 0.0 , 1.0870042564384951e+23 , 0.0 , 0.0 , 0.0 , 0.0 },
                                 { 0.0 , 0.0 , 0.0 , 0.0 , 1.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 },
                                 { 6.047261902484436e+21 , 0.0 , -2.0071008415894426e+18 , -5.952329686495167e+21 , 0.0 , 4.452749170326944e+19 , 1.0870042564384951e+23 , 0.0 , -2.733124374363557e+19 , 0.0 , 0.0 , 0.0 , 0.0 },
                                 { 1.4298591388520803e+25 , 0.0 , -5.952329686495167e+21 , -2.1124617214319102e+25 , 0.0 , 1.0870042564384951e+23 , 3.3339331395306236e+26 , 0.0 , -1.2404078986763186e+23 , 0.0 , 0.0 , 0.0 , 0.0 },
                                 { 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 1.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 },
                                 { -5.952329686495167e+21 , 0.0 , 4.451749170326944e+19 , 1.0870042564384951e+23 , 0.0 , -2.733124374363557e+19 , -1.2404078986763186e+23 , 0.0 , 8.37386242176923e+20 , 0.0 , 0.0 , 0.0 , 0.0 },
                                 { 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 1.0 , 0.0 , 0.0 , 0.0 },
                                 { 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 1.0 , 0.0 , 0.0 },
                                 { 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 1.0 , 0.0 },
                                 { 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 0.0 , 1.0 }});

    Matrix<long double> identity = Matrix<long double>::I(13);

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testMatrixInverseComparation"<<std::endl<<std::endl;
    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrix.toString()<<std::endl;
    std::cout<<"Let's check if the matrix satisfies the hypotheses of the Cholesky method,"<<std::endl;
    std::cout<<"in order to compare the three inversion methods."<<std::endl<<std::endl;
    if(matrix.isSquare() && matrix.isHermitian() && matrix.isPositiveDefinite())
    {
        std::cout<<"The matrix satifies all the hypotheses"<<std::endl<<std::endl;
        std::cout<<"Let's compararate the time and result of each method."<<std::endl<<std::endl;

        std::cout<<">>>>> First the adjoint method <<<<<"<<std::endl<<std::endl;
        auto start = std::chrono::steady_clock::now();

        Matrix<long double> result = matrix.invAdjoint();

        auto stop = std::chrono::steady_clock::now();

        auto t_time = stop-start;
        auto total_us = std::chrono::duration_cast<std::chrono::microseconds>(t_time).count();

        Matrix<long double> check = matrix * result;
        Matrix<long double> E = identity-check;
        long double e = E.norm1();
        long double er = e/((matrix.norm1())*(result.norm1()));

        std::cout<<"Let's check if the multiplication of matrix with is calculated inverse is the identity"<<std::endl<<std::endl;
        std::cout<<"The multiplication result is"<<std::endl<<std::endl;
        std::cout<<check.toString()<<std::endl;
        std::cout << "Absolute error: " << e << std::endl<< std::endl;
        std::cout << "Relative error: " << er << std::endl<< std::endl;
        std::cout << "Total time: " << total_us << " us" << std::endl<< std::endl;

        std::cout<<">>>>> Second the LU decomposition with partial pivot method <<<<<"<<std::endl<<std::endl;
        start = std::chrono::steady_clock::now();

        result = matrix.inverse();

        stop = std::chrono::steady_clock::now();

        t_time = stop-start;
        total_us = std::chrono::duration_cast<std::chrono::microseconds>(t_time).count();

        check = matrix * result;
        E = identity-check;
        e = E.norm1();
        er = e/((matrix.norm1())*(result.norm1()));

        std::cout<<"Let's check if the multiplication of matrix with is calculated inverse is the identity"<<std::endl<<std::endl;
        std::cout<<"The multiplication result is"<<std::endl<<std::endl;
        std::cout<<check.toString()<<std::endl;
        std::cout << "Absolute error: " << e << std::endl<< std::endl;
        std::cout << "Relative error: " << er << std::endl<< std::endl;
        std::cout << "Total time: " << total_us << " us" << std::endl<< std::endl;

        std::cout<<">>>>> Last the Cholesky method <<<<<"<<std::endl<<std::endl;
        start = std::chrono::steady_clock::now();

        result = matrix.invCholesky().second;

        stop = std::chrono::steady_clock::now();

        t_time = stop-start;
        total_us = std::chrono::duration_cast<std::chrono::microseconds>(t_time).count();

        check = matrix * result;
        E = identity-check;
        e = E.norm1();
        er = e/((matrix.norm1())*(result.norm1()));

        std::cout<<"Let's check if the multiplication of matrix with is calculated inverse is the identity"<<std::endl<<std::endl;
        std::cout<<"The multiplication result is"<<std::endl<<std::endl;
        std::cout<<check.toString()<<std::endl;
        std::cout << "Absolute error: " << e << std::endl<< std::endl;
        std::cout << "Relative error: " << er << std::endl<< std::endl;
        std::cout << "Total time: " << total_us << " us" << std::endl<< std::endl;

    }
    else
    {
        std::cout<<"The matrix doesn't satifies the hypotheses"<<std::endl<<std::endl;
    }

    std::cout<<"---------------------------------"<<std::endl;
}



void testMatrixDeterminantComparation()
{
    Matrix<long double> matrixp0({{4,3,2,1},{3,3,2,1},{2,2,2,1},{1,1,1,1}});
    Matrix<long double> matrixp1({{0,0,0,1},{1,0,0,0},{0,1,0,0},{0,0,1,0}});
    Matrix<long double> matrixp2({{6,3,0},{4,1,2},{5,6,1}});
    Matrix<long double> matrixp3({{0,6,3,3,5},{4,3,4,3,6},{2,0,5,2,7},{0,5,6,7,8},{5,6,7,0,9}});
    Matrix<long double> matrixp4({{2,8,1,9},{0,9,1,7},{7,1,8,2},{8,4,9,1}});
    Matrix<long double> matrixp5({{7,8,1,5},{6,2,4,9},{2,1,0,4},{0,0,1,0}});
    Matrix<long double> matrixp6({{1,2,3,9,1,3},{4,2,6,5,4,5},{7,8,9,8,5,9},{9,8,1,1,9,7},{6,5,4,5,6,4},{3,2,1,9,0,1}});

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"testMatrixDeterminantComparation"<<std::endl<<std::endl;
    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrixp0.toString()<<std::endl;

    std::cout<<"Let's compararate the time and result of each method."<<std::endl<<std::endl;

    std::cout<<">>>>> First the determinant with LU decomposition <<<<<"<<std::endl<<std::endl;
    auto start = std::chrono::steady_clock::now();

    long double resultado0 = matrixp0.determinant();

    auto stop = std::chrono::steady_clock::now();

    auto t_time = stop-start;
    auto total_us = std::chrono::duration_cast<std::chrono::microseconds>(t_time).count();

    long double e = std::abs(1 - resultado0);
    long double er = e/std::abs(1);

    std::cout<<"Let's check the error and total time"<<std::endl<<std::endl;
    std::cout << "Absolute error: " << e << std::endl<< std::endl;
    std::cout << "Relative error: " << er << std::endl<< std::endl;
    std::cout << "Total time: " << total_us << " us" << std::endl<< std::endl;

    std::cout<<">>>>> The last the determinant with Gaussian elimination <<<<<"<<std::endl<<std::endl;
    start = std::chrono::steady_clock::now();

    resultado0 = matrixp0.detGauss();

    stop = std::chrono::steady_clock::now();

    t_time = stop-start;
    total_us = std::chrono::duration_cast<std::chrono::microseconds>(t_time).count();

    e = std::abs(1 - resultado0);
    er = e/std::abs(1);

    std::cout<<"Let's check the error and total time"<<std::endl<<std::endl;
    std::cout << "Absolute error: " << e << std::endl<< std::endl;
    std::cout << "Relative error: " << er << std::endl<< std::endl;
    std::cout << "Total time: " << total_us << " us" << std::endl<< std::endl;

    std::cout<<"---------------------------------"<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrixp1.toString()<<std::endl;

    std::cout<<"Let's compararate the time and result of each method."<<std::endl<<std::endl;

    std::cout<<">>>>> First the determinant with LU decomposition <<<<<"<<std::endl<<std::endl;
    start = std::chrono::steady_clock::now();

    long double resultado1 = matrixp1.determinant();

    stop = std::chrono::steady_clock::now();

    t_time = stop-start;
    total_us = std::chrono::duration_cast<std::chrono::microseconds>(t_time).count();

    e = std::abs(-1 - resultado1);
    er = e/std::abs(-1);

    std::cout<<"Let's check the error and total time"<<std::endl<<std::endl;
    std::cout << "Absolute error: " << e << std::endl<< std::endl;
    std::cout << "Relative error: " << er << std::endl<< std::endl;
    std::cout << "Total time: " << total_us << " us" << std::endl<< std::endl;

    std::cout<<">>>>> The last the determinant with Gaussian elimination <<<<<"<<std::endl<<std::endl;
    start = std::chrono::steady_clock::now();

    resultado1 = matrixp1.detGauss();

    stop = std::chrono::steady_clock::now();

    t_time = stop-start;
    total_us = std::chrono::duration_cast<std::chrono::microseconds>(t_time).count();

    e = std::abs(-1 - resultado1);
    er = e/std::abs(-1);

    std::cout<<"Let's check the error and total time"<<std::endl<<std::endl;
    std::cout << "Absolute error: " << e << std::endl<< std::endl;
    std::cout << "Relative error: " << er << std::endl<< std::endl;
    std::cout << "Total time: " << total_us << " us" << std::endl<< std::endl;

    std::cout<<"---------------------------------"<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrixp2.toString()<<std::endl;

    std::cout<<"Let's compararate the time and result of each method."<<std::endl<<std::endl;

    std::cout<<">>>>> First the determinant with LU decomposition <<<<<"<<std::endl<<std::endl;
    start = std::chrono::steady_clock::now();

    long double resultado2 = matrixp2.determinant();

    stop = std::chrono::steady_clock::now();

    t_time = stop-start;
    total_us = std::chrono::duration_cast<std::chrono::microseconds>(t_time).count();

    e = std::abs(-48 - resultado2);
    er = e/std::abs(-48);

    std::cout<<"Let's check the error and total time"<<std::endl<<std::endl;
    std::cout << "Absolute error: " << e << std::endl<< std::endl;
    std::cout << "Relative error: " << er << std::endl<< std::endl;
    std::cout << "Total time: " << total_us << " us" << std::endl<< std::endl;

    std::cout<<">>>>> The last the determinant with Gaussian elimination <<<<<"<<std::endl<<std::endl;
    start = std::chrono::steady_clock::now();

    resultado2 = matrixp2.detGauss();

    stop = std::chrono::steady_clock::now();

    t_time = stop-start;
    total_us = std::chrono::duration_cast<std::chrono::microseconds>(t_time).count();

    e = std::abs(-48 - resultado2);
    er = e/std::abs(-48);

    std::cout<<"Let's check the error and total time"<<std::endl<<std::endl;
    std::cout << "Absolute error: " << e << std::endl<< std::endl;
    std::cout << "Relative error: " << er << std::endl<< std::endl;
    std::cout << "Total time: " << total_us << " us" << std::endl<< std::endl;

    std::cout<<"---------------------------------"<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrixp3.toString()<<std::endl;

    std::cout<<"Let's compararate the time and result of each method."<<std::endl<<std::endl;

    std::cout<<">>>>> First the determinant with LU decomposition <<<<<"<<std::endl<<std::endl;
    start = std::chrono::steady_clock::now();

    long double resultado3 = matrixp3.determinant();

    stop = std::chrono::steady_clock::now();

    t_time = stop-start;
    total_us = std::chrono::duration_cast<std::chrono::microseconds>(t_time).count();

    e = std::abs(976 - resultado3);
    er = e/std::abs(976);

    std::cout<<"Let's check the error and total time"<<std::endl<<std::endl;
    std::cout << "Absolute error: " << e << std::endl<< std::endl;
    std::cout << "Relative error: " << er << std::endl<< std::endl;
    std::cout << "Total time: " << total_us << " us" << std::endl<< std::endl;

    std::cout<<">>>>> The last the determinant with Gaussian elimination <<<<<"<<std::endl<<std::endl;
    start = std::chrono::steady_clock::now();

    resultado3 = matrixp3.detGauss();

    stop = std::chrono::steady_clock::now();

    t_time = stop-start;
    total_us = std::chrono::duration_cast<std::chrono::microseconds>(t_time).count();

    e = std::abs(976 - resultado3);
    er = e/std::abs(976);

    std::cout<<"Let's check the error and total time"<<std::endl<<std::endl;
    std::cout << "Absolute error: " << e << std::endl<< std::endl;
    std::cout << "Relative error: " << er << std::endl<< std::endl;
    std::cout << "Total time: " << total_us << " us" << std::endl<< std::endl;

    std::cout<<"---------------------------------"<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrixp4.toString()<<std::endl;

    std::cout<<"Let's compararate the time and result of each method."<<std::endl<<std::endl;

    std::cout<<">>>>> First the determinant with LU decomposition <<<<<"<<std::endl<<std::endl;
    start = std::chrono::steady_clock::now();

    long double resultado4 = matrixp4.determinant();

    stop = std::chrono::steady_clock::now();

    t_time = stop-start;
    total_us = std::chrono::duration_cast<std::chrono::microseconds>(t_time).count();

    e = std::abs(-544 - resultado4);
    er = e/std::abs(-544);

    std::cout<<"Let's check the error and total time"<<std::endl<<std::endl;
    std::cout << "Absolute error: " << e << std::endl<< std::endl;
    std::cout << "Relative error: " << er << std::endl<< std::endl;
    std::cout << "Total time: " << total_us << " us" << std::endl<< std::endl;

    std::cout<<">>>>> The last the determinant with Gaussian elimination <<<<<"<<std::endl<<std::endl;
    start = std::chrono::steady_clock::now();

    resultado4 = matrixp4.detGauss();

    stop = std::chrono::steady_clock::now();

    t_time = stop-start;
    total_us = std::chrono::duration_cast<std::chrono::microseconds>(t_time).count();

    e = std::abs(-544 - resultado4);
    er = e/std::abs(-544);

    std::cout<<"Let's check the error and total time"<<std::endl<<std::endl;
    std::cout << "Absolute error: " << e << std::endl<< std::endl;
    std::cout << "Relative error: " << er << std::endl<< std::endl;
    std::cout << "Total time: " << total_us << " us" << std::endl<< std::endl;

    std::cout<<"---------------------------------"<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrixp5.toString()<<std::endl;

    std::cout<<"Let's compararate the time and result of each method."<<std::endl<<std::endl;

    std::cout<<">>>>> First the determinant with LU decomposition <<<<<"<<std::endl<<std::endl;
    start = std::chrono::steady_clock::now();

    long double resultado5 = matrixp5.determinant();

    stop = std::chrono::steady_clock::now();

    t_time = stop-start;
    total_us = std::chrono::duration_cast<std::chrono::microseconds>(t_time).count();

    e = std::abs(45 - resultado5);
    er = e/std::abs(45);

    std::cout<<"Let's check the error and total time"<<std::endl<<std::endl;
    std::cout << "Absolute error: " << e << std::endl<< std::endl;
    std::cout << "Relative error: " << er << std::endl<< std::endl;
    std::cout << "Total time: " << total_us << " us" << std::endl<< std::endl;

    std::cout<<">>>>> The last the determinant with Gaussian elimination <<<<<"<<std::endl<<std::endl;
    start = std::chrono::steady_clock::now();

    resultado5 = matrixp5.detGauss();

    stop = std::chrono::steady_clock::now();

    t_time = stop-start;
    total_us = std::chrono::duration_cast<std::chrono::microseconds>(t_time).count();

    e = std::abs(45 - resultado5);
    er = e/std::abs(45);

    std::cout<<"Let's check the error and total time"<<std::endl<<std::endl;
    std::cout << "Absolute error: " << e << std::endl<< std::endl;
    std::cout << "Relative error: " << er << std::endl<< std::endl;
    std::cout << "Total time: " << total_us << " us" << std::endl<< std::endl;

    std::cout<<"---------------------------------"<<std::endl;

    std::cout<<"Test matrix:"<<std::endl<<std::endl;
    std::cout<<matrixp6.toString()<<std::endl;

    std::cout<<"Let's compararate the time and result of each method."<<std::endl<<std::endl;

    std::cout<<">>>>> First the determinant with LU decomposition <<<<<"<<std::endl<<std::endl;
    start = std::chrono::steady_clock::now();

    long double resultado6 = matrixp6.determinant();

    stop = std::chrono::steady_clock::now();

    t_time = stop-start;
    total_us = std::chrono::duration_cast<std::chrono::microseconds>(t_time).count();

    e = std::abs(-12390 - resultado6);
    er = e/std::abs(-12390);

    std::cout<<"Let's check the error and total time"<<std::endl<<std::endl;
    std::cout << "Absolute error: " << e << std::endl<< std::endl;
    std::cout << "Relative error: " << er << std::endl<< std::endl;
    std::cout << "Total time: " << total_us << " us" << std::endl<< std::endl;

    std::cout<<">>>>> The last the determinant with Gaussian elimination <<<<<"<<std::endl<<std::endl;
    start = std::chrono::steady_clock::now();

    resultado6 = matrixp6.detGauss();

    stop = std::chrono::steady_clock::now();

    t_time = stop-start;
    total_us = std::chrono::duration_cast<std::chrono::microseconds>(t_time).count();

    e = std::abs(-12390 - resultado6);
    er = e/std::abs(-12390);

    std::cout<<"Let's check the error and total time"<<std::endl<<std::endl;
    std::cout << "Absolute error: " << e << std::endl<< std::endl;
    std::cout << "Relative error: " << er << std::endl<< std::endl;
    std::cout << "Total time: " << total_us << " us" << std::endl<< std::endl;

    std::cout<<"---------------------------------"<<std::endl;
}

void prueba()
{
    Matrix<long double> M(20,20,0);
    size_t n = M.rowSize();
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            M(i,j) = 1.0L / (i + j + 1.0L);
        }
    }
    long double RealDet = 1.13e-233;

    auto start = std::chrono::steady_clock::now();

    long double det = M.detGauss();

    auto stop = std::chrono::steady_clock::now();

    auto t_time = stop-start;
    auto total_us = std::chrono::duration_cast<std::chrono::microseconds>(t_time).count();

    long double E = std::abs(RealDet - det);
    long double e = E / std::abs(RealDet);

    std::cout<<"---------------------------------"<<std::endl;
    std::cout<<"The test matrix is the Hilbert's Matrix"<<std::endl;
    std::cout<<M.toString()<<std::endl;
    std::cout<<"The real value of determinant is: "<<RealDet<<std::endl<<std::endl;
    std::cout<<"The calculated value of determinant using detGauss is: "<<det<<std::endl<<std::endl;
    std::cout<<"Let's check the error and total time"<<std::endl<<std::endl;
    std::cout << "Absolute error: " << E << std::endl<< std::endl;
    std::cout << "Relative error: " << e << std::endl<< std::endl;
    std::cout << "Total time: " << total_us << " us" << std::endl<< std::endl;

}

int main()
{
    std::cout << "Unit Test: Class dpbase::math::Matrix" << std::endl;

    testMatrix();
    testMatrixMultiplication();
    testMatrixSize();
    testMatrixSquare();
    testMatrixHermitian();
    testMatrixSignature();
    testMatrixPositiveDefinite();
    testMatrixNegativeDefinite();
    testMatrixPositiveSemidefinite();
    testMatrixNegativeSemidefinite();
    testMatrixIndefinite();
    testMatrixIdentity();
    testMatrixGet();
    testMatrixSwap();
    testMatrixEliminate();
    testMatrixPivot();
    testMatrixAdjoint();
    testMatrixDeterminant();
    testMatrixDeterminantGauss();
    testMatrixDeterminantComparation();
    testMatrixNorm1();
    testMatrixTranspose();
    testMatrixInverseAdjoint();
    testMatrixInverse();
    testMatrixInverseCholesky();
    testMatrixInverseComparation();
    //prueba();

    // All assertions passed
    std::cout << "All tests passed!\n";

    return 0;
}
