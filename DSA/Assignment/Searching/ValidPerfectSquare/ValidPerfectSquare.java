package ValidPerfectSquare;
/**
 https://leetcode.com/problems/valid-perfect-square/


 Given a positive integer num, return true if num is a perfect square or false otherwise.

A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.

You must not use any built-in library function, such as sqrt.

 

Example 1:

Input: num = 16
Output: true
Explanation: We return true because 4 * 4 = 16 and 4 is an integer.

Example 2:

Input: num = 14
Output: false
Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.

 

Constraints:

    1 <= num <= 231 - 1


    
 */
public class ValidPerfectSquare{
    public static void main(String[] args) {
        Mohammad mohammad = new Mohammad();
        Aafreen aafreen = new Aafreen();
    }

 }

 class Aafreen
 {
    Aafreen()
    {
        /**     class Solution {
    public boolean isPerfectSquare(int num) {
        if(num==1)
            {
                return true;
            }

        long s=0;
        long e=num;
        while(s<e)
        {
            long m=s+(e-s)/2;

            if(num<m*m)
            {
                e=m;
            }
            else if(num>m*m)
            {
                if(s!=m)
                {
                    s=m;
                }
                else
                {
                    s=m+1;
                }
            }
            else
            {
                return true;
            }
        
        }
        return false;
    } */
}
    }
 
 class Mohammad
 {
    Mohammad()
    {
        //Code Here
        /**
        
    
    

    public boolean isPerfectSquare(int num) 
    {
        if(num==1) return true;
        
        long n=num;
        long i=0;
        long min=0;
        long max=num;
        while(min<max)
        {
            i = min + (max-min)/2;
            if( i*i == n) return trues;
            else if(i*i > n) max=i;
            else
            {
                if(min==i) min=i+1;
                else min=i;
            }
        }
        return false;
    }
        */
    }
 }