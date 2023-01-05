//
//  main.cpp
//  cs201_hw5
//
//  Created by Yağız Gürdamar on 26.12.2022.
//

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "strutils.h"
#include "randgen.h"
#include "movie.h"
#include <fstream>



using namespace std;


vector<string> splitLine(string line);

// Function to compare two movies based on their release year and name
bool compareLines(const string &a, const string &b) {
    vector<string> splitA = splitLine(a);
    vector<string> splitB = splitLine(b);
    int yearA, yearB;
    try {
        yearA = splitA[1] == "" ? 0 : stoi(splitA[1]);
        yearB = splitB[1] == "" ? 0 : stoi(splitB[1]);
    } catch (const invalid_argument&) {
        // If the year string is not in a valid format,
        // treat it as if it were released in the year 0
        yearA = 0;
        yearB = 0;
    }
    if (yearA != yearB) {
        // Sort lines by release year in descending order
        return yearA > yearB;
    }
    // If the release years are the same, sort lines by name in ascending order
    return splitA[0] < splitB[0];
}


// Custom sorting function for the movie vector
void sortMovies(vector<string> &lines) {
    // Perform bubble sort on the movie vector
    for (int i = 0; i < lines.size(); i++) {
        for (int j = 0; j < lines.size() - i - 1; j++) {
            if (compareLines(lines[j+1], lines[j])) {
                // Swap the movies if the second one should come before the first one
                swap(lines[j], lines[j+1]);
            }
        }
    }
}



vector<string> splitLine(string line) {
    vector<string> result;
    string current = "";
    int i = 0;
    while (i < line.size()) {
        if (line[i] != ' ') {
            current += line[i];
        } else {
            result.push_back(current);
            current = "";
        }
        i++;
    }
    result.push_back(current);

    // If the line does not contain three parts,
    // fill the remaining parts with empty strings
    while (result.size() < 3) {
        result.push_back("");
    }

    return result;
}






int main(){
/// Read movie data from file
    vector<Movie> movies;
    string filename;
    cout << "Enter the name of the input file: ";
    cin >> filename;
    ifstream inputFile(filename);
    while (!inputFile.is_open()) {
        // File could not be opened
        cout << "Error: Could not open file " << filename << endl;
        cout << "Enter the name of the input file: ";
        cin >> filename;
        inputFile.open(filename);
    }

    // Read movie data from file
    vector<string> lines;
    string line;
    while (getline(inputFile, line)) {
        lines.push_back(line);
    }

    // Sort the movie vector
    sort(lines.begin(), lines.end(), [](string a, string b) {
        vector<string> splitA = splitLine(a);
        vector<string> splitB = splitLine(b);
        int yearA, yearB;
        try {
            yearA = stoi(splitA[1]);
            yearB = stoi(splitB[1]);
        } catch (const invalid_argument&) {
            // If the year string is not in a valid format,
            // treat it as if it were released in the year 0
            yearA = 0;
            yearB = 0;
        }
        if (yearA != yearB) {
            // Sort lines by release year in descending order
            return yearA > yearB;
        }
        // If the release years are the same, sort lines by name in ascending order
        return splitA[0] < splitB[0];
    });


    // Convert lines to movies
    for (const auto &line : lines) {
        vector<string> split = splitLine(line);
        string name = split[0];
        int year = 0;
        try {
            year = stoi(split[1]);
        } catch (const invalid_argument&) {
            // If the year string is not in a valid format,
            // treat it as if it were released in the year 0
        }
        string genre = split[2];
        movies.emplace_back(name, year, genre);
    }


    // Menu loop
    bool done = false;
    while (!done)  {
           // Print the menu options
           cout << "Select an option:" << endl;
           cout << "1. Select the genre of the movie that you want to watch" << endl;
        cout << "2. Select the year of the movie that you want to watch" << endl;
        cout << "3. Exit program" << endl;
        // Read the user selection
        int selection;
        cin >> selection;

        if (selection == 1) {
            // Option 1: Select the genre of the movie that you want to watch
            cout << "Enter the genre: ";
            string genre;
            cin >> genre;

            // Convert the genre to lower case
            for (char &c : genre) {
                            c = tolower(c);
                        }

            // Flag to indicate if any movies were found
            bool found = false;

            // Print the movies belonging to the selected genre
            for (const auto &movie : movies) {
                if (movie.getGenre() == genre) {
                    movie.print();
                    found = true;
                }
            }

            if (!found) {
                // No matching movies were found
                cout << "No movies found with genre " << genre << endl;
            }
        }
        
        else if (selection == 2) {
            // Option 2: Select the year of the movie that you want to watch
            cout << "Enter the year or year range: ";
            string yearInput;
            cin >> yearInput;
            // Check if the input is a range of years
            int dashPos = yearInput.find('-');
            if (dashPos != string::npos) {
                // The input is a range of years
                int startYear = stoi(yearInput.substr(0, dashPos));
                int endYear = stoi(yearInput.substr(dashPos + 1));
                
                // Flag to indicate if any movies
                bool found = false;
                // Print the movies released within the selected year range
                for (const auto &movie : movies) {
                if (movie.getYear() >= startYear && movie.getYear() <= endYear) {
                movie.print();
                found = true;
                }
            }
                if (!found) {
                    // No matching movies were found
                    cout << "No movies found between the years " << startYear << " and " << endYear << endl;
                }
            } else {
                // The input is a single year
                int year = stoi(yearInput);
                // Flag to indicate if any movies were found
                bool found = false;
                // Print the movies released in the selected year
                for (const auto &movie : movies) {
                    if (movie.getYear() == year) {
                        movie.print();
                        found = true;
                    }
                }

                if (!found) {
                    // No matching movies were found
                    cout << "No movies found in the year " << year << endl;
                }
            }
        }
        else if (selection == 3) {
        // Option 3: Exit the program
        done = true;
        }
        else {
        // Invalid input
        cout << "Error: Invalid option" << endl;
        }
    }

        return 0;
}

                
            


