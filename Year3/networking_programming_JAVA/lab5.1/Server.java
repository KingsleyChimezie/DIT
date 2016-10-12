import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

public class Server
{
    public static void main(String[] args) throws IOException
    {
        try {
            int temp1, temp2, sum;

            ServerSocket server = new ServerSocket(5000, 10);
            System.out.println("Server Is Running...");
            Socket connection = server.accept();
            ObjectOutputStream out = new ObjectOutputStream( connection.getOutputStream() );
            ObjectInputStream in = new ObjectInputStream( connection.getInputStream() );
            String message = " ";
            message = " ";
            message = "--- MENU ---" +"\n"+ "1 - Addition" +"\n"+ "2 - Square Root" +"\n"+ "3 - Power" +"\n"+ "0 - Exit";
            out.writeObject(message);

            do
            {
                message = (String) in.readObject();
                System.out.println ("Data from Client: " + message);

                switch(message)
                {
                    case "1" :
                        message = "Enter num 1: ";
                        out.writeObject(message);
                        message = (String) in.readObject();
                        temp1 = Integer.parseInt(message);
						
                        message = "Enter num 2: ";
                        out.writeObject(message);
                        message = (String) in.readObject();
                        temp2 = Integer.parseInt(message);
						
                        sum = temp1 + temp2;
                        message = Integer.toString(sum);

                        out.writeObject("\n" + temp1 + " + " + temp2 + " = " + message);
                        break;

                    case "2" :
                        message = "Enter a number";
                        out.writeObject(message);
                        message = (String) in.readObject();
                        double num = Double.parseDouble(message);
                        num = Math.sqrt(num);

                        message = Double.toString(num);
                        out.writeObject("\n" + message);
                        break;
                    case "3" :
                        message = "Enter first number ";
                        out.writeObject(message);
                        message = (String) in.readObject();
                        double temp3 = Double.parseDouble(message);
						
                        message = "Enter second number ";
                        out.writeObject(message);
                        message = (String) in.readObject();
                        
                        double temp4 = Double.parseDouble(message);
                        
                        double sum2 = Math.pow(temp3, temp4);

                        message = Double.toString(sum2);

                        out.writeObject("\n" + message);
                        break;

                    default :
                        message = "Invalid input! Please enter 1, 2, 3, or 0";
                        out.writeObject("\n" + message);
                        break;
                        
                    case "0" :
                        out.writeObject(message);
                        connection.close();
                }

            }while(!message.equals("0"));

            
        }
        catch (Exception ex)
        {
            System.err.println(ex);
        }
    }
}




