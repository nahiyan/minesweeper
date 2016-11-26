void generate_mines (int y, int x, int max_mines, int height, int width, int map[height][width][4]) {
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

    number_blocks(height, width, map);
}