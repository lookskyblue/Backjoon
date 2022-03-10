#include<stdio.h>

void Swap(int &a, int &b) { int tmp = a; a = b; b = tmp; }

void InsertionSort(int arr[], const int MAX)
{
    for(int i = 0; i < MAX - 1; i++)
    {
        int least = i;
        
        for(int j = i + 1; j < MAX; j++)
        {
            if(arr[least] > arr[j])
            {
                least = j;
            }
        }
        
        Swap(arr[least], arr[i]);
    }
}

int main()
{
    const int MAX_JUDGMENT = 5;
    int n;
    
    int arr[MAX_JUDGMENT];
    
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++)
    {
        for(int i = 0; i < MAX_JUDGMENT; i++)
        {
            scanf("%d", &arr[i]);
        }
            
        InsertionSort(arr, MAX_JUDGMENT);
        
        if(arr[3] - arr[1] >= 4)
            printf("KIN\n");
            
        else
            printf("%d\n", arr[1] + arr[2] + arr[3]);
    }
    
    return 0;
}