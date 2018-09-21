//#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using namespace std;

class Message1 {
public:
	Message1();
	Message1(string f);
	Message1(string f, string t);
	Message1(string f, string t, string s);
	Message1(string f, string t, string s, string txt);

	string from()       const;
	string to()         const;
	string subject()    const;
	string text()       const;
	string date()       const;

	void setFrom(string f);
	void setRecipient(string t);
	void setSubject(string s);
	void setText(string txt);
	void prependText(string t);
	void appendText(string t);
	void print() const;

private:
	string addDomain(string s);

	string _from;
	string _to;
	string _subject;
	string _text;
	int _date;

};

//Q1.2
string Message1::from() const { return _from; }
string Message1::to() const { return _to; }
string Message1::subject() const { return _subject; }
string Message1::text() const { return _text; }
string Message1::date() const { return string("n/a"); }

//Q1.3
void Message1::print() const {
	cout << "From: "	<< _from << endl;
	cout << "To: "		<< _to << endl;
	cout << "Subject: " << _subject << endl;
	cout << "Date: "	<< date() << endl;
	cout << "Text: "	<< _text << endl;
	cout << endl;
}

//Q1.4
//void Message1::setFrom(string f) { _from = f; }
void Message1::setSubject(string s) { _subject = s; }
void Message1::setText(string txt) { _text = txt; }
void Message1::prependText(string t) { _text = (t + " " + _text); }
void Message1::appendText(string t) { _text += " " + t; }

//Q1.5
void Message1::setRecipient(string t) { _to = addDomain(t); }
void Message1::setFrom(string f) { _from = addDomain(f); }

//Q1.6
string Message1::addDomain(string s) {
	const string _domain = "@qc.cuny.edu";
	istringstream iss(s);
	iss >> s;
	return s + _domain;
	// ^ removes leading & trailing blank spaces & adds "domain" to end of "s" & returns concatenated string
}

//Q1.7
Message1::Message1() { _date = 0; };
Message1::Message1(string f) {
	_from = addDomain(f);     // set sender ("from") using addDomain
	_date = 0;
}

Message1::Message1(string f, string t) {
	_from = addDomain(f);
	_to = addDomain(t);
	_date = 0;
}

Message1::Message1(string f, string t, string s) {
	_subject = s;
	_from = addDomain(f);
	_to = addDomain(t);
	_date = 0;
}

Message1::Message1(string f, string t, string s, string txt) {
	_text = txt;
	_subject = s;
	_from = addDomain(f);
	_to = addDomain(t);
	_date = 0;
}

//Q1.11
ostream& operator << (ostream& os, const Message1 &m) {
	os << "From: " << m.from() << endl;
	os << "To:   " << m.to() << endl;
	os << "Subject: " << m.subject() << endl;
	os << "Date: " << m.date() << endl;
	os << m.text() << endl;
	os << endl;
	return os;
}

//Q2
class Vec_Message1 {
public:
	Vec_Message1();
	Vec_Message1(int n);
	Vec_Message1(int n, const Message1 &a);

	Vec_Message1(const Vec_Message1 &orig);
	Vec_Message1& operator= (const Vec_Message1 &rhs);
	~Vec_Message1();

	int capacity() const { return _capacity; }
	int size() const { return _size; }

	Message1 front() const;
	Message1 back() const;

	void clear();
	void pop_back();
	void push_back(const Message1 &a);

	Message1& at(int n);
	Message1& operator[] (int n);
	const Message1& operator[] (int n) const;

private:
	void allocate();
	void release();

	int _capacity;
	int _size;
	Message1 * _vec;
};

//Q2.1
void Vec_Message1::allocate() {
	if (_capacity <= 0) _vec = NULL;
	else _vec = new Message1[_capacity];
}

void Vec_Message1::release() {
	if (_vec = NULL) { return; }
	else {
		delete[] _vec;
		_vec = NULL;
	}
}

//Q2.3
Vec_Message1::Vec_Message1() : _capacity(0), _size(0), _vec(0) {}

Vec_Message1::Vec_Message1(int n) {
	if (n <= 0) {
		_capacity = 0;
		_size = 0;
		_vec = NULL;
	}
	else {
		_capacity = n;
		_size = n;
		allocate();
	}
}

