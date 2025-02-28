IN = main.c
OUT = main.o
COMPILER_FLAGS = -I /opt/homebrew/opt/ncurses/include \
				 -lncurses \
 				 -std=c17 -Wall -Werror -Wpedantic

$(OUT): $(IN)
	@gcc -o $(OUT) $(COMPILER_FLAGS) $(IN)

run: $(OUT)
	@if [ -e ./$(OUT) ]; then ./$(OUT); fi

clean:
	@if [ -e ./$(OUT) ]; then rm ./$(OUT); fi
