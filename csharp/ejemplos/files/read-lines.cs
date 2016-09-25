using System;
using System.IO;

public class Copy
{
   public static void Main(string[] args)
   {
      if (args.Length != 1)
      {
	 Console.WriteLine("Debe haber exactamente un arg.");
	 return;
      }

      string readfilename = args[0];
      string line;
      
      if (!File.Exists(readfilename))
      {
	 Console.WriteLine("No existe el archivo");
	 return;
      }
      
      System.IO.StreamReader file = new System.IO.StreamReader(readfilename);
      while((line = file.ReadLine()) != null)
      {
	 Console.WriteLine (line);
      }

      file.Close();

      // byte[] bytes = System.IO.File.ReadAllBytes(readfilename);
      // File.WriteAllBytes(writefilename, bytes);
      return;
   }
}
