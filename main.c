

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0;
    int N;
    FILE *bubble;
    bubble = fopen("result.txt", "w"); // Create the text file
    if (bubble == NULL) {
        printf("Failed to create the file.");
        return 1;
    }

    printf("How many numbers do you want to enter: ");
    scanf("%d", &N);

    int *arr = malloc(N * sizeof(int)); // Allocate dynamic memory
    if (arr == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }

    while (i < N)
    {
        printf("Enter the number: ");
        scanf("%d", &arr[i]);
        fprintf(bubble, "%d ", arr[i]); // Write the numbers to the file
        i++;
    }

    int j, temp;
    for (i = 0; i < (N - 1); i++) // Bubble sort the numbers
    {
        for (j = 0; j < N - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    fprintf(bubble, "\nTHE RESULT\n");
    for (i = 0; i < N; i++) // Write the sorted array to the file
    {
        fprintf(bubble, "%d ", arr[i]);
    }

    fclose(bubble);
    free(arr); // Free the allocated memory

    return 0;
}



