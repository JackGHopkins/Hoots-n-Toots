//game.cpp
#include <iostream>
#include <string>
using namespace std;

#define is_down(b) input->buttons[b].is_down
#define pressed(b) (input->buttons[b].is_down && input->buttons[b].changed)
#define release(b) (!input->buttons[b].is_down && input->buttons[b].changed)

struct token {
	int height;
	int width;
	int xcoord;
	int ycoord;
	int bin_colour;
	unsigned int colour;
} token [4][4];


float player_pos_x = -18.f;
float player_pos_y = +18.f;
float gridline_width = 0.2f;
float gridline_length = 24.f;
float gridline_length_mod = 0.2f;

int grid_spacing = 12.5;
int token_mod = 18;

// Selecting Square in grid
int pos_x = 0;
int pos_y = 0;

int player_colour = 1;
int temp_colour = 1;

int grid[4][4] = {
   {0, 0, 0, 0} ,   /*  initialisers for row indexed by 0 */
   {0, 0, 0, 0} ,   /*  initialisers for row indexed by 1 */
   {0, 0, 0, 0} ,	/*  initialisers for row indexed by 2 */
   {0, 0, 0, 0}		/*  initialisers for row indexed by 3 */
};


int win_condition[24] = { {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, };

internal void
simulate_game(Input* input, float dt) {
	clear_screen(0x000000);


	// Selector Controls
	if (pressed(BUTTON_UP) && pos_y > 0) {
		pos_y = pos_y - 1;
		player_pos_y = player_pos_y + grid_spacing;
	}

	if (pressed(BUTTON_DOWN) && pos_y < 3) {
		pos_y = pos_y + 1;
		player_pos_y = player_pos_y - grid_spacing;
	}

	if (pressed(BUTTON_LEFT) && pos_x > 0) {
		pos_x = pos_x - 1;
		player_pos_x = player_pos_x - grid_spacing;
	}

	if (pressed(BUTTON_RIGHT) && pos_x < 3) {
		pos_x = pos_x + 1;
		player_pos_x = player_pos_x + grid_spacing;
	}


	// Placing tokens for - 
	if (pressed(BUTTON_LMB) && player_colour == 1 && temp_colour == 1) {
		token[pos_y][pos_x].bin_colour = 1;
		token[pos_y][pos_x].colour = 0xff0000;
		token[pos_y][pos_x].height = 1;
		token[pos_y][pos_x].width = 4;
		token[pos_y][pos_x].xcoord = pos_x;
		token[pos_y][pos_x].ycoord = pos_y;

		grid[pos_y][pos_x] = 1;
		player_colour = -1;
		temp_colour = 1;
	}

	if (pressed(BUTTON_LMB) && player_colour == -1 && temp_colour == -1 ) {
		token[pos_y][pos_x].bin_colour = 1;
		token[pos_y][pos_x].colour = 0xff0000;
		token[pos_y][pos_x].height = 1;
		token[pos_y][pos_x].width = 4;
		token[pos_y][pos_x].xcoord = pos_x;
		token[pos_y][pos_x].ycoord = pos_y;

		grid[pos_y][pos_x] = -1;
		player_colour = 1;
		temp_colour = -1;

	}

	// Colour Switches
	if (temp_colour == 1) {
		temp_colour = -1;
	}
	else {
		temp_colour = 1;
	}

	//Selector Colour.
	if (player_colour == 1) {
		draw_rect(player_pos_x, player_pos_y, 5, 5, 0xff0000);
	}
	if (player_colour == -1) {
		draw_rect(player_pos_x, player_pos_y, 5, 5, 0x0000ff);
	}

	// Horizontal Lines.
	draw_rect(0, 2 * grid_spacing, gridline_length + gridline_length_mod, gridline_width, 0xffffff);
	draw_rect(0, grid_spacing, gridline_length + gridline_length_mod, gridline_width, 0xffffff);
	draw_rect(0, 0, gridline_length + gridline_length_mod, gridline_width, 0xffffff);
	draw_rect(0, -1 * grid_spacing, gridline_length + gridline_length_mod, gridline_width, 0xffffff);
	draw_rect(0, -2 * grid_spacing, gridline_length + gridline_length_mod, gridline_width, 0xffffff);

	// Vertical Lines.
	draw_rect(2 * grid_spacing, 0, gridline_width, gridline_length, 0xffffff);
	draw_rect(grid_spacing, 0, gridline_width, gridline_length, 0xffffff);
	draw_rect(0, 0, gridline_width, gridline_length, 0xffffff);
	draw_rect(-1 * grid_spacing, 0, gridline_width, gridline_length, 0xffffff);
	draw_rect(-2 * grid_spacing, 0, gridline_width, gridline_length, 0xffffff);

	// Draw Tokens.
	draw_token(token, grid_spacing, token_mod);

	check_win(win_condition, grid);
}