#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

void read_numbers_from_file(const char *filename, int *array, int n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &array[i]);
    }
    fclose(file);
}

int count_duplicates(int *array, int n) {
    int count = 0;
    bool counted[n];

    for (int i = 0; i < n; i++) {
        counted[i] = false; 
    }

    for (int i = 0; i < n; i++) {
        if (!counted[i]) { 
            bool is_duplicate = false;
            for (int j = i + 1; j < n; j++) {
                if (array[i] == array[j]) {
                    is_duplicate = true;
                    counted[j] = true;
                }
            }
            if (is_duplicate) {
                count++;
            }
        }
    }
    return count;
}

int most_repeating_element(int *array, int n) {
    int max_count = 0;
    int most_repeating = array[0];
    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (array[i] == array[j]) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            most_repeating = array[i];
        }
    }
    return most_repeating;
}

int main() {
    const char *filename = "q1_3_test.txt";
    int n;

    printf("Enter how many numbers you want to read from file: ");
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("Error: Maximum allowed number is %d\n", MAX_SIZE);
        return 1;
    }

    int array[MAX_SIZE];
    read_numbers_from_file(filename, array, n);

    printf("The content of the array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    int total_duplicates = count_duplicates(array, n);
    printf("Total number of duplicate values = %d\n", total_duplicates);

    int most_repeating = most_repeating_element(array, n);
    printf("The most repeating element in the array = %d\n", most_repeating);

    return 0;
}
