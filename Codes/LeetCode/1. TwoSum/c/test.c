#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf ("test!\n");

    int *nums, *result, *target;
    nums = (int*)malloc(3);
    result = (int*)malloc(2);
    target = (int*)malloc(sizeof(int));


    free(nums);
    free(result);
    free(target);
   return 0;


}