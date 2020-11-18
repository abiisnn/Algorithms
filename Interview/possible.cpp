#include<bits/stdc++.h>
using namespace std;

/*
	abc{d{e 
		   }3

	abc{d{e}3f}2hij{d{e}3f}2klm
*/
/*
string expandWord(string &pattern) {
	stack<char> memory;
	int open = 0;
	for(int i = 0; i < pattern.size(); i++) {
		if(pattern[i] == '}') {
			int repeted = pattern[++i] - '0';
			string compressed = "";
			while(!memory.empty()) {
				char c = memory.top();
				memory.pop();
				if(c == '{') break;
				compressed += string(1, c);
			}
			reverse(compressed.begin(), compressed.end());
			for(int i = 0; i < repeted; i++) {
				for(char &c: compressed) {
					memory.push(c);
				}
			}
		} else {
			memory.push(pattern[i]);
		}
	}
	string expanded = "";
	while(!memory.empty()) {
		char c = memory.top();
		memory.pop();
		expanded += string(1, c);
	}
	reverse(expanded.begin(), expanded.end());
	return expanded;
}
*/
/*
	abc{d{e}3f}2hij{d{e}3f}2klm
	abc
	   {
		d
	sentence = [abc, d, e]

*/
string expandWord(string &word) {
	vector<string> stack(1, "");
	for(int i = 0; i < word.size(); i++) {
		if(word[i] == '{') {
			stack.push_back("");
		} else if(word[i] == '}') {
			int times = word[++i] - '0';
			for(int j = 0; j < times; j++) {
				stack[stack.size()-2] += stack[stack.size()-1];
			}
			stack.pop_back();
		} else {
			stack[stack.size()-1].push_back(word[i]);
		}
	}
	return stack[0];
}
int main() {
	string pattern;
	cin >> pattern;
	cout << "==========" << endl;
	cout << expandWord(pattern) << endl;
}
