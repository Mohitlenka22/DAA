#include <stdio.h>
#include <string.h>

void selectionSort(char arr[6][100]);

int main()
{
    char arr[6][100] = {"Srinivas", "Lakshmi", "Gopi", "Krishna", "Rama", "Partha"};
    selectionSort(arr);

    for (int i = 0; i < 6; i++)
    {
        printf("%s ", arr[i]);
    }
    return 0;
}

void selectionSort(char arr[6][100])
{
    for (int i = 0; i < 5; i++)
    {
        int min = i;
        for (int j = i + 1; j < 6; j++)
        {
            if (strcmp(arr[j], arr[min]) < 0)
            {
                min = j;
            }
        }
        char t[100];
        strcpy(t, arr[min]);
        strcpy(arr[min], arr[i]);
        strcpy(arr[i], t);
    }
}