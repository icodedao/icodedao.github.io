/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package OnTap;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileDescriptor;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;

/**
 *
 * @author Thanh Phong
 */
public class Test {

   private static void writeFileContents() throws IOException {
 
        try (FileWriter fileWriter = new FileWriter("./src/OnTap/info.txt")) {
            fileWriter.write("10 ");
            fileWriter.write("20.5 ");
            fileWriter.write("Employee ");
            fileWriter.write("50.00 ");
            fileWriter.write("Coffee");
        }
    }
   private static void readFileContents() throws IOException {
        System.out.println("Reading contents of file using Scanner class:");
        try (FileReader fileReader = new FileReader("info.txt");
                Scanner scanner=new Scanner(fileReader)){
            while (scanner.hasNext()) {
                if(scanner.hasNextInt()) {
                    System.out.println(scanner.nextInt());
                } else if(scanner.hasNextDouble()) {
                    System.out.println(scanner.nextDouble());
                } else if(scanner.hasNext()) {
                    System.out.println(scanner.next());
                }
            }
        }
    }
    public static void main(String[] args) throws IOException {
        Test test = new Test();
        test.writeFileContents();
        test.readFileContents();
    }
}
