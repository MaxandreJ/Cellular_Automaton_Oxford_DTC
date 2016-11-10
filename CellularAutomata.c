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

	if(argc == 5)
	{
	number_of_rows = atoi(argv[1]);
	number_of_columns = atoi(argv[2]);
	food_growing_rate = atoi(argv[3]);
	animal_grazing_rate = atoi(argv[4]);
	}
	else
	{
	printf("Wrong number of arguments. They should be given in the following order:\n number_of_rows number_of_columns food_growing_rate animal_grazing_rate\n");
	return(1);
	}

	my_board = populate_board(number_of_rows, number_of_columns, food_growing_rate, animal_grazing_rate);
	
	
	while(1)
	{
		display_board(my_board);
		//To pause the programme
		getchar();
		my_board = perform_step(my_board);
	}	
	

	free(my_board.cell_array_2D);
	free(my_board.animal_positions);
	free(my_board.food_positions);
	return 0;
}

Board populate_board(unsigned int number_of_rows, unsigned int number_of_columns, unsigned int food_growing_rate, 
unsigned int animal_grazing_rate)
{
	int row_number;
	int column_number;
	Cell my_cell;
	Cell my_cell_with_animal;
	Board my_board;
	Animal my_animal;
	Food my_food;
	int row_offset;
	int column_offset;
	int food_position_counter = 0;
	int animal_position_row;
	int animal_position_column;
	int animal_position_counter;
	int breeding_position_counter;
	my_board.number_of_rows = number_of_rows;
	my_board.number_of_columns = number_of_columns;
	
	my_board.cell_array_2D = malloc(sizeof(Cell*)*my_board.number_of_rows);

	// Not optimal but implementing upper bound would be too much work
	my_board.food_positions = malloc(sizeof(Position)*(my_board.number_of_rows*my_board.number_of_columns));
	my_board.animal_positions = malloc(sizeof(Position)*(my_board.number_of_rows*my_board.number_of_columns));
	
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
			my_board.food_positions[food_position_counter].row =  my_cell.position.row;
			my_board.food_positions[food_position_counter].column =  my_cell.position.column;
			food_position_counter++;
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

	//I'm putting an animal in the centre of my board.
	animal_position_row = number_of_rows / 2;
	animal_position_column = number_of_columns / 2;
	my_cell_with_animal = my_board.cell_array_2D[animal_position_row][animal_position_column];

	//Animal set-up
	my_animal = my_cell_with_animal.animal;
	my_animal.position.row = animal_position_row;
	my_animal.position.column = animal_position_column;
	my_animal.present = 1;
	my_animal.alive = 1;
	my_animal.grazing_rate = animal_grazing_rate;
	my_animal.food_stored = 100;
	animal_position_counter = 0;
	for (row_offset = -1 ;row_offset<=1;row_offset++)
		{
			for (column_offset = -1 ;column_offset<=1;column_offset++)
				{
				//printf("animal_position_counter %d\n",animal_position_counter);
				//printf("row_offset %d\n",row_offset);
				//printf("column_offset %d\n",column_offset);
				my_animal.grazing_area_positions[animal_position_counter].row = animal_position_row + row_offset; 
				my_animal.grazing_area_positions[animal_position_counter].column = animal_position_column + column_offset;
				animal_position_counter++;
				}
		}

	
	//down 
	/*my_animal.grazing_area_positions[0].row = (number_of_rows / 2) + 1; 
	my_animal.grazing_area_positions[0].column = number_of_columns / 2;
	my_animal.grazing_area_positions[1] = my_board.cell_array_2D[(number_of_rows / 2) - 1][number_of_columns / 2]; //up
	my_animal.grazing_area_positions[2] = my_board.cell_array_2D[(number_of_rows / 2)][(number_of_columns / 2) + 1]; //right
	my_animal.grazing_area_positions[3] = my_board.cell_array_2D[(number_of_rows / 2) + 1][(number_of_columns / 2)]; //left
	my_animal.grazing_area_positions[4] = my_board.cell_array_2D[(number_of_rows / 2) - 1][(number_of_columns / 2) - 1]; //top-left hand corner
	my_animal.grazing_area_positions[5] = my_board.cell_array_2D[(number_of_rows / 2) - 1][(number_of_columns / 2) + 1]; //top-right hand corner
	my_animal.grazing_area_positions[6] = my_board.cell_array_2D[(number_of_rows / 2) + 1][(number_of_columns / 2) - 1]; //bottom-left hand corner
	my_animal.grazing_area_positions[7] = my_board.cell_array_2D[(number_of_rows / 2) + 1][(number_of_columns / 2) + 1]; //bottom-right hand corner */
	
	breeding_position_counter = 0;
	
	for (row_offset = -1 ;row_offset<=1;row_offset++)
	{
		for (column_offset = -1 ;column_offset<=1;column_offset++)
			{
				// Only up and down and left and right
				if (((row_offset == 0) || (column_offset == 0)) && (!((row_offset == 0) && (column_offset == 0))))
				{
					//printf("%d\n",breeding_position_counter);
					my_animal.breeding_area_positions[breeding_position_counter].row = animal_position_row + row_offset; 
					my_animal.breeding_area_positions[breeding_position_counter].column = animal_position_column + column_offset;
					breeding_position_counter++;
				}
			}
	}

	

	/*
	my_animal.breeding_area[1] = my_board.cell_array_2D[(number_of_rows / 2) - 1][number_of_columns / 2]; //up
	my_animal.breeding_area[2] = my_board.cell_array_2D[(number_of_rows / 2)][(number_of_columns / 2) + 1]; //right
	my_animal.breeding_area[3] = my_board.cell_array_2D[(number_of_rows / 2)][(number_of_columns / 2) - 1]; //left
	*/

	my_board.cell_array_2D[number_of_rows / 2][number_of_columns / 2].animal = my_animal;

	my_board.animal_positions[0].row = number_of_rows / 2;
	my_board.animal_positions[0].column = number_of_columns / 2;

	return my_board;
		 
}

