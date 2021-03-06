#include <stdio.h>
#include <stdlib.h>
#include "../CellularAutomata.h"

void display_board(Board my_board)
{
  //Displays the board.
  //Green cells are for food, red cells for animals, yellow cells for animals + food.
  //If green, the number displayed corresponds to the quantity of food available
  //in that cell.
  //If red, the number displayed corresponds to the quantity of food stored by
  //the animal in that cell.
  //If yellow, the number displayed corresponds to the quantity of food stored
  //by the animal in that cell (in that case, the quantity of food stored in the cell
  //is not displayed).

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
			//If animal and food present, we display the cell in yellow and only the animal food storage
			//Red character on a yellow background
			printf("\x1b[0;31;43m%3d",my_animal.food_stored);

		}
		else if (my_animal.present == 1)
		{
			//If animal only present, we display the cell in red and the animal food storage
			//Black character on a red background
			printf("\x1b[0;30;41m%3d",my_animal.food_stored);
		}
		else if (my_food.quantity != 0)
		{
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
