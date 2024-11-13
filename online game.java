Description

You are playing an online game. In the game, a list of N numbers is given. The player has to arrange the numbers so that all the odd numbers on the list come after the even numbers. Write an algorithm to arrange the given list such that all the odd numbers of the list come after the even numbers.



Input Format

The first line of the input consists of an integer num, representing the size of the list(N). The second line of the input consists of N space-separated integers representing the values of the list.



Output Format

Print N space-separated integers such that all the odd numbers of the list comes after the even numbers



Sample Input 

8

10 98 3 33 12 22 21 11



Sample Output 

Array after Segregation

10 98 22 12 33 3 21 11


Case 1
Case 2
Input (stdin)
8
10 98 3 33 12 22 21 11

Output (stdout)
Array after Segregation
10 98 22 12 33 3 21 11
import java.util.Scanner;
class Main
{
  public static void main(String args[])
  {
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    int[] a=new int[n];
    for(int i=0;i<n;i++)
    {
      a[i]=sc.nextInt();
    }
    int l=0;
    int r=n-1;
    while(l<r)
    {
      while(a[l]%2==0 && l<r)
      l++;
    while(a[r]%2!=0 && l<r)
      r--;
    int t=a[l];
    a[l]=a[r];
    a[r]=t;
    l++;r--;
  }
    System.out.println("Array after Segregation");
    for(int i=0;i<n;i++)
    System.out.print(a[i]+" ");
  }
}
