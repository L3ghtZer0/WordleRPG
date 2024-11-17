/* Class specification file for wordleRPG */
#ifndef WORDLERPG_H
#define WORDLERPG_H
#include <string>
#include <iostream>
#include <new>
#include <cstdlib>

using namespace std;

// Create a class template 
template <typename W>
class WordleRPG 
{
    private:
        vector<string> *aptr; // To point to the vector
        int arraySize;
        void memError(); // Handles memory allocation errors
        void fileError(); // Handles opening the wrong file

    public:
        // Default constructor
        WordleRPG()
        {aptr = 0; arraySize = 0;}

        // Constructor declaration
        WordleRPG(string filename);

        // Destructor
        ~WordleRPG();

        // Accessor to return the array size
        int size() const
        { return arraySize; }

        // Accessor to return a random word
        W getWordAt(const vector<string> &words);

        // Accessor to search through given word and confirm if user input correctly
        W getChar();  
};

/* Constructor for the WordleRPG class. Intitializes the vector of strings
   to the size/amount of words in the file and assigns a word to each subscript.*/

template <typename W> 
WordleRPG<W>::WordleRPG(string filename)
{
    try
    {
        if (filename != "fiveLetterWords.txt")
        {
            string wrongFile = "Incorrect file. Please open the five letter text file.\n";
            throw wrongFile;
        }

        ifstream file(filename, ios:: in);
        string word;

        while (file >> word)
        {
            int totalWords++;
        }
        aptr = new vector<string>(totalWords); // To point to vector of 'totalWords' amount

        while (file >> word)
        {
            for (size_t i = 0; i < totalWords; i++)
            {
                (*aptr)[i] = (word);// Adding each word to the vector
            }
        }
        file.close(); // Closing the file
            
    }
    catch (wrongFile)
    {
        fileError();
        cout << "Please enter the five letter word text file: ";
        cin >> filename;
    }
    catch (bad_alloc)
    {
        memError();
    }
}

/* Destructor for WordleRPG class */

template <typename W>
WordleRPG<W>::~WordleRPG()
{
    if (totalWords > 0)
        delete [] aptr; 
}

/* memError function. Displays error message and terminates program 
   because of bad memeory allocation */

template <typename W>
void WordleRPG<W>::memError()
{
    cout << "ERROR: Cannot allocate memory.\n";
    exit(EXIT_FAILURE);
}

/* fileError function. Displays error message and terminates program 
   if the wrong file is opened. */

template <typename W>
void WordleRPG<W>::fileError()
{
    cout << "ERROR: Wrong file was opened\n";
}

/* getWordAt function. Randomly selects a word from the vector */

template <typename W>
string WordleRPG<W>::getWordAt(const vector<string> &words)
{
    size_t randomIndex = rand() % words.size(); // Keeps the random number in bounds
    return words[randomIndex]
}

template <typename W>
void WordleRPG<W>::getChar()
{
    cout << "This is a test.";
}
#endif