using System;
using System.Collections.Generic;
using System.Linq;
 
public class Linq1 
{
    static public void Main ()
    {
        string[] names = { "Tom", "Dick", "Harry" }; 
        var filtNames = names.Where (n => n.Length > 3);
        foreach (string name in filtNames)
            Console.WriteLine (name); 
    }
}
