package 원리금;

import java.util.Scanner;

public class 원리금 {

	public static void main(String[] args) {
		
		int 원금;
		int 연도;
		double 연이율;
		double 원리금;
		int i, count = 0;
		Scanner sc = new Scanner(System.in);
		
		System.out.printf("원금을 입력하세요 : ");
		원금 = sc.nextInt();
		
		System.out.printf("연이율을 입력하세요 : ");
		연이율 = sc.nextDouble();
		
		System.out.printf("연도수\n원리금");
		
		for(i = 1; i < i + 1; i++) {
			count += 1;
			원리금 = 원금 * (1 + 연이율 / 100);
			System.out.printf("%d\t%f\n", count, 원리금);
			if(원리금 > 2 * 원금) {
				break;
			}
		}
		
		System.out.printf("필요한 연도수 = %d", count);

	}

}
