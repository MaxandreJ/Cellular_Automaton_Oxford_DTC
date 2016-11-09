#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 
   Cellular automata by Maxandre Jacqueline
*/

int main(int argc, char *argv[])
{
	Board my_board;
	int number_of_rows;
	int number_of_columns;
	
	number_of_rows = atoi(argv[1]);
	return 0;
}

board populate_board(int seed, int number_of_rows, int number_of_columns)
{
	int row_number;
	Board my_board;
	my_board.number_of_rows = number_of_rows;
	my_board.number_of_columns = number_of_columns;
	my_board.its_2D_cell_array = malloc(sizeof(cell*)*my_board.number_of_rows);
	for (row_number=0;row_number<number_of_rows;row_number++)
	{
		my_board.its_2D_cell_array[row_number]=malloc(sizeof(cell)*my_board.number_of_columns);
		for (column_number=0;column_number<number_of_columns;column_number++)
		{
			Cell the_processed_cell;
			the_processed_cell = my_board.2D_cell_array[row_number][column_number];
			the_processed_cell.position.row = row_number;
			the_processed_cell.position.column = column_number;
			the_processed_cell.animal.present = 0;
			//We put food only in cells that have an even position.row and even position.column
			//insert code here
			the_processed_cell.food.present = 0;
		}
	}	
	
	 
	
}
