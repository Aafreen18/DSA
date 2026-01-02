package CoinsEasy;

/**
 https://leetcode.com/problems/arranging-coins/

 You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.

Given the integer n, return the number of complete rows of the staircase you will build.

 

Example 1:

Input: n = 5
Output: 2
Explanation: Because the 3rd row is incomplete, we return 2.

Example 2:

Input: n = 8
Output: 3
Explanation: Because the 4th row is incomplete, we return 3.

 */
public class Coins{
    public static void main(String[] args) {
        Mohammad mohammad = new Mohammad();
        Aafreen aafreen = new Aafreen();
    }

 }

 class Aafreen
 {
    Aafreen()
    {
      /**  class Solution {
    public int  arrangeCoins(int n) {
        long sum=0;
        long a=1;

        if(n==1)
            {
                return (int)a;
            }
        
        else
        {
            while(sum<=n)
            {
                sum=sum+a;
                a++;
            }
            return (int)(a-2);
        }
    } 
}*/
    }
 }

 class Mohammad
 {
    Mohammad()
    {
        //Code Here
/**
class Solution 
{
    public int arrangeCoins(int n) 
    {
        if(n==0) return 0;
        else if(n==1 || n==2) return 1;
    
        long x=n;
        long min=0;
        long max=n;
        long num =0;
        while(min<max)
        {
            num = min+(max-min)/2;
            if(sum(num)>x)
            {
                if(sum(num-1)<x)    return (int)(num-1);
                else    max = num;
            }
            else if(sum(num)==x)    return (int)(num);
            else
            {
                if(min==num)    min=num+1;
                else    min=num;
            }
            
        }
        return -1;
    }

    public static long sum(long num)
    {
        return num*(num+1)/2;
    }
} 
*/
    }
 }