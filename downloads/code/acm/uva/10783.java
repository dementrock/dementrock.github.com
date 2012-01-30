import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    public static Scanner cin = new Scanner (new BufferedInputStream(System.in));
    public static void main(String[] args) {
        int t = cin.nextInt(), cntCase = 0;
        while (t-- > 0) {
            int a = cin.nextInt(), b = cin.nextInt();
            int sum = 0;
            for (int i = a; i <= b; ++i) {
                if (i % 2 == 1) {
                    sum += i;
                }
            }
            System.out.printf("Case %d: %d\n", ++cntCase, sum);
        }
    }
}

