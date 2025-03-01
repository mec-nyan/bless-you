#include <curses.h>


typedef struct {
	int fps, wait;
} Timing;


typedef struct {
	int y, x;
} Pos;


Pos incr_y( Pos p, int incr ) {
	return (Pos){ p.y + incr, p.x };
}

Pos incr_x( Pos p, int incr ) {
	return (Pos){ p.y, p.x + incr };
}

Pos incr_pos( Pos p, int y, int x ) {
	return (Pos){ p.y + y, p.x + x };
}

// TODO: Improve this functions iterating each letter/symbol and not
// "bytes" since some unicode characters will occupy several bytes.
int type( const char* text, int fps ) {
	int count = 0;
	// Assume ASCII.
	while ( *text ) {
		addch( *text++ );
		refresh();
		// TODO: Don't use a global!
		napms( 1000 / fps );
		count++;
	}
	return count;
}

int type_at( const char* text, Pos p, int fps ) {
	move( p.y, p.x );
	return type( text, fps );
}

int type_at_and_wait( const char* text, Pos p, Timing t ) {
	int got = type_at( text, p, t.fps );
	napms( t.wait );
	return got;
}
