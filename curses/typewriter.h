#include <curses.h>

typedef struct {
	int y, x;
} Pos;

Pos new_pos( int y, int x ) {
	return (Pos){ y, x };
}

// TODO: Improve this functions iterating each letter/symbol and not
// "bytes" since some unicode characters will occupy several bytes.
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

int type_at( const char* text, Pos p ) {
	move( p.y, p.x );
	return type( text );
}

int type_at_and_wait( const char* text, Pos p, int delay ) {
	int got = type_at( text, p );
	napms( delay );
	return got;
}
