#include <iostream>
#include <string.h>
using namespace std;

void ChangeString(char*, char*);
bool TheSame(char*string, char*word, int, int);

int main()
{
	const int length = 256;
	char string[length], words[length];
	cout << "Enter the string: ";
	cin.getline(string, length, '\n');
	cout << "Enter words through the delete: ";
	cin.getline(words, length, '\n');
	system("cls");
	cout << "\n\t String :\n";
	cout << string;
	ChangeString(string, words);
	cout << "\n\t New String :\n";
	cout << string;
	system("pause");
	return 0;
}

void ChangeString(char* string, char* words)
{
	char* symbols = "ABCDEFGHIJKLMNOPQRSTUWVXYZabcdefghijklnmopqrstuwvxyz";
	char* pWord = strpbrk(string, symbols);
	char*  oneWord = strpbrk(words, symbols);

	while (oneWord)
	{
		int leng = strspn(oneWord, symbols);
		pWord = strpbrk(string, symbols);
		while (pWord)
		{
			int length = strspn(pWord, symbols);
			if (TheSame(pWord, oneWord, length, leng))
				strcpy(pWord, pWord + length);
			else
				pWord += length;
			pWord = strpbrk(pWord, symbols);
		}
		oneWord += leng;
		oneWord = strpbrk(oneWord, symbols);
	}
}

bool TheSame(char*string, char*word, int length, int leng)
{
	if (length != leng)
		return false;
	int t = length;
	for (int i = 0; i < t; i++)
	{
		if (string[i] != word[i])
			return false;
	}
	return true;
}
