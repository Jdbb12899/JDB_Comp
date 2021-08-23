/***********************************************************
Author: <Jacob Blumsack>
Date: <09/19/19>
Effort: <2 hours>
Purpose: <practice more with bitwise operators and shifts>
***********************************************************/

#include <stdio.h>

void set_flag(unsigned int flag_holder[], int flag_position) {
	int i = 0;
	i = 1 << flag_position;
	flag_holder[flag_position / 32] = flag_holder[flag_position / 32] | i;
}
void unset_flag(unsigned int flag_holder[], int flag_position) {
	int i = 0;
	i = 1 << flag_position;
	*flag_holder = *flag_holder & ~i;
}
int check_flag(unsigned int flag_holder[], int flag_position) {
	int j = 0;
	int hold = 0;
	j = 1 << flag_position;
	hold = *flag_holder & j;
	return (hold == 0 ? 0 : 1);
}
void display_32_flags_as_array(unsigned int flag_holder) {
	int i = 0;
	for (i = 1; i <= 32; i++)
	{
		printf("%d", check_flag(&flag_holder, i - 1));
		if (i % 4 == 0)
		{
			printf(" ");
		}
	}
	printf("\n");
}
void display_flags(unsigned int flag_holder[], int size) {
	int i = 0;
	for (i = 0; i <= size - 1; i++)
	{
		display_32_flags_as_array(flag_holder[i]);
	}
	printf("\n");
}

int main(int argc, char* argv[])
{
	unsigned int flag_holder[5] = { 0 };//Set the first integer to zero and all others to zero by default.
	set_flag(flag_holder, 3);
	set_flag(flag_holder, 16);
	set_flag(flag_holder, 31);
	set_flag(flag_holder, 87);
	display_flags(flag_holder, 5);
	printf("\n\n");
	unset_flag(flag_holder, 31);
	unset_flag(flag_holder, 3);
	set_flag(flag_holder, 99);
	set_flag(flag_holder, 100);
	display_flags(flag_holder, 5);
	return 0;
}