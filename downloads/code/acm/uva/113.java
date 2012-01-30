import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    public static Scanner cin = new Scanner (new BufferedInputStream(System.in));
    public static BigInteger calcRoot (BigInteger p, int n) {
        BigInteger one = BigInteger.ONE;
        BigInteger two = BigInteger.valueOf(2);
        BigInteger l = one, r = BigInteger.valueOf(1000000000L);
        while (r.subtract(l).compareTo(BigInteger.ONE) >= 0) {
            BigInteger m = l.add(r).divide(two);
            int cmp = m.pow(n).compareTo(p);
            if (cmp == 0) {
                return m;
            } else if (cmp < 0) {
                l = m.add(one);
            } else {
                r = m.subtract(one);
            }
        }
        if (l.pow(n).compareTo(p) == 0) {
            return l;
        }
        return r;
    }
    public static void main(String[] args) {
        int n;
        BigInteger p;
        while (true) {
            try {
                n = cin.nextInt();
                p = cin.nextBigInteger();
            } catch (NoSuchElementException e) {
                break;
            }
            System.out.println(calcRoot(p, n));
        }
    }
}

