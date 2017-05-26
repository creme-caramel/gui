#include <window.h>

int main()
{
	Window *w = init_window(640, 480, "cool");
	if (!w) return 1;
	ImVec4 clear_color = ImColor(144, 144, 144);

	bool show_test_window = true;
	bool show_another_window = false;

	while (!window_should_close(w))
	{
		pollevents();
		ImGui_ImplGlfw_NewFrame();



		render(w, clear_color);
	}

	terminate_window(w);
	return 0;
}
