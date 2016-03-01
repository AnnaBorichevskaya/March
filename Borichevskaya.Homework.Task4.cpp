#include <iostream>
#include <string.h>
using namespace std;

void Delete(char*, char*);
bool TheSame(char*string, char*word, int, int);

int main()
{
	const int length = 256;
	char string[length], words[length];
	cout << "Enter the text: ";
	cin.getline(string, length, '\n');
	cout << "Enter words through the delete: ";
	cin.getline(words, length, '\n');
	system("cls");
	cout << "\n\t String :\n";
	cout << string;
	Delete(string, words);
	cout << "\n\t New String :\n";
	cout << string;
	system("pause");
	return 0;
}

void Delete(char* string, char* words)
{
	char* symbols = "ABCDEFGHIJKLMNOPQRSTUWVXYZabcdefghijklnmopqrstuwvxyz";
	char* pWord = strpbrk(string, symbols);
	while (pWord)
	{
		int length = strspn(pWord, symbols);
		if (TheSame(pWord, oneWord, length, leng))
			strcpy(pWord, pWord + length);
		else
			pWord += strlen(word);
		pWord = strpbrk(pWord, symbols);
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
