#include <stdio.h>
#include <stdlib.h>
#include "../CellularAutomata.h"

Board live(Board my_board, Animal my_animal)
{
	if(my_animal.food_stored > 10)
  {
  //printf("in the loop\n");
	my_animal.food_stored -= 10;
  }
	else
	{
	my_animal.present = 0;
	my_animal.alive = 0;
  my_board.number_of_animals -= 1;
  //printf("test segmentation fault pre\n");
	//my_board = remove_dead_animal_positions(my_board);
  //printf("test segmentation fault post\n");
	}

	my_board.cell_array_2D[my_animal.position.row][my_animal.position.column].animal = my_animal;

	return(my_board);
}
