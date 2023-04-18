#include <stdio.h>
#include <string.h>

void insertionSort(char arr[6][100]);

int main()
{
    char arr[6][100] = {"Srinivas", "Lakshmi", "Gopi", "Krishna", "Rama", "Partha"};
    insertionSort(arr);
    for (int i = 0; i < 6; i++)
    {
        printf("%s ", arr[i]);
    }

    return 0;
}

void insertionSort(char arr[6][100])
{
    for (int i = 1; i < 6; i++)
    {
        int j = i - 1;
        char key[100];
        strcpy(key, arr[i]);
        while (j >= 0 && strcmp(arr[j], key) > 0)
        {
            strcpy(arr[j + 1], arr[j]);
            j--;
        }
        strcpy(arr[j + 1], key);
    }
}