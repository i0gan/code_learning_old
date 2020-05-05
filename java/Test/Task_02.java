import java.util.Scanner;
public class Task_02
{
	public static void main(String[] args)
	{
		
		int in_num=0;
		int digit=1;
		int i=0;
		Scanner In_num=new Scanner(System.in);
		in_num=In_num.nextInt();
		for(i=0;in_num>=1;i++)
		{
			in_num=in_num/10;
		}
		System.out.println(i);
	}
}
