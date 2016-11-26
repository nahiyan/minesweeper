void new_game(int height, int width, int mines) {
    int selection[] = {0, 0};
    int map[height][width][4];
    int game_status = 0;

    // Setup the ncurses window
    clear();
    noecho();

    // Generate map and draw the board
    generate_map(height, width, map);
    render_board(height, width, map, selection, &game_status);

    // Set cursor at position 0, 0
    move(0, 0);
    refresh();

    // Listen to keyboard
    keyboard_listener(height, width, map, selection, &game_status, mines);

    // Clear up the terminal
    endwin();
}