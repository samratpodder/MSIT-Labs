import java.io.*;
public class printingreverse {
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        try {
            String s[] = br.readLine().split(" ");
            for (int i = s.length-1; i >= 0; i--) {
                System.out.print(s[i]+" ");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
