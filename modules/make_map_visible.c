void make_map_visible (int height, int width, int map[height][width][4]) {
    int i, j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            map[i][j][1] = 1;
        }
    }
}