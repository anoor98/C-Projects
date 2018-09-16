//Aliem Noor
//Assignment 2B
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

int randInt(int a, int b){
    return (rand() % b + a);}

int main() {
    srand(time(0));
    int score = 1000;
    string randString, enteredString;

    while (true) {
        int count = 0, totalOffset = 0, offSet, totalPenalty = 0;
        cout << "\nYour current points: " << score << " , just type -> ";

        for (int a = 0; a < 5; ++a) {
            if ((rand() % 10 + 1) <= 2) {
                if ((rand() % 2 + 1) == 1) {
                    randString[a] = randInt(48, 10);                    //Numbers from 0-9
                    cout << randString[a];}
                  else {
                    randString[a] = randInt(33, 15);                    //Non-alphanumeric characters
                    cout << randString[a];}
            }
              else {
                if ((rand() % 2 + 1) == 1) {
                    randString[a] = randInt(65, 26);                    //Capital letters
                    cout << randString[a];}
                  else {
                    randString[a] = randInt(97, 26);                    //Lowercase letters
                    cout << randString[a];}
            }
        }

        auto startTimer = chrono::steady_clock::now();
        cout << ": "; cin >> enteredString;
        auto endTimer = chrono::steady_clock::now();

        for (int b = 0; b < 5; ++b){
            if (enteredString[b] == randString[b]){
                count++;}
            else {
                offSet = enteredString[b] - randString[b];
                totalOffset += abs(offSet);}
        }

        auto diffTimer = endTimer - startTimer;
        auto timeElapsed = chrono::duration_cast<chrono::milliseconds>(diffTimer).count();
        cout << timeElapsed << " milliseconds, ";

        if (timeElapsed <= 10000){
            cout << "you made it within the interval of 10000...";}
        else cout << "you *failed* it within the interval of 10000...";

        if (timeElapsed <= 10000 && count == 5){
            totalPenalty += 500;
            score += totalPenalty;}
          else if (timeElapsed <= 10000 && count < 5){
            totalPenalty -= totalOffset;
            score += totalPenalty;}
          else if (timeElapsed > 10000 && count == 5){                                  //Calculates penalty
            totalPenalty -= (timeElapsed - 10000);
            score += totalPenalty;}
          else if (timeElapsed > 10000 && count < 5){
            totalPenalty -= (timeElapsed - 10000);
            totalPenalty -= totalOffset;
            score += totalPenalty;}
          else cout << "Something's wrong.";

        if (count < 5){
            cout << "\nString offset is " << totalOffset << ", ";
            cout << "Your total penalty is " << abs(totalPenalty) << "...";}

        int playerPoints;
        if (score <= 0 || score >= 5000) break;
    }
    cout << "\nYour points: " << score << endl;
    cout << (score >= 5000 ? "You won!" : "You lost!");

    return 0;
}
