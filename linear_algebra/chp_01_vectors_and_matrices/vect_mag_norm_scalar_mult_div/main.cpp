#include <iostream>
#include <Eigen/Dense>

int main()
{
    Eigen::Vector3d Position(5.5, 7.3, 3.14);
    std::cout << "\nOriginal values of Position Vector is  ==  \n" << Position << std::endl << std::endl;
    std::cout << "Scalar Multiplication (Position * 2.5)  ==  \n" << Position * 2.5 << std::endl << std::endl;
    std::cout << "Scalar Multiplication (2.5 * Position)  ==  \n" << 2.5 * Position << std::endl << std::endl;
    
    std::cout << "Scalar Multiplication and assignment (Position = Position * 2) OR (Position *= 2)  ==  \n";
    Position *= 2;
    std::cout << Position << std::endl << std::endl;

    // Reset values of vector
    Position(0) = 5.5;  Position(1) = 7.3;  Position(2) = 3.14;

    std::cout << "Scalar Division (Position / 2.5)  ==  \n" << (Position / 2.5) << std::endl << std::endl;

    std::cout << "Scalar Division and assignment (Position = Position / 2) OR (Position /= 2)  ==  \n";
    Position /= 2;
    std::cout << Position << std::endl << std::endl;

    // Reset values of vector
    Position(0) = 5.5;  Position(1) = 7.3;  Position(2) = 3.14;

    std::cout << "Negation of Position Vector is  ==  \n" << -Position << std::endl << std::endl;

    std::cout << "Magnitude of Position Vector is  ==  " << Position.norm() << std::endl << std::endl;

    std::cout << "Position Vector Normalized is  ==  \n";
    Position.normalize();
    std::cout << Position << std::endl << std::endl;

    // Reset values of vector
    Position(0) = 5.5;  Position(1) = 7.3;  Position(2) = 3.14;

    return 0;
}
