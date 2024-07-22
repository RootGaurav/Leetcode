
class Solution {
    public String[] sortPeople(String[] names, int[] heights) {
        int max[]=new int [heights.length];
        int i,j;
        for(i=0;i<heights.length;i++)
        {
            max[i]=heights[i];
        }
        for(i=0;i<max.length;i++)
        {
            for(j=0;j<max.length;j++)
            {
                if(max[i]>max[j])
                {
                    int temp=max[i];
                    max[i]=max[j];
                    max[j]=temp;
                }
            }
        }
        String name[]=new String[names.length];
        for(i=0;i<names.length;i++)
        {
            int index=indexo(heights,max[i]);
            name[i]=names[index];
        }
        return name;
        
    }

    public static int indexo(int []heights,int max)
    {
        int index=0;
        for(int i=0;i<heights.length;i++)
        {
            if(heights[i]==max)
            index=i;
        }
        return index;
    }
}