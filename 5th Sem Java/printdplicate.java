import java.io.*;
import java.util.HashMap;
import java.util.Set;
public class printdplicate {
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            int n = Integer.parseInt(br.readLine());
            int[] arr = new int[n];
            for (int i = 0; i < n; i++) {
                arr[i] = Integer.parseInt(br.readLine());
            }
            System.out.println("Duplicate elements are:");
            HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
            for (int i = 0; i < n; i++) {
                if (map.containsKey(arr[i])) {
                    map.put(arr[i], map.get(arr[i]) + 1);
                } else {
                    map.put(arr[i], 1);
                }
            }
            Set<Integer> set = map.keySet();
            for (int i : set) {
                if (map.get(i) > 1) {
                    System.out.print(i + " \n");
                }
            }
        } 
        catch (Exception e) 
        {
            System.out.println(e);
        }
    }
}