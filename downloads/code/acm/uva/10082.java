import java.util.*;
import java.io.*;
import java.math.*;

class Main {
    public static Scanner cin = new Scanner (new BufferedInputStream(System.in));
    public static String strList = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    public static void process(String str) {
        for (int i = 0; i < str.length(); ++i) {
            char now = str.charAt(i);
            if (now == ' ') {
                System.out.printf(" ");
            } else {
                for (int j = 0; j < strList.length() - 1; ++j) {
                    if (strList.charAt(j + 1) == now) {
                        System.out.printf("%c", strList.charAt(j));
                        break;
                    }
                }
            }
        }
        System.out.printf("\n");
    }
    public static void main(String[] args) {
        while (cin.hasNextLine()) {
            process(cin.nextLine());
        }
    }
}

