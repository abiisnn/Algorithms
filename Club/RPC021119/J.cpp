#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int, int> pairs;

int main() {
	int N, a, b;
	bool is_in;
	set<pairs> visitados, posibles;
	cin >> N;
	for(int i = 0; i < N; i++) {
		cin >> a >> b;
		if(a != b) {
			pairs actual = make_pair(a, b);
			pairs reciproco = make_pair(b, a);
			std::set<pairs>::iterator act = visitados.find(actual);
			if(act == visitados.end()) { // Si actual no esta en VISITADOS
				visitados.insert(actual);
				visitados.insert(reciproco);
				posibles.insert(reciproco);
			} else { // Si actual esta en VISITADOS
				if(act != posibles.end()) {
					posibles.erase(act);
				} else {
					posibles.insert(actual);
				}
			}
		}
	}
	cout << posibles.size() << endl;
}