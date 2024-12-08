#include <stdio.h>
#include <stdlib.h>

struct values
{
    int profit;
    int weight;
};


int compare(const void *x_void, const void *y_void)
{
    struct values *x = (struct values *)x_void;
    struct values *y = (struct values *)y_void;

    double r1 = (double)x->profit / x->weight;
    double r2 = (double)y->profit / y->weight;

    if (r1 < r2) return 1;
    if (r1 > r2) return -1;
    return 0;
}

int main()
{
    int profit[] = {60, 100, 120};
    int weight[] = {10, 20, 30};
    int tarWeight = 50;

    int n = sizeof(profit) / sizeof(profit[0]);
    struct values set[n];

    for (int i = 0; i < n; i++)
    {
        set[i].profit = profit[i];
        set[i].weight = weight[i];
    }


    qsort(set, n, sizeof(struct values), compare);

    double toValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (set[i].weight <= tarWeight)
        {

            toValue += set[i].profit;
            tarWeight -= set[i].weight;
        }
        else
        {

            toValue += (double)set[i].profit / set[i].weight * tarWeight;
            break;
        }
    }

    printf("Maximum Profit: %.2f\n", toValue);

    return 0;
}
