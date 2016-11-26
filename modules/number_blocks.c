void number_blocks (int height, int width, int map[height][width][4]) {
    int number, y, x, i, j;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            number = 0;

            if (!map[y][x][3]) {// if self is not mine
                for (i = (y - 1); i <= (y + 1); i++) {
                    for (j = (x - 1); j <= (x + 1); j++) {
                        if (in_map(i, j, height, width)) {
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