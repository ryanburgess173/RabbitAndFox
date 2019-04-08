# RabbitAndFox
Triad Programming Contest 2019 problem #2
B.  Rabbit and Fox
 
A rabbit has several rabbit holes where is can go for safety.  When a fox shows up, the rabbit must get to a rabbit hole before the fox eats it.  The fox can run twice as fast as the rabbit.  When a fox shows up, the rabbit runs in a straight line for a rabbit hole.  The fox sees where the rabbit is running and it will run for the same hole.  If the fox gets to the hole before the rabbit, the rabbit will be eaten.
You are to write a program that displays the location of the hole where the rabbit should run to avoid the fox.  If there are multiple holes that would provide safety, you only need to display the location on one of them.  If there is no hole that the rabbit can reach before the fox, then the program should display “The rabbit is doomed”.
Input is from the file rabbit.txt which first has an integer n indicating the number of rabbit holes.  There will be no more than 32 rabbit holes.  The file then contains n pairs of floating point numbers indicating the locations of the holes.  This is followed by an integer m indicating the number of fox and rabbit positions.  Each of the m positions will have four floating point numbers, the X and Y coordinate of the rabbit and the X and Y coordinate of the fox.  All coordinates are positive numbers.
For each pair of rabbit and fox positions, if the rabbit can get to a hole before the fox, display the coordinates of the hole.  If the rabbit cannot get to a hole before the fox, display “The rabbit is doomed”.
 
Example input
4
1.0  1.0
10.0 1.0
4.0  4.0
2.0  8.0
3
8.0 2.0  5.0 5.0
5.0 1.0  5.0 5.0
1.0 7.0  5.0 7.0
 
 
Example output
safe at 10.0, 1.0
The rabbit is doomed
safe at 2.0, 8.0
