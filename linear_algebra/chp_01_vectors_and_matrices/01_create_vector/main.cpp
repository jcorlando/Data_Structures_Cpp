#include <iostream>
#include <Eigen/Dense>

int main()
{
    // How to create a column vector named Position and access 
    // and display its contents to the screen
    Eigen::Vector3i Position(3, 4, 5);
    std::cout << "\nThis is 3D Column Vector of Integers" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Position vector  ==  \n" << Position << std::endl;
    std::cout << "\nPosition[0]  ==  " << Position[0] << std::endl;
    std::cout <<   "Position[1]  ==  " << Position[1] << std::endl;
    std::cout <<   "Position[2]  ==  " << Position[2] << std::endl << std::endl;
    std::cout << "Magnitude of Vector is  ==  " << Position.norm() << std::endl << std::endl;


    // Same implementation but using vectors of Doubles instead. 
    Eigen::Vector3d Position_double(5.5, 7.3, 3.14);
    std::cout << "\nThis is 3D Column Vector of Doubles" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Position_double vector  ==  \n" << Position_double << std::endl;
    std::cout << "\nPosition_double[0]  ==  " << Position_double[0] << std::endl;
    std::cout <<   "Position_double[1]  ==  " << Position_double[1] << std::endl;
    std::cout <<   "Position_double[2]  ==  " << Position_double[2] << std::endl << std::endl;
    std::cout << "Magnitude of Vector is  ==  " << Position_double.norm() << std::endl << std::endl;

    return 0;
}
