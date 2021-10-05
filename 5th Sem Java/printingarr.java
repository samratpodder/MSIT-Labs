import java.io.*;
class printingarr{
    public static void main(String[] args)throws IOException {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter Size of Array:");
        int n=Integer.parseInt(br.readLine());
        System.out.println();
        int[] arr = new int[n];
        String[] str = br.readLine().split(" ");
        for(int i=0;i<n;i++){
            arr[i]=Integer.parseInt(str[i]);
        }
        System.out.println("Elements in the array are : ");
        for(int i=0;i<n;i++){
            System.out.print(arr[i]+" ");
        }
    }
}