int in_map (int y, int x, int height, int width) {
    if (x >= 0 && x < width) {
        if (y >= 0 && y < height)
            return 1;
    }
    return 0;
}