Vec_Message1::Vec_Message1(int n, const Message1 &a) {
	if (n <= 0) {
		_capacity = 0;
		_size = 0;
		_vec = NULL;
	}
	else {
		_capacity = n;
		_size = n;
		allocate();
		for (int i = 0; i < _capacity; ++i) {
			_vec[i] = a;
		}
	}
}

Vec_Message1::Vec_Message1(const Vec_Message1 &orig) {
	_capacity = orig._size;
	_size = orig._size;
	allocate();
	for (int i = 0; i < _size; ++i) {
		_vec[i] = orig._vec[i];
	}
}

Vec_Message1& Vec_Message1::operator = (const Vec_Message1 &rhs) {
	if (this == &rhs) return *this;
	_capacity = rhs._size;
	_size = rhs._size;
	release(); allocate();
	for (int i = 0; i < _size; ++i) {
		_vec[i] = rhs._vec[i];
	}
	return *this;
}

Vec_Message1::~Vec_Message1() { release(); }

//Q2.4
void Vec_Message1::clear() { _size = 0; }

void Vec_Message1::pop_back() {
	if (_size > 0) _size--;
}

Message1 Vec_Message1::front() const {
	if (_size <= 0) {
		Message1 default_obj;
		return default_obj;
	}
	else return _vec[0];
}

Message1 Vec_Message1::back() const {
	if (_size <= 0) {
		Message1 default_obj;
		return default_obj;
	}
	else return _vec[_size - 1];
}

//Q2.7
void Vec_Message1::push_back(const Message1 &a) {
	if (_size < _capacity) {
		_vec[_size] = a;
		++_size;
	}
	else {
		if (_capacity == 0) _capacity = 1;
		else _capacity *= 2;
		Message1* oldvec = _vec;
		allocate();
		if (oldvec != NULL) {
			for (int i = 0; i < _size; ++i)
				_vec[i] = oldvec[i];
		}
		delete[] oldvec;
		_vec[_size] = a;
		++_size;
	}
}

//Q2.8
Message1& Vec_Message1::at(int n) {
	if (n >= 0 && n < _size) return _vec[n];
	if (n < 0 || n >= _size) {
		Message1 *pnull = NULL;
		return *pnull;
	}
}

Message1& Vec_Message1::operator[] (int n) {
	return at(n);
}

const Message1& Vec_Message1::operator[] (int n) const {
	if (n >= 0 && n < _size) return _vec[n];
	if (n < 0 || n >= _size) {
		Message1 *pnull = NULL;
		return *pnull;
	}
}

void reverse(Vec_Message1 &v) { // input is reference
	int n = v.size();
	Message1 temp;
	if (n <= 1) return;
	for (int i = 0; i < n / 2; ++i) {
		temp = v.at(i);
		v.at(i) = v.at(n - i - 1);
		v.at(n - i - 1) = temp;
	}
}

void print(ostream &os, const Vec_Message1 &v) { // input is const reference
	for (int i = 0; i < v.size(); ++i) {
		os << v[i] << "  ";
	}
	os << endl;
}

int main() {
	cout << "It compiles!" << endl;

	Message1 a, c;
	a.setSubject("Project #2"); 
	a.setText("This is just a test of the code :^D");
	a.setRecipient(" Professor1"); a.setFrom(" Student1 ");
	a.print();
	cout << endl;
	a.prependText("Will this work???");
	a.appendText("Absolute MadLads! :0");
	cout << a.text() << endl;
	//a.print();
	cout << a;

	Message1 b(a);
	b.print();
	/*
	b.setSubject("Project #2");
	b.setText("Anotha One");
	b.setRecipient(" Professor2"); b.setFrom(" Student2 ");
	b.print();
	cout << endl;

	c.setSubject("Project #2");
	c.setText("And Anotha One");
	c.setRecipient(" Professor3"); c.setFrom(" Student3 ");
	c.print();
	cout << endl;

	Vec_Message1 Messages;
	Messages.push_back(a); Messages.push_back(b); Messages.push_back(c);
	cout << Messages.at(1);
	cout << Messages.front(); 
	cout << Messages.back();

	reverse(Messages);
	cout << Messages.front();
	cout << Messages.back();
	print(cout, Messages);

	a = a = b;
	a = b = a;
	Message1 d(Message1(Message1(a)));  // oh yes
	//cout << b; cout << a;
	*/

	//system("pause");
	return 0;
}