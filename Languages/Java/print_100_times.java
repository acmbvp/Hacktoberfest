// Write a program that will read in a name from the command line and write it out 100 times.

// println prints on new line
// print prints on same line

public class Java_1A{
    public static void main(String[] args)
    {
        String printer = " ";
        if(args[0] != null)
            printer = args[0] + "\t";
        else
            printer = "lol\t";
        for(int i=0; i++<100;)
        {
            System.out.print(printer);
        }
    }
}