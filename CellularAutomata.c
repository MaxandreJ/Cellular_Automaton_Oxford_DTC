#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CellularAutomata.h"
/* 
   Cellular automata by Maxandre Jacqueline
*/

int main(int argc, char *argv[])
{
	Board my_board;
	unsigned int number_of_rows;
	unsigned int number_of_columns;
	unsigned int food_growing_rate;
	unsigned int animal_grazing_rate;
	
	number_of_rows = atoi(argv[1]);
	number_of_columns = atoi(argv[2]);
	food_growing_rate = atoi(argv[3]);
	animal_grazing_rate = atoi(argv[4]);

	my_board = populate_board(number_of_rows, number_of_columns, food_growing_rate, animal_grazing_rate);
	display_board(my_board);

	free(my_board.cell_array_2D);
	return 0;
}

Board populate_board(unsigned int number_of_rows, unsigned int number_of_columns, unsigned int food_growing_rate, 
unsigned int animal_grazing_rate)
{
	int row_number;
	int column_number;
	Cell my_cell;
	Cell my_cell_with_animal;
	Board my_board;
	Animal my_animal;
	Food my_food;
	my_board.number_of_rows = number_of_rows;
	my_board.number_of_columns = number_of_columns;
	
	my_board.cell_array_2D = malloc(sizeof(Cell*)*my_board.number_of_rows);
	for (row_number=0;row_number<number_of_rows;row_number++)
	{
		my_board.cell_array_2D[row_number]=malloc(sizeof(Cell)*my_board.number_of_columns);
		for (column_number=0;column_number<number_of_columns;column_number++)
		{
			my_cell = my_board.cell_array_2D[row_number][column_number];
			my_cell.position.row = row_number;
			my_cell.position.column = column_number;
			
			//Food set-up
			my_food = my_cell.food;
			//We put food only in cells that have an even position.row and even position.column
			if((my_cell.position.row % 2 == 0) && (my_cell.position.column % 2 == 0))
			my_food.quantity = 100;
			else
			my_food.quantity = 0;

			my_food.growing_rate = food_growing_rate;
			
			//No animal except the one defined after the loops
			my_animal = my_cell.animal;

			my_animal.present = 0;

			my_cell.animal = my_animal;
			my_cell.food = my_food;
			my_board.cell_array_2D[row_number][column_number] = my_cell;
					
		}
	}

	//I'm putting an animal in the centre of my board.
	my_cell_with_animal = my_board.cell_array_2D[number_of_rows / 2][number_of_columns / 2];

	//Animal set-up
	my_animal = my_cell_with_animal.animal;
	my_animal.present = 1;
	my_animal.alive = 1;
	my_animal.grazing_rate = animal_grazing_rate;
	my_animal.food_stored = 100;
	
	my_animal.grazing_area = malloc(sizeof(Cell)*8);

	my_animal.grazing_area[0] = my_board.cell_array_2D[(number_of_rows / 2) + 1][number_of_columns / 2]; //down 
	my_animal.grazing_area[1] = my_board.cell_array_2D[(number_of_rows / 2) - 1][number_of_columns / 2]; //up
	my_animal.grazing_area[2] = my_board.cell_array_2D[(number_of_rows / 2)][(number_of_columns / 2) + 1]; //right
	my_animal.grazing_area[3] = my_board.cell_array_2D[(number_of_rows / 2) + 1][(number_of_columns / 2) - 1]; //left
	my_animal.grazing_area[4] = my_board.cell_array_2D[(number_of_rows / 2) - 1][(number_of_columns / 2) - 1]; //top-left hand corner
	my_animal.grazing_area[5] = my_board.cell_array_2D[(number_of_rows / 2) - 1][(number_of_columns / 2) + 1]; //top-right hand corner
	my_animal.grazing_area[6] = my_board.cell_array_2D[(number_of_rows / 2) + 1][(number_of_columns / 2) - 1]; //bottom-left hand corner
	my_animal.grazing_area[7] = my_board.cell_array_2D[(number_of_rows / 2) + 1][(number_of_columns / 2) + 1]; //bottom-right hand corner
	
	my_animal.breeding_area = malloc(sizeof(Cell)*4);

	my_animal.breeding_area[0] = my_board.cell_array_2D[(number_of_rows / 2) + 1][number_of_columns / 2]; //down
	my_animal.breeding_area[1] = my_board.cell_array_2D[(number_of_rows / 2) - 1][number_of_columns / 2]; //up
	my_animal.breeding_area[2] = my_board.cell_array_2D[(number_of_rows / 2)][(number_of_columns / 2) + 1]; //right
	my_animal.breeding_area[3] = my_board.cell_array_2D[(number_of_rows / 2) + 1][(number_of_columns / 2) - 1]; //left

	my_board.cell_array_2D[number_of_rows / 2][number_of_columns / 2].animal = my_animal;

	return my_board;
		 
}

void display_board(Board my_board)
{
int row_number;
int column_number;
Cell my_cell;
Animal my_animal;
Food my_food;


for (row_number=0;row_number<my_board.number_of_rows;row_number++)
	{
	printf("\n\t");
	for (column_number=0;column_number<my_board.number_of_columns;column_number++)
		{
		my_cell = my_board.cell_array_2D[row_number][column_number];
		my_animal = my_cell.animal;
		my_food = my_cell.food;
		if ((my_animal.present == 1) && (my_food.quantity != 0))
		{
			//printf("test if1\n");
			//If animal and food present, we display the cell in yellow and only the animal food storage
			//Red character on a yellow background
			printf("\x1b[0;31;43m%3d",my_animal.food_stored);
			
		}
		else if (my_animal.present == 1)
		{
			//printf("test if2\n");
			//If animal only present, we display the cell in red and the animal food storage
			//Black character on a red background
			printf("\x1b[0;30;41m%3d",my_animal.food_stored);
		}
		else if (my_food.quantity != 0)
		{
			//printf("test if3\n");
			//If food only present, we display the cell in green and the quantity of food
			//Black character on a green background
			printf("\x1b[0;30;42m%3d",my_food.quantity);
		}
		else
		{
			//printf("test if4\n");
			//If nothing, light grey background, no text
			printf("\x1b[0;30;47m   ");
		}
		//Returning to default
		printf("\x1b[0;39;49m");
		}
	}
printf("\n\n");
}




