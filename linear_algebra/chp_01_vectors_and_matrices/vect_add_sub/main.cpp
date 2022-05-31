#include <iostream>
#include <Eigen/Dense>

int main()
{
    Eigen::Vector3d position_a(5.5, 7.3, 3.14);
    Eigen::Vector3d position_b(8.3, 1.2, 4.44);
    std::cout << "\nOriginal values of position_a Vector are  ==  \n" << position_a << std::endl << std::endl;
    std::cout <<   "Original values of position_b Vector are  ==  \n" << position_b << std::endl << std::endl;

    std::cout << "position_a Vector + position_b Vector  ==  \n" << position_a + position_b << std::endl << std::endl;

    
    

    return 0;
}
