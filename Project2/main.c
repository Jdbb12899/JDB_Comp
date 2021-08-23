#include <stdio.h>

int main(int argc, char* argv[])
{
	char word[] = "Happy Birthday!";
	printf("%s\n", word);
	//reverse(word);

	int i;
	int length = 0;
	for (i = 0; word[i] != '\0'; i++) {
		length++;
		printf("%d", length);
	}
	for (; length >= 0; length--) {
		printf("%c", word[i]);
	}

	//printf("%s\n", word);
	//printf("%s\n", reverse(word));
	//printf("%s\n", word);
	return 0;
}