#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#define NUM 3360

void factorize(int num, std::vector<int> &vector)
{
    // push_back the number of 2s that divide num
    while (num % 2 == 0)
    {
        vector.push_back(2);
        num = num/2;
    }
 
    // num must be odd at this point. So we can skip
    // one element (Note i = i +2)
    for(int i = 3; i <= sqrt(num); i = i + 2)
    {
        // While i divides num, push_back i and divide num
        while (num % i == 0)
        {
            vector.push_back(i);
            num = num/i;
        }
    }
 
    // This condition is to handle the case when num
    // is a prime number greater than 2
    if (num > 2)
        vector.push_back(num);
}


int main()
{
	std::vector<int> vector;

	factorize(NUM, vector);

	for(auto each : vector)  std::cout << each << std::endl;

	return 0;
}
