#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>

#include "modules/random_number.c"
#include "modules/generate_map.c"
#include "modules/render_board.c"
#include "modules/in_map.c"
#include "modules/make_map_visible.c"
#include "modules/number_blocks.c"
#include "modules/generate_mines.c"
#include "modules/reveal_block.c"
#include "modules/unrevealed_good_blocks.c"
#include "modules/keyboard_listener.c"
#include "modules/new_game.c"
#include "modules/new_game_options.c"

int main() {
    new_game_options();

    return 0;
}