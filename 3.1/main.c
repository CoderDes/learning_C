#include <stdio.h>

int binsearch(int target, int sortedList[], int len);

int main(void)
{
    int list[] = {1,2,3,4,5,6,7,8,9,10};
    int target = 11;
    printf("target: %d, target index: %d\n", target, binsearch(target,list, 10));
    return 0;
}

int binsearch(int target, int sortedList[], int len)
{
    int lowIndex = 0;
    int highIndex = len - 1;
    int midIndex = (highIndex + lowIndex) / 2;
    while (lowIndex <= highIndex && target != sortedList[midIndex]) {
        if (target < sortedList[midIndex]) {
            highIndex = midIndex - 1;
        }
        else {
            lowIndex = midIndex + 1;
        }
        midIndex = (highIndex + lowIndex) / 2;
    }
    return target == sortedList[midIndex] ? midIndex : -1;
}