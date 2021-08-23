/***********************************************************
Author: <Jacob Blumsack>
Date: <09/14/19>
Effort: <2 hrs>
Purpose: <more practice with bit wise operators and shifts>
***********************************************************/

#include <stdio.h>

void set_flag(int* flag_holder, int flag_position) 
{
	int i;

	i = 1 << flag_position; //left shift
	*flag_holder = *flag_holder | i; //bitwise or (puts 1 where any digit has a 1)
}

int check_flag(int flag_holder, int flag_position) 
{
	int j;
	int hold;

	j = 1 << flag_position;  //left shift
	hold = flag_holder & j;  //bitwise and (puts 1 where both digits have 1)

	return (hold == 0 ? 0 : 1); //if hold is 0 return 0, else 1
}

int main(int argc, char* argv[])
{
	int flag_holder = 0;
	int i;
	set_flag(&flag_holder, 3);
	set_flag(&flag_holder, 16);
	set_flag(&flag_holder, 31);
	for (i = 31; i >= 0; i--)
	{
		printf("%d", check_flag(flag_holder, i));
		if (i % 4 == 0)
		{
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}