import java.util.Scanner;

public class AWatermelon {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int w;

        w = input.nextInt();
        if (w >= 1 && w <= 100) {
            if (w % 2 == 0 && w != 2) {
                System.out.println("YES");
            } else {
                System.out.println("NO");
            }
        }
        input.close(); // Close the scanner to prevent resource leak
    }
}

