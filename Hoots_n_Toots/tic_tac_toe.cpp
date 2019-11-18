
using namespace std;

bool x;
bool o;

int grid[4][4] = {
   {0, 0, 0, 0} ,   /*  initializers for row indexed by 0 */
   {0, 0, 0, 7} ,   /*  initializers for row indexed by 1 */
   {0, 0, 0, 0} ,	/*  initializers for row indexed by 2 */
   {0, 0, 0, 0}	/*  initializers for row indexed by 3 */
};

int win_condition[24] = { {1}, {1}, {1}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, };

int points(int win_condition[], int grid[][]) {

	// 24 * 2 Conditions in total.
	int i;
	x = true;

	if (x == true) {
		i = 1;
	}
	else {
		i = -1;
	}

	// Horizontal Row wins
	if (grid[0][0] || grid[0][1] || grid[0][2]) {
		win_condition[0] = win_condition[0] + i;
	}

	if (grid[0][1] || grid[0][2] || grid[0][3]) {
		win_condition[1] = win_condition[1] + i;
	}

	if (grid[1][0] || grid[1][1] || grid[1][2]) {
		win_condition[2] = win_condition[2] + i;
	}

	if (grid[1][1] || grid[1][2] || grid[1][3]) {
		win_condition[3] = win_condition[3] + i;
	}

	if (grid[2][0] || grid[2][1] || grid[2][2]) {
		win_condition[4] = win_condition[4] + i;
	}

	if (grid[2][1] || grid[2][2] || grid[2][3]) {
		win_condition[5] = win_condition[5] + i;
	}

	if (grid[3][0] || grid[3][1] || grid[3][2]) {
		win_condition[6] = win_condition[6] + i;
	}

	if (grid[3][1] || grid[3][2] || grid[3][3]) {
		win_condition[7] = win_condition[7] + i;
	}


	// Vertical Row Wins
	if (grid[0][0] || grid[1][0] || grid[2][0]) {
		win_condition[8] = win_condition[8] + i;
	}

	if (grid[1][0] || grid[2][0] || grid[3][0]) {
		win_condition[9] = win_condition[9] + i;
	}

	if (grid[0][1] || grid[1][1] || grid[2][1]) {
		win_condition[10] = win_condition[10] + i;
	}

	if (grid[1][1] || grid[2][1] || grid[3][1]) {
		win_condition[11] = win_condition[11] + i;
	}

	if (grid[0][2] || grid[1][2] || grid[2][2]) {
		win_condition[12] = win_condition[12] + i;
	}

	if (grid[1][2] || grid[2][2] || grid[3][2]) {
		win_condition[13] = win_condition[13] + i;
	}

	if (grid[0][3] || grid[1][3] || grid[2][3]) {
		win_condition[14] = win_condition[14] + i;
	}

	if (grid[1][3] || grid[2][3] || grid[3][3]) {
		win_condition[15] = win_condition[15] + i;
	}

	// Diagonal Forward Row Win

	if (grid[0][0] || grid[1][1] || grid[2][2]) {
		win_condition[16] = win_condition[16] + i;
	}

	if (grid[0][1] || grid[1][2] || grid[2][3]) {
		win_condition[17] = win_condition[17] + i;
	}

	if (grid[1][0] || grid[2][1] || grid[3][2]) {
		win_condition[18] = win_condition[18] + i;
	}

	if (grid[1][1] || grid[2][2] || grid[3][3]) {
		win_condition[19] = win_condition[19] + i;
	}

	// Diagonal Backwards Row Win

	if (grid[0][2] || grid[1][1] || grid[2][0]) {
		win_condition[20] = win_condition[20] + i;
	}

	if (grid[1][2] || grid[2][1] || grid[3][0]) {
		win_condition[21] = win_condition[21] + i;
	}

	if (grid[0][3] || grid[1][2] || grid[2][1]) {
		win_condition[22] = win_condition[22] + i;
	}

	if (grid[1][3] || grid[2][2] || grid[3][1]) {
		win_condition[23] = win_condition[23] + i;
	}

	int win(int win_condition[]) {
		for (int z; z < sizeof(win_condition); ++z) {
			if (win_condition[z] == 3) {
				count << "X Wins" << endl;
				system("pause");
			}

			else  (win_condition[z] == -3) {
				count << "O Wins" << endl;
				system("pause");
			}
		}
	}

	int main() {
		points(win_condition, grid);
		win(win_condition);
	}

}
