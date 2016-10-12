import java.net.*;
import java.io.*;
import java.util.Scanner;

public class Client 
{
    public static void main(String[] args)
    {

        try 
		{
            Socket client = new Socket("localhost",5000);
            System.out.println("Client is connected to Server");
            ObjectInputStream in = new ObjectInputStream(client.getInputStream());
            ObjectOutputStream out = new ObjectOutputStream(client.getOutputStream());
            String message = " ";
            Scanner input = new Scanner(System.in);

            while(!message.equals("0"))
            {
                message = ( String ) in.readObject();
                System.out.println (message);
                message = " ";
                System.out.print("\t>> ");
                message = input.next();
                out.writeObject(message);
            }
            System.out.println("GOODBYE!");
            client.close();
        }
        catch (Exception ex) 
		{
            System.err.println(ex);
        }
    }
}
