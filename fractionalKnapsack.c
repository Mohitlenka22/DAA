#include <stdio.h>

void swap(float *a, float *b)
{
    float t = *a;
    *a = *b;
    *b = t;
}

void SelectionSort(float p[], float w[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int max = i;
        for (int j = i + 1; j < n; j++)
        {
            if ((p[j] / w[j]) > (p[max] / w[max]))
                max = j;
        }
        if (max != i)
        {
            swap(&p[i], &p[max]);
            swap(&w[i], &w[max]);
        }
    }
}

void FractionalKnapsack(float w[], float p[], int n, float M)
{
    float x[n], rc = M, maxp = 0.0;
    for (int i = 0; i < n; i++)
        x[i] = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (w[i] > rc)
        {
            x[i] = rc / w[i];
            maxp += p[i] * x[i];
            break;
        }
        else
        {
            x[i] = 1.0;
            maxp += p[i];
            rc -= w[i];
        }
    }
    printf("Solution vector: ");
    for (int i = 0; i < n; i++)
        printf("%f ", x[i]);
    printf("\nmaxp: %f\n", maxp);
}

int main()
{
    int n;
    scanf("%d", &n);
    float w[n], p[n];
    for (int i = 0; i < n; i++)
        scanf("%f%f", &w[i], &p[i]);
    float M;
    scanf("%f", &M);
    // sorting
    SelectionSort(p, w, n);
    for (int i = 0; i < n; i++)
        printf("%f %f ", p[i], w[i]);
    FractionalKnapsack(w, p, n, M);

    return 0;
}







// #include <stdio.h>

// void knapsack(int n, float w[], float p[], float M);

// void swap(float *a, float *b)
// {
//     float temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int main()
// {
//     float w[20], p[20], M;
//     int n;
//     float ratio[20];

//     printf("Enter the no. of objects:- ");
//     scanf("%d", &n);

//     printf("Enter the ws and ps of each object:- ");
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%f %f", &w[i], &p[i]);
//     }

//     printf("enter the capacity of knapsack:- ");
//     scanf("%f", &M);

//     for (int i = 0; i < n; i++)
//     {
//         ratio[i] = p[i] / w[i];
//     }

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (ratio[i] < ratio[j])
//             {
//                 swap(&ratio[i], &ratio[j]);
//                 swap(&w[i], &w[j]);
//                 swap(&p[i], &p[j]);
//             }
//         }
//     }

//     knapsack(n, w, p, M);

//     return 0;
// }

// void knapsack(int n, float w[], float p[], float M)
// {
//     float x[20], maxp = 0;
//     int rc;
//     rc = M;

//     for (int i = 0; i < n; i++)
//         x[i] = 0.0;

//     for (int i = 0; i < n; i++)
//     {
//         if (w[i] > rc)
//         {
//             x[i] = rc / w[i];
//             maxp = maxp + (x[i] * p[i]);
//             break;
//         }
//         else
//         {
//             x[i] = 1.0;
//             maxp = maxp + p[i];
//             rc = rc - w[i];
//         }
//     }

//     printf("\n The result vector is:- ");
//     for (int i = 0; i < n; i++)
//         printf("%f ", x[i]);
//     printf("\n");
//     printf("Maximum p is:- %f", maxp);
// }
