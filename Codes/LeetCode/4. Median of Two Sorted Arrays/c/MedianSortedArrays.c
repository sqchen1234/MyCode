#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Constraints:

    nums1.length == m
    nums2.length == n
    0 <= m <= 1000
    0 <= n <= 1000
    1 <= m + n <= 2000
    -10^6 <= nums1[i], nums2[i] <= 10^6

*/

int limited_rand(int limit)
{
  int r, d = RAND_MAX / limit;
  limit *= d;
  do { r = rand(); } while (r >= limit & r >= 0);
  return r / d;
}

int compare_function(const void *a,const void *b) {
    int *x = (int *) a;
    int *y = (int *) b;
    return *x - *y;
}

int *randomNums(int randNumsSize)
{

    int *randNums;
    randNums = malloc(randNumsSize * sizeof(int));
    int i;
    for ( i = 0; i < randNumsSize; i ++)
    {
        randNums[i] = rand();
    }
    

    return randNums;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    double result;

    int k = (nums1Size + nums2Size + 1) / 2;
    int cutstart1 = 0, cutstart2 = 0;
    int cutend1 = 0, cutend2 = 0;

    while (k>1)
    {
        cutend1 += k/2;
        cutend2 += k/2;

        //throw away kth smallest numbers. 
        if (nums1[cutend1] > nums2[cutend2])
        {
            cutstart2 = cutend2 + 1;
        }else{
            cutstart1 = cutend1 + 1;
        }
        k /= 2;
    }

    result = (nums1[cutstart1] + nums2[cutstart2]) /2;

    return result;
}

int main(void)
{
    printf ("4. Median Sorted Arrays.\n");

    //generate 2 sorted arrays
    int *nums1, nums1size, *nums2, nums2size;
    srand(time(NULL));   // Initialization, should only be called once.
    

    nums1size = limited_rand(10000);
    nums2size = limited_rand(10000);
    printf("num1 size is: %d; num2 size is: %d \n", nums1size, nums2size);
        
    nums1 = randomNums(nums1size);
    nums2 = randomNums(nums2size);

    qsort(nums1, nums1size, sizeof(int), compare_function);
    qsort(nums2, nums2size, sizeof(int), compare_function);



    //find the Median
    printf("the median is : %f", findMedianSortedArrays(nums1, nums1size, nums2, nums2size));

    //cleanup 
    free(nums1);
    free(nums2);  
    return 0;
}