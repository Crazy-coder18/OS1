#include <stdio.h>

void main() {
    int i, j, temp, framearr[20], pages, pageno, frames, memsize, log, pagesize, prosize, base;

    // Input process size
    printf("Enter the Process size: ");
    scanf("%d", &prosize);

    // Input main memory size
    printf("\nEnter the main memory size: ");
    scanf("%d", &memsize);

    // Input page size
    printf("\nEnter the page size: ");
    scanf("%d", &pagesize);

    // Calculate the number of pages
    pages = prosize / pagesize;
    printf("\nThe process is divided into %d pages", pages);

    // Calculate the number of frames
    frames = memsize / pagesize;
    printf("\n\nThe main memory is divided into %d frames\n", frames);

    // Initialize frame array to -1 (indicating empty frames)
    for (i = 0; i < frames; i++) {
        framearr[i] = -1;
    }

    // Input frame number for each page
    for (i = 0; i < pages; i++) {
        pos:
        printf("\nEnter the frame number of page %d: ", i);
        scanf("%d", &temp);

        // Check for invalid frame number
        if (temp >= frames) {
            printf("\n\t****Invalid frame number****\n");
            goto pos;
        }

        // Assign page to the frame
        for (j = 0; j < frames; j++) {
            if (temp == j) {
                framearr[temp] = i;
            }
        }
    }

    // Display frame, page, and validation bit
    printf("\n\nFrame No\tPage No\tValidation Bit\n--------\t-------\t--------------");
    for (i = 0; i < frames; i++) {
        printf("\n %d \t\t %2d \t", i, framearr[i]);
        if (framearr[i] == -1) {
            printf("0");
        } else {
            printf("1");
        }
    }

    // Input logical address and base address
    printf("\nEnter the logical address: ");
    scanf("%d", &log);
    printf("\nEnter the base address: ");
    scanf("%d", &base);

    // Calculate page number from logical address
    pageno = log / pagesize;

    // Find the corresponding frame number
    for (i = 0; i < frames; i++) {
        if (framearr[i] == pageno) {
            temp = i;
            break;
        }
    }

    // Calculate offset within the page
    j = log % pagesize;

    // Calculate the physical address
    temp = base + (temp * pagesize) + j;

    // Display physical address
    printf("\nPhysical address is: %d", temp);
}
