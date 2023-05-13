#include <stdio.h>

#define MAX_SIZE 100

void findSubsets(int set[], int subset[], int n, int sum, int currSum, int index)
{
    if (currSum == sum)
    {
        printf("{");
        for (int i = 0; i < index; i++)
            printf("%d, ", subset[i]);
        printf("\b\b}\n");
        return;
    }

    if (n == 0 || currSum > sum)
        return;

    subset[index] = set[0];
    //Take element
    findSubsets(set + 1, subset, n - 1, sum, currSum + set[0], index + 1);
    //notTake element
    findSubsets(set + 1, subset, n - 1, sum, currSum, index);
}

int main()
{
    int set[MAX_SIZE], subset[MAX_SIZE];
    int n, sum;

    printf("Enter the size of the set: ");
    scanf("%d", &n);

    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &set[i]);

    printf("Enter the sum to find subsets: ");
    scanf("%d", &sum);

    printf("Subsets with sum %d:\n", sum);
    findSubsets(set, subset, n, sum, 0, 0);

    return 0;
}

//0-n-1
//subset = a[0] , curr+=a[0]
//a[i]>curr_sum
//curr
//curr=sum