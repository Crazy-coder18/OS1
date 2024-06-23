#include <stdio.h>

void main() {
    int i, j, n, a[50], frame[10], fno, k, avail, pagefault = 0;

    // Prompt the user for the number of frames
    printf("\nEnter the number of Frames: ");
    scanf("%d", &fno);

    // Prompt the user for the number of references in the reference string
    printf("\nEnter the number of reference string: ");
    scanf("%d", &n);

    // Prompt the user to enter the reference string
    printf("\nEnter the Reference string:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize all frames to -1 (indicating they are empty)
    for (i = 0; i < fno; i++) {
        frame[i] = -1;
    }

    j = 0;

    // Print the reference string
    printf("\nFIFO Page Replacement Algorithm\n\nThe given reference string is:\n\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Process each page in the reference string
    for (i = 0; i < n; i++) {
        printf("\nReference No %d -> ", a[i]);
        avail = 0;

        // Check if the page is already in a frame
        for (k = 0; k < fno; k++) {
            if (frame[k] == a[i]) {
                avail = 1;
                break;
            }
        }

        // If the page is not available in frames, replace it using FIFO
        if (avail == 0) {
            frame[j] = a[i];
            j = (j + 1) % fno;
            pagefault++;

            // Print the current state of frames
            for (k = 0; k < fno; k++) {
                if (frame[k] != -1) {
                    printf("%2d ", frame[k]);
                }
            }
        }
        printf("\n");
    }

    // Print the total number of page faults
    printf("\nPage Fault Is %d\n", pagefault);
}