void display_board(Board my_board)
{
int row_number;
int column_number;
Cell my_cell;
Animal my_animal;
Food my_food;


for (row_number=0;row_number<my_board.number_of_rows;row_number++)
	{
	printf("\n\t");
	for (column_number=0;column_number<my_board.number_of_columns;column_number++)
		{
		my_cell = my_board.cell_array_2D[row_number][column_number];
		my_animal = my_cell.animal;
		my_food = my_cell.food;
		if ((my_animal.present == 1) && (my_food.quantity != 0))
		{
			//If animal and food present, we display the cell in yellow and only the animal food storage
			//Red character on a yellow background
			printf("\x1b[0;31;43m%3d",my_animal.food_stored);
			
		}
		else if (my_animal.present == 1)
		{
			//If animal only present, we display the cell in red and the animal food storage
			//Black character on a red background
			printf("\x1b[0;30;41m%3d",my_animal.food_stored);
		}
		else if (my_food.quantity != 0)
		{
			//If food only present, we display the cell in green and the quantity of food
			//Black character on a green background
			printf("\x1b[0;30;42m%3d",my_food.quantity);
		}
		else
		{
			//printf("test if4\n");
			//If nothing, light grey background, no text
			printf("\x1b[0;30;47m   ");
		}
		//Returning to default
		printf("\x1b[0;39;49m");
		}
	}
printf("\n\n");
}

