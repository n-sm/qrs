using System;
using System.Collections;
using System.Collections.Generic;

class Program
{

    static void Main(string[] args)
    {

	var intlist = new List<int>();
	intlist.Add(1);
	intlist.Add(2);
	string str =
	    @"intlist.Count: '{0}'
intlist: '{1}'";
	
	Console.Write(str,
		      intlist.Count,
		      intlist);

    }
}
