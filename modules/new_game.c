void new_game() {
    clear();
    noecho();

    // Generate map and draw the board
    generate_map(height, width);
    render_board();

    // Set cursor at position 0, 0
    move(0, 0);
    refresh();

    // Listen to keyboard
    keyboard_listener();

    // Clear up the terminal
    endwin();
}