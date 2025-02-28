// main.c
#include <curses.h>
#include <iso646.h>
#include <stdio.h>
#include <stdlib.h>
#include "init.h"
#include "typewriter.h"


int main( void ) {
	//
	WINDOW* screen = init_curses();
	if ( not screen ) {
		perror( "error: failed to initialize ncurses.\n" );
		return EXIT_FAILURE;
	}

	atexit( clean );

	setup();

	char line[ 200 ];
	sprintf( line, "This is ncurses version %d.%d", NCURSES_VERSION_MAJOR, NCURSES_VERSION_MINOR );

	int ms = 1500;

	type_at_and_wait( line, (Pos){ 2, 4 }, ms );

	type_at_and_wait( "Have you heard about it?", (Pos){ 4, 4 }, ms );

	type_at_and_wait( "See you then!", (Pos){ 6, 4 }, ms );


	return 0;
}
