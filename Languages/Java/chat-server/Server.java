import java.io.*;
import java.net.*;
import java.util.*;

public class Server {

    public static void main(String... arg) throws IOException {

        ServerSocket serverSocket = new ServerSocket(5000);
        Socket socket = serverSocket.accept();
        PrintStream sendToConsole = new PrintStream(System.out);
        sendToConsole.println("Connection established!!\n");
        Scanner readFromKeyboard = new Scanner(System.in);
        PrintStream sendToSocket = new PrintStream(socket.getOutputStream());
        Scanner readFromSocket = new Scanner(socket.getInputStream());
        String sendingMessage = "";
        String receivingMessage = "";
        sendToConsole.print("          Press CTRL+C to exit !!!\n\n");
       
        try {
            while (true) {
                receivingMessage = readFromSocket.nextLine();
                sendToConsole.println("Client>> " + receivingMessage);
                sendToConsole.print("Server>> ");
                sendingMessage = readFromKeyboard.nextLine();
                sendToSocket.println(sendingMessage);
            }
        } catch (Exception NoSuchElementException) {
            sendToConsole.println("\n         Connection Disconnected!!!");
        }
        
    }
}