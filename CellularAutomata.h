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

typedef struct Board Board;

Board grow_food(Board my_board, int amount_of_food);

typedef struct Animal 
{
unsigned int present;
unsigned int alive;
unsigned int grazing_rate;
unsigned int food_stored;
Position grazing_area_positions[9];
Position breeding_area_positions[4];
Position position;
} Animal;

Board graze(Board my_board, Animal my_animal);
Board live(Board my_board, Animal my_animal,int animal_number, int number_of_animals);
Board breed(Board my_board, Animal my_animal);

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
Position* animal_positions;
Position* food_positions;
};

Board populate_board(unsigned int number_of_rows, unsigned int number_of_columns, unsigned int food_growing_rate, 
unsigned int animal_grazing_rate);
Board perform_step(Board my_board);
void display_board(Board my_board);
Board remove_dead_animal_positions(Board my_board, int animal_number, int number_of_animals);

#endif
