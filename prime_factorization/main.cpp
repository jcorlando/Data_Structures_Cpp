#include <iostream>


void factorize(int num)
{
	int i = 2;
	int j;
	int k;

	while(i < num)
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
	
	return 0;
}