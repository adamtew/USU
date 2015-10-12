#include <iostream>
#include "life.h"

int countAlive(int i, int j, const bool board[ROWS][COLS]);

void life(const bool current[ROWS][COLS], bool next[ROWS][COLS]){

	int alive = 0;

	for (int i = 0; i < ROWS; i++){
		for (int j = 0; j < COLS; j++){

			alive = countAlive(i, j, current);

			//        1. Any live cell with fewer than two live neighbours dies, as if
			//           caused by under-population.
			bool rule1 = (current[i][j] == true && alive < 2);

			//        2. Any live cell with two or three live neighbours lives on to the
			//           next generation.
			bool rule2 = ((current[i][j] == true) && (alive == 2 || alive == 3));

			//        3. Any live cell with more than three live neighbours dies, as if by
			//           overcrowding.
			bool rule3 = (current[i][j] == true && alive > 3);

			//        4. Any dead cell with exactly three live neighbours becomes a live cell,
			//           as if by reproduction.
			bool rule4 = (current[i][j] == false && alive == 3);
			
			if (rule1) next[i][j] = false;
			if (rule2) next[i][j] = true;
			if (rule3) next[i][j] = false;
			if (rule4) next[i][j] = true;

			if (!rule1 && !rule2 && !rule3 && !rule4) next[i][j] = false;
			
		}
	}
}

int countAlive(int i, int j, const bool board[ROWS][COLS]){

	int alive = 0;

	for (int ci = i - 1; ci <= i + 1; ci++){
		for (int cj = j - 1; cj <= j + 1; cj++){

			if ((board[ci][cj] == true) && (ci != i || cj != j)){
				alive += 1;
			}

		}
	}

	return alive;
}