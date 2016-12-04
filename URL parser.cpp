#include <iostream>
using namespace std;
int main()
{
	string url;
	cout << "Enter the URL: ";   //read the URL
	cin >> url;
	char c = url.at(0);       //start parsing the string
	int len = url.length();   //counting the length of string
	int i = 0;
	while (c != '/')      //if the parsed character is not a digit.(Till we reach the host address.)
	{
		i++;                   //move forward.
		c = url.at(i);           //read the new character.
	}
	i += 2;
	c = url.at(i);
	cout << "Host: ";
	while (c != '/' && c != ':')  //print the Host address, which should be a collection of digits, and .'s.
	{
		cout << c;
		i++;
		if (i == len)               //if end of string is reached stop.
			break;
		c = url.at(i);               //parse next character.
	}
	if (c == ':')                   //if there is a colon, which means when the port is specified.
	{
		i++;
		c = url.at(i);
		cout << " Port: ";
		while (isdigit(c))           //print the port.
		{
			cout << c;
			i++;
			if (i == len)
				break;
			c = url.at(i);
		}
	}
	else                           //else, print there is not port.
		cout << " No port in URL.";
	cout << endl;
}