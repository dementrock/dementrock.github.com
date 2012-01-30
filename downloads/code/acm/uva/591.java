import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    public static Scanner cin = new Scanner (new BufferedInputStream(System.in));
    public static void main(String[] args) {
        int [] h = new int[100];
        int n, cntCase = 0;
        while((n = cin.nextInt()) != 0) {
            int sum = 0, ave = 0;
            for (int i = 0; i < n; ++i) {
                h[i] = cin.nextInt();
                ave += h[i];
            }
            ave /= n;
            for (int i = 0; i < n; ++i) {
                sum += Math.abs(ave - h[i]);
            }
            System.out.printf("Set #%d\nThe minimum number of moves is %d.\n\n", ++cntCase, sum / 2);
        }
    }
}

