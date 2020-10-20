//Kamrin Chizek
//Lab 4
//Fall 2020 C++
/* This program will use a set of data, that correlates to temperatures, 
from an input file and put that data into a bar chart format */

#include <iostream> //adding basic library
#include <fstream> //adding library for file input
#include <iomanip> //adding library for setw()

using namespace std; //created to shortcut the use of std

void xaxis(); //Prototype for my x axis labels
void NegTemps(float); //Prototype for function dealing with negative values
void PosTemps(float); //Prototype for funtion dealing with positive values

const string tempFile = "C:/Users/kchiz/OneDrive/Documents/C++/Labs/Lab 4/Lab 4/Lab 4/Lab4TempInputs.dat"; /*creating string for 
																										   input file location*/


int main()
{
	ifstream inFile; 
	inFile.open(tempFile); //opening input file

	float temps; //creating a varible to store the data read in from the file

	inFile >> temps; //Priming read for data

	if (!inFile) //Error message if there is a problem reading the data or not being able to find the file. Ends program
	{
		cout << "There was an error in finding the file or reading in the inputs. \nPlease check the location, file name, and inputs (Do not use characters)." << endl;
		return 1;
	}

	xaxis(); //funtion call for my x axis labels
	
	while (inFile) 
	{
		if (temps < -30 || temps >120) /*if data is read outside the range, it will end the program 
									   and tell you which data value is in question*/
		{
			cout << temps << " is outside of range. Please stay within the range of -30 to 120 and try again." << endl;
			return 1;
		}
		else if (temps >= -30 && temps <= -3) //else if statement to deal with the negative values
		{
			NegTemps(temps);
		}
		else if (temps >=3 && temps <= 120) //else if statement to deal with the positive values
		{
			PosTemps(temps);
		}
		else if (temps > -3 && temps <3) /*else if statement to deal with values that produce no stars and provides 
										 transition between positive and negative values*/
		{
			cout << setw(6) << temps << setw(15) << "|" << endl;
		}

		inFile >> temps; //Second Priming Read
	}

	inFile.close(); //closing the input file
	
	return 0;
}

void xaxis() //x axis label function
{
	cout << "     Temperatures recorded every hour for 24 hours" << endl << "     Every star represents 3 degrees" << endl << endl; //creates title
	cout << setw(11) << -30 << setw(10) << 0 << setw(10) << 30 << setw(10) << 60 << setw(10) << 90 << setw(10) << 120 << endl; //Sets x axis labels to match the stars as close as possible
}

void NegTemps(float temps) //Function that deals with negative values and uses the "temps" variable
{
	float star = (temps / 3); //creating the stars to be a third of the input
	
	int i = 1;

	cout << setw(6) << temps; //creates the y axis temperatures
	cout << setw(int(star) + 15); //sets the width to deal with space between temp value and stars

	while (i <= int(-(star))) //while loop to output the stars
	{
		cout << "*"; 

		i++; //increases i by 1

		if (i > int(-(star)))
		{
			cout << "|" << endl;
		}
	}
}

void PosTemps(float temps) //function to deal with positive values
{
	float star = (temps / 3); //creating the stars to be a third of the input

	int i = 1;

	cout << setw(6) << temps; //sets y axis labels of temps
	cout << setw(15) << "|"; //sets line for 0

	while (i <= int(star)) //while loop outputing the number of correct stars
	{
		cout << '*';

		i++;
		
		if (i > int(star))
		{
			cout << endl;
		}

	}


}