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
	int step_number = 0;
	char* verbose_flag;
	int verbose_flag_chosen;


	///Getting arguments from the command line

	if(argc == 5)
	{
		number_of_rows = atoi(argv[1]);
		number_of_columns = atoi(argv[2]);
		food_growing_rate = atoi(argv[3]);
		animal_grazing_rate = atoi(argv[4]);
	}
	else if(argc == 6)
	{
		number_of_rows = atoi(argv[1]);
		number_of_columns = atoi(argv[2]);
		food_growing_rate = atoi(argv[3]);
		animal_grazing_rate = atoi(argv[4]);
		verbose_flag = malloc(sizeof(char)*strlen(argv[5]));
		verbose_flag = argv[5];
	}
	else
	{
	printf("Wrong number of arguments. They should be given in the following order:\n"
	"number_of_rows number_of_columns food_growing_rate animal_grazing_rate (--verbose)\n");
	return(1);
	}
	//Awkward, should've used a library for arg_parse
	if (argc == 6)
	verbose_flag_chosen = (strcmp(verbose_flag,"--verbose") == 0);
	else
	verbose_flag_chosen = 0;


	my_board = construct_board(number_of_rows, number_of_columns, food_growing_rate, animal_grazing_rate);

	printf("\nInitial board.\n");
	display_board(my_board);

	///Iterating until stopped by the user (Ctrl-C)
	while(1)
	{
		printf("\n=== Step number %d ===\n", step_number);
		my_board = perform_step(my_board, animal_grazing_rate, step_number, verbose_flag_chosen);
		//To pause the programme
		if (!verbose_flag_chosen)
		{
			display_board(my_board);
		}
		getchar();
		step_number++;
	}

	///I remember to free the memory allocated in the heap.
	///Nevertheless, the code is not exception safe...
	///C doesn't seem very user-friendly for handling exceptions
	///What a surprise
	free(my_board.cell_array_2D);
	free(my_board.food_positions);
	free(verbose_flag);
	return 0;
}
