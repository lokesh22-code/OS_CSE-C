#include <stdio.h>

int main() {
    int pages[50], frame[10], n, f, i, j, k, flag, faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frame[i] = -1;

    j = 0;

    for(i = 0; i < n; i++) {
        flag = 0;

        for(k = 0; k < f; k++) {
            if(frame[k] == pages[i]) {
                flag = 1;
                break;
            }
        }

        if(flag == 0) {
            frame[j] = pages[i];
            j = (j + 1) % f;
            faults++;
        }
    }

    printf("Total Page Faults = %d\n", faults);
    return 0;
}
