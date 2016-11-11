# Cellular_Automaton_Oxford_DTC
A cellular automaton created for my project in the programming course at Oxford Doctoral Training Centre.

##How to run the programme

In the terminal, once your current directory is set to the folder containing my files, run the following command in the terminal to compile :
``` sh
gcc CellularAutomata.c functions/*.c -o CellularAutomata
```

Once it is done, run the created binary by typing the following command in the terminal :
``` sh
./CellularAutomata <number_of_rows> <number_of_columns> <food_growing_rate> <animal_grazing_rate> (--verbose)
```

For example you can run the following command to create a grid of size 10x6, with a food_growing_rate of 5 and an animal_grazing_rate of 8.
``` sh
./CellularAutomata 10 6 5 8
```

If you want to know more about the elements that are interacting, you can use the verbose mode by running :
``` sh
./CellularAutomata 10 6 5 8 --verbose
```

##Display

Green cells represent where food is, red cells: animals, yellow cells: animals and food. If a cell is green, the number displayed in black corresponds to the quantity of food available in the cell. If a cell is red, the number displayed in black corresponds to the quantity of food stored by the animal in that cell. If a cell is yellow the number displayed in red corresponds to the quantity of food stored by the animal in that cell (in that case, the quantity of food stored in the cell is not displayed).

