package com.company;

import java.util.Scanner;

public class PTCLTZ {

    public static void main(String[] args) {

        int s=3, t=0, counter=0 ;
        Scanner scan = new Scanner(System.in);
        t = scan.nextInt();

        for (int i = 0 ; i < t ; i++)
        {
            counter = 0;
            s = scan.nextInt();

            if(s > 10000 && s < 1) break;

            while(s != 1)
            {
                s = collatz(s);
                counter++;
            }
            System.out.println(counter);
        }

    }

    public static int collatz(int s)
    {
        if(s % 2 == 0) s /= 2;
        else s = 3 * s + 1;
        return s;
    }
}
