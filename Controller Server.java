/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package udp;

import java.awt.AWTException;
import java.awt.Robot;
import java.awt.event.KeyEvent;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.SocketException;

/**
 *
 * @author CRAP
 */
public class UDP {

    /**
     * @param args the command line arguments
     */
    
    
    public static void main(String[] args) throws SocketException, IOException, AWTException {
        // TODO code application logic here
        
        DatagramSocket serverSocket = new DatagramSocket(8888);
            byte[] receiveData = new byte[20];
             Robot r = new Robot();
        
        
        
          while(true)
               {
                  DatagramPacket receivePacket = new DatagramPacket(receiveData, receiveData.length);
                  serverSocket.receive(receivePacket);
                  String clientSentence = new String( receivePacket.getData());
                  System.out.println("RECEIVED: " +clientSentence);
                  
                 
                  if(clientSentence.contains("UP")){
                if(clientSentence.contains("ON")){
                    r.keyPress(KeyEvent.VK_W);
                   
                }else{
                    r.keyRelease(KeyEvent.VK_W);
                }
            }
            
            if(clientSentence.contains("DOWN")){
                if(clientSentence.contains("ON")){
                    r.keyPress(KeyEvent.VK_S);
                }else{
                    r.keyRelease(KeyEvent.VK_S);
                }
            }
            
            if(clientSentence.contains("LEFT")){
                if(clientSentence.contains("ON")){
                    r.keyPress(KeyEvent.VK_A);
                }else{
                    r.keyRelease(KeyEvent.VK_A);
                }
            }
            
            if(clientSentence.contains("RIGHT")){
                if(clientSentence.contains("ON")){
                    r.keyPress(KeyEvent.VK_D);
                }else{
                    r.keyRelease(KeyEvent.VK_D);
                }
            }
            
            if(clientSentence.contains("A ")){
                if(clientSentence.contains("ON")){
                    r.keyPress(KeyEvent.VK_H);
                }else{
                    r.keyRelease(KeyEvent.VK_H);
                }
            }
            
            if(clientSentence.contains("B ")){
                if(clientSentence.contains("ON")){
                    r.keyPress(KeyEvent.VK_J);
                }else{
                    r.keyRelease(KeyEvent.VK_J);
                }
            }
            
            if(clientSentence.contains("START")){
                if(clientSentence.contains("ON")){
                    r.keyPress(KeyEvent.VK_CONTROL);
                }else{
                    r.keyRelease(KeyEvent.VK_CONTROL);
                }
            }
            
            if(clientSentence.contains("SELECT")){
                if(clientSentence.contains("ON")){
                    r.keyPress(KeyEvent.VK_SPACE);
                }else{
                    r.keyRelease(KeyEvent.VK_SPACE);
                }
            }
            
            receiveData = new byte[20];
            
               }
    }
}
