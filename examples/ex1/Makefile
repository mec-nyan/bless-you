IN = ex1.cpp
OUT = ex1.o
# macOS: I've installed a more recent version of curses with brew.
# because macOS is s**t, and comes with a very outdated one.
# Replace or remove some of the COMPILER_FLAGS accordingly!
COMPILER_FLAGS = -I /opt/homebrew/opt/ncurses/include \
				 -lncurses \
				 -std=c++23 -Wall -Werror -Wpedantic

$(OUT): $(IN)
	@g++ -o $(OUT) $(COMPILER_FLAGS) $(IN)

run: $(OUT)
	@if [ -e ./$(OUT) ]; then ./$(OUT); fi

clean:
	@if [ -e ./$(OUT) ]; then rm ./$(OUT); fi
