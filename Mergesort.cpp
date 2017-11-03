#include <vector>
#include <iostream>
using namespace std;
void Mergesort(vector<int> & bar);
void merge(vector<int>&left, vector<int>& right, vector<int>& bars);

int main() {
	vector<int>v{ 7,10,15,0,1,9,20,17,30,2,3,11,30,31 };
	Mergesort(v);
	for (int i = 0; i < v.size(); i++)
		cout << v[i]<<" ";
	system("pause");
	return 1;
}
void Mergesort(vector<int> & bar) {
	if (bar.size() <= 1) return;

	int mid = bar.size() / 2;
	vector<int> left;
	vector<int> right;

	for (size_t j = 0; j < mid; j++)
		left.push_back(bar[j]);
	for (size_t j = 0; j < (bar.size()) - mid; j++)
		right.push_back(bar[mid + j]);

	Mergesort(left);
	Mergesort(right);
	merge(left, right, bar);
}
void merge(vector<int>&left, vector<int>& right, vector<int>& bars)
{
	int nL = left.size();
	int nR = right.size();
	int i = 0, j = 0, k = 0;

	while (j < nL && k < nR)
	{
		if (left[j] < right[k]) {
			bars[i] = left[j];
			j++;
		}
		else {
			bars[i] = right[k];
			k++;
		}
		i++;
	}
	while (j < nL) {
		bars[i] = left[j];
		j++; i++;
	}
	while (k < nR) {
		bars[i] = right[k];
		k++; i++;
	}
}