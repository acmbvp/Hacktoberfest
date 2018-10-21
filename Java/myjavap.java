import java.lang.reflect.*;

/* 
Creating own javap tool--
this tool disassembles a class file to displays metadata or information about the fields,constructors 
and methods present in a class file.
How to run after compiling code: 
        > java myjavap <class-name>
 e.g.   > java myjavap java.lang.String
        > java myjavap java.util.Scanner */

public class myjavap {
    public static void main(String... input) {
        try {
            Class c = Class.forName(input[0]); // taking input from command line

            Field field[] = c.getDeclaredFields();
            Constructor constructor[] = c.getDeclaredConstructors();
            Method method[] = c.getDeclaredMethods();

            System.out.println("\nAll Fields in class " + c.getName() + ":");
            for (int i = 0; i < field.length; i++) {
                System.out.println("    " + field[i]);
            }
            System.out.println("\nAll Constructors in class " + c.getName() + ":");
            for (int i = 0; i < constructor.length; i++) {
                System.out.println("    " + constructor[i]);
            }
            System.out.println("\nAll Methods in class " + c.getName() + ":");
            for (int i = 0; i < method.length; i++) {
                System.out.println("    " + method[i]);
            }

        } catch (ClassNotFoundException cnfe) {
            System.out.println("Class you entered is not found.");
        } catch (ArrayIndexOutOfBoundsException aioe) {
            System.out.println("you have entered Invalid input.");
        } catch (Exception e) {
            System.out.println("Invalid");
        }
    }
}
