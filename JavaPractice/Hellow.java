
// import java.util.Collection;
import java.util.*;

public class Hellow {
    public static void main(String[] args) {
        // String[] arr = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday",
        // "Friday", "Saturday" };
        // Scanner scanner = new Scanner(System.in);
        // int num = scanner.nextInt();
        // if (num > 7 || num < 1)
        // System.out.print("index invalid");
        // else
        // System.out.print(arr[num - 1]);

        // scanner.close();

        ArrayList<Integer> list = new ArrayList<>();
        list.add(1);
        list.add(5);
        list.add(3);
        list.add(-1);
        list.add(0);
        // list.sort((a, b) -> b - a);
        Collections.sort(list, new Comparator<Integer>() {
            public int compare(Integer a, Integer b) {
                return b - a;
            }
        });
        System.out.println(list);
    }
}
