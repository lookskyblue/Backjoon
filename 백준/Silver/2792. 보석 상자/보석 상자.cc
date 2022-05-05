#include <stdio.h>
long long j[300010] = {};
 
int main(void){
 
    long long  N, M;
    long long result=1000000000;
    long long max = 0;
    scanf("%lld %lld", &N, &M);
 
    for (int i = 0; i < M; i++){
        scanf("%lld", &j[i]);
        if (max < j[i])
            max = j[i];
    }
 
    long long left = 1, right = max;
    
    while (left <= right){
        long long mid = (left + right) / 2;
        long long tempT = 0;
        
        for (int i = 0; i < M; i++)
        {
            tempT += j[i] / mid;
            if (j[i]%mid != 0)
                tempT++;
        }
 
        if (tempT <= N){
            right = mid - 1;
            if (mid<result)
            result = mid;
        }
        else
            left = mid + 1;
 
    }
 
    printf("%lld\n", result);
 
}
