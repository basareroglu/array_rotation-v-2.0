# array_rotation-v-2.0
Arrat rotation in n*m matrix

The program reads the initial matrix (max 30 x 30) from a file, whose name (20 characters maximum) is
acquired from the keyboard. The file contains 2 integer values nr nc on the first line, indicating the number of rows nr and columns nc of the matrix. The following nr lines of the file, one per row of the matrix, should report nc integers each, separated by spaces.
- repeatedly acquires a command from the keyboard, in the format
<selector> <index> <direction> <locations>
Where <selector> is either the string “row”, “column” or “end”, respectively indicating whether the user wants to perform the rotation on a row ("row"), on a column ("column"), or terminate the program ("end").
<index> is the index of the selected row/column, starting from 1
<direction> is either the string “right”, ”left”, ”up” or “down”, indicating the direction of the rotation
<locations> is a positive integer indicating the number of positions P of the rotation.
The resulting matrix after each sequential rotation printed on the screen.

 
Example of input file:
3 3 
1 2 3 
4 5 6
7 8 9
Example of sequential commands acquired from keyboard:
row 2 right 1
column 3 down 2
row 1 left 4
column 1 up 2
end 1 end 1
The results of the rotation operations are represented by the following figure:
<img width="1049" alt="image" src="https://user-images.githubusercontent.com/91722056/236355409-9da4da6d-09eb-4378-9b97-5c7dfd9dc6a6.png">
