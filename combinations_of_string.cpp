#include<stdlib.h>
#include<string.h>


void delete_duplicates(char *given_str, char *str)
{
	int *alph, str_index = 0;
	alph = (int*)malloc(sizeof(int)* 26);
	memset(alph, 0, sizeof(int)* 26);
	for (int i = 0; given_str[i] != '\0'; i++)
	{
		int val = given_str[i] - 'a';
		if (alph[val] == 0)
		{
			alph[val] = 1;
			str[str_index++] = given_str[i];
		}
	}
	str[str_index] = '\0';
	free(alph);
}

void combinations(char *given_str)
{
	char *str;
	str = (char*)malloc(sizeof(char)* 26);
	//remove duplicates preserving order
	delete_duplicates(given_str, str);
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
	free(str);
}
