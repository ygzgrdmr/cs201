//
//  main.cpp
//  cs201_4
//
//  Created by Yağız Gürdamar on 14.12.2022.
//

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "strutils.h"
#include "randgen.h"


using namespace std;
            
struct Movie{
string movie_name;
int movie_year;
string genre;
};
        
        
        
void splitstr(vector<Movie> &movies,string str, string deli = " ")
{
    int start = 0;
    int end = str.find(deli);
    Movie func_movie;
    while (end != -1) {
        string new_movie= str.substr(start, end - start);
        int index=new_movie.find(";");
        int index2=new_movie.rfind(";");
        func_movie.movie_name=new_movie.substr(0,index);
        func_movie.movie_year=stoi(new_movie.substr(index+1,index2-index-1));
        func_movie.genre=new_movie.substr(index2+1);
        movies.push_back(func_movie);
        start = end + deli.size();
        end = str.find(deli, start);
    }
    int last=str.rfind(deli);
    string last_string=str.substr(last+1);
    int index=last_string.find(";");
    int index2=last_string.rfind(";");
    func_movie.movie_name=last_string.substr(0,index);
    func_movie.movie_year=stoi(last_string.substr(index+1,index2-index-1));
    func_movie.genre=last_string.substr(index2+1);
    movies.push_back(func_movie);
}

vector<string> append(vector<string> &a, vector<string> &b){
    int length= a.size();
    for(int i=0;i<length;i+=3){
        string x=a[i];
        string y=a[i+1];
        string z=a[i+2];
        b.push_back(x);
    }
    return b;
}


void menu(vector<Movie> movies){
    Movie func_movie;
    int choice;
    cout<<"Please select your action:"<<endl;
    cout<<"1. Select the genre of the movie that you want to watch"<<endl;
    cout<<"2. Select the year of the movie that you want to watch"<<endl;
    cout<<"3. Choose a random movie"<<endl;
    cout<<"4. Exit program"<<endl;
    
    while(choice!=4){
        cout<<endl;
      cout<<"Enter your choice: ";
    cin>>choice;
        if(choice==1){
            bool check1=false;
            string genre;
            cout<<"Please enter the genre of the movie you want to watch: ";
            cin>>genre;
            cout<<""<<endl;
            bool check3 = true;
            for (int i=0; i < movies.size();i++ ){
              string tolower=LowerString(movies[i].genre);
                if(movies[i].genre==genre || genre==tolower)
                {
                    if( check3) {

                        cout << genre <<" movies from newest to oldest:"<<endl;
                        check3 = false;

                    }
                    cout<<"Movie name: "<<movies[i].movie_name<<" Release Year: "<<movies[i].movie_year<<endl;
                    
                  check1=true;
                  }
                
            }
           if(!check1){
            cout<<"There are no "<< genre<<" movies!"<<endl;
          }
        }
        
        else if(choice==2){
            string year;
          cout<<"Please enter the year of the movie you want to watch: ";
          cin>>year;
          int finder=year.find("-");
          
            if (finder>0){
              
                string parse1,parse2;
                parse1= year.substr(0,finder);
                parse2=year.substr(finder+1);
              
              bool checker1=false;
            for (int i=stoi(parse1);i<=stoi(parse2);i++){
              for(int j=0;j<movies.size();j++){
                if(movies[j].movie_year==i){
                checker1=true;
              }
              }
              
              }
              if(checker1){
                  cout<<"Movies released between the years "<< year <<" from A to Z with decreasing year ordering:"<<endl;
               for (int i=0; i < movies.size();i++ ){
                if(stoi(parse1)<=movies[i].movie_year && movies[i].movie_year<=stoi(parse2))
                {
                    cout<<"Movie name: "<<movies[i].movie_name<<" Release Year: "<<movies[i].movie_year<<" Genre: "<<movies[i].genre<<endl;
                 
                }
                   
            }
                  
              }
              else if (!checker1){
                cout<<"There are no movies released between "<<year<<"!"<<endl;
        
              }
            }
          else{
            bool checker=false;
            for (int i=0;i<movies.size();i++){
              if(movies[i].movie_year==stoi(year)){
                checker=true;
              }
            }
            if (checker){
                cout<<"Movies released in "<< year <<" from A to Z:"<<endl;
            for (int i=0; i < movies.size();i++ ){
                if(movies[i].movie_year==stoi(year))
                {
                    cout<<"Movie name: "<<movies[i].movie_name<<" Genre: "<<movies[i].genre<<endl;
                  
                }
                
            }
              }
            else if(!checker){
              cout<<"There are no movies released in "<<year<<"!";
                cout<<""<<endl;
            }
          }
        }
       else if(choice==3){
          RandGen rand;
          int r = rand.RandInt(movies.size());
          cout<<"Movie name: "<<movies[r].movie_name<<" Release Year: "<<movies[r].genre<<endl;
            
        }
        else if(choice>4 || choice<1){
            cout<<"Invalid action!"<<endl;
            
        }
    }
    cout<<"Thank you..."<<endl;
    
}


int main(){
    vector<Movie> movies;
    Movie movie_at;
    string movie;
 cout<< "Welcome to the movie recommender program!"<<endl;
 cout<<""<<endl;
 cout<<"Please enter the movie, year and genre list:"<<endl;
    cin>>movie;
    splitstr(movies,movie, "|");
    int NumItems= movies.size();
    for(int i = 0; i < NumItems -1; i++)  {
         for(int j = i + 1; j < NumItems; j++)  {
             if(movies[i].movie_year < movies[j].movie_year){
                 string temp = movies[i].movie_name;
                 movies[i].movie_name = movies[j].movie_name;
                 movies[j].movie_name = temp;
                 int temp1 = movies[i].movie_year;
                 movies[i].movie_year = movies[j].movie_year;
                 movies[j].movie_year = temp1;
                 string temp2 = movies[i].genre;
                 movies[i].genre = movies[j].genre;
                 movies[j].genre = temp2;
             }
             else if (movies[i].movie_year == movies[j].movie_year){
                 if(movies[i].movie_name > movies[j].movie_name){
                     string temp = movies[i].movie_name;
                     movies[i].movie_name = movies[j].movie_name;
                     movies[j].movie_name = temp;
                     int temp1 = movies[i].movie_year;
                     movies[i].movie_year = movies[j].movie_year;
                     movies[j].movie_year = temp1;
                     string temp2 = movies[i].genre;
                     movies[i].genre = movies[j].genre;
                     movies[j].genre = temp2;
                 }
             }
            
              
            }
         }
    cout<<""<<endl;
    menu(movies);
    
  return 0;
}


