#include <iostream>
#include <Eigen/Dense>

int main()
{
    Eigen::Vector3d position_a(5.5, 7.3, 3.14);
    Eigen::Vector3d position_b(8.3, 1.2, 4.44);
    std::cout << "\nOriginal values of position_a Vector are  ==  \n" << position_a << std::endl << std::endl;
    std::cout <<   "Original values of position_b Vector are  ==  \n" << position_b << std::endl << std::endl;

    std::cout << "(position_a + position_b)  ==  \n" << position_a + position_b << std::endl << std::endl;

    std::cout << "(position_a - position_b)  ==  \n" << position_a - position_b << std::endl << std::endl;
    
    std::cout << "Negation is demonstrated as such -(position_a)  ==  \n" << -position_a << std::endl << std::endl;

    std::cout << "Compound operator += as in (position_a += position_b) OR (position_a = position_a + position_b)  ==  \n";
    position_a += position_b;
    std::cout << position_a << std::endl << std::endl;

    // Reset values of vector
    position_a(0) = 5.5;  position_a(1) = 7.3;  position_a(2) = 3.14;

    std::cout << "Compound operator -= as in (position_a -= position_b) OR (position_a = position_a - position_b)  ==  \n";
    position_a -= position_b;
    std::cout << position_a << std::endl << std::endl;

    // Reset values of vector
    position_a(0) = 5.5;  position_a(1) = 7.3;  position_a(2) = 3.14;

    return 0;
}
