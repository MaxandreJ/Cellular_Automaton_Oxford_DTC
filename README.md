# Cellular_Automaton_Oxford_DTC
A cellular automaton created for my project in the programming course at Oxford Doctoral Training Centre.

In the terminal, once your current directory is set to the folder containing my files, run the following command in the terminal to compile :
``` sh
gcc CellularAutomata.c functions/*.c -o CellularAutomata
```

Once it is done, run the created binary by typing the following command in the terminal :
``` sh
./CellularAutomata <number_of_rows> <number_of_columns> <food_growing_rate> <animal_grazing_rate> (--verbose)
```

For example you can run the following command to create a grid of size 10x10, with a food_growing_rate of 5 and an animal_grazing_rate of 10.
``` sh
./CellularAutomata 10 10 5 10
```

If you want to know more about the elements that ar interacting, you can use the verbose mode by running :
``` sh
./CellularAutomata 10 10 5 10 --verbose
```
