#include <stdio.h>

float fractional_knapsack(int n, float weight[], float profit[], float capacity)
{
    int i, j;
    float ratio[n];

    // calculating the ratios
    for (i = 0; i < n; i++)
        ratio[i] = profit[i] / weight[i];

    // sorting the items by ratio in descending order
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (ratio[j] < ratio[j + 1])
            {
                float temp;

                temp = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp;

                temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;

                temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;
            }
        }
    }

    float maxProfit = 0.0;

    // calculating the main maxProfit
    for (i = 0; i < n; i++)
    {
        if (capacity >= weight[i])
        {
            maxProfit += profit[i];
            capacity -= weight[i];
        }
        else
        {
            maxProfit += profit[i] * (capacity / weight[i]);
            break;
        }
    }

    return maxProfit;
}

int main()
{
    int n, i;
    float capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    float weight[n], profit[n];

    printf("Enter weights:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &weight[i]);

    printf("Enter profits:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &profit[i]);

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    float result = fractional_knapsack(n, weight, profit, capacity);

    printf("Maximum profit = %.2f\n", result);

    return 0;
}
