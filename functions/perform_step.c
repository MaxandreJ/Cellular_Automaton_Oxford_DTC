#include <stdio.h>
#include <stdlib.h>
#include "../CellularAutomata.h"

Board perform_step(Board my_board, int animal_grazing_rate, int step_number, int verbose_flag_chosen)
{
	int number_of_animals;
	int amount_of_food;
  int row_number;
  int column_number;
  Cell my_cell;
	Animal my_animal;
	Position my_animal_position;

  my_board = grow_food(my_board);
  if (verbose_flag_chosen)
  {
  printf("\nFood growing.\n");
  display_board(my_board);
  }

  int number_of_animals_at_present_turn = my_board.number_of_animals;

  for (row_number=0;row_number<my_board.number_of_rows;row_number++)
  {
    for (column_number=0;column_number<my_board.number_of_columns;column_number++)
    {
    my_cell = my_board.cell_array_2D[row_number][column_number];
    my_animal = my_cell.animal;
    if (my_animal.present && my_animal.alive
      && (my_animal.step_of_birth < step_number))
    {
  		my_board = graze(my_board, my_animal);
      my_animal = my_board.cell_array_2D[my_animal.position.row][my_animal.position.column].animal;

      if (verbose_flag_chosen)
      {
      printf("Animal at row %d and column %d grazing.\n", my_animal.position.row,
    my_animal.position.column);
      display_board(my_board);
      }

  		my_board = live(my_board, my_animal);
      my_animal = my_board.cell_array_2D[my_animal.position.row][my_animal.position.column].animal;

      if (verbose_flag_chosen)
      {
      printf("Animal at row %d and column %d living (consuming food).\n", my_animal.position.row,
    my_animal.position.column);
      display_board(my_board);
      }


      my_board = breed(my_board, my_animal, animal_grazing_rate, step_number);

      if (verbose_flag_chosen)
      {
      printf("Animal at row %d and column %d breeding.\n", my_animal.position.row,
    my_animal.position.column);
      display_board(my_board);
      }

    }
    }
	}

	return(my_board);

}
