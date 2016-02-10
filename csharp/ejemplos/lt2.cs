using System;
using System.Collections.Generic;
using System.Linq;

class Linq3
{
    static void Main()
    {
	int l, m = 1;
	m = Int32.MaxValue;
	l = m;
	Console.WriteLine("Max int32: {0}", m);
	var todos = Enumerable.Range(0, l);
	int[] subset = { 1, 2, 4, 5, 6, 7, 8 };

	Console.Write("subset tiene: ");
	foreach(var x in subset) Console.Write("{0} ,", x); 
	Console.WriteLine("");
	
	// VERSION 1
	var linqtest = todos.Where(x => subset.Contains(x));
	var dt1 = DateTime.Now;
	Console.WriteLine("Versión 1: ");
	//foreach (var n in linqtest) Console.Write("{0}, ", n);
	var dt2 = DateTime.Now;
	var delta1 = dt2 - dt1;
	Console.WriteLine("\tTardó: {0}", delta1.ToString());
	Console.WriteLine();

	
	// VERSION 2
	linqtest = todos.Where(x => x >= 1 && x <= 8 );
	dt1 = DateTime.Now;
	Console.WriteLine("Versión 2: ");
	foreach (var n in linqtest) Console.Write("{0}, ", n);
	dt2 = DateTime.Now;
	delta1 = dt2 - dt1;
	Console.WriteLine("\tTardó: {0}", delta1.ToString());


	// VERSION 3
	var sset = new HashSet<int>(subset); 
	linqtest = todos.Where(x => sset.Contains(x)); 
	dt1 = DateTime.Now;
	Console.WriteLine("Versión 3: ");
	foreach (var n in linqtest) Console.Write("{0}, ", n);
	dt2 = DateTime.Now;
	delta1 = dt2 - dt1;
	Console.WriteLine("\tTardó: {0}", delta1.ToString());

	
	
    }
}
