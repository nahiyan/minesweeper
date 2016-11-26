int in_map (y, x) {
    if (x >= 0 && x < width) {
        if (y >= 0 && y < height)
            return 1;
    }
    return 0;
}