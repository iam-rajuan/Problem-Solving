#include <iostream>
using namespace std;
int main(){
long long m,n,a;

	cin >> m >> n >> a;

	long long p = (m+a-1)/a;
	long long q = (n+a-1)/a;

	long long x= p*q;

	cout << x <<endl;
	return 0;
}