#ifndef CELLULAR_AUTOMATA
#define CELLULAR_AUTOMATA

typedef struct Position
{
int row;
int column;
} Position;

typedef struct Food
{
unsigned int quantity;
int growing_rate;
} Food;

typedef struct Board Board;

Board grow_food(Board my_board);

typedef struct Animal
{
unsigned int present;
unsigned int alive;
unsigned int grazing_rate;
unsigned int food_stored;
unsigned int number_of_grazing_area_positions;
unsigned int number_of_breeding_area_positions;
int step_of_birth;
Position grazing_area_positions[9];
Position breeding_area_positions[4];
Position position;
} Animal;

Board construct_animal(Board my_board, int animal_position_row, int animal_position_column,
  int animal_grazing_rate, int step_number);
Board graze(Board my_board, Animal my_animal);
Board live(Board my_board, Animal my_animal);
Board breed(Board my_board, Animal my_animal, int animal_grazing_rate, int step_number);

typedef struct Cell
{
Position position;
Animal animal;
Food food;
} Cell;

struct Board
{
unsigned int number_of_rows;
unsigned int number_of_columns;
Cell** cell_array_2D;
Position* food_positions;
int amount_of_food;
int number_of_animals;
};

Board perform_step(Board my_board, int animal_grazing_rate, int step_number, int verbose_flag_chosen);
void display_board(Board my_board);
Board construct_board(unsigned int number_of_rows, unsigned int number_of_columns, unsigned int food_growing_rate,
unsigned int animal_grazing_rate);

#endif
