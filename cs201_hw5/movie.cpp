#include "movie.h"
#include <iostream>


using namespace std;

Movie::Movie()
{
    // Default constructor
    name = "";
    year = 0;
    genre = "";
}

Movie::Movie(string n, int y, string g)
{
    // Parameterized constructor
    name = n;
    year = y;
    genre = g;
}

void Movie::setName(string n)
{
    // Set the movie name
    name = n;
}

string Movie::getName() const
{
    // Return the movie name
    return name;
}

void Movie::setGenre(string g)
{
    // Set the movie genre
    genre = g;
}

string Movie::getGenre() const
{
    // Return the movie genre
    return genre;
}

void Movie::setYear(int y)
{
    // Set the movie release year
    year = y;
}

int Movie::getYear() const
{
    // Return the movie release year
    return year;
}

void Movie::print() const
{
    // Print the movie name, year, and genre
    cout << name << " " << year << " " << genre << endl;
}
