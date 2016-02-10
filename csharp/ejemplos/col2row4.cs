// cat.cs
using System;
using System.IO;

public class Cat
{
    public static void Main(string[] args)
    {

	//Console.Out.NewLine = ",";
	
	string filename = args[0];
	string outfilename = filename + "2.csv";
	    
	if(File.Exists(filename))
	{
	    
	    System.IO.StreamReader file = 
		new System.IO.StreamReader(filename);

	    System.IO.StreamWriter outfile = 
		new System.IO.StreamWriter(outfilename);
	    
		
	    string line;
	    int primero = 0;
	    while((line = file.ReadLine()) != null)
	    {
		if (primero == 0) primero++;
		else outfile.Write (",");
		outfile.Write (line);
	    }
	    
	    file.Close();
	    outfile.Close();
	}
	else
	{
	    Console.WriteLine ("File {0} couldn't be found.", filename);
	}
	
    }
}



    /*
      using (System.IO.StreamWriter file = 
      new System.IO.StreamWriter(@"C:\Users\Public\TestFolder\WriteLines2.txt"))
      {
      foreach (string line in lines)
      {
      // If the line doesn't contain the word 'Second', write the line to the file.
      if (!line.Contains("Second"))
      {
      file.WriteLine(line);
      }
      }
      }
    */
