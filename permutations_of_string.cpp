#include<string.h>
#include<stdio.h>

void swap(char *a, char *b)
{
	//swap two charachters
	if (*a == '\0' || *b == '\0')
		return;
	char temp = *a;
	*a = *b;
	*b = temp;
}

void rotate(char *str)
{
	//rotating the string in-place
	int len = strlen(str);
	for (int i = 0, j = len - 1; i < j; i++, j--)
	{
		swap(&str[i], &str[j]);
	}
}

int next_lex(char *str)
{
	//Arranges next lexicographical string(in-place) if exists return 1 else 0
	/*
	The Algorithm:
	->Find the largest index k such that a[k] < a[k + 1]. If no such index exists, the permutation is the last permutation.
	->Find the largest index l greater than k such that a[k] < a[l].
	->Swap the value of a[k] with that of a[l].
	->Reverse the sequence from a[k + 1] up to and including the final element a[n].
	https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order
	*/
	int len = strlen(str);
	int i, j;
	for (i = len - 1; i > 0; i--)
	{
		if (str[i] > str[i - 1])
		{
			break;
		}
	}
	if (i == 0)
	{
		return 0;
	}
	for (j = len - 1; j > i; j--)
	{
		if (str[j] > str[i - 1])
		{
			break;
		}
	}
	swap(&str[j], &str[i - 1]);
	rotate(str + i);
	return 1;
}

void qsort(char *str,int len)
{
	//Sorting a string using quick sort technique
	if (len == 0)
	{
		return;
	}
	char pivot = str[0];
	int i = 1, j = len - 1;
	while (i <= j)
	{
		if (str[i]>pivot && str[j] < pivot)
		{
			swap(&str[i], &str[j]);
			i++;
			j--;
		}
		else if (str[i] <= pivot && str[j] >= pivot)
		{
			i++;
			j--;
		}
		else if (str[i] <= pivot)
		{
			i++;
		}
		else if (str[j] >= pivot)
		{
			j--;
		}
	}
	swap(&str[0], &str[j]);
	qsort(str, j);
	qsort(str + j + 1, len - j - 1);
}
void permutations_next(char *str)
{
	//all possible permutations of a string in lexicographical order
	qsort(str, strlen(str));
	do
	{
		printf("%s\n", str);
	} while (next_lex(str));
}

void permute(char *str, int left)
{
	//all possible permutations of a string
	if (left == strlen(str))
	{
		printf("%s\n", str);
		return;
	}
	for (int i = left; str[i] != '\0'; i++)
	{
		swap(&str[left], &str[i]);
		permute(str, left + 1);
		swap(&str[left], &str[i]);
	}
}
void permutaions(char *str)
{
	//driver function for permute
	permute(str,0);
}