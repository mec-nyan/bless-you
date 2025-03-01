#include "typewriter.h"


void say_hi( Timing t ) {
	int  sz = 200;
	char line[ sz ];
	snprintf(
		line, sz, "This is ncurses version %d.%d", NCURSES_VERSION_MAJOR, NCURSES_VERSION_MINOR );

	type_at_and_wait( line, (Pos){ 2, 4 }, t );

	type_at_and_wait( "Have you heard about it?", (Pos){ 4, 4 }, t );
}

void term_info( Timing t ) {
	Pos p = { 2, 4 };

	type_at_and_wait( "Terminal info:", p, t );

	int  sz = 200;
	char line[ sz ];

	p = incr_pos( p, 2, 4 );
	snprintf( line, sz, "Name: %s", termname() );
	type_at_and_wait( line, p, t );

	p = incr_y( p, 2 );
	snprintf( line, sz, "Lines: %d", LINES );
	type_at_and_wait( line, p, t );

	p = incr_y( p, 2 );
	snprintf( line, sz, "Columns: %d", COLS );
	type_at_and_wait( line, p, t );

	p = incr_y( p, 2 );
	snprintf( line, sz, "Has colours? %s", has_colors() ? "true" : "false" );
	type_at_and_wait( line, p, t );

	p = incr_y( p, 2 );
	snprintf( line, sz, "Can define colours? %s", can_change_color() ? "true" : "false" );
	type_at_and_wait( line, p, t );

	p = incr_y( p, 2 );
	snprintf( line, sz, "Number of colours: %d", COLORS );
	type_at_and_wait( line, p, t );

	p = incr_y( p, 2 );
	snprintf( line, sz, "Number of pairs: %d", COLOR_PAIRS );
	type_at_and_wait( line, p, t );
}

void good_bye( Timing t ) {
	type_at_and_wait( "Bye then!", (Pos){ 2, 4 }, t );
}

void show_info( Timing t ) {
	say_hi( t );
	clear();
	term_info( t );
}

Timing set_speed( bool fast ) {
	int fps = 20, wait = 1500;
	if ( fast ) {
		fps  = 50;
		wait = 300;
	}
	return (Timing){ fps, wait };
}

void quit( Timing t ) {
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
