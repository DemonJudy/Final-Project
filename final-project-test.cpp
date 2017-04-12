//#include "stdafx.h"
//////mid-term-5,lab8-1
#include <iostream>
#include <fstream>		// for external file streams
#include <cstdlib>      // for definition of EXIT_FAILURE
#include <ctime>        // select random numbers
using namespace std;	// use the standard namespace
#define inFile "Students' full name.txt"

int FileInput(void);
int Randomunmber(void);
void FormerDisplay(void);
void NumInput(void);
void Loop(void);
void LoopDisplay(void);
void LatterDisplay(void);

int n=0;
int num[n]={0};
int numtable[40];
char TFtable[40];
char namech[40];
char nametable[40];
char namebuffer[1600];

int main()
{

	//display the title of program
	FormerDisplay();
	
	// Prepare files.
	FileInput();
	
	Loop();
	
	//collect selected students' number

	NumInput();//////
	
	//display the result of program
	LatterDisplay();
	
	return 0;
}

void FormerDisplay(void)
{
	cout << "*************************************************************************" << endl;
	cout << "* Rowan University " << "				" << " Date: 03/15/17		*" << endl;
	cout << "* College of Computer Science" << "			" << " Professor: Rafael Orta *" << endl;
	cout << "* Class: CSNP C++							*" << endl;
	cout << "*									*" << endl;
	cout << "* Program Name: PTS (Participation Tracking System)			*" << endl;
	cout << "*									*" << endl;
	cout << "* Objective: This program keeps track of participation during the class *" << endl;
	cout << "*	     and does random selection of students that have not	*" << endl;
	cout << "*	     participated      						*" << endl;
	cout << "*									*" << endl;
	cout << "* Author: Gaoyuwei Gu&Nicholas Cordero							*" << endl;
	cout << "*************************************************************************" << endl;
	cout << endl << endl;
}

int FileInput(void)
{
	ifstream nf;
	nf.open("Students' full name.txt");
	if (!nf.fail ())
	{
		for(int m=0;m<=39;m++)
		{
			n++;
			nf.getline(&nametable[m-1],40,NWLN);//////found no solution
			TFtable[m-1]='F';
			{
				if(m<9)
				{
					numtable[m-1]=n;
				}
				else if(m<18)
				{
					numtable[m-1]=n+1;
				}
				else
				{
					numtable[m-1]=n+2;
				}
			}
			//cout << numtable[m-1] << nametable[m-1] << TFtable[m-1] 
			//<< "The above is for test." << endl;//////test function,delete later
		}
		return 1; // success return
	}
	else
	{
		cerr << "*** ERROR: Cannot open " << inFile
			 << " for input." << endl;
		return -1; // failure return
	}
		
	// Close files.
	nf.close();
}

void Loop(void)
{
	int input=0;//////
	char state;
	do
	{
		//display the students' name table
		LoopDisplay();
		cout << endl << endl;
		cout << "Please enter the student number or type 'r' to secelt a random student." << endl;
		//cin >> input;
		//if(input=='R'||input=='r')
		{
			cout << "The stduent selected is " << Randomunmber() << ". Is the student present in the class? (Y/N)" << endl;
			//cin >> state;
		}
	}
	while(input==1);//////
}

void LoopDisplay(void)
{
	int a;
	for(a=0;a<39;a++)
	{
		if((a+1)%4==0&&(a+1)<10)
		{
			cout << numtable[a-1] << "  " << nametable[a-1] << " " << TFtable[a-1] << endl;
		}
		else if((a+1)%4!=0&&(a+1)<10)
		{
			cout << numtable[a-1] << "  " << nametable[a-1] << " " << TFtable[a-1] << "		";
		}
		else if((a+1)%4==0)
		{
			cout << numtable[a-1] << " " << nametable[a-1] << " " << TFtable[a-1] << endl;
		}
		else
		{
			cout << numtable[a-1] << " " << nametable[a-1] << " " << TFtable[a-1] << "		";
		}
	}
}

void NumInput(void)
{
	//////
}

void LatterDisplay(void)
{
	cout << "*************************************************************************" << endl;
	cout << "*	Summary of Students that Participated for the Day		*" << endl;
	cout << "*************************************************************************" << endl;
	int i;
	for(i=0;i<n;i++)
	{
		if( TFtable[i] == 'T' )
		{
			cout << nametable[i] << endl;
		}
	}
}

int Randomunmber(void)
{
	int r; //Random number
	//r=experimental::randint(1,n);
	srand(time(0));
	do
	{
		r=rand();
	}
	while(r<1||r>n);
	return r;
}
