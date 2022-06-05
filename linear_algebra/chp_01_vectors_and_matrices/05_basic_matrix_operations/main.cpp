#include <iostream>
#include <Eigen/Dense>

int main()
{
    // Matrix multiplication is defined as the Dot product between each        [x]
    // row of the first matrix with each column of the second matrix.          |y| <--- Column vector x, y, z
    // If the second matrix is a column vector, then the columns of the   ---> [z]
    // first matrix tell us exactly how the x, y, and z axes are reoriented
    // in a new coordinate system established through multiplication by the first
    // matrix. This is the key concept within the topic of coordinate transformations.


    Eigen::Matrix3i matrix_3d;
    matrix_3d << 4, 1, 5,
                 9, 8, 1,
                 2, 5, 4;

    Eigen::Vector3i column_vector(7, 6, 4);


    std::cout << "\nmatrix_3d  ==  \n\n" << matrix_3d << std::endl;
    std::cout << "\ncolumn_vector  ==  \n\n" << column_vector << std::endl << std::endl;


    // Matrix multiplication with column vector
    std::cout << "\nMatrix multiplication with column vector : " << std::endl;
    std::cout << "\nmatrix_3d * column_vector  ==  \n\n" << matrix_3d * column_vector << std::endl << std::endl;


    
    Eigen::Matrix3i matrix_3d_left = matrix_3d;
    Eigen::Matrix3i matrix_3d_right;
    matrix_3d_right << 5, 5, 4,
                       7, 6, 9,
                       3, 1, 5;
    

    
    std::cout << "\nmatrix_3d_left  ==  \n\n" << matrix_3d_left << std::endl;
    std::cout << "\nmatrix_3d_right  ==  \n\n" << matrix_3d_right << std::endl << std::endl;


    // Matrix multiplication with matrix
    std::cout << "\nMatrix multiplication with another matrix : " << std::endl;
    std::cout << "\nmatrix_3d_left * matrix_3d_right  ==  \n\n" << matrix_3d_left * matrix_3d_right << std::endl << std::endl;



    return 0;
}
