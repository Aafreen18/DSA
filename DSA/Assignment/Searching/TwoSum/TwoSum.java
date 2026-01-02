 package TwoSum;
 /**
  https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
  
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 < numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.

 

Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].

 */

 public class TwoSum{
    public static void main(String[] args) {
        Mohammad mohammad = new Mohammad();
        Aafreen aafreen = new Aafreen();
    }

 }

 class Aafreen
 {
    Aafreen()
    {
     /**    class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int arr[] = new int[2];
        int a=0;
        int b=0;
        for(int i=0;i<=numbers.length-1;i++)
        {
          for(int j=0;j<=arr.length-1;j++)
          {
                if(numbers[i]!=numbers[j])
                {
                    a=i;
                    b=j;
                    int k;
                    int l;
                    for(k=a;k<=numbers.length-1;k++)
                    {
                        for(l=b;l<=numbers.length-1;l++)
                            {
                                if(target==numbers[k]+numbers[l] && k!=l)
                                {
                                    arr[0] = k+1;
                                    arr[1] = l+1;
                                    return arr;
                                }

                            }    
                    }
                    
                }
                else 
                {
                    if(target==numbers[i]+numbers[j] && i!=j)
                    {
                        arr[0]=i+1;
                        arr[1]=j+1;
                        return arr; 
                    }
                }
                
            }

        }
        arr[0]=-1;
        arr[1]=-1;
        return arr;
       
    }
}
/* */
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
    public int[] twoSum(int[] numbers, int target) 
    {
        for(int i=0; i<numbers.length; i++)
        {
            //i ki value jab 0 hogi to ye if ke andar wala code run karega
            if(i==0)
            {
                for(int j=0; j<numbers.length; j++)
                {
                    if(numbers[i] + numbers[j] == target && i != j)
                    {
                        int[] arr = {i+1, j+1};
                        return arr;
                    }
                }
            }


            //yaad rhe ye kbhi bhi i=0 pe nhi hoga, isliye i-1 kbhi bhi negative nhi aayega

            //wrna wo check karega ki kya i'th element or usse pichhla wala element equal he ya nhi
            else
            {
                if(numbers[i] != numbers[i-1])
                {

                    for(int j=0; j<numbers.length; j++)
                    {
                        if(numbers[i] + numbers[j] == target && i != j)
                        {
                            int[] arr = {i+1, j+1};
                            return arr;
                        }
                    }
                }
            }   
        }
        int[] arr = {-1, -1};
        return arr;
        
    }
}
         */


        /**
         example se smjhte he
         jese maanlo ek array he 
         numbers = [2,2,3,4]
         target maanlo 7 he
         hamne ek loop chalaya
         i=0 se leke i=3 tak, theek he?
         kyunki numbers.length = 4 he, or hme 0 se chala rhe he to 0,1,2,3 theek?
         
    i to row btata h aur j column ko
    wo multidimensional array me hota he, hamari array single dimension he
    thik h
         ye hamara pehla for loop he line 82 pe
         sbse pehle i ki value aayi 0 matlab ab ham if ke andar jayenge
         if me hmne ek or loop chalaya j=0 se leke j=3 tak
         ab hmne dekha kya number[i]+number[j] target ke equal he ya nhi, ok?
         
         mtlb abhi i ki value 0 he or j ki bhi 0, to numbers[0] = 2 he , numbers[0] + numbers[0] hoga 2+2 matlb 4
         4 target ke equal nhi he to skip ho jayega , agar by chance 4 ki jagah 7 bhi answer aajata galti se, tbhi bhi skip hi hota kyunki hamari ek or condition he
         i or j dono equal nhi hone chahiye, but abhi dono equal he yani 0 , isliye skip ho gya
         ab i ki value abhi nhi bdlegi magar j ki value bdlegi , j++
         to basically loop ye check karega
         starting se

         2+2 =4 yaha i=0, j=0 (skipped due to i=j)
         2+2 = 4 yaha i=0 j=1
         2+3 = 5 yaha i =0 j=2
         2+4 = 6  yaha i =0 j=3

         in sab me se koi bhi target value ke equal nhi aaya mtlb 7 ke equal koi nhi he 
         har baar false mil rha he condition ko, but hamara j wala for loop samapt hogya kyunki j=3 pohuch gya
         ab i ki value badhegi
         i 0 tha ab i =1 ho jayega dubara se 83rd line se code chalu hoga flow karna kyunki loop he
         ab dubara ek if else check karega kya i 0 ke equal he ? is baar condition false hogi or hamara code seedha else me chale jayega
         code seedha 103rd line se flow krna chaalu hoga

         ab ham check kar rhe he ki kya i'th element and i-1'th element equal he
         ham jaante ki hamari array assecnding order me he sorted he already kyunki question me given he
         i=0 pe numbers[i] ki value 2 thi, to ab ya to 2 se jyada hogi ya to 2 ke equal
         agar 2 ke equal hui to fir se same values hi return hongi ye ham jante he
         hamne jo example liya he usme same hi he [2,2,3,4] isme numbers[1]==numbers[0]
         ke equal he matlab 2=2 he , true, 
         kyunki dekhlete he ek baar
         dubara same hi cheez follow ho rhi hogi jo hmne phle kari thi
         bas i ki value hi badlegi



         2+2 =4 yaha i=1, j=0 
         2+2 = 4 yaha i=1 j=1 (skipped due to i=j)
         2+3 = 5 yaha i =1 j=2
         2+4 = 6  yaha i =1 j=3

         (pura loop hi skipped due to numbers[i]=numbers[i-1])

         ab dekho i ki value badal gyi lekin fir bhi output same rha kyunki numbers[i] ki value to same hi he
         hena??
         agar ham is case me loop chalaye hi nhi to hamara time bachega
         time complexity ghategi
         to mtlb loop tbhi chalega jab numbers[i] ki value change hogi , sirf i ki nhi
         to hamare case me pura loop nhi chalega

         ab agli i ki value aayegi 2, jispe numbers[i] = 3 ke equal hoga, kyunki numbers[2] = 3 // [(i=0)2,(i=1)2,(i=2)3,(i=3)4]
         fir se 82 line me jayenge
         condition check answer false
         fir 103 line else ke andar condition false
         j wala loop chalu

         3+2 =5 yaha i=2, j=0 
         3+2 = 5 yaha i=2 j=1 
         3+3 = 6 yaha i =2 j=2 (skipped due to i=j)

         magar jab j=3 hoga to

         3+4 = 7  yaha i =2 j=3
         ye value target ke equal aagyi mtlb hame ans mil gya he
         to hamne ek arr banayi
         jisme hmne store kiya 2 elements {i+1, j+1}
         mtlb{2+1,3+1}==> {3,4}'ab is array ko return kar dia as an answer'
         done
         hopefully aagya smjh me




         */
    }
 }

 