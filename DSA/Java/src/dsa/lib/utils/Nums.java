package dsa.lib.utils;

public class Nums {
    /**
     * Get the value on the place specified.
     *
     * @param num   The num.
     * @param place The place. 1 for unit place, 10 for tens place, 100 for hundreds place.
     * @return The value digit.
     */
    public static int placeValueOf(int num, int place) {
        return lastDigitOf(num / place);
    }

    public static int lastDigitOf(int num) {
        return num % 10;
    }
}
