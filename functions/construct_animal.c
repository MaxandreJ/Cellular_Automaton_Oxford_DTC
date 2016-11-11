#include <stdio.h>
#include <stdlib.h>
#include "../CellularAutomata.h"

Board construct_animal(Board my_board, int animal_position_row, int animal_position_column,
  int animal_grazing_rate, int step_number)
{
  //Constructor for an animal.

  Animal my_animal;
  int row_offset;
  int column_offset;
  int breeding_position_counter = 0;
  int grazing_position_counter = 0;
  int position_within_borders;

  Cell my_cell_with_animal;

  my_cell_with_animal = my_board.cell_array_2D[animal_position_row][animal_position_column];

  my_animal = my_cell_with_animal.animal;
  my_animal.position.row = animal_position_row;
  my_animal.position.column = animal_position_column;
  my_animal.present = 1;
  my_animal.alive = 1;
  my_animal.grazing_rate = animal_grazing_rate;
  my_animal.food_stored = 100;
  my_animal.step_of_birth = step_number;

  //Definition of the positions of the grazing_area for my_animal
  //Everywhere one unit away from my_animal, including diagonals
  for (row_offset = -1 ;row_offset<=1;row_offset++)
    {
      for (column_offset = -1 ;column_offset<=1;column_offset++)
        {
          //Making sure we're not defining positions out of the board
        position_within_borders = (
          (animal_position_row + row_offset >= 0) &&
        (animal_position_row + row_offset < my_board.number_of_rows) &&
        (animal_position_column + column_offset >= 0) &&
      (animal_position_column + column_offset < my_board.number_of_columns));

        if (position_within_borders)
        {
          my_animal.grazing_area_positions[grazing_position_counter].row = animal_position_row + row_offset;
          my_animal.grazing_area_positions[grazing_position_counter].column = animal_position_column + column_offset;
          grazing_position_counter++;
        }
        }
    }
    my_animal.number_of_grazing_area_positions = grazing_position_counter;

  //Definition of the positions of the breeding_area for my_animal
  //Everywhere one unit away from my_animal, excluding diagonals
  for (row_offset = -1 ;row_offset<=1;row_offset++)
  {
    for (column_offset = -1 ;column_offset<=1;column_offset++)
      {
        //Making sure we're not defining positions out of the board
        position_within_borders = (
          (animal_position_row + row_offset >= 0) &&
          (animal_position_row + row_offset < my_board.number_of_rows) &&
          (animal_position_column + column_offset >= 0) &&
        (animal_position_column + column_offset < my_board.number_of_columns)
        );
        if (position_within_borders)
        {
          // Only up and down and left and right
          if (((row_offset == 0) || (column_offset == 0)) &&
          (!((row_offset == 0) && (column_offset == 0))))
          {
            my_animal.breeding_area_positions[breeding_position_counter].row = animal_position_row + row_offset;
            my_animal.breeding_area_positions[breeding_position_counter].column = animal_position_column + column_offset;
            breeding_position_counter++;
          }
        }
      }
  }
  my_animal.number_of_breeding_area_positions = breeding_position_counter;
  my_board.cell_array_2D[animal_position_row][animal_position_column].animal = my_animal;
  my_board.number_of_animals += 1;

  return my_board;
}
