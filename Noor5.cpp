//Aliem Noor
//Assignment 5 Implementation: My Ship Sails
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <vector>
using namespace std;

int myrandom (int i) { return std::rand()%i;}
int card_to_move(vector<string> input) {
int i =0; int j;
char suit = input.at(0).at(0);
	for (auto comparison : input){
		if (comparison.at(0) == suit){
			i++;}
		else{j=i;break;}
	}
	return j;
}

bool are_all_same_suit(vector<string> input){
	char suit = input.at(0).at(0);
	for (auto comparison : input){
		if (comparison.at(0) != suit) return false;}
		return true;
	}

int main(){
srand ( unsigned ( std::time(0) ) );
vector <string> myvector;
vector <string>all_cards;
vector <string>player_0;
vector <string>player_1;
vector <string>player_2;
vector <string>player_3;
vector <string>player_4;
string card[] = {"DA","DK","DQ","DJ","D2","D3","D4","D5","D6","D7","D8","D9","D10","HA","HK","HQ","HJ","H2","H3","H4","H5","H6","H7","H8","H9","H10","SA","SK","SQ","SJ","S2","S3","S4","S5","S6","S7","S8","S9","S10","CA","CK","CQ","CJ","C2","C3","C4","C5","C6","C7","C8","C9","C10"};
vector <string>cards(card, card + sizeof(card) / sizeof(string));
	for (int i=1; i<52; ++i) myvector.push_back(cards[i]);

	random_shuffle ( myvector.begin(), myvector.end() );
	random_shuffle ( myvector.begin(), myvector.end(), myrandom);

	for (std::vector<string>::iterator it=myvector.begin(); it!=myvector.end(); ++it){
		all_cards.push_back(*it);}
	for(int i=0;i<7;i++){
		player_0.push_back(all_cards[i]);
		player_1.push_back(all_cards[i+9]);
		player_2.push_back(all_cards[i+18]);
		player_3.push_back(all_cards[i+27]);
		player_4.push_back(all_cards[i+36]);}

string x,a,b,c,d,e,f,g,y;
a=player_0[0];b=player_0[1];c=player_0[2];d=player_0[3];e=player_0[4];f=player_0[5];g=player_0[6];
cout<<"player_0 (a)"<<a<<setw(5)<<"(b)"<<b<<setw(5)<<"(c)"<<c<<setw(5)<<"(d)"<<d<<setw(5)<<"(e)"<<e<<setw(5)<<"(f)"<<f<<setw(5)<<"(g)"<<g<<endl;

char choice;
	cout << "which one to replace ?"<<endl;

	while(cin >> choice){
		cout << "which one to replace ?"<<endl;
		char check;

		switch (choice){
		case 'a':
			player_1.push_back(player_0[0]);
			player_0.erase(player_0.begin());
			break;

		case 'b':
			player_1.push_back(player_0[1]);
			player_0.erase(player_0.begin()+1);
			break;

		case 'c':
			player_1.push_back(player_0[2]);
			player_0.erase(player_0.begin()+2);
			break;
		case 'd':
			player_1.push_back(player_0[3]);
			player_0.erase(player_0.begin()+3);
			break;

		case 'e':
			player_1.push_back(player_0[4]);
			player_0.erase(player_0.begin()+4);
			break;

		case 'f':
			player_1.push_back(player_0[5]);
			player_0.erase(player_0.begin()+5);
			break;

		case 'g':
			player_1.push_back(g);
			player_0.erase(player_0.begin()+6);
			break;

case '?':
cout<<"player_0 (a)"<<a<<setw(5)<<"(b)"<<b<<setw(5)<<"(c)"<<c<<setw(5)<<"(d)"<<d<<setw(5)<<"(e)"<<e<<setw(5)<<"(f)"<<f<<setw(5)<<"(g)"<<g<<endl;
cout<<"player_1 (a)"<<player_1[0]<<setw(5)<<"(b)"<<player_1[1]<<setw(5)<<"(c)"<<player_1[2]<<setw(5)<<"(d)"<<player_1[3]<<setw(5)<<"(e)"<<player_1[4]<<setw(5)<<"(f)"<<player_1[5]<<setw(5)<<"(g)"<<player_1[6]<<endl;
cout<<"player_2 (a)"<<player_2[0]<<setw(5)<<"(b)"<<player_2[1]<<setw(5)<<"(c)"<<player_2[2]<<setw(5)<<"(d)"<<player_2[3]<<setw(5)<<"(e)"<<player_2[4]<<setw(5)<<"(f)"<<player_2[5]<<setw(5)<<"(g)"<<player_2[6]<<endl;
cout<<"player_3 (a)"<<player_3[0]<<setw(5)<<"(b)"<<player_3[1]<<setw(5)<<"(c)"<<player_3[2]<<setw(5)<<"(d)"<<player_3[3]<<setw(5)<<"(e)"<<player_3[4]<<setw(5)<<"(f)"<<player_3[5]<<setw(5)<<"(g)"<<player_3[6]<<endl;
cout<<"player_4 (a)"<<player_4[0]<<setw(5)<<"(b)"<<player_4[1]<<setw(5)<<"(c)"<<player_4[2]<<setw(5)<<"(d)"<<player_4[3]<<setw(5)<<"(e)"<<player_4[4]<<setw(5)<<"(f)"<<player_4[5]<<setw(5)<<"(g)"<<player_4[6]<<endl;
cout << endl;
cout << "which one to replace ?"<<endl;
break;
default:
break;
}

		if(are_all_same_suit(player_0)==true){
			cout<<"player_0 wins"<<endl;
			break;}

		else if(are_all_same_suit(player_1)==true){
			cout<<"player_1 wins" <<endl;
			break;}

		else if(are_all_same_suit(player_2)==true){
			cout<<"player_2 wins" <<endl;
			break;}

		else if(are_all_same_suit(player_3)==true){
			cout<<"player_3 wins" <<endl;
			break;}

		else if(are_all_same_suit(player_4)==true){
			cout<<"player_4 wins" <<endl;
			break;}

		else{
			if(choice=='?'){continue;}
			if(are_all_same_suit(player_1)!=true){
				player_2.push_back(player_1[card_to_move(player_1)]);
				player_1.erase(player_1.begin()+(card_to_move(player_1)));}
			if(are_all_same_suit(player_2)!=true){
				player_3.push_back(player_2[card_to_move(player_2)]);
				player_2.erase(player_2.begin()+(card_to_move(player_2)));}

			if(are_all_same_suit(player_3)!=true){
				player_4.push_back(player_3[card_to_move(player_3)]);
				player_3.erase(player_3.begin()+(card_to_move(player_3)));}

			if(are_all_same_suit(player_4)!=true){
				player_0.push_back(player_4[card_to_move(player_4)]);
				player_4.erase(player_4.begin()+(card_to_move(player_4)));}
}
a=player_0[0];b=player_0[1];c=player_0[2];d=player_0[3];e=player_0[4];f=player_0[5];g=player_0[6];
cout << "(a)" << a << setw(5) << "(b)" << b << setw(5) << "(c)" << c << setw(5) << "(d)" << d << setw(5) << "(e)" << e << setw(5) << "(f)" << f<<setw(5)<<"(g)" << g << endl;
	}
}
