#include <curses.h>
#include <clocale>
#include <iostream>
#include <string>


struct NcursesOptions {
	std::string locale;
	bool        start_color, default_colors, cbreak, noecho, hide_cur;
};

class Ncurses {
public:
	Ncurses();
	Ncurses( NcursesOptions );
	~Ncurses();

	int add_str( std::string ) const;
	int add_str_at( std::string, int, int ) const;
	int paint( bool ) const;

	enum class Color { BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE };

	Ncurses* set_fg( Color );
	Ncurses* set_bg( Color );

	enum class Style { NORMAL, BOLD, DIM, ITALIC, STROKE, REVERSE, HIDDEN, BLINK, UNDERLINE };

	Ncurses* set_attr( Style );
	Ncurses* del_attr( Style );

	int show() const;
	int clear() const;

	char get_char() const;

private:
	WINDOW* screen;

	WINDOW* init( NcursesOptions ) const;
};

inline Ncurses::Ncurses( NcursesOptions opts ) {
	screen = init( opts );
}

inline Ncurses::Ncurses() {
	NcursesOptions opts = {
		.locale         = "",
		.start_color    = true,
		.default_colors = true,
		.cbreak         = true,
		.noecho         = true,
		.hide_cur       = true,
	};
	screen = init( opts );
}

inline Ncurses::~Ncurses() {
	if ( screen ) {
		echo();
		nocbreak();
		curs_set( true );
		endwin();
	}
	// TODO: Verbose finalization of curses.
	// Maybe add terminal info, etc.
	if ( std::getenv( "BLESS_YOU_VERBOSE" ) ) {
		std::cout << "Bless you!\n";
	}
}

inline WINDOW* Ncurses::init( NcursesOptions opts ) const {
	char* locale = std::setlocale( LC_ALL, opts.locale.c_str() );
	if ( not locale ) {
		throw "Error: setlocale()";
	}

	auto screen = initscr();
	if ( not screen ) {
		throw "Error: initscr()";
	}

	if ( opts.start_color ) {
		if ( not has_colors() ) {
			throw "Error: Terminal doesn't handle colors.";
		}
		// TODO: Check for error return values.
		start_color();
		opts.default_colors and use_default_colors();
	}

	opts.cbreak and   cbreak();
	opts.noecho and   noecho();
	opts.hide_cur and curs_set( false );

	return screen;
}

// TODO: Better return values.
inline int Ncurses::add_str( std::string text ) const {
	return waddstr( screen, text.c_str() );
}

inline int Ncurses::add_str_at( std::string text, int y, int x ) const {
	return mvwaddstr( screen, y, x, text.c_str() );
}

inline int Ncurses::paint( bool now ) const {
	if ( now ) {
		return wrefresh( screen );
	}
	return wnoutrefresh( screen );
}

inline char Ncurses::get_char() const {
	return char( wgetch( screen ) );
}

inline int Ncurses::clear() const {
	return wclear( screen );
}

inline int Ncurses::show() const {
	return doupdate();
}

inline Ncurses* Ncurses::set_attr( Ncurses::Style st ) {
	switch (st) {
		case Style::NORMAL:
		wattrset(screen, A_NORMAL);
		break;
		case Style::BOLD:
		wattrset(screen, A_BOLD);
		break;
		case Style::DIM:
		wattrset(screen, A_DIM);
		break;
		case Style::ITALIC:
		wattrset(screen, A_ITALIC);
		break;
		case Style::STROKE:
			// TODO: curses dosn't handle strikethrough.
		break;
		case Style::REVERSE:
		wattrset(screen, A_STANDOUT);
		break;
		case Style::HIDDEN:
		wattrset(screen, A_PROTECT);
		break;
		case Style::BLINK:
		wattrset(screen, A_BLINK);
		break;
		case Style::UNDERLINE:
		wattrset(screen, A_UNDERLINE);
		break;
	}
	return this;
}

inline Ncurses* Ncurses::del_attr( Ncurses::Style st ) {
	switch (st) {
		case Style::NORMAL:
		wattroff(screen, A_NORMAL);
		break;
		case Style::BOLD:
		wattroff(screen, A_BOLD);
		break;
		case Style::DIM:
		wattroff(screen, A_DIM);
		break;
		case Style::ITALIC:
		wattroff(screen, A_ITALIC);
		break;
		case Style::STROKE:
			// TODO: curses dosn't handle strikethrough.
		break;
		case Style::REVERSE:
		wattroff(screen, A_STANDOUT);
		break;
		case Style::HIDDEN:
		wattroff(screen, A_PROTECT);
		break;
		case Style::BLINK:
		wattroff(screen, A_BLINK);
		break;
		case Style::UNDERLINE:
		wattroff(screen, A_UNDERLINE);
		break;
	}
	return this;
}
