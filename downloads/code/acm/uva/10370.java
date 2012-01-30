import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    public static Scanner cin = new Scanner (new BufferedInputStream(System.in));
    public static void main(String[] args) {
        int c = cin.nextInt();
        int [] a = new int[1000];
        while (c-- > 0) {
            int n = cin.nextInt();
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                a[i] = cin.nextInt();
                sum += a[i];
            }
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (a[i] * n > sum) {
                    ++cnt;
                }
            }
            System.out.printf("%.3f%%\n", 100.0 * cnt / n);
        }
    }
}

