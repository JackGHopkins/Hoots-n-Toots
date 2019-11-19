#define is_down(b) input->buttons[b].is_down
#define pressed(b) (input->buttons[b].is_down && input->buttons[b].changed)
#define release(b) (!input->buttons[b].is_down && input->buttons[b].changed)

float player_pos_x = -18.f;
float player_pos_y = +18.f;
float gridline_width = 0.2f;
float gridline_length = 24.f;

int gridline_spacing = 12.5;

// Selecting Square in grid
int pos_x = 0;
int pos_y = 0;

int grid_select[4][4] = {
   {0, 0, 0, 0} ,   /*  initializers for row indexed by 0 */
   {0, 0, 0, 0} ,   /*  initializers for row indexed by 1 */
   {0, 0, 0, 0} ,	/*  initializers for row indexed by 2 */
   {0, 0, 0, 0}	/*  initializers for row indexed by 3 */
};

int win_condition[24] = { {0}, {0}, {}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, };

internal void
simulate_game (Input* input, float dt) {
	clear_screen(0x000000);

	float speed = 50.f; // units per second 
	//if (is_down(BUTTON_UP)) player_pos_y += speed * dt;
	//if (is_down(BUTTON_DOWN)) player_pos_y -= speed * dt;
	//if (is_down(BUTTON_LEFT)) player_pos_x -= speed * dt;
	//if (is_down(BUTTON_RIGHT)) player_pos_x += speed * dt;

	draw_rect(player_pos_x, player_pos_y, 5, 5, 0xff0000);

	if (pressed(BUTTON_UP) && pos_y > 0) {
		pos_y = pos_y - 1;
		player_pos_y = player_pos_y + gridline_spacing;
	}

	if (pressed(BUTTON_DOWN) && pos_y < 3) {
		pos_y = pos_y + 1;
		player_pos_y = player_pos_y - gridline_spacing;
	}

	if (pressed(BUTTON_LEFT) && pos_x > 0) {
		pos_x = pos_x - 1;
		player_pos_x = player_pos_x - gridline_spacing;
	}

	if (pressed(BUTTON_RIGHT) && pos_x < 3) {
		pos_x = pos_x + 1;
		player_pos_x = player_pos_x + gridline_spacing;
	}

	// Horizontal Lines.
	draw_rect(0, 2*gridline_spacing, gridline_length, gridline_width, 0xffffff);
	draw_rect(0, gridline_spacing, gridline_length, gridline_width, 0xffffff);
	draw_rect(0, 0, gridline_length, gridline_width, 0xffffff);
	draw_rect(0, -1*gridline_spacing, gridline_length, gridline_width, 0xffffff);
	draw_rect(0, -2*gridline_spacing, gridline_length, gridline_width, 0xffffff);
	
	// Vertical Lines.
	draw_rect(2 * gridline_spacing, 0, gridline_width, gridline_length, 0xffffff);
	draw_rect(gridline_spacing, 0, gridline_width, gridline_length, 0xffffff);
	draw_rect(0, 0, gridline_width, gridline_length, 0xffffff);
	draw_rect(-1 * gridline_spacing, 0, gridline_width, gridline_length, 0xffffff);
	draw_rect(-2 * gridline_spacing, 0, gridline_width, gridline_length, 0xffffff);
}