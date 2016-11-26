void render_board () {
    if (!map_generated)
        generate_map(height, width);

    int i, j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            mvprintw(i, j, "x");
            // Flags
            if (map[i][j][0])
                mvprintw(i, j, "!");

            // If it's visible
            if (map[i][j][1]) {
                // Blank if there's nothing else we assume there's a number and we display it
                if (map[i][j][2] == 0)
                    mvprintw(i, j, " ");
                else
                    mvprintw(i, j, "%d", map[i][j][2]);

                // Mine
                if (map[i][j][3])
                    mvprintw(i, j, "*");
            }
        }
    }

    for(i = 0; i < height; i++) {
        mvprintw(i, width, "|");
    }
    for(j = 0; j <= width; j++) {
        mvprintw(height, j, "-");
    }

    if (game_status == -1)
        mvprintw(0, 0, "YOU LOST!");
    if (game_status == 2)
        mvprintw(0, 0, "YOU WON!");

    move(selection[0], selection[1]);

    refresh();
}