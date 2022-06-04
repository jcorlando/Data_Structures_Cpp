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

    std::cout << "\nmy_matrix  ==  \n\n" << my_matrix << std::endl << std::endl;



    

    return 0;
}
