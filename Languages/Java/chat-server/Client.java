import java.io.*;
import java.net.*;
import java.util.Scanner;

public class Client {
    public static void main(String... s) throws IOException {

        Socket socket = new Socket("127.0.0.1", 5000);
        Scanner readFromKeyboard = new Scanner(System.in);
        PrintStream sendToConsole = new PrintStream(System.out);
        PrintStream sendToSocket = new PrintStream(socket.getOutputStream());
        Scanner readFromSocket = new Scanner(socket.getInputStream());

        String sendingMessage = "";
        String receivingMessage = "";
        sendToConsole.print("          Press CTRL+C to exit !!!\n\n");

        try {
            while (true) {
                        sendToConsole.print("Client>> ");
                        sendingMessage = readFromKeyboard.nextLine();
                        sendToSocket.println(sendingMessage);
                        receivingMessage = readFromSocket.nextLine();
                        sendToConsole.println("Server>> " + receivingMessage);
                    }
                } catch (RuntimeException NoSuchElementException) {
                    sendToConsole.println("\n          Connection Disconnected!!!");
                }
    
}
