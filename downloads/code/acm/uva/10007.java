import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    public static final int MAXN = 300;
    public static BigInteger[] f = new BigInteger[MAXN+1];
    public static boolean[] vis = new boolean[MAXN+1];
    public static Scanner cin = new Scanner (new BufferedInputStream(System.in));
    public static BigInteger dp (int n) {
        if (vis[n]) {
            return f[n];
        }
        vis[n] = true;
        if (n <= 1) {
            return f[n] = BigInteger.valueOf(1);
        }
        f[n] = BigInteger.valueOf(0);
        for (int i = 0; i < n; ++i) {
            f[n] = f[n].add(dp(i).multiply(dp(n - 1 - i)));
        }
        return f[n];
    }
    public static void main(String[] args) {
        BigInteger frac = BigInteger.valueOf(1);
        BigInteger[] ans = new BigInteger[MAXN+1];
        for (int i = 1; i <= MAXN; ++i) {
            frac = frac.multiply(BigInteger.valueOf(i));
            ans[i] = frac.multiply(dp(i));
        }
        while (true) {
            int n = cin.nextInt();
            if (n == 0) {
                break;
            }
            System.out.println(ans[n]);
        }
    }
}
