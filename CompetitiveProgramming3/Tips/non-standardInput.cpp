/* 
	Take this problem with a non-standard input format: the first line of input is an integer N. 
	This is followed by N lines, each starting with the character '0', followed by a dto '.', the followed by an unknown
	number of digits (up to 100 digits), and finally terminated with three dots '...'.
*/ 
#include<cstdio>
using namespace std;

int N;	// using global variables in contests can be a good strategy
char x[110]; // make it a habit to set array size a bit larger than needed

int main() {
	scanf("%d\n", &N);
	while(N--) {	// we simply loop fromm N, N-1, N-2, ..., 0
		scanf("0.%[0-9]...\n", &x);	// '&' is optional when x is a char array 
		printf("the digits are 0.%s\n", x);
	}
}