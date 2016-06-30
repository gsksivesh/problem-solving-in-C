//index = rows * [row_index] + [column_index]
//searching an element in matrix which is sorted row wise and coloumn wise
int search_matrix(int *matrix, int rows, int coloumns, int key)
{
	int start_index;
	//starting from the top right
	start_index = coloumns - 1;
	while (start_index <= (rows * coloumns) - 1 )
	{
		if (key == matrix[start_index])
			return 1;
		//move the index left side if key is less than element in matrix[start_index]
		else if (key < matrix[start_index])
		{
			start_index--;
			//checking if its going to before row
			if ((start_index + 1) % coloumns == 0)
			{
				break;
			}
		}
		//move the index right side if key is greater than element in matrix[start_index]
		else
		{
			start_index += coloumns;
		}
	}
	return 0;
}
