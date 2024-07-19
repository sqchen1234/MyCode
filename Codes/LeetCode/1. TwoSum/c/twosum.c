#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int *target, int* returnSize) {
    int *returnArray = malloc(2 * sizeof(int));

    for (int i= 0; i < numsSize; i ++)
    {
        for (int j=0; j < numsSize; j ++)
        {
            if (i>=j) {
                // skip
            }else if (nums[i] + nums[j] == *target) {
                returnArray[0] = i;
                returnArray[1] = j;
                break;


            }

        }
    }
    *returnSize = 2;
    return returnArray;
}

int limited_rand(int limit)
{
  int r, d = RAND_MAX / limit;
  limit *= d;
  do { r = rand(); } while (r >= limit);
  return r / d;
}


int *randomNums(int randNumsSize, int *randTarget)
{
    srand(time(NULL));   // Initialization, should only be called once.

    int *randNums;
    randNums = malloc(randNumsSize * sizeof(int));
    int i;
    for ( i = 0; i < randNumsSize; i ++)
    {
        randNums[i] = rand();
    }
    
    int a = limited_rand(randNumsSize), b = limited_rand(randNumsSize);
    *randTarget = randNums[a] + randNums[b];

    printf("The preset result is %d and %d.\n", a, b);
    return randNums;
}

/*
2 <= nums.length <= 10^4
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
*/
int main()
{
    printf ("Two Sum!\n");
// read in the array and target number
    //int nums[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, target = 20, *result;
    int *nums, *result, *target, *resultsize;
    target = malloc(sizeof(int));
    resultsize = malloc(sizeof(int)); 
    int numSize = 100000;
    nums = randomNums(numSize, target);

    //resultsize = 2;
    printf("the size of num[] is %d\n", numSize);
    printf("the target number is %d\n", *target);


// calculate the result
    result = twoSum(nums, numSize, target, resultsize);
// print out the result

    printf ("The result is : %d, %d\n", result[0], result[1]);

    free(result);
   free(resultsize);
   free(nums);
    free(target);

    return 0;


}