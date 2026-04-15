public static int calculateLaps(int L, int W, int E, int R) {
    int perimeter = 2 * (L + W);
    int powerPerLap = perimeter * R;
    return E / powerPerLap;
}