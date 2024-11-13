Description

Richard Castle wants to buy a shirt. As he is very lazy, he decided to buy the shirt online. He chooses a shirt on Flipkart and is surprised to see the same shirt on Snapdeal, and Amazon as well. So he decided to buy the shirt from the website which offers the least price. The price of the shirt, the discount percentage, and the shipping charges of all three websites have been given as input. Help him in calculating the price of the shirt on each website and decide which website has the lowest price.If the price in all the three websites are same then first priority goes to Flipkart, then Snapdeal and finally Amazon.



Input Format

Input consists of 9 integers. The first three input corresponds to Flipkart details such as the price of the shirt, discount offered, and shipping charges. The next three input corresponds to Snapdeal details such as the price of the shirt, discount offered, and shipping charge. The last three input corresponds to Amazon details such as the price of the shirt, discount offered, and shipping charge.



Output Format

The Output consists of three integers that denote the prices on Flipkart, Snapdeal, and Amazon and should suggest the website that has the lowest price.



Sample Input

1000

50

50

900

50

70

800

10

200



Sample Output

In Flipkart: Rs.550

In Snapdeal: Rs.520

In Amazon: Rs.920

Choose Snapdeal


Case 1
Case 2
Input (stdin)
1000
50
50
900
50
70
800
10
200

Output (stdout)
In Flipkart: Rs.550
In Snapdeal: Rs.520
In Amazon: Rs.920
Choose Snapdeal
import java.util.Scanner;
class Main
{
  public static void main(String args[])
  {
    Scanner sc=new Scanner(System.in);
    int pr1=sc.nextInt();
    int dis1=sc.nextInt();
    int sc1=sc.nextInt();
    int pr2=sc.nextInt();
    int dis2=sc.nextInt();
    int sc2=sc.nextInt();
    int pr3=sc.nextInt();
    int dis3=sc.nextInt();
    int sc3=sc.nextInt();
    double ffp = pr1-(pr1 * dis1 / 100) + sc1;
        double sfp = pr2-(pr2 * dis2 / 100) + sc2;
        double afp = pr3-(pr3 * dis3 / 100) + sc3;
    String bestWebsite = "Flipkart"; // Default to Flipkart if prices are equal
        double minPrice = ffp;

        if (sfp< minPrice) {
            minPrice = sfp;
            bestWebsite = "Snapdeal";
        }

        if (afp < minPrice) {
            minPrice = afp;
            bestWebsite = "Amazon";
        }

        // Print the result
        
    System.out.println("In Flipkart: Rs."+(int)ffp);
     System.out.println("In Snapdeal: Rs."+(int)sfp);
    System.out.println("In Amazon: Rs."+(int)afp);
    System.out.println("Choose "+bestWebsite); 
  }
}
