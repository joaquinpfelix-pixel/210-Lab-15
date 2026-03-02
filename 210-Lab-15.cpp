//COMSC-210 | Lab 15 | Joaquin Felix
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//Constant declarations
const string INPUT_FILE = "input.txt";

//Movie Class declaration
class Movie
{
    private:
        string title;
        int yearReleased;
        string screenWriter;
    public:
    void setTitle(string t);
    void setYearReleased(int y);
    void setScreenWriter(string s);

    string getTitle() const;
    int getYearRelease() const;
    string getScreenWriter() const;

    void print() const;
};

//Function prototypes
bool openFiles(ifstream &inFile);
void loadMovies(vector<Movie> &movie);

int main()
{

}

//openFile() opens input file and checks for errors
//arguments: ifstream reference
// returns: true if successful, false otherwise
bool openFile(ifstream &inFile)
{
    inFile.open(INPUT_FILE);

    if (!inFile)
    {
        cout << "Error: Could not open file "
             << INPUT_FILE << "." << endl;
        return false;
    }
    return true;
}

//LoadMovies() reads file data into vector
// arguments: vector<Movie> reference
// returns: nothing
void loadMovies(vector<Movie> &movie)
{
    ifstream inFile;

    if(!openFile(inFile))
    {
        return;
    }

    string title;
    int year;
    string writer;

    while (getline(inFile, title))
    {
        inFile >> year;
        inFile.ignore();
        getline(inFile, writer);
    }

}