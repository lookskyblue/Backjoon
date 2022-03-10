#include<stdio.h>

void Swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

void SelectionSort(int arr[], const int MAX)
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
    const int MAX = 10;
    int w[MAX];
    int k[MAX];
    
    for(int i = 0; i < (MAX * 2); i++)
    {
        if(i < 10)
        {
            scanf("%d", &w[i]);
        }
        
        else
        {
            scanf("%d", &k[i - MAX]);
        }
            
    }
 
    SelectionSort(w, MAX);
    SelectionSort(k, MAX);
    
    int w_sum = 0;
    int k_sum = 0;
    
    for(int i = 0; i < 3; i++)
    {
        w_sum += w[MAX-1 - i];
        k_sum += k[MAX-1 - i];
    }
    
    printf("%d %d", w_sum, k_sum);
    
    return 0;
}