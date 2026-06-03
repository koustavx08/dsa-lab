#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int profit;
    int deadline;
} Job;

int i, j;

// comparator function for sorting jobs by profit (descending)
int compare(const void *a, const void *b) {
    Job *j1 = (Job *)a;
    Job *j2 = (Job *)b;

    return j2->profit - j1->profit;
}

void jobSequencing(int deadline[], int profit[], int n) {
    Job jobs[n];

    for(i = 0; i < n; i++) {
        jobs[i].id = i + 1;
        jobs[i].profit = profit[i];
        jobs[i].deadline = deadline[i];
    }

    // sort jobs according to profit
    qsort(jobs, n, sizeof(Job), compare);

    int slot[n];
    int selected[n];

    for(i = 0; i < n; i++) {
        slot[i] = 0;
        selected[i] = -1;
    }

    int count = 0;
    int totalProfit = 0;

    // schedule jobs
    for(i = 0; i < n; i++) {
        int start;

        if(jobs[i].deadline < n)
            start = jobs[i].deadline - 1;
        else
            start = n - 1;

        for(j = start; j >= 0; j--) {
            if(slot[j] == 0) {
                slot[j] = 1;
                selected[j] = jobs[i].id;

                count++;
                totalProfit += jobs[i].profit;

                break;
            }
        }
    }

    printf("\nJobs Selected: ");

    for(i = 0; i < n; i++) {
        if(selected[i] != -1)
            printf("Job%d ", selected[i]);
    }

    printf("\nNumber of Jobs Done = %d", count);
    printf("\nMaximum Profit = %d\n", totalProfit);
}

int main() {
    int n, i;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    int deadline[n], profit[n];

    printf("Enter deadlines:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &deadline[i]);

    printf("Enter profits:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &profit[i]);

    jobSequencing(deadline, profit, n);

    return 0;
}
