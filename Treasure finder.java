Description

Nikitha and Danny are close friends. They both are studying in the same school. Now they are on summer vacation. As they are bored, they ask their parents to take them to an exhibition. Nikitha and Danny play a game. In this game, there are three boxes with some number written on top. There is a treasure in one of the three boxes and it is present in the box with the second largest number on top. Also, to open the box, they need to decode the correct code of this box. The clue given to them to find the code is that it is the largest number that divides all three given numbers. So, now help Nikitha and Danny to decode the code.



Input Format

Input consists of three integers. The first input corresponds to the number of the first box. The second input corresponds to the number of the second box. The third input corresponds to the number of the third box.



Output Format

Refer to the sample output.



Sample Input 1

2

4

6



Sample Output 1

The treasure is in the box which has the number 4

The code to open the box is 2


Case 1
Case 2
Input (stdin)
2
4
6

Output (stdout)
The treasure is in the box which has the number 4
The code to open the box is 2
import java.util.Scanner;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int b = scanner.nextInt();
        int c = scanner.nextInt();
        int[] numbers = {a, b, c};
        Arrays.sort(numbers);
        int secondLargest = numbers[1];
        int gcd = gcd(gcd(a, b), c);
        System.out.println("The treasure is in the box which has the number " + secondLargest);
        System.out.println("The code to open the box is " + gcd);
    }
    private static int gcd(int x, int y) {
        while (y != 0) {
            int temp = y;
            y = x % y;
            x = temp;
        }
        return x;
    }
}
