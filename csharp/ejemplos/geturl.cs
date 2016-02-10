// buscar:
// http://www.codeproject.com/Articles/18034/HttpWebRequest-Response-in-a-Nutshell-Part
using System;
using System.IO;
using System.Net;

public class Cat
{
    public static void Main(string[] args)
    {
	string address = "http://www.google.com";

	HttpWebRequest request = WebRequest.Create("http://google.com") as HttpWebRequest;

        //request.Accept = "application/xrds+xml";
        HttpWebResponse response = (HttpWebResponse)request.GetResponse();

        WebHeaderCollection header = response.Headers;

        var encoding = ASCIIEncoding.ASCII;
        using (var reader = new System.IO.StreamReader(response.GetResponseStream(), encoding))
        {
            string responseText = reader.ReadToEnd();
        }
	//var request = (HttpWebRequest)WebRequest.Create(address);
//	Console.Write(request.GetResponse());
	/*
	using (WebClient client = new WebClient())
	{
	    client.DownloadString(address);
	}
	*/
    }
}
