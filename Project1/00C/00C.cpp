#include<iostream>
#include<string>
#include<vector>

using namespace std;

int resolver(int t)
{
	t = t * 2;
	return t;
}

void leerentradayresolver(vector<int> vector)
{
	int n;
	int i = 1;
	cin >> n;
	if (!cin)
	{
		cin >> n;
		vector.push_back(n);
	}

	for (int j = 0; j <vector.size(); j++)
		if (vector[j] != 0)
			cout << resolver(vector[j]) << "\n";
}
int main()
{

	vector<int> vector(0);
	leerentradayresolver(vector);
	system("pause");
	return 0;
}