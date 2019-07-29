#include<stdio.h>

int main() {
	int initial;
	int i, n;

	n = 0;
	while(scanf("%d", &initial), initial >= 0) {
		int created[12];
		int required[12];
		n++;
		for(i = 0; i < 12; i++) 
			scanf("%d", &created[i]);
		for(i = 0; i < 12; i++) 
			scanf("%d", &required[i]);

		printf("Case %d:\n", n);
		for(i = 0; i < 12; i++) {
			if(required[i] <= initial) {
				initial -= required[i];
				printf("No problem! :D\n");
			}
			else 
				printf("No problem. :(\n");
			initial += created[i];			
		}
	}
}