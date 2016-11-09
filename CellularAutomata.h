#ifndef HEADER_EXAMPLE
#define HEADER_EXAMPLE

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

food grow_food(int& growing_rate);

typedef struct Animal 
{
unsigned int present;
unsigned int alive;
unsigned int grazing_rate;
unsigned int food_stored;
Cell* grazing_area;
Cell* breeding_area;
} Animal;

void graze(animal& an_animal, cell& a_cell);
void breed(animal& an_animal, cell& a_cell);

typedef struct Cell 
{
const Position position;
Animal animal;
Food food;
} Cell;

typedef struct Board 
{
unsigned int number_of_rows;
unsigned int number_of_columns;
Cell** 2D_cell_array;
} Board;

Board populate_board(int seed);
Board perform_step();
void display_board(Board my_board);

#endif
