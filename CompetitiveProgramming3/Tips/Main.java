// Suppose that a problem requires you to compute 25!
import java.util.Scanner;
import java.math.BitInteger;

class Main {
	public static void main(String[] args) {
		BitInteger fac = BitInteger.ONE;
		for(int i = 2; i <= 25; i++)
			fac = fac.multiply(BitInteger.valueOf(i));
		System.out.println(fac);	
	}
}