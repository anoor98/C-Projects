//Q2
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
using namespace std;


class Student {
    private:
        string name;
        vector<double> grades;
    public:
        
        string getName() const{
            return name;    
        };                    // apply keyword "const" correctly
        
        void setName(const string &s){
            name = s;    
        }
        
        string& nameRef(){return name;}
        
        void addGrade(double x){
            if (x >= 0 && x <= 100) {
                grades.push_back(x);
            }
        }// non-const methods
        
        //Q4
        double * gradePtr(int n){
            if (n > grades.size() || n < 0)
                return NULL;
            else
                return  &grades[n];
        } // const methods
        
        double getAvg() const {
            double temp = 0;
            if(grades.size() == 0) {return 0;}
            else {
                for (int i = 0; i < grades.size(); ++i){
                    temp += grades[i];    
                }
            }
            return temp / grades.size();
        } // apply keyword "const" correctly
        
        double highestGrade() const {
            int high = 0;
            for(int i = 0; i < grades.size(); ++i){
                if(grades[i] > high){
                    high = grades[i];    
                }    
            }
            return high;
        }               // apply keyword "const" correctly
        
        void print() const {
            cout << name << endl;
            if (grades.size() == 0) 
                cout << "No grades posted yet..." << endl;
            for (int i = 0; i < grades.size(); ++i){
                cout << grades[i] << " ";   
            }
        }                        // apply keyword "const" correctly
};

void highlow_avg_grade(Student *a, Student *b, int n) {
    string name_high; double high; string name_low; double low;
    //cout << a->getName() << " " << a->getAvg() << endl;
    
    for(int i = 0; i < n; ++i) {
        cout << b[i].getName() << " " << b[i].getAvg() << endl;
    }
    
    high = a->getAvg(); name_high = a->getName();
    for(int i = 0; i < n; ++i) {
        if(b[i].getAvg() > high)
            high = b[i].getAvg(); name_high = b[i].getName();
    }
    
    low = a->getAvg(); name_low = a->getName();
    for(int i = 0; i < n; ++i) {
        if(b[i].getAvg() < low)
            low = b[i].getAvg(); name_low = b[i].getName();
    }
    
    cout << "high avg = " << name_high << "  " << high << endl;
    cout << "low avg  = " << name_low << "  " << low << endl;
    
}

void highlow_top_grade(Student *a, Student *b, int n) {
    string name_high; double high; string name_low; double low;
    //cout << a->getName() << " " << a->highestGrade() << endl;
    
    for(int i = 0; i < n; ++i) {
        cout << b[i].getName() << " " << b[i].highestGrade() << endl;
    }
    
    high = a->highestGrade(); name_high = a->getName();
    for(int i = 0; i < n; ++i) {
        if(b[i].highestGrade() > high)
            high = b[i].getAvg(); name_high = b[i].getName();
    }
    
    low = a->highestGrade(); name_low = a->getName();
    for(int i = 0; i < n; ++i) {
        if(b[i].highestGrade() < low)
            low = b[i].highestGrade(); name_low = b[i].getName();
    }
    
    cout << "high top grade = " << name_high << "  " << high << endl;
    cout << "low top grade  = " << name_low << "  " << low << endl;
    
}

int main() {
    Student *Alice = new Student;
    Student *BobTwins = new Student[2];
    Alice->nameRef() = "Alice";
    BobTwins[0].setName("Bob A"); BobTwins[1].setName("Bob B");
    // use nameRef() to set name of Alice to "Alice";
    // use setName(...) to set names of BobTwins to "Bob A" and "Bob B"
    Alice->print(); BobTwins[0].print(); BobTwins[1].print();
    // call print() for Alice and BobTwins
    for (int i = 65; i <= 110; i += 10) {
        Alice->addGrade(i + 0.1);
        //  addGrade(i+0.1)    add grades for Alice
    }
    for (int i = 57; i <= 110; i += 10) {
        BobTwins[0].addGrade(i + 0.2);
        // addGrade(i+0.2)     add grades for BobTwins[0]
    }
    int igrade = 0;
    while (true) {
        double *d = BobTwins[0].gradePtr(igrade);    //pointer to double for BobTwins[0]
        if(d == NULL) break; // if d == NULL then break out of loop
        BobTwins[1].addGrade(*d - 0.5);  // addGrade(*d - 0.5)     add grades for BobTwins[1]
        ++igrade;                 // increment counter
    }

     Alice->print(); BobTwins[0].print(); BobTwins[1].print();// call print() for Alice and BobTwins
    highlow_avg_grade(Alice, BobTwins, 2);       // call functions
    highlow_top_grade(Alice, BobTwins, 2);
    
    delete Alice; delete [] BobTwins;// release memory as appropriate
    return 0;
}