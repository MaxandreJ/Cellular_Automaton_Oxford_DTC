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

Food grow_food(int growing_rate);

typedef struct Cell Cell;
typedef struct Board Board;

typedef struct Animal 
{
unsigned int present;
unsigned int alive;
unsigned int grazing_rate;
unsigned int food_stored;
Cell* grazing_area;
Cell* breeding_area;
} Animal;

Board graze(Animal an_animal, Cell a_cell);
Board breed(Animal an_animal, Cell a_cell);

struct Cell 
{
Position position;
Animal animal;
Food food;
};

struct Board 
{
unsigned int number_of_rows;
unsigned int number_of_columns;
Cell** cell_array_2D;
};

Board populate_board(unsigned int number_of_rows, unsigned int number_of_columns, unsigned int food_growing_rate, 
unsigned int animal_grazing_rate);
Board perform_step();
void display_board(Board my_board);

#endif
