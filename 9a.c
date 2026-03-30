#include <stdio.h>

int main() {
    int pages[50], frame[10], n, f, i, j, k, pos, faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter pages: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frame[i] = -1;

    for(i = 0; i < n; i++) {
        int found = 0;

        for(j = 0; j < f; j++) {
            if(frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            int farthest = -1;
            pos = -1;

            for(j = 0; j < f; j++) {
                int k;
                for(k = i+1; k < n; k++) {
                    if(frame[j] == pages[k])
                        break;
                }

                if(k > farthest) {
                    farthest = k;
                    pos = j;
                }
            }

            frame[pos] = pages[i];
            faults++;
        }
    }

    printf("Total Page Faults = %d\n", faults);
    return 0;
}
