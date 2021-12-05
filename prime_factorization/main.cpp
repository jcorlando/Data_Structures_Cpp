#include <iostream>


void myfunction(int param)
{
	int i = 2;
	int j, k;

	while(i < param)
	{
		k = i;
		
		for (j = 2; j <= k; j++)
		{
			if (k % j == 0)
			{
				k = k/j;
				j--;
				if (k == 1)
				{
					break;
				}
			}
		}
		i++;
	}
}


int main()
{
	std::cout << "Hello World!" << std::endl;
	return 0;
}