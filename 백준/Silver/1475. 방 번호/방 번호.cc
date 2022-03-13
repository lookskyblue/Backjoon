#include <iostream>
using namespace std;

int N;
int arr[10];

void Solve()
{
    while(N != 0)
    {
        arr[N % 10]++;
        N /= 10;
    }
    
    int max_num = 0;
    int max_count = 0;
    int second_max_num = 0;
    int second_max_count = 0;
    
    for(int i = 0; i < 10; i++)
    {
        if(max_count < arr[i])
        {
            max_count = arr[i];
            max_num = i;
        }
    }
    
    for(int i = 0; i < 10; i++)
    {
        if(i == max_num) continue;
        if(second_max_count < arr[i])
        {
            second_max_count = arr[i];
            second_max_num = i;
        }
    }
    
    if(max_num == 6 || max_num == 9)
    {
        int sum_six_nine = arr[6]+arr[9];
        max_count = sum_six_nine % 2 == 0 ? sum_six_nine/2 : sum_six_nine  / 2 + 1;
        
        if(second_max_count > max_count)
            cout << second_max_count;
            
        else
            cout << max_count;
    }
    
    else
        cout << max_count;
}

int main()
{
    cin >> N;
    Solve();

	return 0;
}