#include <stdio.h>

int main()
{
    const int MAX = 9;
    int n[MAX];
    int sum = 0;
    int two_people_sum;
    int fake_people_idx[2];
    
    for(int i = 0; i < MAX; i++)
    {
        scanf("%d", &n[i]);
        sum += n[i];
    }
    
    two_people_sum = sum - 100;
    
    for(int i = 0; i < MAX -1; i++)
    {
        int least = i;
        
        for(int j = i + 1; j < MAX; j++)
        {
            if(n[least] > n[j])    
            {
                int tmp = n[j];
                n[j] = n[least];
                n[least] = tmp;
            }
        }
    }
    
    for(int i = 0; i < MAX -1; i++)
    {
        for(int j = i+1; j < MAX; j++)
        {
            if(n[i] + n[j] == two_people_sum)
            {
                fake_people_idx[0] = i;
                fake_people_idx[1] = j;
                break;
            }
        }
    }
    
    for(int i = 0; i < MAX; i++)
    {
        if(i == fake_people_idx[0] || i == fake_people_idx[1])
            continue;
            
        printf("%d\n", n[i]);
    }
    
    return 0;
}