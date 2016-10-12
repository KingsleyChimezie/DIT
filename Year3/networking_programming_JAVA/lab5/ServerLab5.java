import java.net.*;
import java.io.*;
public class ServerLab5 {
	public static void main(String[] args) {
		try {
			ServerSocket server = new ServerSocket( 5000, 10 ); // create ServerSocket
			System.out.println("Server is Running on port 5000");
			Socket connection = server.accept();
			ObjectOutputStream out = new ObjectOutputStream( connection.getOutputStream() );
			ObjectInputStream in = new ObjectInputStream( connection.getInputStream() );
			String message = "Connection successful";
			out.writeObject(message);
			message = ( String ) in.readObject();
			;
            
             switch(message) {
                 case "1" :
                    System.out.println ("Integer From Clint: << 1 >>");
                     String reply = "CLIENT, ENTER 2 NUMBERS\n";
			         out.writeObject(reply);
                     
                     String num1 = "num1: ";
			         out.writeObject(num1);
                     //num1 = ( String ) in.readObject();
                     
                     String num2 = "num2: ";
			         out.writeObject(num2);
			         //num2 = ( String ) in.readObject();
                     
                    System.out.println(num1 + num2);
                    break;
                     
                 default :
                    System.out.println("Invalid input from client");
              }
			connection.close();
		} 
		catch (Exception ex) {
			System.err.println(ex);
		} 
	}
}