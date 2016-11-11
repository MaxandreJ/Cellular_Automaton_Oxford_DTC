/*#include "../CellularAutomata.h"
#include <stdlib.h>
#include <stdio.h>

Board remove_dead_animal_positions(Board my_board, int animal_number)
{
	int loop_counter;
	for(loop_counter = animal_number; loop_counter < my_board.number_of_animals - 1; loop_counter++)
	my_board.animal_positions[loop_counter] = my_board.animal_positions[loop_counter + 1];

	return(my_board);
}
*/
