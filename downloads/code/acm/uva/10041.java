import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    public static Scanner cin = new Scanner (new BufferedInputStream(System.in));
    public static void main(String[] args) {
        int t = cin.nextInt();
        int [] s = new int[500];
        while (t-- > 0) {
            int r = cin.nextInt();
            for (int i = 0; i < r; ++i) {
                s[i] = cin.nextInt();
            }
            Arrays.sort(s, 0, r);
            int mid = s[r / 2];
            int ans = 0;
            for (int i = 0; i < r; ++i) {
                ans += Math.abs(s[i] - mid);
            }
            System.out.println(ans);
        }
    }
}

