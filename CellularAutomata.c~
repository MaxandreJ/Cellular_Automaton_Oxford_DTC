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

board populate_board(unsigned int number_of_rows, unsigned int number_of_columns,unsigned int food_growing_rate, 
unsigned int animal_grazing_rate)
{
	int row_number;
	int column_number;
	Cell my_cell;
	Board my_board;
	my_board.number_of_rows = number_of_rows;
	my_board.number_of_columns = number_of_columns;
	my_board.its_2D_cell_array = malloc(sizeof(cell*)*my_board.number_of_rows);
	for (row_number=0;row_number<number_of_rows;row_number++)
	{
		my_board.its_2D_cell_array[row_number]=malloc(sizeof(cell)*my_board.number_of_columns);
		for (column_number=0;column_number<number_of_columns;column_number++)
		{
			my_cell = my_board.2D_cell_array[row_number][column_number];
			my_cell.position.row = row_number;
			my_cell.position.column = column_number;
			
			//Food set-up
			my_food = my_cell.food;
			//We put food only in cells that have an even position.row and even position.column
			if((the_processed_cell.position.row % 2 == 0) && (the_processed_cell.position.column % 2 == 0))
			my_food.quantity = 100;
			else
			my_food.quantity = 0;

			my_food.growing_rate = food_growing_rate;
			
			//No animal except the one defined after the loops
			my_animal = my_cell.animal;

			my_animal.present = 0;		
		}
	}

	//I'm putting an animal in the centre of my board.
	my_cell_with_animal = my_board.2D_cell_array[number_of_rows / 2][number_of_columns / 2];

	//Animal set-up
	my_animal = my_cell_with_animal.animal;
	my_animal.present = 1;
	my_animal.alive = 1;
	my_animal.grazing_rate = animal_grazing_rate;
	my_animal.food_stored = 100;

	my_animal.grazing_area = {my_board.2D_cell_array[(number_of_rows / 2) + 1][number_of_columns / 2], //down
my_board.2D_cell_array[(number_of_rows / 2) - 1][number_of_columns / 2], //up
my_board.2D_cell_array[(number_of_rows / 2)][(number_of_columns / 2) + 1], //right
my_board.2D_cell_array[(number_of_rows / 2) + 1][(number_of_columns / 2) - 1], //left
my_board.2D_cell_array[(number_of_rows / 2) - 1][(number_of_columns / 2) - 1], //top-left hand corner
my_board.2D_cell_array[(number_of_rows / 2) - 1][(number_of_columns / 2) + 1], //top-right hand corner
my_board.2D_cell_array[(number_of_rows / 2) + 1][(number_of_columns / 2) - 1], //bottom-left hand corner
my_board.2D_cell_array[(number_of_rows / 2) + 1][(number_of_columns / 2) + 1] }; //bottom-right hand corner

	my_animal.breeding_area = {my_board.2D_cell_array[(number_of_rows / 2) + 1][number_of_columns / 2], //down
my_board.2D_cell_array[(number_of_rows / 2) - 1][number_of_columns / 2], //up
my_board.2D_cell_array[(number_of_rows / 2)][(number_of_columns / 2) + 1], //right
my_board.2D_cell_array[(number_of_rows / 2) + 1][(number_of_columns / 2) - 1] }; //left
		 
}

void display_board(Board my_board)
{
int row_number;
int column_number;
Cell my_cell;

for (row_number=0;row_number<number_of_rows;row_number++)
	{
	printf("\n\t");
	for (column_number=0;column_number<number_of_columns;column_number++)
		{
		my_cell = my_board.2D_cell_array[row_number][column_number];
		my_animal = my_cell.animal;
		my_food = my_cell.food;
		if ((my_animal.present == 1) && (my_food.quantity != 0))
		{
			//If animal and food present, we display the cell in yellow and only the animal food storage
			//Black character on a yellow background
			printf("\x1b[0;30;43m%3d",my_animal.food_stored);
			//Returning to default
			printf("\x1b[0;37;40m");
		}
		else if (my_animal.present == 1)
		{
			//If animal only present, we display the cell in red and the animal food storage
			//Black character on a red background
			printf("\x1b[0;30;41m%3d",my_animal.food_stored);
			//Returning to default
			printf("\x1b[0;37;40m");
		}
		else if (my_food.quantity != 0)
		{
			//If food only present, we display the cell in green and the quantity of food
			//Black character on a green background
			printf("\x1b[0;30;42m%3d",my_food.quantity);
			//Returning to default
			printf("\x1b[0;37;40m");
		}
		else
		{
			//If nothing, light grey background, no text
			printf("\x1b[0;30;47m ");
			//Returning to default
			printf("\x1b[0;37;40m");
		}
		}
	}

}


