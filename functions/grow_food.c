#include <stdio.h>
#include <stdlib.h>
#include "../CellularAutomata.h"

Board grow_food(Board my_board)
{
  //Food grows everywhere there was ever food, in accordance to their growing_rate.

int food_number;
int my_food_row;
int my_food_column;

for (food_number=0; food_number < my_board.amount_of_food; food_number++)
	{

	my_food_row = my_board.food_positions[food_number].row;
	my_food_column = my_board.food_positions[food_number].column;

	if(my_board.cell_array_2D[my_food_row][my_food_column].food.quantity <=
    100 - my_board.cell_array_2D[my_food_row][my_food_column].food.growing_rate)

	my_board.cell_array_2D[my_food_row][my_food_column].food.quantity +=
  my_board.cell_array_2D[my_food_row][my_food_column].food.growing_rate;

	else
	my_board.cell_array_2D[my_food_row][my_food_column].food.quantity = 100;

	}

return(my_board);

};
