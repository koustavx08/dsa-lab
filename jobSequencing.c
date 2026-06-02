#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int profit;
    int deadline;
} Job;

// Comparator for sorting jobs by profit in descending order
int compare(const void *a, const void *b) {
    Job *j1 = (Job *)a;
    Job *j2 = (Job *)b;
    return j2->profit - j1->profit;
}

void jobSequencing(int deadline[], int profit[], int n) {
    Job jobs[n];

    // Create job array
    for (int i = 0; i < n; i++) {
        jobs[i].profit = profit[i];
        jobs[i].deadline = deadline[i];
    }

    // Sort jobs by profit
    qsort(jobs, n, sizeof(Job), compare);

    int slot[n];
    for (int i = 0; i < n; i++)
        slot[i] = 0;

    int count = 0;
    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        int start = (jobs[i].deadline < n) ? jobs[i].deadline - 1 : n - 1;

        for (int j = start; j >= 0; j--) {
            if (slot[j] == 0) {
                slot[j] = 1;
                count++;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("\nNumber of jobs done = %d", count);
    printf("\nMaximum profit = %d\n", totalProfit);
}

int main() {
    int n;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    int deadline[n], profit[n];

    printf("Enter deadlines:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &deadline[i]);
    }

    printf("Enter profits:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &profit[i]);
    }

    jobSequencing(deadline, profit, n);

    return 0;
}
