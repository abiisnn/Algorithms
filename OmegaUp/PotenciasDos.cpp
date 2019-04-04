// Problem: https://omegaup.com/arena/problem/ptwo#problems
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(int argc, char const *argv[])
{
	String str;
	stack <char> pila;
	int i;
	char c;
	cout << str;

	for(i = 0; i < str.size(); i++) {
		c = str.at(i);

		if(c == '(' || c == '{' || c == '[') 
			pila.push(c);

		if(!pila.empty()) {
			if(c == ')' && pila.top() == '(' )	
				pila.pop();

			else if(c == '}' && pila.top() == '{' )	
				pila.pop();

			else if(c == ']' && pila.top() == '[' )
				pila.pop();
		}	
	}

	return 0;
}
