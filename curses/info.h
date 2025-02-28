#include "typewriter.h"


void say_hi( int ms ) {
	int  sz = 200;
	char line[ sz ];
	snprintf(
		line, sz, "This is ncurses version %d.%d", NCURSES_VERSION_MAJOR, NCURSES_VERSION_MINOR );

	type_at_and_wait( line, (Pos){ 2, 4 }, ms );

	type_at_and_wait( "Have you heard about it?", (Pos){ 4, 4 }, ms );
}

void term_info( int ms ) {
	type_at_and_wait( "Terminal info:", (Pos){ 2, 4 }, ms );

	int  sz = 200;
	char line[ sz ];

	int y = 4, x = 8;
	snprintf( line, sz, "Name: %s", termname() );
	type_at_and_wait( line, (Pos){ y, x }, ms );
	y += 2;

	snprintf( line, sz, "Lines: %d", LINES );
	type_at_and_wait( line, (Pos){ y, x }, ms );
	y += 2;

	snprintf( line, sz, "Columns: %d", COLS );
	type_at_and_wait( line, (Pos){ y, x }, ms );
	y += 2;

	snprintf( line, sz, "Has colours? %s", has_colors() ? "true" : "false" );
	type_at_and_wait( line, (Pos){ y, x }, ms );
	y += 2;

	snprintf( line, sz, "Can define colours? %s", can_change_color() ? "true" : "false" );
	type_at_and_wait( line, (Pos){ y, x }, ms );
	y += 2;

	snprintf( line, sz, "Number of colours: %d", COLORS );
	type_at_and_wait( line, (Pos){ y, x }, ms );
	y += 2;

	snprintf( line, sz, "Number of pairs: %d", COLOR_PAIRS );
	type_at_and_wait( line, (Pos){ y, x }, ms );
	y += 2;
}

void good_bye( int ms ) {
	type_at_and_wait( "Bye then!", (Pos){ 2, 4 }, ms );
}

void show_info( int ms ) {
	say_hi( ms );
	clear();
	term_info( ms );
}

int set_speed( bool fast ) {
	if ( fast ) {
		// TODO: Fix this global variable!
		ms = 20;
		return 300;
	}
	return 1500;
}

void quit( int ms ) {
	int y, x;
	getmaxyx( stdscr, y, x );
	x      = 4;
	y     -= 2;
	Pos p  = { y, x };
	type_at_and_wait( "Press any key to quit", p, ms );

	getch();

	clear();
	type_at_and_wait( "Good bye then!", p, ms );
}
