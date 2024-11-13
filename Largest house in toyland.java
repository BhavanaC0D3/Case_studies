Description

In the city of Toyland, there are N houses. Noddy is looking for a piece of land in the city to build his house. All the houses in the city lie in a straight line and all of them are given a house number and position of the house from the entry point of the city. Noddy wants to find the house numbers between which he can build the largest house. Write an algorithm to help Noddy to find the house numbers between which he can build his house.

Hint: No two houses will have the same position in case of multiple such answers, print the one with the least distance from the reference point.



Input Format

The first line of the input consists of an integer num, representing the number of houses (N). The next N lines consist of two space-separated integers – house Num and pos, representing the house number and the position of the houses.



Constraints

2 < num < 10^6
1 < house Num < num
0 < pos < 10^6


Output Format

Print two space-separated integers representing the house numbers in ascending order between which the largest plot is available.



Sample Input

5

3 7

1 9

2 0

5 15

4 30



Sample Output

4 5


Case 1
Case 2
Input (stdin)
5
3 7
1 9
2 0
5 15
4 30

Output (stdout)
4 5
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read the number of houses
        int num = scanner.nextInt();
        
        // Create a list to store the house number and position pairs
        List<House> houses = new ArrayList<>();
        
        // Read each house's number and position
        for (int i = 0; i < num; i++) {
            int houseNum = scanner.nextInt();
            int pos = scanner.nextInt();
            houses.add(new House(houseNum, pos));
        }
        
        // Sort the houses based on their position
        houses.sort(Comparator.comparingInt(h -> h.position));
        
        // Initialize variables to find the maximum distance
        int maxDistance = -1;
        int house1 = -1;
        int house2 = -1;
        
        // Traverse sorted houses to find the largest distance
        for (int i = 1; i < houses.size(); i++) {
            int distance = houses.get(i).position - houses.get(i - 1).position;
            if (distance > maxDistance) {
                maxDistance = distance;
                house1 = houses.get(i - 1).houseNum;
                house2 = houses.get(i).houseNum;
            }
        }
        
        // Print the result in ascending order
        if (house1 < house2) {
            System.out.println(house1 + " " + house2);
        } else {
            System.out.println(house2 + " " + house1);
        }
        
        scanner.close();
    }
    
    // Inner class to hold house number and position
    static class House {
        int houseNum;
        int position;
        
        House(int houseNum, int position) {
            this.houseNum = houseNum;
            this.position = position;
        }
    }
}