Board perform_step(Board my_board)
{
	int number_of_animals;
	int amount_of_food;
	int animal_number;
	Animal my_animal;
	Position my_animal_position;

	number_of_animals = sizeof(my_board.animal_positions)/sizeof(my_board.animal_positions[0]);
	amount_of_food = sizeof(my_board.food_positions)/sizeof(my_board.food_positions[0]);

	for (animal_number=0; animal_number < number_of_animals; animal_number++)
	{
		my_animal_position = my_board.animal_positions[animal_number];
		my_animal = my_board.cell_array_2D[my_animal_position.row][my_animal_position.column].animal;
		my_board = graze(my_board, my_animal);
		my_animal = my_board.cell_array_2D[my_animal_position.row][my_animal_position.column].animal;
		my_board = live(my_board, my_animal, animal_number, number_of_animals);
		my_board = grow_food(my_board, amount_of_food);
		//Missing food growing part and breeding
	}

	return(my_board);

}

Board graze(Board my_board, Animal my_animal)
{
	Cell my_grazed_cell;
	int number_position_grazing_area;
	int my_grazed_cell_row;
	int my_grazed_cell_column;
	
	for(number_position_grazing_area=0;number_position_grazing_area<9;number_position_grazing_area++)
	{
		my_grazed_cell_row = my_animal.grazing_area_positions[number_position_grazing_area].row;
		my_grazed_cell_column = my_animal.grazing_area_positions[number_position_grazing_area].column;

		my_grazed_cell = my_board.cell_array_2D[my_grazed_cell_row][my_grazed_cell_column];
		
		if(my_grazed_cell.food.quantity >= my_animal.grazing_rate)
		{
		//Reducing the amount of food in the cell
		my_grazed_cell.food.quantity -= my_animal.grazing_rate;
			//Storing that food in the animal
			if(my_animal.food_stored + my_animal.grazing_rate <= 100)
			my_animal.food_stored += my_animal.grazing_rate;
			else
			my_animal.food_stored = 100;
		}
		//If the grazed cell doesn't have enough food for the grazing_rate
		else
		{
			if(my_animal.food_stored + my_grazed_cell.food.quantity <= 100)
			my_animal.food_stored += my_grazed_cell.food.quantity;
			else
			my_animal.food_stored = 100;
			my_grazed_cell.food.quantity = 0;
			
		}

		// I'm passing variables by value so I need to do lots of copying
		// Passing by reference would be more memory efficient
		my_board.cell_array_2D[my_grazed_cell_row][my_grazed_cell_column] = my_grazed_cell;
	}
	my_board.cell_array_2D[my_animal.position.row][my_animal.position.column].animal = my_animal;

	return(my_board);
}

Board live(Board my_board, Animal my_animal, int animal_number, int number_of_animals)
{
	if(my_animal.food_stored >= 10)
	my_animal.food_stored -= 10;
	else
	{
	my_animal.present = 0;
	my_animal.alive = 0;
	my_board = remove_dead_animal_positions(my_board, animal_number, number_of_animals);
	}

	my_board.cell_array_2D[my_animal.position.row][my_animal.position.column].animal = my_animal;

	return(my_board);
}

Board remove_dead_animal_positions(Board my_board, int animal_number, int number_of_animals)
{
	int loop_counter;
	for(loop_counter = animal_number; loop_counter < number_of_animals - 1; loop_counter++) 
	my_board.animal_positions[loop_counter] = my_board.animal_positions[loop_counter + 1];

	return(my_board);

}

Board grow_food(Board my_board, int amount_of_food)
{
int food_number;
int my_food_row;
int my_food_column;

for (food_number=0; food_number < amount_of_food; food_number++)
	{
	my_food_row = my_board.food_positions[food_number].row;
	my_food_column = my_board.food_positions[food_number].column;
	if(my_board.cell_array_2D[my_food_row][my_food_column].food.quantity <= 100 - my_board.cell_array_2D[my_food_row][my_food_column].food.growing_rate)
	my_board.cell_array_2D[my_food_row][my_food_column].food.quantity += my_board.cell_array_2D[my_food_row][my_food_column].food.growing_rate;
	else
	my_board.cell_array_2D[my_food_row][my_food_column].food.quantity = 100;
	}

return(my_board);

};




