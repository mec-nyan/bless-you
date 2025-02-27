// ex1.cpp
#include "../../blessyou.hpp"

int main() {

	auto nc = Ncurses();


	nc.add_str_at("I 💖 ", 4, 8);

	nc.set_attr(Ncurses::Style::ITALIC)->set_attr(Ncurses::Style::DIM);

	nc.add_str("C++!");

	nc.get_char();

	return 0;

}
