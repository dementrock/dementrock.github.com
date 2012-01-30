import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    public static Scanner cin = new Scanner (new BufferedInputStream(System.in));
    public static void main(String[] args) {
        BigInteger [] fac = new BigInteger[1001];
        fac[0] = BigInteger.ONE;
        for (int i = 1; i <= 1000; ++i) {
            fac[i] = fac[i - 1].multiply(BigInteger.valueOf(i));
        }
        while (cin.hasNextInt()) {
            int n = cin.nextInt();
            System.out.println(Integer.toString(n) + "!");
            System.out.println(fac[n]);
        }
    }
}

