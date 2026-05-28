/*
 ============================================================================
 Name        : SemesterProject.c
 Author      : Anna Leonhardt
 Version     : 2.0
 Copyright   : Your copyright notice
 Description : Initial C coded version of a Crossy Road, Pac-Man mashup game.

 ============================================================================
 */
#include "GameFunctions.h"
#include <string.h>
#include <stdio.h>

int main(void) {
#define length 2 // determines how many characters can be inputted by user for controls

	printf(
			"                        CROSSY-MAN\n\nPress 'c' on keyboard and enter to see the controls\nPress 'p' on keyboard and enter to play the game\n\n"); //Displays the initial game instructions
	fflush(stdout);  //pushes the main title to the console

	int flag = 0;	// defines flag as 0 initially
	int curx = 9;	// sets current x position to 9
	int cury = 9;	// sets the current y position to 9
	int counter = 0; //initializes counter to 0

	while (flag == 0) { //Coding the "Main/start screen"
		char input[length]; //sets initial input to null
		scanf("%s", &input);

		if (strcmp(input, "c") == 0) { //controls screen display
			printf("\n     In-Game Controls\n"); //Prints the Controls label
			printf("Press 'e' to end the game\n"); //Prints the end game control
			printf("Press 'w' to move forward\n"); //Prints the move forward control
			printf("Press 'a' to move left\n"); //Prints the move left control
			printf("Press 's' to move backward\n"); //Prints the move backward control
			printf("Press 'd' to move right\n\n"); //Prints the move right control
			printf("Press 'm' to return to the main menu\n\n"); //Prints main menu control

			fflush(stdout);  //pushes the game to the console
			scanf("%s", &input); //scans the new user input
			if (strcmp(input, "m") == 0) { // takes user's input and compares it to 'm' key
				main(); // if UInput is m, recalls main function and returns to original screen user sees
			} else if (strcmp(input, "e") == 0) { // takes user's input and compares to 'e' key
				printf("Goodbye"); // if UInput is 'e' , print "Goodbye" and push the system to output to console screen
				fflush(stdout);  //pushes the game to the console
			} else if (strcmp(input, "p") == 0) { // compares the UInput to 'p' key
				break; // if UInput is 'p' , overall if statement breaks and moves on to the else if
			}
		}

		else if (strcmp(input, "p") == 0) { // else if to compares the user's input to 'p' key
			printf(
					"                                              Begin game\n"); // if the UI is 'p', print "Begin game" to console screen
			fflush(stdout); //pushes the game to the console

			Game grid;

			createGrid(&grid, 10, 30);
			initGrid(&grid);
			printf("Points: %d\n", counter); // Print updated counter value
			printGrid(&grid);

//					printf("O", r + 1, randC[r]);
			// obstacles move across the axis.
			fflush(stdout); //pushes the game to the console
			scanf("%s", &input);  //scans the user input and stores in "input"
			while (strcmp(input, "e") != 0) { // compares UserInput to 'e' during entire program, if 'e' is pressed,
											  // Goodbye is printed and flag is set to 1, terminating the program

				while (strcmp(input, "w") == 0) { //loop to move the character forward in array
					swap(&grid, curx, cury, curx--, cury); //after every move by the user, move the array down one
					counter++;
					//update counter by 1
					printf("Points: %d\n", counter); // Print updated counter value
					printGrid(&grid);
					fflush(stdout);
					scanf("%s", &input);
				}

				while (strcmp(input, "a") == 0) { //loop to move the character left in array
					swap(&grid, curx, cury, curx, cury--);
					printf("Points: %d\n", counter); // Print updated counter value
					printGrid(&grid);
					fflush(stdout);
					scanf("%s", &input);
				}
				while (strcmp(input, "s") == 0) { //loop to move the character right in array
					swap(&grid, curx, cury, curx++, cury);
					printf("Points: %d\n", counter); // Print updated counter value
					printGrid(&grid);
					fflush(stdout);
					scanf("%s", &input);
				}
				while (strcmp(input, "d") == 0) { //loop to move the character backward in array
					swap(&grid, curx, cury, curx, cury++);
					printf("Counter: %d\n", counter); // Print updated counter value
					printGrid(&grid);
					fflush(stdout);
					scanf("%s", &input);
				}
			}
			printf("Goodbye");		// Goodbye is printed
			fflush(stdout);			// And pushed to the console screen
			flag = 1;// Flag count is set to 1, the program ends and has to be restarted to begin again
		}
	}
}
