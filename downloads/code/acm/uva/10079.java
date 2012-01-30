import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    public static Scanner cin = new Scanner (new BufferedInputStream(System.in));
    public static void main(String[] args) {
        long n;
        while((n = cin.nextLong()) >= 0) {
            System.out.println(n * (n + 1) / 2 + 1);
        }
    }
}

