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
int w, n;

typedef struct{
	float value;
	float weight;
}item;
item ii[1000];

typedef struct node {
	float weight, value;
	int level;
}node;

int cmp (const void * l, const void * r) {
	item r1 = *((item*)l);
	item r2 = *((item*)r);
	float lll = r1.value/r1.weight;
	float rr = r2.value/r2.weight;
	if (lll > rr) {
		return -1;
	}else {
		return 1;
	}
}

float findBound (node * ptr) {
	float curweight = ptr->weight;
	float curvalue = ptr->value;
	int j = ptr->level;
	while (j < n && curweight + ii[j].weight <= w) {
		curweight += ii[j].weight;
		curvalue += ii[j].value;
		j++;
	}
	if (j < n) {
		curvalue = curvalue + (w-ii[j].weight)*(ii[j].value/ii[j].weight);
	}
	return curvalue;
}

float solve () {
	float maxValue = 0;
	node * q[1000000];
	int start = 0;
	int end = 0;
	node * ptr;
	ptr = (node*)malloc(sizeof(node));
	ptr->weight = 0;
	ptr->value = 0;
	ptr->level = -1;
	q[end] = ptr;
	end++;

	qsort (ii, n, sizeof(item), cmp);
	

	node * temp;
	float bound;
	while (start != end) {
		temp = q[start];
		start++;
		if (temp->level == n-1) {
			continue;
		}
		ptr = (node*)malloc(sizeof(node));
		if (temp->level == -1) {
			ptr->level = 0;
		}else {
			ptr->level = temp->level + 1;
		}
		ptr->weight = temp->weight + ii[temp->level].weight;
		ptr->value = temp->value + ii[temp->level].value;
		if (ptr->weight <= w && ptr->value > maxValue) {
			maxValue = ptr->value;
		}

		bound = findBound (ptr);

		if (bound > maxValue) {
			q[end] = ptr;
			end++;
		}
		ptr = (node*)malloc(sizeof(node));
		ptr->weight = temp->weight;
		ptr->value = temp->value;
		ptr->level = temp->level + 1;
		bound = findBound (ptr);
		if (bound > maxValue) {
			q[end] = ptr;
			end++;
		}
	}
	return maxValue;
}


int main (void) {
	freopen ("input.in", "r", stdin);
	sc (w), sc (n);

	for (int i = 0; i < n; i++) {
		cin>>ii[i].value>>ii[i].weight;
	}

	cout<<solve()<<endl;

	return 0;
}
