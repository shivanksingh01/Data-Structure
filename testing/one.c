#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *fptr;
int comp = 0;
int ar[500];
//function to print the array
void printarray(int arr[], int size)
{
    fptr = fopen("input.txt", "a");
    int i, j;
    for (i = 0; i < size; i++)
    {
        fprintf(fptr, "%d", arr[i]);
    }
    fprintf(fptr, "\n");
    fclose(fptr);
}

//function to swap the variables
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//permutation function
void permutation(int *arr, int start, int end)
{
    if (start == end)
    {
        printarray(arr, end + 1);
        return;
    }
    int i;
    for (i = start; i <= end; i++)
    {
        //swapping numbers
        swap((arr + i), (arr + start));
        //fixing one first digit
        //and calling permutation on
        //the rest of the digits
        permutation(arr, start + 1, end);
        swap((arr + i), (arr + start));
    }
}

void qs(char *items, int left, int right);
int quicksort(char *items, int len)
{
    comp = 0;
    qs(items, 0, len - 1);
    return comp;
}

void qs(char *items, int left, int right)
{
    int i, j;
    char x, y;

    i = left;
    j = right;
    x = items[(left + right) / 2];

    do
    {
        while ((items[i] < x) && (i < right))
            i++;
        while ((x < items[j]) && (j > left))
            j--;

        if (i <= j)
        {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++;
            j--;
            comp++;
        }
    } while (i <= j);

    if (left < j)
        qs(items, left, j);
    if (i < right)
        qs(items, i, right);
}

void read_ints()
{
    FILE *file = fopen("input.txt", "r");
    int i = 0;
    int j = 0;

    while (!feof(file))
    {
        printf("\n");
        fscanf(file, "%d", &i);
        ar[j] = i;
        printf("%d  ", ar[j]);
        j++;
    }

    fclose(file);
}
int fact(int n)
{
    int i, f = 1;
    for (i = 1; i <= n; i++)
    {
        f = f * i;
    }
    return f;
}

int main()
{

    int size;
    printf("Enter the size of array\n");
    scanf("%d", &size);
    int i;
    int arr[size];
    for (i = 0; i < size; i++)
        scanf("%d", &arr[i]);

    permutation(arr, 0, size - 1);

    char line[500];
    int cp;
    FILE *fptr;
    FILE *out;
    int tot = 0;
    fptr = fopen("input.txt", "r");
    while (fgets(line, sizeof(line), fptr))
    {
        out = fopen("output.txt", "a");
        cp = quicksort(line, strlen(line));
        tot = tot + cp;
        fprintf(out, "%s\n", line);
        fprintf(out, "No of comparisons %d", cp);
        fprintf(out, "\n");
        fclose(out);
    }
    int fac = fact(size);

    double avg = (double)tot / fac;
    out = fopen("output.txt", "a");
    fprintf(out, "Total no.of comparisons:%d\n", tot);
    fprintf(out, "Average no.of comparisons:%f", avg);

    return 0;
}