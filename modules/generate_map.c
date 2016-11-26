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