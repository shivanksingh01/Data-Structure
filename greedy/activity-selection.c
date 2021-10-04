#include <stdio.h>
void activities(int a[], int s[], int f[], int n)
{
    int i, j;
    printf("Selected Activities are : ");
    i = 0;
    printf("A%d ", a[i]);
    for (j = 1; j < n; j++){
        if (s[j] >= f[i])
        {
            printf("A%d ", a[j]);
            i = j;
        }
    }
}
int main()
{
    int s[100], f[100], a[100], n, i, j, swap, swap1, swap2;
    printf("Enter number of elements\n");
    scanf("%d", &n);
    printf("Enter %d integers of Item Number : \n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter %d integers of start time : \n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &s[i]);
    printf("Enter %d integers of end time : \n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &f[i]);         // Sort by finish time in ascending order 
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if (f[j] > f[j + 1])
            {
                swap = s[j];
                s[j] = s[j + 1];
                s[j + 1] = swap;
                swap1 = f[j];
                f[j] = f[j + 1];
                f[j + 1] = swap1;
                swap2 = a[j];
                a[j] = a[j + 1];
                a[j + 1] = swap2;
            } //if
        }     //d
    }         //c
    activities(a, s, f, n);
    return 0;
}