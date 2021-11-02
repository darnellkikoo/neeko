import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		System.out.println(" /$$$$$$$   /$$$$$$                /$$$$$ /$$$$$$$   /$$$$$$$$       /$$       /$$");
		System.out.println("| $$__  $$  |__  $$               |_  $$| $$__  $$  |__  $$__/	    | $$      | $$");
		System.out.println("| $$  \\ $$     | $$                 | $$| $$  \\ $$    | $$  /$$$$$$ | $$$$$$$ | $$  /$$$$$$");
		System.out.println("| $$$$$$$      | $$   /$$$$$$       | $$| $$$$$$$/    | $$ |____  $$| $$__  $$| $$ /$$__  $$");
		System.out.println("| $$__  $$ /$$ | $$  |______/  /$$  | $$| $$____/     | $$  /$$$$$$$| $$  \\ $$| $$| $$$$$$$$");
		System.out.println("| $$  \\ $$| $$ | $$           | $$  | $$| $$          | $$ /$$__  $$| $$  | $$| $$| $$_____/");
		System.out.println("| $$$$$$$/|  $$$$$/           |  $$$$$$/| $$          | $$|  $$$$$$$| $$$$$$$/| $$|  $$$$$$$");
		System.out.println("|_______/  \\_____/             \\_______/|__/          |__/ \\_______/|_______/ | __/\\________/");
		int choice = 0;
		Scanner scan = new Scanner(System.in);
		do {
			System.out.println("1. Start The Simulation!!");
			System.out.println("2. Close App");
			System.out.printf("Choice >> \n");			
			choice = scan.nextInt();
			scan.nextLine();
			if(choice == 1) {
				int number1 = 0, number2 = 0;
				// INPUT NO 1
				do {
					System.out.printf("Input the first number [1 - 100](inclusive): ");
					number1 = scan.nextInt();
					scan.nextLine();

				}while(number1 < 1 || number1 > 100);
				
				//INPUT NO 2
				do {
					System.out.printf("Input the second number [1 - 100](inclusive): ");
					number2 = scan.nextInt();

					scan.nextLine();
				}while(number2 < 1 || number2 > 100);
				
				//print Java data Types
				String baris = "+================================================================================================================+";
				System.out.println(baris);
				System.out.println("+  + (String type) | (Character Type) | * (Integer type) | / (Floating Type) | input 1 == input 2 (Boolean Type) +");
				System.out.println(baris);
				char numb1 = (char) number1;
				char numb2 = (char) number2;
				int kali = number1*number2;
				float bagi = (float)number1/number2;
				System.out.printf("+      %-12s|       %c   %c      |        %-10d|       %-12f|                %-19s+\n", number1 + " + " + number2, numb1, numb2, kali, bagi, number1==number2 ? "True":"False");
				System.out.println(baris);
				System.out.println("Press enter to proceed..");
				scan.nextLine();
				
				//Print Table arithmetic operation
				System.out.println("+===========================================================+");
				System.out.println("+Data Type : Integer                                        +");
				System.out.println("+===========================================================+");				
				System.out.println("+     +     |     -     |     *     |     /     |     %     +");
				System.out.println("+===========================================================+");
				int tambah = number1+number2;
				int kurang = number1-number2;
				int kalikali = number1*number2;
				int bagibagi = number1/number2;
				int modulo = number1%number2;
				System.out.printf("+    %-7d|    %-7d|    %-7d|     %-6d|     %-6d+\n", 
						tambah, kurang, kalikali, bagibagi, modulo);
				System.out.println("+===========================================================+");
				System.out.println("Press enter to proceed..");
				scan.nextLine();
				
				boolean p1 = false, p2 = false;
				//scan p1
				do {
					System.out.printf("Give me value for p1[true | false]: ");
					p1 = scan.nextBoolean();
					scan.nextLine();
				}while(p1 != true && p1 != false);
				
				
				//scan p2
				do {
					System.out.printf("Give me value for p1[true | false]: ");
					p2 = scan.nextBoolean();
					scan.nextLine();
				}while(p2 != true && p2 != false);
				
				
				//DISPLAY LOGICAL TABLE
				System.out.println("+====================================================================+");
				System.out.println("+Logical Table                                                       +");
				System.out.println("+====================================================================+");
				char bool1 = 'F', bool2 = 'F';
				String bool11 = "False", bool22 = "False";
				if(p1 == true) {
					bool1 = 'T';
					bool11 = "True";
				}
				if(p2 == true) {
					bool2 = 'T';
					bool22 = "True";
				}
				
				System.out.printf(" P1 = %c , P2 = %c                                                     +\n", bool1, bool2);
				System.out.println("+       !P1       |       !P2       |       &&       |       ||      +");
				System.out.println("+====================================================================+");
				System.out.printf("+      %-11s|      %-11s|     %-11s|      %-9s+\n", !p1, !p2, p1&&p2, p1||p2);
				System.out.println("+====================================================================+");
				

			}else if(choice == 2) {
				System.out.println("thank you for using the apps!!");
			}
		}while(choice != 2);
		scan.close();
	}



}
