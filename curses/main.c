// main.c
#include <curses.h>
#include <iso646.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "info.h"
#include "init.h"


int main( int argc, char* argv[] ) {
	//
	WINDOW* screen = init_curses();
	if ( not screen ) {
		perror( "error: failed to initialize ncurses.\n" );
		return EXIT_FAILURE;
	}

	atexit( clean );

	Timing t = set_speed( argc > 1 and strncmp( argv[ 1 ], "--fast", 6 ) == 0 );

	setup();

	show_info( t );

	quit( t );

	return 0;
}
