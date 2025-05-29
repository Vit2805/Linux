#include <stdio.h>

void judge_sd(int num)
{
	if ((num & 1) == 0 )
	{
		printf("%d is even\n", num);
		return;
	}
	else
	{
		printf("%d is odd\n", num);
		return;
	}
}
int main (int argc, char const *argv[])
{
	judge_sd(0);
	judge_sd(1);
	judge_sd(4);
	
	return 0;
}