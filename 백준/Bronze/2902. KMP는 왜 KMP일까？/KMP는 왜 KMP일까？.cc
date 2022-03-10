#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

void ShowEachUpperAlpha(string str)
{
    char* word = strtok((char*)str.c_str(), "-");

    while (word != nullptr)
    {
        cout << word[0];
        word = strtok(NULL, "-");
    }
}

int main()
{
    string str;

    cin >> str;

    ShowEachUpperAlpha(str);

    return 0;
}