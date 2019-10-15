import java.util.*;

public class Test_2{
	public static void main(String args[])
	{
		
		String str=new Scanner(System.in).nextLine();
        String[] srr=str.split(" ");
        ArrayList<Integer> list=new ArrayList<Integer>();
        for (int i = 0; i < srr.length; i++) {
            list.add(Integer.valueOf(srr[i]));
        }
		
        System.out.println(FindMax(list));
		
		
		
		
		
	}
		public  static Integer FindMax(ArrayList list)
{
	
	int current = 0;
	int max = 0;
	for(ListIterator<Integer> it=list.listIterator();it.hasNext();)
    {    
		current+=it.next();
		if(current <0)
			current=0;
		if(current>max)
			max = current;
	}
	if(max==0)
	{
		max = -0xFFFFFF;
		for(ListIterator<Integer> it=list.listIterator();it.hasNext();)
		{
			if(max<it.next())
				max = it.next();
			
			
		}
		
	}
	return max;

}



}
