void render_board (int height, int width, int map[height][width][4], int selection[2], int* game_status) {
    int i, j;

    // Draw the blocks
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            // Unrevealed block
            mvprintw(i, j, "x");

            // Flags
            if (map[i][j][0])
                mvprintw(i, j, "!");

            // If it's visible
            if (map[i][j][1]) {
                if (map[i][j][2] == 0)
                    mvprintw(i, j, " "); // Black space
                else
                    mvprintw(i, j, "%d", map[i][j][2]); // Display the number (1-9) of mines around this block

                // Mine
                if (map[i][j][3])
                    mvprintw(i, j, "*");
            }
        }
    }

    // Draw border to the right and bottom of the board
    for(i = 0; i < height; i++) {
        mvprintw(i, width, "|");
    }
    for(j = 0; j <= width; j++) {
        mvprintw(height, j, "-");
    }

    // Let the user know if the game is over
    if (*game_status == -1)
        mvprintw(0, 0, "YOU LOST!");
    if (*game_status == 2)
        mvprintw(0, 0, "YOU WON!");

    // Let the user move the cursor using WASD
    move(selection[0], selection[1]);

    refresh();
}