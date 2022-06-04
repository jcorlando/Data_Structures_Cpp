#include <iostream>
#include <Eigen/Dense>

int main()
{
    /*
    Matrices are usually denoted by uppercase letters such as "M."
    To differentiate between vectors and matrices I will most likely
    be denoting vectors with lowercase notation and matrices with uppercase
    notation.  An individual entry of a matrix M is identified by writing
    two zero-based subscripts such that the first subscript represents
    the row index, and the second subscript represents the column index.
    Each individual entry in the matrix is denoted by a subscript such as
    M(row, column)  ==  element (row, column) of Matrix "M."

    Oftentimes we need to access the diagonal elements/subscripts across a square matrix.
    For these elements/subscripts we can access them quite easily.  The entries M(i, i),
    where the row index and column index are equal to each other, are called the diagonal
    entries of the matrix M, and they are said to reside on the main diagonal of the matrix.

    Definition of a Diagonal Matrix is as follows : Any matrix for which all of the off-diagonal
    entries are zero.       For example : 
                                                [ 3, 0, 0 ]
                                                | 0, 8, 0 |  <-- This is a diagonal matrix
                                                [ 0, 0, 4 ]
    
    Note : some or all of the entries on the main diagonal itself could be zero, and
    the matrix would still be considered to be a diagonal matrix.

    More lecture notes will be coming soon...
    */



    // Create & initialize Matrix
    Eigen::Matrix3d my_matrix;

    my_matrix << 3, 0, 0,
                 0, 8, 0,
                 0, 0, 4;


    // Print out my initialized matrix
    std::cout << "\nmy_matrix  ==  \n\n" << my_matrix << std::endl << std::endl;


    // Accessing specified elements of a matrix
    std::cout << "my_matrix[0, 0]  ==   " << my_matrix(0, 0) << std::endl << std::endl;
    std::cout << "my_matrix[1, 1]  ==   " << my_matrix(1, 1) << std::endl << std::endl;
    std::cout << "my_matrix[2, 2]  ==   " << my_matrix(2, 2) << std::endl << std::endl;
    std::cout << "my_matrix[0, 1]  ==   " << my_matrix(0, 1) << std::endl << std::endl;
    std::cout << "my_matrix[0, 2]  ==   " << my_matrix(0, 2) << std::endl << std::endl;


    // Assign a value to an element
    std::cout << "\nchanging value my_matrix[0, 2]  =  3" << std::endl;
    my_matrix(0, 2) = 3;
    std::cout << "\nNow my_matrix  ==  \n\n" << my_matrix << std::endl << std::endl;

    // Transpose of matrix
    std::cout << "This is the Transpose of my_matrix^T\n\n" << my_matrix.transpose() << std::endl << std::endl;

    // Access a Column vector
    std::cout << "To access a Column vector at index[0] use my_matrix.col(0)  ==   \n\n" << my_matrix.col(0) << std::endl << std::endl;
    std::cout << "To access a Column vector at index[1] use my_matrix.col(1)  ==   \n\n" << my_matrix.col(1) << std::endl << std::endl;
    std::cout << "To access a Column vector at index[2] use my_matrix.col(2)  ==   \n\n" << my_matrix.col(2) << std::endl << std::endl;

    // Access a Row vector
    std::cout << "To access a Row vector at index[0] use my_matrix.row(0)  ==   \n\n" << my_matrix.row(0) << std::endl << std::endl;
    std::cout << "To access a Row vector at index[1] use my_matrix.row(1)  ==   \n\n" << my_matrix.row(1) << std::endl << std::endl;
    std::cout << "To access a Row vector at index[2] use my_matrix.row(2)  ==   \n\n" << my_matrix.row(2) << std::endl << std::endl;

    // Access a single element of Column vector
    std::cout << "\nTo access a single element of the Column vector at index[1][1] use my_matrix.col(1)[1]  ==   \n\n" << my_matrix.col(1)[1] << std::endl << std::endl;

    // Access a single element Row vector
    std::cout << "To access a single element of the Row vector at index[2][2] use my_matrix.row(2)[2]  ==   \n\n" << my_matrix.row(2)[2] << std::endl << std::endl;

    return 0;
}
