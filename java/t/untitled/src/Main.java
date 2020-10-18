import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        System.out.println("Enter an integer:");
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        if (n % 5 == 0 && n % 6 == 0) {
            System.out.println(n + " is divisible by both 5 and 6");
        } else if (n % 6 == 0 || n % 5 == 0) {
            System.out.println(n + " is divisible by 5 or 6, but not both");
        } else {
            System.out.println(n + " is not divisible by either 5 or 6");
        }
    }
}

