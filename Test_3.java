import java.util.Scanner;
public class Test_3
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int []arr = new int [2000];
		arr[0]=1;
		arr[1]=1;
		double target=Math.sqrt(2000);
		for(int i=2;i<target;i++)
		{
			if(arr[i]==0)
			{
				for(int j = i*i;j<2000;j+=i)
				arr[j]=1;
			
			}
		
		}
		int flag=0;
		for(int i=2;i<=2000;i++)
		{
			if(arr[i]==0)
			{
				System.out.print(i+" ");
			flag++;
			}
			
		
			if(flag==5)
			{
				
				flag=0;
				System.out.print("\n");
			}
			
			
		
		}
	
	}


}