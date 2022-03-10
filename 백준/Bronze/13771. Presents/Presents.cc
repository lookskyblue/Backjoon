#include <stdio.h>

int main()
{
    int max;
    float n[100];
    
    scanf("%d", &max);
    
    for(int i = 0; i < max; i++)
    {
        scanf("%f", &n[i]);
    }
    
    for(int i = 0; i < max - 1; i++)
    {
        int min_idx = i;
        
        for(int j = i + 1; j < max; j++)
        {
            if(n[min_idx] > n[j])
                min_idx = j;
        }
        
        float tmp = n[min_idx];
        n[min_idx] = n[i];
        n[i] = tmp;
    }
    
    printf("%.2f ", n[1]);
    
    return 0;
}