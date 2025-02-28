#include <curses.h>

class ColorPair {
public:
	ColorPair();
	~ColorPair();

private:
	int ncolors;
	int npairs;
};

inline ColorPair::ColorPair() {
	
}
