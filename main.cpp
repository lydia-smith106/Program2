//Lydia Smith
//Program 2
//COSC 
//3/15/21

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "BinarySearchTree.cpp"
#include <iomanip>
#include "timer.h"

using namespace std;

string cleanWord(string word);
int not_checked = 0;

int main() 
{
	
	//declare file stream and dictionary binary search tree
    string line;
	string word;
    ifstream myfile("dict.txt");
	ifstream bookfile("book.txt");
	BinarySearchTree<string> dict_list;
	
	int found = 0;
	int not_found = 0;
	int found_compares = 0;
	int not_found_compares = 0;

	//declare watch to time book compares
	Timer Watch;

	//add words from dictionary to binary search tree
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
			string newLine = cleanWord(line);
			dict_list.AddLeaf(newLine);
			//cout << newLine;
        }
        myfile.close();
    }

    else cout << "Unable to open file";

	//start timer
	Watch.Start();
	//line.clear();

	string newWord;

	//int num = 0;
	//open book file
	if (bookfile.is_open())
	{
		while (!bookfile.eof())
		{
			bookfile >> word;

			newWord = cleanWord(word);

			if (newWord.empty() == false) 
			{
				//cout << endl << "Clean word: " << newWord << endl;
				int j = 1;
				try
				{
					if (dict_list.Find(newWord))
					{
						found++;
					}
					else
					{

						throw(j);

					}
				}
				catch (int myNum)
				{
					not_found++;

				}

			}
		}
		bookfile.close();
	}

	else cout << "Unable to open file";



	Watch.Stop();
	//Watch.Reset();
	//cout << endl << "NUM:" << num << endl;
	cout << std::fixed;
	std::cout << std::setprecision(2);
	cout << "dictionary size: " << dict_list.getSize()<<endl;
	cout << "Done checking and these are the results:" << endl;
	cout << "finished in time: " << Watch.Time() << endl;
	cout << "There are " << found << " words found in the dictionary." << endl;
	cout << "There are " << not_found << " words not found in the dictionary." << endl;
	cout << "There are " << not_checked << " words not checked." << endl;


    return 0;
}

string cleanWord(string word) 
{
	if (isdigit(word[0]) != 0 || word[0] == '\'')
	{
		word.clear();
		not_checked++;
		return word;

	}
	else
	{
		for(int i = 0; i<word.length(); i++)
		{
			word[i] = tolower(word[i]);

			if (!(isalnum(word[i])) && word[i] != '\'')
			{
				//cout << practice[i];
				word.erase(i, 1);
				i--;
			}

		}	

		return word;
	}

};
