// NO FUNCIONA. EL COMPILADOR DICE:
/*
col2row2.cs(9,19): error CS0234: The type or namespace name 'RegularExpressions' does not exist in the namespace 'System.Text' (are you missing an assembly reference?)
*/
// cat.cs
using System;
using System.IO;
//using System.Text;
using System.Text.RegularExpressions;
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
		//string result = readText.Replace(System.Environment.NewLine, ",");
		string result = Regex.Replace(readText, @"\r\n?|\n", ",");
		Console.WriteLine(result);
	}
    }
}
}
