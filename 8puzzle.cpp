#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define itr iterator
#define ritr reverse_iterator
#define pint pair<int, int>
#define pll pair<ll, ll>
#define S second
#define F first
#define v(a) vector<a>
#define mk(a, b) make_pair(a, b)
#define psh(a) push_back(a)
#define mem(arr, a) memset(arr, a, sizeof(arr))
#define pr(n) printf("%d\n", n)
#define sc(n) scanf ("%d", &n)
#define scll(n) scanf ("%lld", &n)
#define prll(n) printf("%lld\n", n)
#define MOD 1000000007ll
#define inf 1000000000ll


int puzzle[3][3];

bool check () {
	int arr[8];
	int i, j;
	int ctr = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (puzzle[i][j] != 0) {
				arr[ctr] = puzzle[i][j];
				ctr++;
			}
		}
	}
	int cnt = 0;
	for (i = 0; i < ctr; i++) {
		for (j = i; j < ctr; j++) {
			if (arr[i] > arr[j]) {
				cnt++;
			}
		}
	}

	if (cnt % 2 == 0) {
		return true;
	}else {
		return false;
	}
}

bool solve () {
	if (!check ()){
		return false;
	}else {
		findSolution();
	}
}

int main (void) {
	freopen ("input.in", "r", stdin);
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			sc (puzzle[i][j]);
		}
	}

	if (!solve ()) {
		cout<<"Not Possible to solve"<<endl;
	}else {

	}

	return 0;
}
