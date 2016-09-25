// cat.cs
using System;
using System.IO;
using System.Text;
// using System.Text.RegularExpressions;
public class Cat
{
    public static void Main(string[] args)
    {

	for(int i = 0; i < args.Length; i++)
	{
	    string filename = args[i];
	    if(File.Exists(filename))
	    {

		string readText = File.ReadAllText(filename);
		string result = readText.Replace(System.Environment.NewLine, ",");
		//string result = Regex.Replace(readText, @"\r\n?|\n", ",");
		Console.WriteLine(result);
	}
    }
}
}
