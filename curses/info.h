#include "typewriter.h"


void say_hi( timing t ) {
	int  sz = 200;
	char line[ sz ];
	snprintf(
		line, sz, "This is ncurses version %d.%d", NCURSES_VERSION_MAJOR, NCURSES_VERSION_MINOR );

	type_at_and_wait( line, (Pos){ 2, 4 }, t );

	type_at_and_wait( "Have you heard about it?", (Pos){ 4, 4 }, t );
}

void term_info( timing t ) {
	type_at_and_wait( "Terminal info:", (Pos){ 2, 4 }, t );

	int  sz = 200;
	char line[ sz ];

	int y = 4, x = 8;
	snprintf( line, sz, "Name: %s", termname() );
	type_at_and_wait( line, (Pos){ y, x }, t );
	y += 2;

	snprintf( line, sz, "Lines: %d", LINES );
	type_at_and_wait( line, (Pos){ y, x }, t );
	y += 2;

	snprintf( line, sz, "Columns: %d", COLS );
	type_at_and_wait( line, (Pos){ y, x }, t );
	y += 2;

	snprintf( line, sz, "Has colours? %s", has_colors() ? "true" : "false" );
	type_at_and_wait( line, (Pos){ y, x }, t );
	y += 2;

	snprintf( line, sz, "Can define colours? %s", can_change_color() ? "true" : "false" );
	type_at_and_wait( line, (Pos){ y, x }, t );
	y += 2;

	snprintf( line, sz, "Number of colours: %d", COLORS );
	type_at_and_wait( line, (Pos){ y, x }, t );
	y += 2;

	snprintf( line, sz, "Number of pairs: %d", COLOR_PAIRS );
	type_at_and_wait( line, (Pos){ y, x }, t );
	y += 2;
}

void good_bye( timing t ) {
	type_at_and_wait( "Bye then!", (Pos){ 2, 4 }, t );
}

void show_info( timing t ) {
	say_hi( t );
	clear();
	term_info( t );
}

timing set_speed( bool fast ) {
	int fps = 20, wait = 1500;
	if ( fast ) {
		fps  = 50;
		wait = 300;
	}
	return (timing){ fps, wait };
}

void quit( timing t ) {
	int y, x;
	getmaxyx( stdscr, y, x );
	x      = 4;
	y     -= 2;
	Pos p  = { y, x };
	type_at_and_wait( "Press any key to quit", p, t );

	getch();

	clear();
	type_at_and_wait( "Good bye then!", p, t );
}
