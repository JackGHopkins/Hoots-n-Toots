#include <windows.h>

bool running = true;

void* buffer_memory;
int buffer_width;
int buffer_height;
BITMAPINFO buffer_bitmap_info;

LRESULT CALLBACK window_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	LRESULT result = 0;

	// Stop the program running when the window is closed.
	switch (uMsg) {
		case WM_CLOSE:
		case WM_DESTROY: {
			running = false;
		}
		break;

		// Creating flexible screen size.

		case WM_SIZE: {
			RECT rect;
			GetClientRect(hwnd, &rect);
			buffer_width = rect.right - rect.left;
			buffer_height = rect.bottom - rect.top;

			int buffer_size = buffer_width * buffer_height * sizeof(unsigned int);

			if (buffer_memory) VirtualFree(buffer_memory, 0, MEM_RELEASE);
			// Make memory from the heap. Not using Malloc but instead a windows specific function as a butter. The memory is a void pointer.
			buffer_memory = VirtualAlloc(0, buffer_size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

			// Creating bitmap that contains information about the dimensions and color of a DIB (Type of colour table) to create an image.
			buffer_bitmap_info.bmiHeader.biSize = sizeof(buffer_bitmap_info.bmiHeader);
			buffer_bitmap_info.bmiHeader.biWidth = buffer_width;
			buffer_bitmap_info.bmiHeader.biHeight = buffer_height;
			buffer_bitmap_info.bmiHeader.biPlanes = 1;
			buffer_bitmap_info.bmiHeader.biBitCount = 32;
			buffer_bitmap_info.bmiHeader.biCompression = BI_RGB;
		}
		break;

		// Sets up call back.
		default: {
			result = DefWindowProc(hwnd, uMsg, wParam, lParam);
		}
	}
	return result;
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
	// Create a Window Class.
	WNDCLASS window_class = {};

	// Draw window horizontall and vertically. 
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	window_class.lpszClassName = "Game Window Class";
	window_class.lpfnWndProc = window_callback;

	// Register Class
	RegisterClass(&window_class);

	// Call "Create Window"
	HWND window = CreateWindow(window_class.lpszClassName, "Hoot 'n Toot", WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, 0, 0, hInstance, 0);
	// Handle to a device context (the reference that windows uses to get a device context to draw to the window).
	HDC hdc = GetDC(window);


	while (running) {
		// Input
		MSG message;
		while(PeekMessage(&message, window, 0, 0, PM_REMOVE)) {
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		// Simulate

		// Render
		StretchDIBits(hdc, 0, 0, buffer_width, buffer_height, 0, 0, buffer_width, buffer_height, buffer_memory, &buffer_bitmap_info, DIB_RGB_COLORS, SRCCOPY);
	}
}
