import java.util.Scanner;
public class Brain{
  public static void main(String[] args){
    System.out.println("This is a small part of a big brain")
		Scanner kboard = new Scanner(System.in);
		
		//variables for bmi
		double m, ft, lbs, kg, bmi;
		
		//data
		System.out.print("your height in feet: ");
		ft = kboard.nextDouble();
		
		System.out.println("Your weight in Pounds");
		lbs = kboard.nextDouble();
		
		//convert into metric units
		kg = lbs * 0.45359237;
		m = ft * 30.48;
		
		//calculate bmi
		bmi = kg / (m*m);
		System.out.print("Your BMI is " + bmi);
}
}
