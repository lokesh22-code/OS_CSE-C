#include <stdio.h>

int main() {
    int bt[20], rem[20], wt[20], tat[20];
    int n, tq, i, time = 0, remain;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Burst Time:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rem[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    remain = n;

    while(remain != 0) {
        for(i = 0; i < n; i++) {
            if(rem[i] > 0) {
                if(rem[i] <= tq) {
                    time += rem[i];
                    wt[i] = time - bt[i];
                    rem[i] = 0;
                    remain--;
                } else {
                    time += tq;
                    rem[i] -= tq;
                }
            }
        }
    }

    for(i = 0; i < n; i++)
        tat[i] = bt[i] + wt[i];

    printf("\nBT\tWT\tTAT\n");
    for(i = 0; i < n; i++)
        printf("%d\t%d\t%d\n", bt[i], wt[i], tat[i]);

    return 0;
}
