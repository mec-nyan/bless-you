#include <curses.h>
#include <iso646.h>
#include <locale.h>

// This is just an example. We don't need to elaborate or pass
// arguments for different initialization options.
WINDOW* init_curses( void ) {
	// You need to set the locale first.
	const char* locale = setlocale( LC_ALL, "" );
	if ( not locale ) {
		return NULL;
	}

	// initscr will set the global "stdscr" as a WINDOW* to the
	// "main" window. It also returns that ptr, so I'd rather
	// name it "screen".
	WINDOW* screen = initscr();
	// But we could've just check "if ( not stdscr ) ...".
	if ( not screen ) {
		return NULL;
	}

	return screen;
}

int setup(void) {
	if ( not has_colors() ) {
		perror( "error: can't handle colors.\n" );
		return 1;
	}

	// TODO: Check for errors?
	noecho();
	cbreak();

	start_color();
	use_default_colors();

	return 0;
}

// Uset "atexit( clean )". So even if we exit with error early we will
// free resources and restore the terminal to its original state.
void clean( void ) {
	echo();
	nocbreak();
	curs_set( 1 );
	endwin();
	printf( "All cleaned up!\n" );
}
