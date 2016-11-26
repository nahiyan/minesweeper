void new_game_options () {
    int height = 10,
        width = 20,
        mines = 30;

    // Setup ncurses window
    initscr();
    noecho();
    curs_set(TRUE);

    // Let player choose the difficulty
    printw("Select your difficulty:\n");
    printw("1. Beginner\n");
    printw("2. Intermediate\n");
    printw("3. Expert\n");
    printw("4. Custom\n");
    refresh();

    char difficulty = getchar();
    if (difficulty == '1' || difficulty == '2' || difficulty == '3')
        switch (difficulty) {
            case '1':
                height = 10;
                width = 20;
                mines = 30;
                break;
            case '2':
                height = 20;
                width = 40;
                mines = 300;
                break;
            case '3':
                height = 40;
                width = 80;
                mines = 600;
                break;
        }
    else if (difficulty == '4') {
        // Setup the ncurses window
        clear();
        echo();

        printw("What will be the size of your board?\n");
        printw("Height: ");
        scanw("%d", &height);
        printw("Width: ");
        scanw("%d", &width);
        printw("Mines: ");
        scanw("%d", &mines);
    }

    new_game(height, width, mines);
}