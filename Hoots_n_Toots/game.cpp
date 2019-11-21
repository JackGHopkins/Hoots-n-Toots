#define is_down(b) input->buttons[b].is_down
#define pressed(b) (input->buttons[b].is_down && input->buttons[b].changed)
#define release(b) (!input->buttons[b].is_down && input->buttons[b].changed)

float player_pos_x = -18.f;
float player_pos_y = +18.f;
float gridline_width = 0.2f;
float gridline_length = 24.f;
float gridline_length_mod = 0.2f;

int gridline_spacing = 12.5;

// Selecting Square in grid
int pos_x = 0;
int pos_y = 0;

int player_colour = 0;

int grid_select[4][4] = {
   {0, 0, 0, 0} ,   /*  initialisers for row indexed by 0 */
   {0, 0, 0, 0} ,   /*  initialisers for row indexed by 1 */
   {0, 0, 0, 0} ,	/*  initialisers for row indexed by 2 */
   {0, 0, 0, 0}		/*  initialisers for row indexed by 3 */
};

int win_condition[24] = { {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}, };


class Token {
private:
	int m_width;
	int m_height;
	int m_pos_x;
	int m_pos_y;
	string m_colour;
public:
	Token() {}
	Token(const )
};

internal void
simulate_game (Input* input, float dt) {
	clear_screen(0x000000);

	if (player_colour == 0) {
		draw_rect(player_pos_x, player_pos_y, 5, 5, 0xff0000);
	}

	if (player_colour == 1) {
		draw_rect(player_pos_x, player_pos_y, 5, 5, 0x0000ff);
	}

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


	// Placing tokens for - 
	if (pressed(BUTTON_LMB) && player_colour == 0) {
		draw_rect(player_pos_x, player_pos_y, 4, 2, 0xff0000);
		
	}

	if (pressed(BUTTON_LMB) && player_colour == 1) {
		draw_rect(player_pos_x, player_pos_y, 2, 4, 0x0000ff);
		player_colour = 0;
	}

	// Horizontal Lines.
	draw_rect(0, 2*gridline_spacing, gridline_length + gridline_length_mod, gridline_width, 0xffffff);
	draw_rect(0, gridline_spacing, gridline_length + gridline_length_mod, gridline_width, 0xffffff);
	draw_rect(0, 0, gridline_length + gridline_length_mod, gridline_width, 0xffffff);
	draw_rect(0, -1*gridline_spacing, gridline_length + gridline_length_mod, gridline_width, 0xffffff);
	draw_rect(0, -2*gridline_spacing, gridline_length + gridline_length_mod, gridline_width, 0xffffff);
	
	// Vertical Lines.
	draw_rect(2 * gridline_spacing, 0, gridline_width, gridline_length, 0xffffff);
	draw_rect(gridline_spacing, 0, gridline_width, gridline_length, 0xffffff);
	draw_rect(0, 0, gridline_width, gridline_length, 0xffffff);
	draw_rect(-1 * gridline_spacing, 0, gridline_width, gridline_length, 0xffffff);
	draw_rect(-2 * gridline_spacing, 0, gridline_width, gridline_length, 0xffffff);
}