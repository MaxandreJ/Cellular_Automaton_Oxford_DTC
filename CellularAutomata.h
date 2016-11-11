#ifndef CELLULAR_AUTOMATA
#define CELLULAR_AUTOMATA

//I need to give the prototype Board first, because functions that I use need
//that type.
typedef struct Board Board;

//Easy access to the position of an element
//I use rows and columns instead of cartesian coordinates x and y because they are
//confusing. A matrix doesn't have an orthonormal basis!
typedef struct Position
{
int row;
int column;
} Position;

//Each food has a distinct quantity and growing_rata. In facts, I set it up
//so that every Food has the same growing_rate, but my data structure allows it
//to be different for each individual food.
typedef struct Food
{
unsigned int quantity;
int growing_rate;
} Food;

Board grow_food(Board my_board);

//Animals can be present and dead. I don't use this distinction but it could be
//used if one wanted to have zombie animals.
//Using grazing_area_positions and breeding_area_positions allows easy access
//to adjacent cells.
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

//Animal constructor.
Board construct_animal(Board my_board, int animal_position_row, int animal_position_column,
  int animal_grazing_rate, int step_number);
Board graze(Board my_board, Animal my_animal);
Board live(Board my_board, Animal my_animal);
//Each animal will have a "step of birth" based on the step_number that they are
//born at. It allows for newly born animals not to breed instantly.
Board breed(Board my_board, Animal my_animal, int animal_grazing_rate, int step_number);

typedef struct Cell
{
Position position;
Animal animal;
Food food;
} Cell;

//The board, or in cellular automaton parlance "grid" has a cell_array_2D that
//contains most of the data of this programme. The rest could be considered as
//"metadata".
struct Board
{
unsigned int number_of_rows;
unsigned int number_of_columns;
Cell** cell_array_2D;
Position* food_positions;
int amount_of_food;
int number_of_animals;
};

//The board constructor.
Board construct_board(unsigned int number_of_rows, unsigned int number_of_columns, unsigned int food_growing_rate,
unsigned int animal_grazing_rate);
Board perform_step(Board my_board, int animal_grazing_rate, int step_number, int verbose_flag_chosen);
void display_board(Board my_board);


#endif
