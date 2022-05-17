#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
	char source_file[512] = ""; 
	char temp[512]        = "";
	char dest_file[512]   = "";

	strcpy(source_file, "./");
	printf("\nEnter the name of the source file:  ");
	scanf("%s", temp);
	strncat( source_file, temp, 128 );

	if( access( source_file, F_OK ) == -1)
  {
		printf("\nSource file does not exist\n");
		return -1;
  }

	strcpy(dest_file, "./");
	printf("\nEnter the name of the destination file:  ");
	scanf("%s", temp);
	strncat( dest_file, temp, 128 );





	return 0;
}

