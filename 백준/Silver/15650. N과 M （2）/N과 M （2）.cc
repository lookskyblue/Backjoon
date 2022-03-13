#include <iostream>

using namespace std;

int N, M;
int arr[9];

void DFS(int idx, int cnt)
{
    if(cnt == M)
    {
        for(int i = 0; i < cnt; i++)
            cout << arr[i] << " ";
        cout << '\n';
        
        return;
    }
    
    for(int i = idx; i <= N; i++)
    {
        arr[cnt] = i;
        DFS(i + 1, cnt + 1);
    }
}

int main()
{
    cin >> N >> M;
    
    DFS(1, 0);

    return 0;
}