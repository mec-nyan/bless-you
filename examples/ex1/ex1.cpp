// ex1.cpp
#include "../../blessyou.hpp"

int main() {

	auto nc = Ncurses();

	nc.add_str_at("I 💖 C++!", 4, 8);

	nc.get_char();

	return 0;

}
