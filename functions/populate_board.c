#include "../CellularAutomata.h"
#include <stdlib.h>
#include <stdio.h>

Board populate_board(unsigned int number_of_rows, unsigned int number_of_columns, unsigned int food_growing_rate,
unsigned int animal_grazing_rate)
{
	int row_number;
	int column_number;
	Cell my_cell;
	Board my_board;
	Animal my_animal;
	Food my_food;
	int animal_position_row;
	int animal_position_column;
	int food_position_counter = 0;
  int step_number = -1;

	my_board.number_of_rows = number_of_rows;
	my_board.number_of_columns = number_of_columns;

	my_board.cell_array_2D = malloc(sizeof(Cell*)*my_board.number_of_rows);

	// Not optimal but implementing upper bound would be too much work
	my_board.food_positions = malloc(sizeof(Position)*(my_board.number_of_rows*my_board.number_of_columns));

  //printf("number of rows : %d\n",number_of_rows);

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
			//if((my_cell.position.row % 2 == 0) && (my_cell.position.column % 2 == 0))
			//{
			my_food.quantity = 100;
			//Store the places where there's food in a different array
      //printf("my_cell.position.row : %d\n",my_cell.position.row);
			my_board.food_positions[food_position_counter].row =  my_cell.position.row;
			my_board.food_positions[food_position_counter].column =  my_cell.position.column;
			food_position_counter++;
      //printf("%d\n",food_position_counter);
			//}
			//else
			//my_food.quantity = 0;


			my_food.growing_rate = food_growing_rate;

			//No animal except the one defined after the loops
			my_animal = my_cell.animal;

			my_animal.present = 0;

			my_cell.animal = my_animal;
			my_cell.food = my_food;
			my_board.cell_array_2D[row_number][column_number] = my_cell;

		}
	}
//insert
//  for (food_position_counter=0;food_position_counter <25;food_position_counter++)
//	{
//      printf("row : %d\n",my_board.food_positions[food_position_counter].row);
//      printf("column : %d\n",my_board.food_positions[food_position_counter].column);
//  }
//end insert

  my_board.amount_of_food  = my_board.number_of_rows * my_board.number_of_columns;
	//I'm putting an animal in the centre of my board.
  my_board.number_of_animals = 0;
	animal_position_row = number_of_rows / 2;
	animal_position_column = number_of_columns / 2;

  my_board = construct_animal(my_board, animal_position_row, animal_position_column,
    animal_grazing_rate, step_number);


	return my_board;

}
