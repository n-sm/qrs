using System;
using System.Collections.Generic;
using System.Linq;

class Linq3
{
    static void Main()
    {
	var todos = Enumerable.Range(0, 9999999);
	int[] subset1 = { 1, 2, 4, 5, 6, 7, 8 };
	var subset2 = Enumerable.Range(10, 21);
	//foreach (var e in subset2) Console.WriteLine(e);
	int i = 1;
	
	Console.Write("'subset2 tiene {0}' es '{1}'", i, subset2.Contains(i));
	

	// VERSION 1
	var linqtest = todos.Where(x => subset1.Contains(x));
	var dt1 = DateTime.Now;
	foreach (var n in linqtest) Console.WriteLine(n);
	var dt2 = DateTime.Now;
	var delta1 = dt2 - dt1;
	Console.WriteLine("Version 1 Tardó: {0}", delta1.ToString());


	
	// VERSION 2
	linqtest = todos.Where(x => x == 1 || x == 2 || x == 4 || x == 5 ||
				   x == 6 || x == 7 || x == 8);
	dt1 = DateTime.Now;
	foreach (var n in linqtest) Console.WriteLine(n);
	dt2 = DateTime.Now;
	delta1 = dt2 - dt1;
	Console.WriteLine("Version 2 Tardó: {0}", delta1.ToString());


	
	
    }
}
