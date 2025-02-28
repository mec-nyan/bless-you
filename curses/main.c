// main.c
#include <curses.h>
#include <iso646.h>
#include <stdio.h>
#include <stdlib.h>
#include "init.h"
#include "info.h"


int main( void ) {
	//
	WINDOW* screen = init_curses();
	if ( not screen ) {
		perror( "error: failed to initialize ncurses.\n" );
		return EXIT_FAILURE;
	}

	atexit( clean );

	setup();

	show_info();

	return 0;
}
