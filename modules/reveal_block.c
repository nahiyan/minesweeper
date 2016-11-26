void reveal_block (int y, int x, int height, int width, int map[height][width][4]) {
    map[y][x][1] = 1; // Make it visible

    if (!map[y][x][2]) { // invisible and not numbered
        int i, j;

        for (i = (y - 1); i <= (y + 1); i++) {
            for (j = (x - 1); j <= (x + 1); j++) {
                if (in_map(i, j, height, width)) {
                    if (!map[i][j][3] && !map[i][j][1]) { // not mine and not visible
                        reveal_block(i, j, height, width, map);
                    }
                }   
            }
        }
    }
}