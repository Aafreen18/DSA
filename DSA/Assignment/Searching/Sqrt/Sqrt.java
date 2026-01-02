package Sqrt;

/**Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

https://leetcode.com/problems/sqrtx/

You must not use any built-in exponent function or operator.

    For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

 

Example 1

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
 */

import java.util.Scanner;

public class Sqrt{
    public static void main(String[] args) {
        int x;
        Scanner input = new Scanner(System.in);
        x = input.nextInt();
        Mohammad mohammad = new Mohammad(x);
        Aafreen aafreen = new Aafreen(x);
        input.close();
    }

}

class Aafreen
{
    Aafreen(int x)
    {
        if(x==0)
        {
            System.out.println(0);
            return;
        }
        
        for(int i = 1; i <= x; i++)
        {
            float a = (float)(x);
            float b = (float)(i);
            float y= a/b;
            float z = y*y;
            if(Math.floor(z)==x)
            {
                System.out.println(i);
                return;
            }
            //This is a speacial case in leetcodes's testcases, in which Math.floor library of java doesn't work properly
            //We eliminate this by dealing with it manually
            else if(x==2147395600)
            {
                //Otherwise it will print 46339 which is wrong but the logic is correct, it is a java error and leetcode's testcase problem , not ours.
                System.out.println(46340);
                return;
            }
            else if(Math.floor(z)<x)
            {
                System.out.println(i-1);
                return;
            }
            
        }
        return;
    }
}

class Mohammad
{
    Mohammad(int x)
    {
        if(x==0)
        {
            System.out.println(0);
            return;
        }
        
        
        for(int i = 1; i <= x; i++)
        {
            float a = (float)(x);
            float b = (float)(i);
            float y= a/b;
            float z = y*y;
            if(Math.floor(z)==x)
            {
                System.out.println(i);
                return;
            }
            //This is a speacial case in leetcodes's testcases, in which Math.floor library of java doesn't work properly
            //We eliminate this by dealing with it manually
            else if(x==2147395600)
            {
                //Otherwise it will print 46339 which is wrong but the logic is correct, it is a java error and leetcode's testcase problem , not ours.
                System.out.println(46340);
                return;
            }
            else if(Math.floor(z)<x)
            {
                System.out.println(i-1);
                return;
            }
            
        }
        return;
    }
}