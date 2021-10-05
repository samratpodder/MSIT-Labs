import java.io.*;
public class printingevenpositions {
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            System.out.println("Enter Size");
            int n = Integer.parseInt(br.readLine());
            int[] arr = new int[n];
            System.out.println("Entering elements");
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(br.readLine());
            }
            System.out.println("Elements at even pos:");
            for (int i = 0; i < n; i++) {
                if (arr[i] % 2 == 0) {
                    System.out.println(arr[i]);
                }
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
