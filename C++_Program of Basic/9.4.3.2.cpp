#include <iostream>
#include <functional>
#include <vector>
using namespace std;

auto square = [] (int num) -> int {return num*num;};

vector<int>& change(vector<int> &vec , function<int(int)> fun)
{
	for(auto& x : vec)
	{
		x = fun(x);
	}
	return vec;
}
void print(const vector<int> &vec)
{
	for(auto x : vec)
		cout << x << endl;
}
int main()
{
	int a[5] {1,2,3,4,5};
	vector<int> ivec(a , a+5);
	cout << "1: " << endl;
	print(ivec);	
	cout << endl;
	change(ivec , square);
	cout << "2: " << endl;
	print(ivec);
}
