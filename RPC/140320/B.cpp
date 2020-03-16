#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
typedef long long int lli;

/*
	First: a < b
	Second: a > b
*/
bool sortbysec(const pair<int, char> &a, const pair<int, char> &b) {
	if(a.first == b.first) {
		return (a.second > b.second);
	} else {
		return (a.first < b.first);		
	}
}
int main() {
	optimizar_io
	string s;
	cin >> s;
	vector<pair<int, char>> bucket;
	fore(i, 0, 26) {
		bucket.pb(make_pair(0, 'a' + i));
	}
	fore(i, 0, s.size()) {
		bucket[s[i] - 'a'].first++;
	}
	sort(bucket.begin(), bucket.end(), sortbysec);

	for(int i = bucket.size() - 1; i >= 0; i--) {
		fore(j, 0, bucket[i].first) {
			cout << bucket[i].second;
		}
	}
	cout << endl;

}