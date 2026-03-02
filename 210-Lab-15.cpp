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
    int getYearReleased() const;
    string getScreenWriter() const;

    void print() const;
};

//Function prototypes
bool openFiles(ifstream &inFile);
void loadMovies(vector<Movie> &movie);

int main()
{
    vector<Movie> movies;

    loadMovies(movies);

    for (int i = 0; i < movies.size(); i++)
    {
        movies[i].print();
    }
    return 0;
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
void loadMovies(vector<Movie> &movies)
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

        Movie tempMovie;

        tempMovie.setTitle(title);
        tempMovie.setYearReleased(year);
        tempMovie.setScreenWriter(writer);

        movies.push_back(tempMovie);
    }
    inFile.close();

}

//setTitle() sets movie title
void Movie::setTitle(string t)
{
    title = t;
}

//setYearReleased() sets year 
void Movie::setYearReleased(int y)
{
    yearReleased = y;
}
//setYearReleased() new year
void Movie::setScreenWriter(string s)
{
    screenWriter = s;
}

string Movie::getTitle() const
{
    return title;
}

int Movie::getYearReleased() const
{
    return yearReleased;
}

string Movie::getScreenWriter() const
{
    return screenWriter;
}

//print() outputs formatted movie data
void Movie::print() const
{
    cout << "Movie: " << screenWriter << endl;
    cout << "    Year released: "
         << yearReleased << endl;
    cout << "    Screenwriter: "
         << title << endl << endl;
}