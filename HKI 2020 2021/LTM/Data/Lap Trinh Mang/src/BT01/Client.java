/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package BT01;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;
import java.net.UnknownHostException;

/**
 *
 * @author Thanh Phong
 */
public class Client {

    private static Socket socket = null;
    private static BufferedWriter out = null;
    private static BufferedReader in = null;
    private static BufferedReader stdIn = null;

    public static void Client(String address, int port) throws UnknownHostException, IOException {
        socket = new Socket(address, port);
        System.out.println("Client started");
        System.out.println("Connected");
        out = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
        in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        stdIn = new BufferedReader(new InputStreamReader(System.in));

        String line = "";
        while (!line.equals("Bye")) {
            System.out.print("Input: ");
            line = stdIn.readLine();
            if (!line.equals("Bye")) {
                System.out.println("Client sent: " + line);
                out.write(line);
                out.newLine();
                out.flush();
                try {
                    line = in.readLine();
                    System.out.println("Client received: " + line);
                } catch (Exception e) {
                    System.err.print(e);
                }
            } else {
                out.write(line);
                out.newLine();
                out.flush();
                break;
            }
        }
        in.close();
        out.close();
        socket.close();
        System.out.println("Closing connection");
    }

    public static void main(String args[]) throws UnknownHostException, IOException {
        Client.Client("127.0.0.1", 5000);
    }
}
