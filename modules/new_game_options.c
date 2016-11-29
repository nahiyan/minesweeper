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

    move(1, 0);
    refresh();

    char input, option = 0;

    while (input != 13) {
        input = getchar();
        switch (input) {
            case 'w':
                if ((option - 1) >= 0)
                    option--;
                break;
            case 's':
                if ((option + 1) <= 3)
                    option++;
                break;
        }
        move(option + 1, 0);
        refresh();
    }

    if (option == 0 || option == 1 || option == 2)
        switch (option) {
            case 0:
                height = 10;
                width = 20;
                mines = 15;
                break;
            case 1:
                height = 20;
                width = 40;
                mines = 200;
                break;
            case 2:
                height = 40;
                width = 80;
                mines = 400;
                break;
        }
    else if (option == 3) {
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