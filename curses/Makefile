IN = main.c
DEP = init.h typewriter.h info.h
OUT = main.o
COMPILER_FLAGS = -I /opt/homebrew/opt/ncurses/include \
				 -lncurses \
 				 -std=c17 -Wall -Werror -Wpedantic

$(OUT): $(IN) $(DEP)
	@gcc -o $(OUT) $(COMPILER_FLAGS) $(IN)

run: $(OUT)
	@if [ -e ./$(OUT) ]; then ./$(OUT); fi

run_verbose: $(OUT)
	@if [ -e ./$(OUT) ]; then \
		export BLESS_YOU_VERBOSE=1 && ./$(OUT); fi

run_fast: $(OUT)
	@if [ -e ./$(OUT) ]; then ./$(OUT) --fast; fi

clean:
	@if [ -e ./$(OUT) ]; then rm ./$(OUT); fi
