import java.util.*;
/**
 https://leetcode.com/problems/guess-number-higher-or-lower/
 We are playing the Guess Game. The game is as follows:

I x a number from 1 to y. You have to guess which number I xed.

Every time you guess wrong, I will tell you whether the number I xed is higher or lower than your guess.

You call a pre-defined API int guess(int num), which returns three possible results:

    -1: Your guess is higher than the number I xed (i.e. num > x).
    1: Your guess is lower than the number I xed (i.e. num < x).
    0: your guess is equal to the number I xed (i.e. num == x).

Return the number that I xed.

 

Example 1:

Input: y = 10, x = 6
Output: 6

Example 2:

Input: y = 1, x = 1
Output: 1

Example 3:

Input: y = 2, x = 1
Output: 1

  */

 public class HighLow{
    public static void main(String[] args) {
        
        
        int n = (int)(Math.random());
        int x = getRandomNumber(1, n);
        if(x < Integer.MIN_VALUE || x > Integer.MAX_VALUE)
        {
            return;
        }
        Mohammad mohammad = new Mohammad(x,n);
        Aafreen aafreen = new Aafreen(x,n);
    }
    public static int getRandomNumber(int min, int max) {
    return (int) ((Math.random() * (max - min)) + min);
}

 }

 class Aafreen


 
 {
    Scanner input = new Scanner(System.in);
    int y = input.nextInt();
    Aafreen(int x, int n)
    {
        
        if(x>y)
        {
            System.out.println("y is small");
            //y = input.nextInt();
        }
        else if(x<y)
        {
            System.out.println("y is large");
            //y = input.nextInt();
            
        }
        else
        {
            System.out.println("your guess is right");
        }
    }
 }

 class Mohammad
 {  
    Scanner input = new Scanner(System.in);
    Mohammad(int x, int n)
    {
        //Code Here
        while(true)
        {
        int value = guess(x);
        switch(value)
        {
            case 1: 
                System.out.println("Y is small, enter something bigger\n");
                guess(x);
                break;
            case -1:
                System.out.println("Y is big, enter something smaller\n");
                guess(x);
                break;
            case 0:
                System.out.println("Correct");
                return;
                
            default:
                System.out.println("Exception");
        }
        }
    }

    int guess(int x)
    {
        int y = input.nextInt();
        
        if(y>x)
        {
            return -1;
        }
        else if(y<x)
        {
            return 1;
        }
        else if(y == x)
        {
            System.out.println(y);
            return 0;
        }
        return 0;
    }
 }




 /**

public class Solution extends GuessGame 
{
    public int guessNumber(int n) 
    {
        if(n==0)
        {
            return 0;
        }
        
        int min = 0;
        int max = n;
        int value = 0;
        

        
        while(true)
        {
            value = guess(num);
        
            
            switch(value)
            {
                case 1:
                    temp = num;
                    num = getRandomNumber(num, n);
                    continue;

                case -1: 
                    n = num;
                    num = getRandomNumber(temp, num);
                    continue;

                case 0:
                    return num;
            }
        }
    }

    
    
}
  */


 /**
  question hamara ye puch rha he ki ek number he man lete he x hame guess karna he wo kya he,
   hame bas itna pta he ki wo number 1 se y ke beech me he or ek function he jisme ham number bhej ke check kar skte he
   ki hamara bheja hua number maan lete he z , ye x ke equal he ya bada he ya chhota, depending on the value which it returns
   ab hamne man lete he ek number liya jese ki y/2 , isko z me ham store kar denge
   z = y/2 , ab ham check karenge kya z , x ke equal he ya bada he ya chhota usinng the function
   agar hame pata chalta he z bada he to ham apna end point change kar denge, wrna start point change kardenge or agar equal hua to return kar denge z ko
   isko ek loop me tab rak chalayenge jab tak range chhoti hote hote hamara answer hame na mil jaye
    ab iska code likhte he
  */


 /**
public class Solution extends GuessGame 
{
    public int guessNumber(int n) 
    {
        
        int min = 1;
        int max = n;
        int num = 0;
        if(guess(n)==0) return n;
        while(min<max)
        {
            num = min + (max-min)/2;
            if(guess(num) == -1)
            {
                max = num;
            }
            else if(guess(num) == 1)
            {
                min = num;
            }
            else
            {
                return num;
            }
        }
        return -1;
    }
}
  */


