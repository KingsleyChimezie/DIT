import java.net.*;

import java.util.Date;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;

public class UDPClient {
	public static void main(String[] args) {
		try {
             DateFormat dateFormat = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
             Date date = new Date();
            
            
			DatagramSocket client = new DatagramSocket();
			//String message = "Hello Server";
			byte data [] =  dateFormat.format(date).getBytes();
			DatagramPacket sendPacket = new DatagramPacket( data, data.length,InetAddress.getLocalHost(),5000);
			System.out.println("Sending Data to Server");
			client.send(sendPacket);
			client.close();
		} 
		catch (Exception e) {
			System.out.println(e);
		}
	}
}