#include <stdio.h>
#include <stdlib.h>
#include "../CellularAutomata.h"

Board breed(Board my_board, Animal my_animal, int animal_grazing_rate, int step_number)
{
  //An animal breeds in adjacent cells (at most 1 cell away, excluding diagonals)
  //on the board.

  Cell my_bred_cell;
  int number_position_breeding_area;
  int my_bred_cell_row;
  int my_bred_cell_column;

  if (my_animal.alive)
  {
    for (number_position_breeding_area=0;
      number_position_breeding_area<my_animal.number_of_breeding_area_positions;
      number_position_breeding_area++)
    {
      my_bred_cell_row = my_animal.breeding_area_positions[number_position_breeding_area].row;
      my_bred_cell_column = my_animal.breeding_area_positions[number_position_breeding_area].column;

      my_bred_cell = my_board.cell_array_2D[my_bred_cell_row][my_bred_cell_column];

      //An animal can breed on a cell only if an animal is not already present
      if (!my_bred_cell.animal.present)
      {
        my_board = construct_animal(my_board, my_bred_cell_row, my_bred_cell_column,
          animal_grazing_rate, step_number);
      }
    }
  }

  return my_board;
}
