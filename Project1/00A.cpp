#include<iostream>
#include<string>
#include<vector>
using namespace std;



int resolver(int t)
{
	t = t * 2;
	return t;
}

void leerpantallayresuelve(int n,vector <int>& vector)
{
	for (int i = 0; i < n; i++)
		cin >> vector[i];
	for (int j = 0; j < n; j++)
		cout << resolver(vector[j]) << "\n";
}
int main()
{
	int n;
	cin >> n;
	vector<int> vector(n);
	leerpantallayresuelve(n, vector);
	system("pause");
	return 0;
}