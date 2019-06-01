###Kookmin University Software Department, CPP Project

# Hello, This is the Push Box Game using Cpp/C++

----
## What is the Push Box Game?
see [Wikipedia](https://en.wikipedia.org/wiki/Sokoban)

It is a type of classic puzzle game. It is also called Sokoban, push push, etc.
How to play is detailed in Wikipedia.

----
## Before progress
1. Constraint

 * The wall is marked 1.
 * The box is marked 2.
 * The Goal is marked 3.
 * The empty space is marked 0.
 * Outside the wall is marked 4.
 * Do not display player in the map.
 * Use the ncurses library.

2. Outline

 * Variable names and Function names
    * map
    * level
    * step
    * push
    * goalList
    * position, pair<int x, int y>
    * isSuccess()
    * move()
 * Make a map formatted by text file. Make maps by level. In map first and second integers are the coordinate of the starting point.
 * Using the fstream library read a map. And store coordinates of goals in goalList.
 * Removes index 0 on the coordinate. (Selective)
 * Have to recognize the arrow key input.
 * First, initialize to level 1.
 * When the arrow key is input, execute move().
 * move(direction) { if(when there is empty space in the direction) {setStep(+1)} else if (when there is a wall in the direction) {} else if (when there is a box in the direction) { if (canTheBoxMove) {setPush(+1), setStep(+1)} else {} }
 * In postProcessing(), display the player in the map. And confirm whether player complete current level. And do something properly(change the level, initialize, etc).
 * If (level == final level && isSuccess()) {send a congratulation message} 

3. + *alpha*

 * Measure the completion time for each level.
 * Reset button.

----
## Progress
1. libraries
 * fstream: To read a text file.
 * time.h: To measure the completion time.
 * Windows.h: To use sleep().

2. Variable names 
 * MAX_SIZE_ROW
 * MAX_SIZE_COL
 * FINALLEVEL
 * map
 * level
 * push
 * goalList
 * position, pair<int x, int y>
 * startTimer
 * endTimer
 * records, vector<vector<int>>

3. Function names
 * readMap(): read a map matching the current level.
 * isSuccess(): return bool. confirm completion.
 * postProcessing(): display the player in the map. And confirm whether player complete current level. And do something properly (change the level, initialize, etc).
