#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
	char source_file[512] = ""; 
	char temp[512]        = "";
	char dest_file[512]   = "";
	
	FILE *fptr1, *fptr2;
	char filename[100], c;

	strcpy(source_file, "./");
	printf("\nEnter the name of the source file:  ");
	scanf("%s", temp);
	strncat( source_file, temp, 128 );

	if( access( source_file, F_OK ) == -1)
  {
		printf("\nSource file does not exist\n");
		return -1;
  }

	// Open file pointer for reading
  fptr1 = fopen(source_file, "r");
  if (fptr1 == NULL)
	{
		printf("Cannot open file %s \n", source_file);
		return -1;
  }

	strcpy(dest_file, "./");
	printf("\nEnter the name of the destination file:  ");
	scanf("%s", temp);
	strncat( dest_file, temp, 128 );


	// Open file pointer for writing
	fptr2 = fopen(dest_file, "w");
	if (fptr2 == NULL)
	{
		printf("Cannot open file %s \n", dest_file);
		return -1;
	}
	
	// Read contents from file
	c = fgetc(fptr1);
	while (c != EOF)
	{
		fputc(c, fptr2);
		c = fgetc(fptr1);
	}
	
	printf("\nContents copied to %s\n",dest_file );

	return 0;
}

