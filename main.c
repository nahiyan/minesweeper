#include <ncurses.h>
#include <unistd.h>
#include <stdio.h>
#include "random_number.c"

int height,
    width,
    map[1000][1000][4],
    max_mines,
    game_status = 0, // 0 -> not started, -1 -> lost, 1 -> game started and 2 -> won!
    map_generated = 0,
    selection[2] = {0, 0}; // y x

int unrevealed_good_blocks () {
    int count = 0, i, j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (!map[i][j][1] && !map[i][j][3]) // If invisible and doesn't contain a mine
                count++;
        }
    }

    return count;
}

void make_map_visible () {
    int i, j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            map[i][j][1] = 1;
        }
    }
}

int in_map (y, x) {
    if (x >= 0 && x < width) {
        if (y >= 0 && y < height)
            return 1;
    }
    return 0;
}

void number_blocks () {
    int number, y, x, i, j;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            number = 0;

            if (!map[y][x][3]) {// if self is not mine
                for (i = (y - 1); i <= (y + 1); i++) {
                    for (j = (x - 1); j <= (x + 1); j++) {
                        if (in_map(i, j)) {
                            if (!(i == y && j == x)) { // Not self
                                if (map[i][j][3]) // Mine
                                    number++;
                            }
                        }   
                    }
                }

                map[y][x][2] = number;
            }
        }
    }
}

void generate_mines (int y, int x) {
    int mines = 0;
    int position[2];

    while (mines < max_mines) {
        position[0] = random_number(0, height - 1);
        position[1] = random_number(0, width - 1);
        if (!map[position[0]][position[1]][3]) { // If there's no mine already
            if (position[0] != y && position[1] != x) {
                map[position[0]][position[1]][3] = 1;
                mines++;
            }
        }
    }

    number_blocks();
}

void generate_map (int height, int width) {
    int i, j;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            map[i][j][0] = 0;
            map[i][j][1] = 0;
            map[i][j][2] = 0;
            map[i][j][3] = 0;
        }
    }
    map_generated = 1;
}

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

void reveal_block (int y, int x) {
    map[y][x][1] = 1; // Make it visible

    if (!map[y][x][2]) { // invisible and not numbered
        int i, j;

        for (i = (y - 1); i <= (y + 1); i++) {
            for (j = (x - 1); j <= (x + 1); j++) {
                if (in_map(i, j)) {
                    if (!map[i][j][3] && !map[i][j][1]) { // not mine and not visible
                        reveal_block(i, j);
                    }
                }   
            }
        }
    }
}

void keyboard_listener () {
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
            case 'q':
                if (!map[*y][*x][1]) { // Only let player flag invisible blocks
                    if (map[*y][*x][0])
                        map[*y][*x][0] = 0;
                    else
                        map[*y][*x][0] = 1;
                }
                break;
            case 'e':
                if (game_status == 0) {
                    game_status = 1;
                    generate_mines(*y, *x);
                }

                if (!map[*y][*x][0]) { // Continue if it's not flagged
                    if (map[*y][*x][3]) { // If the user steps on a mine
                        make_map_visible();
                        game_status = -1; // Player lost!
                    } else {
                        reveal_block(*y, *x);
                        if (!unrevealed_good_blocks())
                            game_status = 2; // Player won!
                    }
                }
                
                break;
        }

        render_board();
    }
}

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

void new_game_options () {
    // Setup ncurses window
    initscr();
    noecho();
    curs_set(TRUE);

    mvprintw(0, 0, "Select your difficulty:\n");
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
                max_mines = 30;
                break;
            case '2':
                height = 20;
                width = 40;
                max_mines = 300;
                break;
            case '3':
                height = 40;
                width = 80;
                max_mines = 600;
                break;
        }
    else if (difficulty == '4') {
        clear();
        echo();
        printw("What will be the size of your board?\n");
        printw("Height: ");
        scanw("%d", &height);
        printw("Width: ");
        scanw("%d", &width);
        printw("Mines: ");
        scanw("%d", &max_mines);
    } else {
        height = 10;
        width = 20;
        max_mines = 30;
    }
    new_game();
}

int main() {
    new_game_options();

    return 0;
}