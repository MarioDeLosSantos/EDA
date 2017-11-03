#include <iostream>
#include <vector>
#include <string>


using namespace std;

bool elemento_situado(const vector < int >& v, int ini, int fin)
{
	int mitad;
	if (v.size() == 0) {
		return true;
	}
	else if (fin == ini)
	{
		if (v[fin] == fin)
		{
			return true;
		}
		else if (v[ini] == ini)
		{
			return true;
		}
		else return false;
	}
	else
	{
		mitad = (fin + ini) / 2;
		if (v[mitad] > mitad) { //atras
			return elemento_situado(v, ini, mitad);
		}
		else if (v[mitad] < mitad) { //Alante

			return elemento_situado(v, mitad + 1, fin);
		}
		else return true;
	}
}

void creaVector(int n, vector <int>& v) {
	int elem;
	v.clear();
	if (n != 0)
	{
		for (unsigned int i = 0; i < n; i++)
		{
			cin >> elem;
			v.push_back(elem);
		}
	}
}

int main()
{
	vector <int> v;
	vector <string> s;
	int numVectores, longitud;
	cin >> numVectores;
	for (unsigned int i = 0; i < numVectores; i++)
	{
		cin >> longitud;
		creaVector(longitud, v);
		if (elemento_situado(v, 0, v.size() - 1)) s.push_back("SI");
		else s.push_back("NO");
	}

	for (unsigned int j = 0; j < s.size(); j++)
	{
		cout << s[j] << endl;
	}
	system("pause");
	return 0;
}