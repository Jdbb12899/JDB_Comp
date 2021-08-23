#include <stdio.h>

void reverse(char word[]) {
	int i;
	int length = 0;
	char hold[100];
	for (i = 0; word[i] != '\0'; i++) {
		length++;
	}
	int j = 0;
	while (length != 0) {
		word[length] = hold[j];
		j++;
		length--;
	}
	while (j != 0) {
		word[j] = hold[j];
		j--;
	}
	return word;
}
