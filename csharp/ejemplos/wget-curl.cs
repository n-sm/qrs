using System;
using System.IO;
using System.Net;

public class WgetCurl
{
    public static void Main(string[] args)
    {
      int len = args.Length;
      string[] links = new string[1];
      var c = new WebClient();

      if(len == 0)
	Console.Write(c.DownloadString("http://www.google.com")); // default
      else links = args;

      for (int i = 0; i < len; i++)
      	{
      	  string data = c.DownloadString(links[i]);
      	  Console.Write(data);
      	}
    }
}

//evillar 330
//bloqueada la cuenta
//trato

// ejecucion de sentencia 397 paso 5to piso impresora //