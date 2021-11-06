#include <stdio.h>

// 
// Pointers and references explained
// 

int main()
{

    int my_num = 45;
    int *my_ptr = NULL;
    int **my_ref = &my_ptr;
    if(my_ptr == NULL) printf("my_ptr is a Null pointer\n");
    else printf("my_ptr = %p\n", my_ptr);
    if(my_ref == NULL) printf("my_ref is a Null pointer\n");
    else printf("my_ref = %p\n", my_ref);

    return 0;
}
