// curses.c
#include <curses.h>
#include <iso646.h>
#include <stdio.h>
#include <stdlib.h>
#include "init.h"

// TODO: Improve this functions iterating each letter/symbol and not "bytes"
// since some unicode characters will occupy several bytes.
int type( const char* text ) {
	int count = 0;
	// Assume ASCII.
	while ( *text ) {
		addch( *text++ );
		refresh();
		napms( 50 );
		count++;
	}
	return count;
}

int main( void ) {
	//
	WINDOW* screen = init_curses();
	if ( not screen ) {
		perror( "error: failed to initialize ncurses.\n" );
		return EXIT_FAILURE;
	}

	atexit( clean );

	if ( not has_colors() ) {
		perror( "error: can't handle colors.\n" );
		return EXIT_FAILURE;
	}

	noecho();
	cbreak();

	start_color();
	use_default_colors();

	char line[ 200 ];
	sprintf( line, "This is ncurses version %d.%d", NCURSES_VERSION_MAJOR, NCURSES_VERSION_MINOR );

	move( 2, 4 );
	type( line );
	getch();

	move( 4, 4 );
	type( "Did you know something about this?" );
	getch();

	move( 6, 4 );
	type( "See you later mate!" );
	napms( 1000 );

	return 0;
}
