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

