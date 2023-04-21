#include <stdio.h>
 
int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n)
{

    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);

    else
        return max(
            val[n - 1]
                + knapSack(W - wt[n - 1], wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}

int main()
{
    int Value[] = {1,2,5,4,5};
    int size[] = {1,3,2,5,4};
    int maxWeight = 9;
    int n = sizeof(Value) / sizeof(Value[0]);
    printf("%d", knapSack(maxWeight, size, Value, n));
    return 0;
}

