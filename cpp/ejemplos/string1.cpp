#include <iostream>
#include <string>
//using namespace std;

std::string prompt("Enter a line of text: "), line( 50, '*');
  
int main()
{
  std::string text;
  std::cout << line << std::endl << prompt << std::endl;
  std::getline( std::cin, text);
  std::cout << line << std::endl
       << "Your text is " << text.size()
	    << " characters long!" << std::endl;
  return 0;
}
