int unrevealed_good_blocks (int height, int width, int map[height][width][4]) {
    int count = 0, i, j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            if (!map[i][j][1] && !map[i][j][3]) // If invisible and doesn't contain a mine
                count++;
        }
    }

    return count;
}