#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Geometry>

int main()
{
    /* THE DOT PRODUCT.
    *  --------------------
    *  The dot product between two n-dimensional vectors a and b is a scalar quantity.
    *  The corresponding components of the two vectors are multiplied together and
    *  summed. This product gets its name from the notation a · b in which a dot is placed
    *  between the two vectors participating in the product. Because it produces a scalar
    *  quantity, the dot product is also known as the scalar product.
    */

    // Scalar that holds the answer of the Dot Product
    int scalar;

    // Create two vectors
    Eigen::Vector3i a(5, 4, 1);
    Eigen::Vector3i b(8, 7, 4);

    // Compute Dot Product
    scalar = a.dot(b);

    // Print results
    std::cout << std::endl << "The Scalar product between vector a \n\n" << a << "\n\nand vector b \n\n" << b << "\n\nis  ==   " << scalar << std::endl << std::endl;


    /* THE CROSS PRODUCT.
    *  -----------------------
    *  The cross product is also known as the vector product.  The cross product produces
    *  another vector which is orthogonal to both a and b ( a x b = c ), and the length of
    *  the resultant vector "c" is the area of the parallelogram formed by the plane
    *  constrained by the two vectors a and b.
    */


    // Create three vectors
    Eigen::Vector3i a(1,  6, -8);
    Eigen::Vector3i b(4, -2, -1);
    Eigen::Vector3i c;


    // Compute Cross Product
    c = a.cross(b);


    // Print results
    std::cout << std::endl << "The Cross product between vector a \n\n" << a << "\n\nand vector b \n\n" << b << "\n\nis  ==   \n\n" << c << std::endl << std::endl;


    return 0;
}
