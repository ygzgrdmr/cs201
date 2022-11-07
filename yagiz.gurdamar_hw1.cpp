#include <iostream>

using namespace std;

int main() {
    
    string name;
    double exam_grade1;
    double exam_grade2;
    double weighted_exam_avr;
    double hw1,hw2,hw3,hw4,hw5;
    double hw_avg;
    double ratio;
    double hw_grade;
    double q1,q2,q3,q4;
    double quiz_grade;
    double course_numeric_grade;
    
    cout << "The purpose of this program is to calculate your CS201 grade. What is your name? ";
    cin >>name;
    cout << "Hello " << name << ", what are your midterm and final exam grades? ";
    cin >> exam_grade1 >> exam_grade2;
    weighted_exam_avr = (0.3 * exam_grade1 + 0.35 * exam_grade2) / 0.65;
    if (weighted_exam_avr >= 30){
        cout << "What are the grades of your 5 homework? ";
        cin >> hw1 >> hw2 >> hw3 >> hw4 >> hw5;
        hw_avg= (hw1+hw2+hw3+hw4+hw5)/5;
        ratio = hw_avg/ weighted_exam_avr;
        if (ratio <=2.0){
            hw_grade=hw_avg;
            cout << "You'll get all the points earned from homework!" << endl;
            }
        else if (ratio>2.0 && ratio<3.0){
            hw_grade= hw_avg *(3-ratio);
            cout << "You'll get " << hw_grade <<" from the points earned from homework!" << endl;
            
        }
        else if (ratio >=3.0){
            hw_grade= 0;
            cout << "You'll get NONE of the points earned from homework!"<<endl;
        }
        
        cout <<"What are the grades of your 4 quizzes? If any, enter your grade as 0 for missed quizzes. ";
        cin >> q1 >> q2>> q3 >> q4;
        
        if (q1<=q2 && q1<=q3 && q1<=q4){
            quiz_grade= ((q2+q3+q4))/ 30*100;
            
        }
        else if (q2<=q1 && q2<=q3 && q2<=q4){
            quiz_grade= ((q1+q3+q4))/ 30*100;
        }
        
        else if (q3<=q1 && q3<=q2 && q3<=q4){
            quiz_grade= ((q1+q2+q4))/ 30*100;
            
        }
        else {
            quiz_grade= ((q1+q3+q2))/ 30*100;
            
        }
        
        course_numeric_grade = quiz_grade * 0.10 + hw_grade * 0.25 + exam_grade1 * 0.30 + exam_grade2 * 0.35;
        
        cout << name << ", your grade for CS201 is: " << course_numeric_grade <<endl;
        }
    
    else{
        cout << name << ", your weighted exam average is less than 30, you will fail the course!"<<endl;
        }
    
    

return 0;
}