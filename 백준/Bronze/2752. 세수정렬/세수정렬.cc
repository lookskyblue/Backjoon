#include <stdio.h>

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    const int MAX = 3;
    int n[MAX];
    
    for(int i = 0; i < MAX; i++)
    {
        scanf("%d", &n[i]);
    }
    
    
    
    for(int i = 0; i < MAX - 1; i++)
    {
        int min_idx = i;
        
        for(int j = i + 1; j < MAX; j++)
        {
            if(n[min_idx] > n[j])
            {
                min_idx = j;
            }
        }
        
        swap(n[i], n[min_idx]);
    }
    
    for(int i = 0; i < MAX; i++)
        printf("%d ", n[i]);
    
    return 0;
}