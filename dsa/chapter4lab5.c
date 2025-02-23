#include<stdio.h>

void tower(int n, char src, char tar, char aux)
{
	if (n == 1)
		printf("\nMove %d disc from %c to %c", n, src, tar);
	else {
		tower(n-1, src, aux, tar);
		printf("\nMove %d disc from %c to %c", n, src, tar);
		tower(n-1, aux, tar, src);
	}
}

int main()
{
	int n = 3; // Example number of discs
	tower(n, 'A', 'C', 'B');
	return 0;
}