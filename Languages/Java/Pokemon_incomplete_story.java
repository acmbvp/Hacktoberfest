import java.util.Scanner;

public class Pokemon_incomplete_story {
	public static void main(String[] args) {
		Scanner scnr = new Scanner(System.in);

	
		String pokemonTeam[] = new String[6];
//		pokemonTeam[0] = Starter Mon
//		pokemonTeam[1] = Viridan Forest Mon
//		pokemonTeam[2] = 
//		pokemonTeam[3] = 
//		pokemonTeam[4] = 
//		pokemonTeam[5] = 

		System.out.println("Hello there! Welcome to the world of Pokemon! \n" // beginning speech
				+ "My name is Oak. People call me the Pokemon Professor. \n"
				+ "This world is inhabited by creatures called Pokemon! \n" + "For some "
				+ "people, Pokemon are pets. Others use them for fights. \n"
				+ "Myself... I study Pokemon as a profession.");
		System.out.println();
		System.out.println("First tell me, what is your name?");

		String yourName = scnr.nextLine(); // ask name
		System.out.println("Right! So your name is " + yourName + "?");

		boolean nameQ1 = false; // activates loop, name retype if true
		while (nameQ1 == false) {
			String NameYN1 = scnr.nextLine();
			if (NameYN1.contains("y")) {
				nameQ1 = true;
			} else {
				System.out.println("Oh, then what was your name?");
				yourName = scnr.nextLine();
				System.out.println("Right! So your name is " + yourName + "?"); // finalized your name
			}
		}

		System.out.println("Okay " + yourName + ", what gender do you identify as?"); // gender question
		String gender = scnr.nextLine();

		System.out.println("Wonderful! Now, this is my grandson. \n" + "He's been your rival since you were a baby. \n"
				+ "Erm, what was his name again?"); // ask for rival name

		String rivalName = scnr.nextLine();

		System.out.println("Right! So his name is " + rivalName + "?");

		boolean nameQ2 = false; // activates loop, rival retype if true
		while (nameQ2 == false) {
			String NameYN2 = scnr.nextLine();
			if (NameYN2.equals("yes")) {
				nameQ2 = true;
			} else {
				System.out.println("Oh, then what was his name?");
				rivalName = scnr.nextLine();
				System.out.println("Right! So his name is " + rivalName + "?");
			}
		}
		System.out.println("That's right! I remember now! His name is " + rivalName);

		try {
			Thread.sleep(2000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} // 2000ms = 2S

		System.out.println(yourName + "! Your very own Pokemon legend is about to unfold!\n"
				+ "A world of dreams and adventures with Pokemon awaits!\n" + "Let's go!"); // finalized rival name

// end intro script

		try {
			Thread.sleep(4000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} // 4000ms = 4s

		System.out.println();
		System.out.println("Welcome to Pallet town, the place where \"Shades of Your Journey Await\"");
		System.out.println();

		try {
			Thread.sleep(4000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} // 4000ms = 4s

		System.out.println("It's time for you to choose your partner Pokemon!"); // list starters
		System.out.println("Would you like the grass type, Bulbasaur\n" + "or maybe the water type, Squirtle,\n"
				+ "or possibly the fire type, Charamander?");

		try {
			Thread.sleep(3000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} // 3000ms = 3s
		System.out.println();
		System.out.println("Now, which type would you perfer?");
		
		pokemonTeam[0] = scnr.nextLine(); // choose starter based on type
		switch (pokemonTeam[0]) {
		case "grass":
			pokemonTeam[0] = "Bulbasaur";
			break;
		case "water":
			pokemonTeam[0] = "Squirtle";
			break;
		case "fire":
			pokemonTeam[0] = "Charamander";
			break;
		}
		
		System.out.println();
		System.out.println("You have chosen " + pokemonTeam[0] + "!"); // starter is set to pokemonTeam[0]
		System.out.println("You can now travel the Kanto region with your Pokemon, and challenge the Pokemon Leauge!");
		System.out.println();

		try {
			Thread.sleep(3000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} // 3000ms = 3s

//Enter Viridian City

		System.out.println("You have arrived in Viridian City!");
		System.out.println("Do you want to visit the gym or continue onwards?");

		String viridianChoice = scnr.nextLine(); // Navigate Viridian City
		if (viridianChoice.contains("gym")) {
			System.out.println("The gym seems to be empty, you decide to head to Viridian Forest");
		} else {
			System.out.println("You continued past town, heading north");
		}

		try {
			Thread.sleep(4000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} // 4000ms = 4s
		System.out.println();

// forest 
		boolean catchme = true;
		while(catchme == true){
			virdianforest(pokemonTeam, scnr);
			System.out.println("With you new capture in tow, would you like leave the forest or stay searching for Pokemon?");
			String forestcatch = scnr.nextLine();
			if(forestcatch.contains("leave")){
				catchme = false;
			}
			if(pokemonTeam[6] == "Pidgey" || pokemonTeam[6] == "Caterpie"|| pokemonTeam[6] == "Weedle"|| pokemonTeam[6] == "Pikachu"){
				catchme = false;
			}
		}
		

		System.out.println("With you new capture in tow, you leave the forest and enter Pewter City.");
		System.out.println();
		try {
			Thread.sleep(5000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} // 5000ms = 5s

		System.out.println("Welcome to Pewter City, a place \"Between Rugged Mountains\"");
		System.out.println();

//Enter Pewter City

		try {
			Thread.sleep(2000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} // 2000ms = 2s

		System.out.println("The path diverges towards the Pokemon Gym and the Museum.\n" + "Which path will you take?");

		String pewterChoice = scnr.nextLine();
		if (pewterChoice.contains("gym")) {
			System.out.println("You took the left path and entered the Pewter City Gym");
		} else if (pewterChoice.contains("museum")) {
			System.out.println("You enter the Pewter City Meuseum, only to realize that you have no money.\n"
					+ "You sadly exit the building and head towards the Gym.");
		} else {
			System.out.println("You look around confused, and an elderly man helps you find your way to the city Gym.");
		}

		try {
			Thread.sleep(6000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} // 6000ms = 6s

		System.out.println("Standing in your first Gym, you prepare yourself and walk forward to back of the gym.");
		System.out.println("Brock, the gym leader of Pewter City, stands waiting.");
		try {
			Thread.sleep(6000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} // 6000ms = 6s

		System.out.println();
		System.out.println("Brock:\"I am Brock, the Rock-Solid Pokémon Trainer! Come at me with all you have!\"");
		try {
			Thread.sleep(5000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} // 5000ms = 5s

		System.out.println();
		System.out.println("*You are challenged by Gym Leader Brock*");
		try {
			Thread.sleep(4000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} // 4000ms = 4s

		System.out.println("*Brock sends out Geodude*");
		try {
			Thread.sleep(4000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} // 4000ms = 4s

		System.out.println("To defeat the Rock-type Pokemon, Geodude, which type of Pokemon should you use?");

		String brockType = scnr.nextLine();
		boolean brockGeo = false;
		while (brockGeo == false) {
			if (brockType.equals("water") || brockType.equals("grass") || brockType.equals("fighting")
					|| brockType.equals("ground")) { // Battling Brock
				brockGeo = true;
			} else {
				System.out.println("*It's not very effective!*");
				System.out.println("Try another type");
				brockType = scnr.nextLine();
			}
		}

		System.out.println("*Its Super-Effective!*");
		System.out.println("*Geodude fainted*");
		try {
			Thread.sleep(4000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} // 4000ms = 4s
		
		brockGeo = false;
		System.out.println("*Brock sends out Onix*");
		try {
			Thread.sleep(4000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} // 4000ms = 4s

		System.out.println("To defeat the Rock-type Pokemon, Onix, which type of Pokemon should you use?");

		brockType = scnr.nextLine();
		brockGeo = false;
		while (brockGeo == false) {
			if (brockType.equals("water") || brockType.equals("grass") || brockType.equals("fighting")
					|| brockType.equals("ground")) { // Battling Brock
				brockGeo = true;
			} else {
				System.out.println("*It's not very effective!*");
				System.out.println("Try another type");
				brockType = scnr.nextLine();
			}
		}

		System.out.println("*Its Super-Effective!*");

		try {
			Thread.sleep(1000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} // 1000ms = 1s

		System.out.println("Congratulations! You have defeated Brock, and earned the Boulder Badge!");
		try {
			Thread.sleep(5000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} // 5000ms = 5s
		
		int gainedEXP = 0;
		for (int i = 0; i < pokemonTeam.length; ++i) {
			gainedEXP = (int) (Math.random() * 100);
			System.out.println(pokemonTeam[i] + " gained " + gainedEXP + " EXP!");
		}
		System.out.println();
		System.out.println("To be continued...");
		System.out.println();
	}


		public static void virdianforest(String[] pokemonTeam, Scanner scnr){
		System.out.println("Walking into the deep forest, you feel as if there is something watching you.");
		
		try {
			Thread.sleep(2000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} // 2000ms = 2s

		System.out.print(".");
		try {
			Thread.sleep(2000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} // 4000ms = 4s
		System.out.print(".");
		try {
			Thread.sleep(2000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} // 4000ms = 4s
		System.out.println(".");
		try {
			Thread.sleep(2000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} // 4000ms = 4s

		boolean forest = false;
		while (forest == false) {
			int forestRand = (int) (Math.random() * 3);   //2nd pokemon spwans based on random gene
			switch (forestRand) {
			case 0:
				System.out.println("A wild Pidgey appeared!");
				pokemonTeam[1] = "Pidgey";
				break;
			case 1:
				System.out.println("A wild Pikachu appeared!");
				pokemonTeam[1] = "Pikachu";
				break;
			case 2:
				System.out.println("A wild Caterpie appeared!");
				pokemonTeam[1] = "Caterpie";
				break;
			default: {
				System.out.println("A wild Weedle appeared! It has a unqiue color to it.");
				pokemonTeam[1] = "Weedle";
			}
			}

			System.out.println("You have one Pokeball, do you want to catch this Pokemon?");
			String forestChoice = scnr.nextLine();
			if (forestChoice.contains("y")) {
				forest = true;
			}
		}

		System.out.println("You threw the Pokeball!");
		try {
			Thread.sleep(2000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} // 2000ms = 2s

		System.out.println("...");
		try {
			Thread.sleep(2000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} // 4000ms = 4s

		System.out.println("You captured a " + pokemonTeam[1] + "!!"); // Captured pokemon 2
		System.out.println();
		try {
			Thread.sleep(4000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		} // 4000ms = 4s
	}




}