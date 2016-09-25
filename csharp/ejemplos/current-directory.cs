// cmdline1.cs
// arguments: A B C
using System;
using System.IO;

public class CommandLine
{
   public static void Main(string[] args)
   {

       string path = Directory.GetCurrentDirectory();
       Console.WriteLine("Current Directory is: {0}", path);
       
   }
}
