#include <stdio.h>

void Move (int n, char A, char B, char C);
int main () {

    int n;
	scanf("%d", &n);
	Move(n, 'A', 'B', 'C');

	return 0;
}

void Move (int n, char A, char B, char C) {
	if(n == 1) {
		printf("%c -> %c\n", A, C);
	} else {
		Move(n-1, A, C, B);
		printf("%c -> %c\n", A, C);
		Move(n-1, B, A, C);
	}	
}