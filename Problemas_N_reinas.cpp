#include <iostream>
#include<vector>

using namespace std;

int diagonal_asc(int x, int y)
{
	int d = x + y;
	return d;
}

int diagonal_des(int x, int y,int NumeroReinas)
{
	int d = x - y+(NumeroReinas-1);
	return d;
}

bool no_ataca(vector<int>& sol, int k , vector<bool>& filas, vector<bool>& d_asc, vector<bool>& d_desc)
{
	bool b = !filas[sol[k]] && !d_asc[diagonal_asc(k, sol[k])] && !d_desc[diagonal_des(k, sol[k], sol.size())];
	return b;
}

bool es_completable(vector<int>& sol, int k, vector<bool>& filas, vector<bool>& d_asc, vector<bool>& d_desc,int tamano)
{
	bool b = (k <tamano-1 ) && no_ataca(sol, k, filas, d_asc, d_desc);
	return b;
}

bool es_solucion(vector<int>& sol, int k, vector<bool>& filas, vector<bool>& d_asc, vector<bool>& d_desc,int tamano)
{

	bool b = (k ==tamano-1 ) && no_ataca(sol, k, filas, d_asc, d_desc);
	return b;
}



void procesar_solucion(int& n)
{
	n++;
}

void cuatro_reinas(vector<int>& sol, int k, vector<bool>& filas, vector<bool>& d_asc, vector<bool>& d_desc, const int tamano,int& n)
{
	for (int i = 0; i < tamano; i++) {
		sol[k] = i;
		if (es_solucion(sol, k, filas, d_asc, d_desc,tamano))
			procesar_solucion(n);
		else if (es_completable(sol, k, filas, d_asc, d_desc,tamano))
		{
			filas[i] = true;
			d_asc[diagonal_asc(k, i)] = true;
			d_desc[diagonal_des(k, i,tamano)] = true;
			cuatro_reinas(sol, k + 1, filas, d_asc, d_desc,tamano,n);
			filas[i] = false;
			d_asc[diagonal_asc(k, i)] = false;
			d_desc[diagonal_des(k,i,tamano)] = false;
		}
	}
}

int main()
{
	int Numpruebas, tamano, numSoluciones;
	cin >> Numpruebas;
	for (int i = 0; i < Numpruebas; i++) {
		numSoluciones = 0;
		cin >> tamano;
		vector<int>v(tamano);
		vector<bool>filas(tamano);
		vector<bool>d_asc(tamano * 2 - 1);
		vector<bool>d_desc(tamano * 2 - 1);
		cuatro_reinas(v, 0, filas, d_asc, d_desc, tamano, numSoluciones);
		cout << numSoluciones<<"\n";
	}
	system("pause");
	return 0;
}