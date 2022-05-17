#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
	char source_file[512] = ""; 
	char dest_file[512] = "";
	strcpy(source_file, "./");

	printf("\nEnter the name of the source file:  ");
	scanf("%s", dest_file);

	strncat( source_file, dest_file, 128 );

//	if( access( source_file, F_OK ) != -1)
//	{
//		printf("file is found");
//	}
//	else
//  {
//		printf("file is not found");
//		return -1;
//  }

	strcpy(dest_file, "./");

	printf("\nThe name of the source file is           :=  %s\n", source_file);

	printf("\nEnter the name of the destination file:  ");
	scanf("%s", dest_file);
	printf("\nThe name of the destination file is      :=  %s\n\n", dest_file);

	return 0;
}

