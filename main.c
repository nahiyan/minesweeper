#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>

int height,
    width,
    map[1000][1000][4],
    max_mines,
    game_status = 0, // 0 -> not started, -1 -> lost, 1 -> game started and 2 -> won!
    map_generated = 0,
    selection[2] = {0, 0}; // y x

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