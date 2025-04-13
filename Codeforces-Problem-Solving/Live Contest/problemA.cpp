#include <iostream>
#include <vector>

using namespace std;

int min_operations(const vector<int>& a, int n){
	bool all_equal = true;
	for (int i=1; i<n; ++i){
		if (a[i] != a[0]){
			all_equal = false;
			break;
		}
	}


if (all_equal) return 0;
bool non_increasing = true;
for (int i = 1; i < n; ++i){
	non_increasing = false;
	break;
}

if (non_increasing) return 1;
return 2;
}


int main(){
	int t;
	cin >> t;

	while (t--){
		int n;
		cin >> n;

		vector<int> a(n);
		for (int i = 0; i<n; ++i){
			cin >> a[i];
		}
		cout << min_operations(a,n) <<endl;
	}
	return 0;
}