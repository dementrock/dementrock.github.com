import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    public static Scanner cin = new Scanner (new BufferedInputStream(System.in));
    public static void main(String[] args) {
        String str;
        while (!(str = cin.nextLine()).equals("0")) {
            int factor = 1, sum = 0;
            for (int i = str.length() - 1; i >= 0; --i) {
                factor *= 2;
                if (str.charAt(i) > '0') {
                    sum += (int) (str.charAt(i) - '0') * (factor - 1);
                }
            }
            System.out.println(sum);
        }
    }
}

