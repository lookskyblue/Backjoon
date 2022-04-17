#include <iostream>
#include <map>
#include <stack>
#include <cctype>

using namespace std;

map<char, int> alpha_map;
stack<double> s;

double Calculate(double a, double b, char letter)
{
	if (letter == '*') return a * b;
	if (letter == '/') return a / b;
	if (letter == '+') return a + b;
	if (letter == '-') return a - b;
}

void Solve(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		char letter = str[i];

		if (letter >= 'A' && letter <= 'Z') // 알파벳이면
		{
			s.push(alpha_map[letter]);
		}
		else // 연산자면
		{
			double a, b;

			b = s.top();
			s.pop();
			a = s.top();
			s.pop();

			double result = Calculate(a, b, letter);

			s.push(result);
		}
	}

	//cout << fixed;
	//cout.precision(2);
	
	printf("%.2f", s.top());
	//cout << s.top();
}

void Input()
{
	string str;
	int N;
	
	cin >> N;
	cin >> str;

	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;

		alpha_map.insert({ 'A' + i, x });
	}

	Solve(str);
}

int main()
{
	Input();

	return 0;
}
