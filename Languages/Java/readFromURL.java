//Java Program  to illustrate reading and writing 
// in URLConnection Class 
import java.io.*; 
import java.net.*; 
import java.util.ArrayList; 
import java.util.Date; 
import java.util.HashMap; 
import java.util.List; 
import java.util.Map; 
  
public class URLConnectionclass  
{ 
    public static void main(String[] args)  
    { 
        try
        { 
            URL url = new URL("https://www.geeksforgeeks.org/java"); 
              
            //open the connection to the above URL. 
            URLConnection urlcon = url.openConnection(); 
              
            //Executing the below line would print the value of 
            // Allow User Interaction field. 
            // System.out.println(urlcon.getAllowUserInteraction()); 
              
            //Executing the below line would print  
            // the value of Content Type field. 
            // System.out.println(urlcon.getContentType()); 
              
            //Executing the below line would print the value  
            // of URL of the given connection. 
            // System.out.println(urlcon.getURL()); 
              
            //Executing the below line would  
            // print the value of Do Input field. 
            // System.out.println(urlcon.getDoInput()); 
              
            //Executing the below line would  
            // print the value of Do Output field. 
            // System.out.println(urlcon.getDoOutput()); 
              
            //Executing the below line would  
            // print the value of Last Modified field. 
            // System.out.println(new Date(urlcon.getLastModified())); 
              
            //Executing the below line would  
            // print the value of Content Encoding field. 
            // System.out.println(urlcon.getContentEncoding()); 
              
            //To get a map of all the fields of http header 
            Map<String, List<String>> header = urlcon.getHeaderFields(); 
              
            //print all the fields along with their value. 
            for (Map.Entry<String, List<String>> mp : header.entrySet())  
            { 
                System.out.print(mp.getKey() + " : "); 
                System.out.println(mp.getValue().toString()); 
            } 
            System.out.println(); 
            System.out.println("Complete source code of the URL is-"); 
            System.out.println("---------------------------------"); 
              
            //get the inputstream of the open connection. 
            BufferedReader br = new BufferedReader(new InputStreamReader 
                                                (urlcon.getInputStream())); 
            String i; 
              
            //print the source code line by line. 
            while ((i = br.readLine()) != null)  
            { 
                System.out.println(i); 
            } 
        }  
          
        catch (Exception e)  
        { 
            System.out.println(e); 
        } 
    } 
} 