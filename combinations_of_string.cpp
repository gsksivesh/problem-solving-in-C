#include<stdio.h>
#include<conio.h>

void combinations(char *str)
{
	//2^strlen(str) ~= 1 << strlen(str)
	for (int i = 1; i < (1 << strlen(str)); i++)
	{
		int temp = i;
		int index = 0;
		//Characters of index in which the bits are set in temp are printed
		while (temp != 0)
		{
			if (temp & 1 == 1)
			{
				printf("%c", str[index]);
			}
			index++;
			temp = temp >> 1;
		}
		printf("\n");
	}
}
