#include <stdio.h>
#include <stdlib.h>
#include "../CellularAutomata.h"

Board live(Board my_board, Animal my_animal)
{
  //An animal lives, which consumes energy by using up the food they have stored.

	if(my_animal.food_stored > 10)
  {
	my_animal.food_stored -= 10;
  }
  //If the animal food consumption exceeds the amount of food he stored, it dies.
	else
	{
	my_animal.present = 0;
	my_animal.alive = 0;
  my_board.number_of_animals -= 1;
	}

	my_board.cell_array_2D[my_animal.position.row][my_animal.position.column].animal = my_animal;

	return(my_board);
}
