import java.util.InputMismatchException;
import java.util.Scanner;
/* 	A number is said to be a Spy number if the sum of all the digits is equal to the product of all digits.
 	e.g. Input : 123
 			sum=(1+2+3)=6==product=(1*2*3)=6 It's a spy number. */

public class SpyNumber {
    public static void main(String... arg) {
        Scanner scan = new Scanner(System.in);
        int sum = 0, product = 1;

        try {
            System.out.print("Enter your number: ");
            int input = scan.nextInt();
            int digit;
            while (input > 0) {
                digit = input % 10;
                sum = sum + digit;
                product = product * digit;
                input = input / 10;
            }
            if (sum == product) {
                ps.println("It's a SpyNumber.");
            } else {
                ps.println("It's not a SpyNumber.");
            }
        } catch (InputMismatchException ime) {
            System.out.println("You have entered Invalid Input.");
        }
    }
}