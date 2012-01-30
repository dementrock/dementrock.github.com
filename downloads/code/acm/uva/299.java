import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    public static Scanner cin = new Scanner (new BufferedInputStream(System.in));
    public static void main(String[] args) {
        int n, l, cntSwap, tmp;
        int [] a = new int[100];
        n = cin.nextInt();
        while (n-- > 0) {
            l = cin.nextInt();
            cntSwap = 0;
            for (int i = 0; i < l; ++i) {
                a[i] = cin.nextInt();
            }
            for (int i = 0; i < l; ++i) {
                for (int j = 1; j < l; ++j) {
                    if (a[j - 1] > a[j]) {
                        ++cntSwap;
                        tmp = a[j - 1];
                        a[j - 1] = a[j];
                        a[j] = tmp;
                    }
                }
            }
            System.out.printf("Optimal train swapping takes %d swaps.\n", cntSwap);
        }
    }
}
