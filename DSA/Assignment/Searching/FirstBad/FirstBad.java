package FirstBad;
/**
 https://leetcode.com/problems/first-bad-version/
 
 You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

 

Example 1:

Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.

Example 2:

Input: n = 1, bad = 1
Output: 1

 

Constraints:

    1 <= bad <= n <= 231 - 1


 */

public class FirstBad {
    public static void main(String[] args) {
        Mohammad mohammad = new Mohammad();
        Aafreen aafreen = new Aafreen();
    }

 }

 class Aafreen
 {
    Aafreen()
    {
        //Code Here
    }
 }

 class Mohammad
 {
    Mohammad()
    {
        //Code Here
    /**
    import java.util.*;
    public class Solution extends VersionControl 
    {
    public int firstBadVersion(int n) 
    {
        int min = 1;
        int max = n;
        int x = getRandomNumber(min,n);
        
        boolean check;

        while(true)
        {
            check = isBadVersion(x);
            if(check)
            {
                //Found Bad Version , checking is it first bad version
                max = x;
                if(!isBadVersion(x-1))
                {
                    return x;
                }
                else
                {
                    x = getRandomNumber(min, max);
                }  
                
            }
            else
            {
                //not found any bad version yet
                min = x;
                x = getRandomNumber(min , max);
            }
        }

    }

    public static int getRandomNumber(int min, int max) 
    {
        Random random = new Random();
        return random.nextInt((max - min) + 1) + min;
    }
    }
    */

    }
    
 }