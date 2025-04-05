import java.util.Scanner;

public class Hellow {
    public static void main(String[] args) {
        String[] arr = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
        Scanner scanner = new Scanner(System.in);
        int num = scanner.nextInt();
        if (num > 7 || num < 1)
            System.out.print("index invalid");
        else
            System.out.print(arr[num - 1]);

        scanner.close();
    }
}