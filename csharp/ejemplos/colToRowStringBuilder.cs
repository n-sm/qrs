// colToRow.cs
using System;
using System.IO;
using System.Text;

public class ColToRow
{
    public ColToRow() {}
    public string colToRow(StreamReader colFile)
    {
	var sb = new StringBuilder();
	
	string line;

	var primero = 0;
	while((line = colFile.ReadLine()) != null)
	{
	    if (primero == 0) primero++;
	    else sb.Append (",");
	    sb.Append (line);
	}
	return sb.ToString();
	
    }
}

public class Program
{
    public static void Main(string[] args)
    {
	var filename = args[0];
	var helper = new ColToRow();
	
	if(File.Exists(filename))
	{
	    
	    var file = new StreamReader(filename);
	    string row = helper.colToRow(file);
	    Console.Write(row);
	    file.Close();

	}
	else
	{
	    Console.WriteLine ("File {0} couldn't be found.", filename);
	}
	
    }
}
