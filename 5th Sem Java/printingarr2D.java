import java.io.*;
public class printingarr2D {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter size of array");
        int n = Integer.parseInt(br.readLine());
        int arr[][] = new int[n][n];
        System.out.println("Enter elements of array");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[i][j] = Integer.parseInt(br.readLine());
            }
        }
        System.out.println("The array is");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
    }
}
