import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    public static Scanner cin = new Scanner (new BufferedInputStream(System.in));
    public static void main(String[] args) {
        int n = cin.nextInt();
        int [][] a = new int[n][n];
        int [] f = new int[n];
        int [] line = new int[n];
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                a[i][j] = cin.nextInt();
            }
        }
        for (int start_line = 0; start_line < n; ++start_line) {
            Arrays.fill(line, 0);
            for (int end_line = start_line; end_line < n; ++end_line) {
                Arrays.fill(f, 0);
                for (int i = 0; i < n; ++i) {
                    line[i] += a[end_line][i];
                    f[i] = (i == 0 ? line[i] : Math.max(f[i - 1] + line[i], line[i]));
                    ans = Math.max(ans, f[i]);
                }
            }
        }
        System.out.println(ans);
    }
}

