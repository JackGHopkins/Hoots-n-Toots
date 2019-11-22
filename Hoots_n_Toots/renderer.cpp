// renderer.cpp

global_variable float render_scale = 0.01f;

internal void
clear_screen(u32 color) {
	unsigned int* pixel = (u32*)render_state.memory;

	for (int y = 0; y < render_state.height; y++) {
		for (int x = 0; x < render_state.width; x++) {
			*pixel++ = color;
		}
	}
}

internal void
draw_rect_in_pixels(int x0, int y0, int x1, int y1, u32 color) {

	x0 = clamp(0, x0, render_state.width);
	x1 = clamp(0, x1, render_state.width);
	y0 = clamp(0, y0, render_state.height);
	y1 = clamp(0, y1, render_state.height);


	for (int y = y0; y < y1; y++) {
		unsigned int* pixel = (u32*)render_state.memory + x0 + y * render_state.width;
		for (int x = x0; x < x1; x++) {
			*pixel++ = color;
		}
	}
}

internal void
draw_rect(float x, float y, float half_size_x, float half_size_y, u32 color) {

	x *= render_state.height * render_scale;
	y *= render_state.height * render_scale;
	half_size_x *= render_state.height * render_scale;
	half_size_y *= render_state.height * render_scale;

	x += render_state.width / 2.f;
	y += render_state.height / 2.f;


	// Change to pixels (converter).
	int x0 = x - half_size_x;
	int x1 = x + half_size_x;
	int y0 = y - half_size_y;
	int y1 = y + half_size_y;


	draw_rect_in_pixels(x0, y0, x1, y1, color);
}

internal void
draw_token(struct token token[4][4], int grid_spacing, int token_mod) {

	// Iterate through all squares on the board to check if a token has been placed.
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (*token[j][i]->bin_colour == 1 ) {
				draw_rect(j * grid_spacing - token_mod, i * -grid_spacing + token_mod, 4, 1, 0xff0000);
			}
			else if (grid[i][j] == -1 )
				draw_rect(j * grid_spacing - token_mod, i * -grid_spacing + token_mod, 1, 4, 0x0000ff);
		}

	}
}


bool x;
bool o;

void check_win(int win_condition[24], int grid[4][4]) {

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
}