#include <stdlib.h>

int *ft_range(int start, int end)
{
    int *nums;
    int size;
    int count;
    int i = 0;
    if(start == end)
        size = 1;
    else if(start < end)
    {
        size = end - start + 1;
        count = 1;
    }
    else if(start > end)
    {
        size = start - end + 1;
        count = -1;
    }
    if (size != 1 && (start == 0 || end == 0))
    {
        size++; 
    }
    nums = (int *)malloc(size * sizeof(int));
    if(!nums)
        return NULL;
        
    while (i <= size - 1)
    {
        nums[i] = start;
        start += count;
        i++;
    }
    return nums;
}