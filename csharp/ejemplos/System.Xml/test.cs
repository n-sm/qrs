using System;
using System.Collections.Generic;
using System.Xml;
 
namespace org.doublecloud
{
    class XmlParsingDemo
    {
        static void Main(string[] args)
        {
            XmlDocument doc = new XmlDocument();
	    XmlDocument doc2 = new XmlDocument();
            doc.Load(@"books.xml");
	    doc2.Load(@"xpath-lang.html");
 
            XmlNodeList nodes = doc.DocumentElement.SelectNodes("/catalog/book");
 
            List<Book> books = new List<Book>();
 
            foreach (XmlNode node in nodes)
            {
                Book book = new Book();
 
                book.author = node.SelectSingleNode("author").InnerText;
                book.title = node.SelectSingleNode("title").InnerText;
                book.id = node.Attributes["id"].Value;
 
                books.Add(book);
            }
 
            System.Console.WriteLine("Total books: " + books.Count);
        }
    }
 
    class Book
    {
        public string id;
        public string title;
        public string author;
    }
}
