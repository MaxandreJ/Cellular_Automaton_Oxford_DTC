#include <stdio.h>
#include <stdlib.h>
#include "../CellularAutomata.h"

Board graze(Board my_board, Animal my_animal)
{
  //An animal grazes (eats) in all adjacent cells (at most 1 cell away,
  //including diagonals) on the board.

	Cell my_grazed_cell;
	int number_position_grazing_area;
	int my_grazed_cell_row;
	int my_grazed_cell_column;

	for(number_position_grazing_area=0;number_position_grazing_area<9;number_position_grazing_area++)
	{
		my_grazed_cell_row = my_animal.grazing_area_positions[number_position_grazing_area].row;
		my_grazed_cell_column = my_animal.grazing_area_positions[number_position_grazing_area].column;

		my_grazed_cell = my_board.cell_array_2D[my_grazed_cell_row][my_grazed_cell_column];

    //If the grazed cell has enough food for the animal's grazing rate
		if(my_grazed_cell.food.quantity >= my_animal.grazing_rate)
		{
		//Reducing the amount of food in the cell
		my_grazed_cell.food.quantity -= my_animal.grazing_rate;
			//Storing that food in the animal
      //The amount of food stored by an animal can't exceed 100.
			if(my_animal.food_stored + my_animal.grazing_rate <= 100)
			my_animal.food_stored += my_animal.grazing_rate;
			else
			my_animal.food_stored = 100;
		}
		//If the grazed cell doesn't have enough food for the animal's grazing_rate
		else
		{
      //Storing what's left food in the animal
      //The amount of food stored by an animal can't exceed 100.
			if(my_animal.food_stored + my_grazed_cell.food.quantity <= 100)
			my_animal.food_stored += my_grazed_cell.food.quantity;
			else
			my_animal.food_stored = 100;

			my_grazed_cell.food.quantity = 0;
		}

		// I'm passing variables by value so I need to do lots of copying.
		// Passing by reference would be more memory efficient.
		my_board.cell_array_2D[my_grazed_cell_row][my_grazed_cell_column] = my_grazed_cell;
	}
	my_board.cell_array_2D[my_animal.position.row][my_animal.position.column].animal = my_animal;

	return(my_board);
}
