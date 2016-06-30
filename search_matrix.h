//index = rows * [row_index] + [column_index]
int search_matrix(int *matrix, int rows, int coloumns, int key)
{
	int start_index;
	start_index = coloumns - 1;
	while (start_index <= (rows * coloumns) - 1 )
	{
		if (key == matrix[start_index])
			return 1;
		else if (key < matrix[start_index])
		{
			start_index--;
			if ((start_index + 1) % coloumns == 0)
			{
				break;
			}
		}
		else
		{
			start_index += coloumns;
		}
	}
	return 0;
}