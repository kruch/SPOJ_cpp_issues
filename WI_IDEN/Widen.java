import java.util.Scanner;

public class Widen {

    public static void main(String[] args)
    {
        //input
        Scanner reader = new Scanner(System.in);
        int n = reader.nextInt();
        String inputString = reader.next();


        String Output = widen(n, inputString);
        System.out.println(Output);
    }

    public static String widen(int n, String Phrase)
    {

        if(Phrase.length() <= n)
        {
            return Phrase;
        }
        // remove all non-digit and non-letter chars
        for(int i = Phrase.length()-1 ; i >= 0 ; i--)
        {
            if(!Character.isLetter(Phrase.charAt(i)) && !Character.isDigit(Phrase.charAt(i)))
            {
                Phrase = Phrase.substring(0, i) + Phrase.substring(i+1,Phrase.length());
                if(Phrase.length() <= n) return Phrase;
            }
        }
        //remove all numeric chars
        for(int i = Phrase.length()-1 ; i >= 0 ; i-- )
        {
            if(Character.isDigit(Phrase.charAt(i)))
            {
                Phrase = Phrase.substring(0, i) + Phrase.substring(i+1, Phrase.length());
            }
        }
        // checking the first vowel and removing the rest of the vowels
        boolean firstVowel = false;
        for(int i = 0 ; i<Phrase.length()  ; i++)
        {

            if(     Phrase.charAt(i) == 'A' ||
                    Phrase.charAt(i) == 'E' ||
                    Phrase.charAt(i) == 'I' ||
                    Phrase.charAt(i) == 'O' ||
                    Phrase.charAt(i) == 'U' ||
                    Phrase.charAt(i) == 'Y' )
            {
                if(firstVowel == false)
                {
                    firstVowel = true;
                    continue;
                }
                Phrase = Phrase.substring(0,i) + Phrase.substring(i+1,Phrase.length());
                if(Phrase.length() <= n) return Phrase;
                if(   Phrase.charAt(i+1) == 'A' ||
                        Phrase.charAt(i+1) == 'E' ||
                        Phrase.charAt(i+1) == 'I' ||
                        Phrase.charAt(i+1) == 'O' ||
                        Phrase.charAt(i+1) == 'U' ||
                        Phrase.charAt(i+1) == 'Y' )
                {
                    Phrase = Phrase.substring(0,i+1) + Phrase.substring(i+2,Phrase.length());
                }
                if(Phrase.length() <= n) return Phrase;
            }
            if(Phrase.length() <= n) return Phrase;
        }
        // removing characters from the second last one
        for(int i = Phrase.length()-2 ; i >= 0 ; i--)
        {
            Phrase = Phrase.substring(0,i) + Phrase.substring(i+1, Phrase.length());
            if(Phrase.length() <= n) return Phrase;
        }

        return Phrase;
    }
}
