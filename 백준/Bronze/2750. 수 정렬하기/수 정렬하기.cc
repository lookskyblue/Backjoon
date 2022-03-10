#include <iostream>

using namespace std;

void SelectionSort(int arr[], int n)
{
    int j;
    int key;
    
    for(int i = 1; i < n; i++)
    {
        key = arr[i];
        
        for(j = i - 1; j >= 0 && key < arr[j]; j--)
        {
            arr[j+1] = arr[j];
        }
        
        arr[j+1] = key;
    }
}

void PrintfArr(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

int main()
{
    const int MAX = 1000;
    int n;
    int arr[MAX] = {0};
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    SelectionSort(arr, n);
    PrintfArr(arr, n);
}