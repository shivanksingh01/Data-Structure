//  find next letter in an character array  (similar to ceil )
#include<stdio.h>
char nextAlphabeticalLetter(char arr[],int n, char key){
    int low = 0, high = n-1;
    char res = '#';
    
    while (low<=high){
        int mid = low+(high-low)/2;
        if (arr[mid]==key){
                low  = mid + 1; //continue search in right sub-array
        }
        else if (key > arr[mid] ){
            low= mid+1;
        }
        else if (key < arr[mid]){
            res = arr[mid];  //can be q candidate for ceil, store character
            high = mid-1;
        }
    }
    return res;  
}

int main(){
    char arr[] = {'a', 'c', 'f', 'g', 'h', 'k', 's'};
    int n = sizeof(arr)/sizeof(char);
    char key = 'g';
    printf("key : %c\n", key);
    printf("character array : ");
    for (int i = 0; i < n; i++)
    {
        printf("%c\t", arr[i]);
    }
    printf("\n");
    
    printf("next letter  : %c\n", nextAlphabeticalLetter(arr, n, key));
    return 0;
}