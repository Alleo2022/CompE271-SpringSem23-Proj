/*
 * Functions.c
 *
 *  Created on: Mar 2, 2023
 *      Author: Anna Leonhardt
 */
#include "GameFunctions.h"
#include <stdio.h>
#include <stdlib.h>

void createGrid(Game *grid, int rows, int cols) {		//sets the grid and grid size
	grid->x = rows;
	grid->y = cols;
	grid->z = (int**) malloc(rows * sizeof(int*));
	grid ->c = (int**) malloc(rows * sizeof(int*));
	for (int i = 0; i < rows; i++) {
		grid->z[i] = (int*) malloc(cols * sizeof(int));
		grid ->c[i] = (int*) malloc(cols * sizeof(int));
	}
}

void initGrid(Game *grid) {		//initializes and fills the grid
	for (int i = 0; i < grid->x; i++) {
		for (int j = 0; j < grid->y; j++) {
			grid->z[i][j] = '_';
		}
	}
	for (int i = 0; i < grid->x; i++) {
		for (int j = 0; j < grid->y; j++) {
			grid->c[i][j] = '_';
		}
	}
	grid->z[9][9] = 'O';		//sets the bottom row character to be O for the user to swap
	grid ->c[5][4] = 'x';		//creates an obstacle
	grid ->c[8][7] = 'x';		//creates an obstacle
	grid ->c[3][10] = 'x';		//creates an obstacle
	grid ->c[3][15] = 'x';		//creates an obstacle
}

void printGrid(Game *grid) {		//prints the game grid

	for (int i = 0; i < grid->x; i++) {
		for (int j = 0; j < grid->y; j++) {
			printf("%c", grid->z[i][j]);
			printf("%c", grid->c[i][j]);
		}
		printf("\n");
	}
}


void swap(Game *grid, int i1, int j1, int i2, int j2) { 	//Swap function partially modeled after an online template
	char temp = grid->z[i1][j1];
	grid->z[i1][j1] = grid->z[i2][j2];
	grid->z[i2][j2] = temp;
}
