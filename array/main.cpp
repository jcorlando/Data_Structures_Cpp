#include "myvector.hpp"
#include <vector>

// 
// Assignment: #_1
// Implement an automatically resizing vector.
// 
// Driver code
int main()
{
    {
        std::cout << "----------- My implementation Code Starts Here --------------" << std::endl;
        //////////////////////////////////////////////////////////////////////////////////
        ///////////////////////// Using my own implemantation ////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////
        myvector<int> v;
        myvector<char> v1;
        v.push(10);
        v.push(20);
        v.push(30);
        v.push(40);
        v.push(50);
        v1.push(71);
        v1.push(72);
        v1.push(73);
        v1.push(74);
    
        std::cout << "Vector size : " << v.size() << std::endl;
        std::cout << "Vector capacity : " << v.getcapacity() << std::endl;
    
        std::cout << "Vector elements : ";
        v.print();
    
        v.push(100, 1);
    
        std::cout << "\nAfter updating 1st index" << std::endl;
    
        std::cout << "Vector elements of type int : " << std::endl;
        v.print();
        // This was possible because we used templates
        std::cout << "Vector elements of type char : " << std::endl;
        v1.print();
        std::cout << "Element at 1st index of type int: " << v.get(1) << std::endl;
        std::cout << "Element at 1st index of type char: " << v1.get(1) << std::endl;
    
        v.pop();
        v1.pop();
    
        std::cout << "\nAfter deleting last element" << std::endl;
    
        std::cout << "Vector size of type int: " << v.size() << std::endl;
        std::cout << "Vector size of type char: " << v1.size() << std::endl;
        std::cout << "Vector capacity of type int : " << v.getcapacity() << std::endl;
        std::cout << "Vector capacity of type char : " << v1.getcapacity() << std::endl;
    
        std::cout << "Vector elements of type int: ";
        v.print();
        std::cout << "Vector elements of type char: ";
        v1.print();
        std::cout << std::endl;
        //////////////////////////////////////////////////////////////////////////////////
        ///////////////////////// Using my own implemantation ////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////
    }

    {
        std::cout << "----------------- STL Code Starts Here ----------------------" << std::endl;
        //////////////////////////////////////////////////////////////////////////////////
        /////////////////////////// Using built-in C++ STL ///////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////
        std::vector<int> v;
        std::vector<char> v1;
        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        v.push_back(40);
        v.push_back(50);
        v1.push_back(71);
        v1.push_back(72);
        v1.push_back(73);
        v1.push_back(74);
    
        std::cout << "Vector size : " << v.size() << std::endl;
        std::cout << "Vector capacity : " << v.capacity() << std::endl;
    
        std::cout << "Vector elements : ";

        // function to print array elements
        for (auto element : v)
            { std::cout << element << " "; }
        std::cout << std::endl;

        v.at(1) = 100;
    
        std::cout << "\nAfter updating 1st index" << std::endl;
    
        std::cout << "Vector elements of type int : " << std::endl;
        // function to print array elements
        for (auto element : v)
            { std::cout << element << " "; }
        std::cout << std::endl;


        std::cout << "Vector elements of type char : " << std::endl;
        
        // function to print array elements
        for (auto element : v1)
            { std::cout << element << " "; }
        std::cout << std::endl;

        std::cout << "Element at 1st index of type int: " << v.at(1) << std::endl;
        std::cout << "Element at 1st index of type char: " << v1.at(1) << std::endl;
    
        v.pop_back();
        v1.pop_back();
    
        std::cout << "\nAfter deleting last element" << std::endl;
    
        std::cout << "Vector size of type int: " << v.size() << std::endl;
        std::cout << "Vector size of type char: " << v1.size() << std::endl;
        std::cout << "Vector capacity of type int : " << v.capacity() << std::endl;
        std::cout << "Vector capacity of type char : " << v1.capacity() << std::endl;
    
        std::cout << "Vector elements of type int: ";
        // function to print array elements
        for (auto element : v)
            { std::cout << element << " "; }
        std::cout << std::endl;

        std::cout << "Vector elements of type char: ";
        // function to print array elements
        for (auto element : v1)
            { std::cout << element << " "; }
        std::cout << std::endl;
        //////////////////////////////////////////////////////////////////////////////////
        /////////////////////////// Using built-in C++ STL ///////////////////////////////
        //////////////////////////////////////////////////////////////////////////////////
    }

    return 0;
}
