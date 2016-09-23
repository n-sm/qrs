using System;
using System.IO;

public class Copy
{
   public static void Main(string[] args)
   {
      if (args.Length != 2)
      {
	 Console.WriteLine("Debe haber exactamente dos argumentos.");
	 return;
      }

      string readfilename = args[0];
      string writefilename = args[1];

      if (!File.Exists(readfilename))
      {
	 Console.WriteLine("No existe el archivo");
	 return;
      }
      
      if (File.Exists(writefilename))
      {
	 Console.WriteLine("Existe el archivo de output");
	 return;
      }
      
      byte[] bytes = System.IO.File.ReadAllBytes(readfilename);
      File.WriteAllBytes(writefilename, bytes);
      return;
   }
}
