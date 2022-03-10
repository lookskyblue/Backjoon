import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	int arr[];
	int type;
	int val;
	int sum=0;
	int i;
	
	type = sc.nextInt();
	val = sc.nextInt();
	arr = new int[type];
	
	for(i=0; i<type; i++)
		arr[i] = sc.nextInt();
	
	for (i = arr.length - 1; val!=0; i--) {
		sum=sum+val/arr[i];
		val=val%arr[i];
	}
	System.out.println(sum);
	}
}