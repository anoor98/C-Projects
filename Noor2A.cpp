#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> numbers;    //player guesses
vector<int> key;        //generated 4-digit numbers
int track = 0;
int bull = 0;
int cow = 0;
int const guess = 4;

int rand(int y){
    srand(y);
    srand((unsigned)time(0));
    int i = rand() % 6 + 1;
    cout << i << "\n";
    return i;
}

int input_check(int x){
    for(unsigned int i=0; i<numbers.size(); ++i){
        if(track>0 && x==numbers[i]){
        cout << "Same numbers are not allowed\n";
        }
    }
        if(x>9){cout << "Number less than 9";}
        numbers.push_back(x);
}

int win_game(int x){
    if(x==guess){
        cout<<"You got it right!!!\n";
    }
    return 0;
}

void check_(){
    if(numbers[track]==key[track]){
            bull += 1;}
        for(int i=0; i<guess; ++i){
            if(numbers[track]==key[i] && numbers[track]!=key[track]){
                cow += 1;}
        }
}

void end_guess(){
   if(track==guess && bull!=guess){
        cout<<"Bull = " << bull << "/t/tCow= " << cow << endl;
        numbers.erase (numbers.begin(),numbers.end()+0);
        cout << "Try again....\n";
        bull = 0;
        cow = 0;
        track = 0;
    }
}

int main(){

try{
    cout << "Please enter a number: ";
    int n = 0;
    cin >> n;
    rand(n);
    cout << "Enter 4 digits, Press Enter after each digit.\n";
    int inputs;
    while(numbers.size() < guess && cin >> inputs){
        input_check(inputs);
        int check_bull, cow();
        ++track;
        win_game(bull);
        end_guess();
        track++;}
    if(numbers.size()>guess){cout << "Only 4 Guess";}
}
catch(exception& e){
    cerr <<"error: " << e.what();}

}
