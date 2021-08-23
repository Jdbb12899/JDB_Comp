#include <iostream>
#include <math.h>

int funr4(int p, int q, int r);

int main() {
	funr4(4, 2, 14);
}

int funr4(int p, int q, int r)
{
	int a = r - q;
	int b = a >> 31;
	a = a + b;
	a = a >> 1;
	b = a + q;
	if (b <= p)
	{
		if (b >= p)
		{
			printf("0 returned\n");
			return 0;
		}
		else
		{
			int x = 2 * funr4(p, b + 1, r) + 1;
			printf("%d\n", x);
			return x;
		}
	}
	else
	{
		int y = 2 * funr4(p, q, b - 1);
		printf("%d\n", y);
		return y;
	}
}