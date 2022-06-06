#include <iostream>
#include <Eigen/Dense>

int main()
{
    // SOLVE SYSTEMs OF LINEAR EQUATIONS.
    // -----------------------------------


    // Eigen::Matrix3d A;  // Assuming that Ax = b, we want to solve for x by inverting
    // Eigen::Vector3d b;  // matrix A and solve this linear system of equations.

    // A << 1, 2, 3,  // <-- These are the linear coefficients
    //      4, 5, 6,  // <-- on the left side of the equation. 
    //      7, 8, 10; // 
    
    // b << 3,     // <-- These are the constant terms
    //      3,     // <-- on the right side of the system
    //      4;     // <-- of equations
    
    
    // std::cout << "\nHere is the matrix A:\n" << A << std::endl << std::endl;
    // std::cout << "Here is the vector b:\n" << b << std::endl << std::endl;
    // Eigen::Vector3d x = A.colPivHouseholderQr().solve(b);
    // std::cout << "The solution is:\n" << x << std::endl << std::endl;



    // PRACTICE PROBLEM
    // -----------------

    // Eigen::Matrix3d A;
    // Eigen::Vector3d b;

    // A <<  2,  5,  2,
    //       3, -2,  4,
    //       -6, 1, -7;
    

    // b <<  -38,
    //        17,
    //       -12;
    

    // std::cout << "\nHere is the matrix A:\n" << A << std::endl << std::endl;
    // std::cout << "Here is the vector b:\n" << b << std::endl << std::endl;
    // Eigen::Vector3d x = A.colPivHouseholderQr().solve(b);
    // std::cout << "The solution is:\n" << x << std::endl << std::endl;




    // PRACTICE PROBLEM 2
    // -------------------

    Eigen::Matrix3d A;
    Eigen::Vector3d b;

    A <<  3,  0, -9,
          7, -4, -1,
          4, 6,   5;
    

    b <<   33,
          -15,
           -6;
    

    std::cout << "\nHere is the matrix A:\n" << A << std::endl << std::endl;
    std::cout << "Here is the vector b:\n" << b << std::endl << std::endl;
    Eigen::Vector3d x = A.colPivHouseholderQr().solve(b);
    std::cout << "The solution is:\n" << x << std::endl << std::endl;



    return 0;
}
