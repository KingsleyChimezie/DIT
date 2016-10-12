import java.net.*;
import java.io.*;

public class IPSpam2 
{
  
    public static void main(String[] args) throws Exception 
    {

        InetAddress address = InetAddress.getByName(args[0]);

        String IP = address.getCanonicalHostName().toString();

        int count = 0;
        
        System.out.println(IP);

        String website = ".sbl.spamhaus.org"; //www.spamhaus.org/sbl/

        String query;
        try 
        {
            query = IP + website;
            InetAddress.getByName(query);
            System.out.println( IP + " is a known spammer.");
        } 
        catch (Exception e) 
        {
            System.out.println(IP + " appears legitimate");
        }
    }
}
 
