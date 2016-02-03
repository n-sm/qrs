using System;
using System.Collections.Generic;
using System.Linq;

class Linq2
{
    static void Main()
    {
	string[] names = { "Tom", "Dick", "Harry" };
	var namesSubset = names.Where (n => n.Length > 3 );
	foreach (string n in namesSubset) Console.WriteLine(n);
    }
}
