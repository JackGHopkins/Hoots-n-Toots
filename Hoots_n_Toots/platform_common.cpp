struct Button_State {
	bool is_down;
	bool changed;
};

enum {
	BUTTON_UP,
	BUTTON_DOWN,
	BUTTON_LEFT,
	BUTTON_RIGHT,
	BUTTON_LMB,

	BUTTON_COUNT, // Should be the last item in the array, so we always know the size.
};

struct Input {
	Button_State buttons[BUTTON_COUNT];
};