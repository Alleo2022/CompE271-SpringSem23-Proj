/*
 * GameFunctions.h
 *
 *  Created on: Mar 2, 2023
 *      Author: Anna Leonhardt
 */

#ifndef GAMEFUNCTIONS_H_
#define GAMEFUNCTIONS_H_

typedef struct {
	int x;	//initializes the x axis
	int y;	//initializes the y axis
	int **z;	//initializes the z 'axis'
	int **c;	//initializes the c 'axis'
} Game;	//ends the struct and gives the struct a name

void createGrid(Game *grid, int x, int y);	//initializes the function ot create the grid using the x and y axes
void initGrid(Game *grid);	//initializes the function for the grid to be filled with characters
void printGrid(Game *grid);		//initializes the function to print the grid
void swap(Game *grid, int i1, int j1, int i2, int j2);	//initializes the swap functions for the grid to be called

#endif /* GAMEFUNCTIONS_H_ */
