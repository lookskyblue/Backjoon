#include <stdio.h>

int main()
{
    const int MAX = 4;
    int n[MAX];
    
    for(int i = 0; i < MAX; i++)
    {
        scanf("%d", &n[i]);
    }
    
    for(int i = 0; i < MAX - 1; i++)
    {
        int max_idx = i;
        
        for(int j = i + 1; j < MAX; j++)
        {
            if(n[max_idx] < n[j])
            {
                max_idx = j;
            }
        }
        
        int tmp = n[i];
        n[i] = n[max_idx];
        n[max_idx] = tmp;
    }
    
    int second_max = n[1];
    int least = n[MAX-1];
   
    printf("%d", second_max * least);
    
    return 0;
}