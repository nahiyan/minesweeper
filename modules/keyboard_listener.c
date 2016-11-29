void keyboard_listener (int height, int width, int map[height][width][4], int selection[2], int* game_status, int mines) {
    char input;
    int* y = &selection[0];
    int* x = &selection[1];
    while (1) {
        input = getchar();
        switch (input) {
            case 'w':
                if ((*y - 1) >= 0 && (*y - 1) <= (height - 1))
                    *y -= 1;
                break;
            case 's':
                if ((*y + 1) >= 0 && (*y + 1) <= (height - 1))
                    *y += 1;
                break;
            case 'a':
                if ((*x - 1) >= 0 && (*x - 1) <= (width - 1))
                    *x -= 1;
                break;
            case 'd':
                if ((*x + 1) >= 0 && (*x + 1) <= (width - 1))
                    *x += 1;
                break;
            case 'e':
                if (!map[*y][*x][1]) { // Only let player flag invisible blocks
                    if (map[*y][*x][0])
                        map[*y][*x][0] = 0;
                    else
                        map[*y][*x][0] = 1;
                }
                break;
            case 'q':
                if (*game_status == 0) {
                    *game_status = 1;
                    generate_mines(*y, *x, mines, height, width, map);
                }

                if (!map[*y][*x][0]) { // Continue if it's not flagged
                    if (map[*y][*x][3]) { // If the user steps on a mine
                        make_map_visible(height, width, map);
                        *game_status = -1; // Player lost!
                    } else {
                        reveal_block(*y, *x, height, width, map);
                        if (!unrevealed_good_blocks(height, width, map))
                            *game_status = 2; // Player won!
                    }
                }
                
                break;
        }

        render_board(height, width, map, selection, game_status);
    }
}