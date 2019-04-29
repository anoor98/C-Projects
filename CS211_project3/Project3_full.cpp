//#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <ctime>
#include <chrono>
#include <cmath>
#include <map>
using namespace std;

class Name;
class Message;
class EmailAccount;
class Drafts;
class BaseFolder;
class Inbox;
class Outbox;
class ISP;


/*Vector Template*/
template<typename T>
class Vec {
public:
	Vec();
	Vec(int n);
	Vec(int n, const T &a);

	Vec(const Vec &orig);
	Vec& operator= (const Vec &rhs);
	~Vec();

	int capacity() const { return _capacity; }       // inline
	int size() const { return _size; }           // inline

	T front() const;
	T back() const;

	void clear();
	void pop_back();
	void push_back(const T &a);

	T& at(int n);

	T& operator[] (int n);
	const T& operator[] (int n) const;

	void erase(int n);

private:
	void allocate();
	void release();
	int _capacity;
	int _size;
	T * _vec;
}; //Everything Non-Inline

template<typename T>
Vec<T>::Vec() : _capacity(0), _size(0), _vec(NULL) {}

template<typename T>
Vec<T>::Vec(int n) {
	if (n <= 0) {
		_capacity = 0;
		_size = 0;
		_vec = NULL;
	}
	else {
		_capacity = n;
		_size = n;
		allocate();//call allocate
	}
}

template<typename T>
Vec<T>::Vec(int n, const T&a) {
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

template<typename T>
Vec<T>::Vec(const Vec &orig) {
	_capacity = orig._size;
	_size = orig._size;
	allocate();
	for (int i = 0; i < _size; ++i) {
		_vec[i] = orig._vec[i];
	}
}

template<typename T>
Vec<T>& Vec<T>::operator = (const Vec<T> &rhs) {
	if (this == &rhs) return *this;
	_capacity = rhs._size;
	_size = rhs._size;
	release(); allocate();
	for (int i = 0; i < _size; ++i) {
		_vec[i] = rhs._vec[i];
	}
	return *this;
}

template<typename T>
Vec<T>::~Vec() { release(); }

template<typename T>
T Vec<T>::front() const {
	if (_size <= 0) {
		T default_obj;
		return default_obj;
	}
	else return _vec[0];
}

template<typename T>
T Vec<T>::back() const {
	if (_size <= 0) {
		T default_obj;
		return default_obj;
	}
	else return _vec[_size - 1];
}

template<typename T>
void Vec<T>::clear() { _size = 0; }

template<typename T>
void Vec<T>::pop_back() {
	if (_size > 0) _size--;
}

template<typename T>
void Vec<T>::push_back(const T &a) {
	if (_size < _capacity) {
		_vec[_size] = a;
		++_size;
	}
	else {
		if (_capacity == 0) _capacity = 1;
		else _capacity *= 2;
		T* oldvec = _vec;
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

template<typename T>
T& Vec<T>::at(int n) {
	if (n >= 0 && n < _size) return _vec[n];
	if (n < 0 || n >= _size) {
		T *pnull = NULL;
		return *pnull;
	}
}

template<typename T>
T& Vec<T>::operator[] (int n) { return at(n); }

template<typename T>
const T& Vec<T>::operator[] (int n) const {
	if (n >= 0 && n < _size) return _vec[n];
	if (n < 0 || n >= _size) {
		T *pnull = NULL;
		return *pnull;
	}
}

template<typename T>
void Vec<T>::release()
{
	if (_vec != NULL) {
		delete[] _vec;
	}
	_vec = NULL;
}

template<typename T>
void Vec<T>::allocate()
{
	if (_capacity > 0)
		_vec = new T[_capacity];
	else
		_vec = NULL;
}

template<typename T>
void Vec<T>::erase(int n) {
	for (int i = n; i < _size - 1; ++i) {
		_vec[i] = _vec[i + 1];
	}
	--_size;
}


//////////////////////*Class Declarations*//////////////////////////

/*class Name*/

class Name {
public:
	Name() {}
	Name(string s);
	void set(string s);                           // mutator
	string name() const;         // accessor
	string address() const;   // accessor
private:
	string _name;
	string _address;
};

/*class Message*/

class Message {
public:
	Message(string f);
	Message(string f, string t);
	Message(string f, string t, string s);
	Message(string f, string t, string s, string txt);

	const Name& from() const;
	const Name& to() const;
	string subject() const;
	string text()    const;

	string date()    const;                          // see below
	void send();                                     // see below

	void setRecipient(string t);
	void setSubject(string s);
	void setText(string txt);

	void prependText(string t);                      // see Message1 class
	void appendText(string t);                       // see Message1 class
	void print() const;                              // see Message1 class

private:
	void setDate();                                  // see below

	Name _from;                                      // use "Name" class
	Name _to;                                        // use "Name" class
	string _subject;
	string _text;
	time_t _date;                                    // see below
};

/*class BaseFolder*/

class BaseFolder {
public:
	int size() const;
	virtual ~BaseFolder();

	void display() const;
	void erase(int n);
	void forward(int n) const;
	void print(int n) const;
	void receive(const Message *m);

	void reply(int n) const;
protected:
	BaseFolder(EmailAccount *ac);
	virtual string type() const = 0;                         // pure virtual if desired
	virtual const Name& tofrom(const Message *m) const = 0;  // pure virtual if desired
															 // data
	Vec<const Message*> _msg;
	EmailAccount *_ac;

private:
	BaseFolder(const BaseFolder &orig);
	BaseFolder & operator= (const BaseFolder &rhs);
};

/*class Inbox*/

class Inbox : public BaseFolder {
public:
	Inbox(EmailAccount *ac);                     // public constructor
protected:
	virtual string type() const;                           // override
	virtual const Name& tofrom(const Message *m) const;    // override
};

/*class Outbox*/

class Outbox : public BaseFolder {
public:
	Outbox(EmailAccount *ac);                    // public constructor
protected:
	virtual string type() const;                           // override
	virtual const Name& tofrom(const Message *m) const;    // override
};

/*class Drafts*/

class Drafts {
public:
	Drafts(EmailAccount *ac);
	~Drafts();

	void display() const;
	void send(int n);
	void erase(int n);

	Message* addDraft();
	Message* addDraft(Message *m);
	Message* getDraft(int n);
	Message* operator[](int n);

private:
	Drafts(const Drafts &orig);
	Drafts & operator= (const Drafts &rhs);
	int newKey();

	// data
	int _newKey;
	map<int, Message*> _drafts;
	EmailAccount *_ac;
};

/*class EmailAccount*/

class EmailAccount {
public:
	EmailAccount(string s);
	~EmailAccount();

	const Name& owner() const;  // accessor
	Drafts& drafts();        // accessor/mutator
	BaseFolder& in();            // accessor/mutator
	BaseFolder& out();           // accessor/mutator

	void send(Message *m);
	void receive(Message *m);
	void insert(Message *m);

private:
	EmailAccount(const EmailAccount &orig);
	EmailAccount & operator= (const EmailAccount &rhs);

	Name _owner;
	Drafts * _drafts;
	BaseFolder  * _in;
	BaseFolder * _out;
};

/*class ISP*/

class ISP {
public:
	static void addAccount(EmailAccount *e);
	static void send(Message *m);
private:
	ISP();
	static map<Name, EmailAccount*> _accounts;
};

//////////////////////*Non-Inline Class Definitions*//////////////////////////

/*class Name non-inline definitions*/

Name::Name(string s) { set(s); }

void Name::set(string s) {
	const string _domain = "@qc.cuny.edu";
	istringstream iss(s);
	iss >> _name;

	if (_name.size() == 0) _address = " ";
	else {
		_address = _name + _domain;
		for (int i = 0; i < _address.size(); ++i) {
			_address[i] = tolower(_address[i]);
		}
	}
}

string Name::name() const { return _name; }         // accessor
string Name::address() const { return _address; }   // accessor

bool operator== (const Name &n1, const Name &n2) {
	return n1.address() == n2.address();
}

bool operator< (const Name &n1, const Name &n2) {
	return n1.address() < n2.address();
}

/*class Message non-inline definitions*/

Message::Message(string f) {
	_from.set(f);     // set sender ("from") using addDomain
	_date = 0;
}

Message::Message(string f, string t) {
	_from.set(f);
	_to.set(t);
	_date = 0;
}

Message::Message(string f, string t, string s) {
	_subject = s;
	_from.set(f);
	_to.set(t);
	_date = 0;
}

Message::Message(string f, string t, string s, string txt) {
	_text = txt;
	_subject = s;
	_from.set(f);
	_to.set(t);
	_date = 0;
}

const Name& Message::from() const { return _from; }
const Name& Message::to() const { return _to; }
string Message::subject() const { return _subject; }
string Message::text()    const { return _text; }

void Message::print() const {
	cout << "From: " << _from.name() << "    <" << _from.address() << ">" << endl;
	cout << "To:   " << _to.name() << "    <" << _to.address() << ">" << endl;
	cout << "Subject: " << _subject << endl;
	cout << "Date: " << date() << endl;
	cout << _text << endl;
	cout << endl;
}

void Message::send() { setDate(); };

void Message::setDate() {
	auto t_now = chrono::system_clock::now();
	_date = chrono::system_clock::to_time_t(t_now);
}

void Message::setRecipient(string t) { _to.set(t); }
void Message::setSubject(string s) { _subject = s; }
void Message::setText(string txt) { _text = txt; }

string Message::date() const {
	if (_date > 0)
		return ctime(&_date);   // possible compiler warning or error
	else
		return "";
}

void Message::prependText(string t) { _text = (t + " " + _text); }
void Message::appendText(string t) { _text += " " + t; }

/*class BaseFolder non-inline definitions*/

int BaseFolder::size() const { return _msg.size(); }
BaseFolder::~BaseFolder() {
	for (int i = 0; i < _msg.size(); i++) {
		delete _msg[i];
	}
}

void BaseFolder::display() const {
	cout << _ac->owner().name() << "  " << type() << endl;
	if (_msg.size() <= 1) cout << "No messages to display" << endl;
	for (int i = 1; i < _msg.size(); ++i) {
		const Name &tmp = tofrom(_msg[i]);
		cout << i << endl;
		cout << tmp.name() << endl;
		cout << _msg[i]->subject() << endl;
	}
}

void BaseFolder::erase(int n) {
	if (n >= 1 && n < _msg.size()) {
		delete _msg[n];
		_msg.erase(n);
	}
}

void BaseFolder::forward(int n) const {
	if (n >= 1 && n < _msg.size()) {
		const Message *m = _msg[n];
		string fwd_subject = "Fwd:  " + m->subject();
		Message *ptr = new Message(_ac->owner().name(), "", fwd_subject, m->text());
		_ac->insert(ptr);
	}
	else;
}

void BaseFolder::print(int n) const {
	if (n >= 1 && n < _msg.size()) {
		_msg[n]->print();
	}
	else;
}

void BaseFolder::receive(const Message *m) {
	_msg.push_back(m);
}

void BaseFolder::reply(int n) const {
	if (n >= 1 && n < _msg.size()) {
		const Message *m = _msg[n];
		string subject = "Re:  " + m->subject();
		const Name& tmp = tofrom(m);
		Message *ptr = new Message(_ac->owner().name(), tmp.name(), subject, m->text());
		_ac->insert(ptr);
	}
	else;
}

BaseFolder::BaseFolder(EmailAccount *ac) : _ac(ac) {
	_msg.push_back(NULL);
}

BaseFolder::BaseFolder(const BaseFolder &orig) {}
BaseFolder& BaseFolder::operator= (const BaseFolder &rhs) {
	return *this;
}

/*class Inbox non-inline definitions*/

Inbox::Inbox(EmailAccount *ac) : BaseFolder(ac) {}

string Inbox::type() const { return "inbox"; }
const Name& Inbox::tofrom(const Message *m) const { return m->from(); }

/*class Outbox non-inline definitions*/

Outbox::Outbox(EmailAccount *ac) : BaseFolder(ac) {}

string Outbox::type() const { return "inbox"; }                           // override
const Name& Outbox::tofrom(const Message *m) const { return m->from(); }

/*class Drafts non-inline definitions*/

void Drafts::erase(int n) {
	delete _drafts[n];
	_drafts.erase(n);
}

Drafts::Drafts(EmailAccount *ac) {
	_ac = ac;
	_newKey = 0;
	_drafts[0] = NULL;
}

Drafts::~Drafts() {
	map<int, Message*>::iterator m_it;
	for (m_it = _drafts.begin(); m_it != _drafts.end(); ++m_it) {
		delete m_it->second;
	}
}

int Drafts::newKey() { return ++_newKey; }
/*_newKey cannot be static because it is being modified and it attached to an object.*/


Message* Drafts::addDraft() {
	int key = newKey();
	Message *ptr = new Message(_ac->owner().name());
	_drafts[key] = ptr;
	return ptr;
}

Message* Drafts::addDraft(Message *m) {
	int key = newKey();
	_drafts[key] = m;
	return m;
}

void Drafts::display() const {
	//map<int, Message*>::const_iterator mit;
	cout << _ac->owner().name() << " drafts: " << endl;
	if (_drafts.size() <= 1) {
		cout << "No messages to display" << endl;
	}
	else {
		map<int, Message*>::const_iterator mit;
		for (mit = _drafts.begin(); mit != _drafts.end(); ++mit) {
			if (mit->first == 0) continue;
			Message *ptr = mit->second;  // ptr = ...
			cout << mit->first << endl; // print  i,   ptr->to().name(),   ptr->subject()
			cout << ptr->to().name() << endl;
			cout << ptr->subject();
		}
	}
}

void Drafts::send(int n) {
	Message *ptr = _drafts[n];
	if (ptr == NULL) cout << "Message not found." << endl;
	else if (ptr->to().address() == "") {
		cout << "You must specify a recipient" << endl;
	}
	else {
		ptr->send();
		_drafts.erase(n);
		_ac->send(ptr);
	}
}

Message* Drafts::getDraft(int n) { return _drafts[n]; }
Message* Drafts::operator[](int n) { return _drafts[n]; }

Drafts::Drafts(const Drafts &orig) {}
Drafts & Drafts::operator= (const Drafts &rhs) {
	return *this;
}

/*class EmailAccount non-inline definitions*/

EmailAccount::EmailAccount(string s) {
	_owner.set(s);
	_drafts = new Drafts(this);
	_in = new Inbox(this);
	_out = new Outbox(this);
	ISP::addAccount(this);
}

EmailAccount::~EmailAccount() {
	delete _drafts;
	delete _in;
	delete _out;
}

const Name& EmailAccount::owner() const { return _owner; }  // accessor
Drafts& EmailAccount::drafts() { return *_drafts; }        // accessor/mutator
BaseFolder& EmailAccount::in() { return *_in; }            // accessor/mutator
BaseFolder& EmailAccount::out() { return *_out; }           // accessor/mutator

void EmailAccount::receive(Message *m) { receive(m); }

void EmailAccount::insert(Message *m) { _drafts->addDraft(m); }

void EmailAccount::send(Message *m) {
	_out->receive(m);
	ISP::send(m);
}

EmailAccount::EmailAccount(const EmailAccount &orig) {}
EmailAccount & EmailAccount::operator= (const EmailAccount &rhs) {
	return *this;
}

/*class ISP non-inline definitions*/

map<Name, EmailAccount*> ISP::_accounts;

void ISP::addAccount(EmailAccount *e) {
	_accounts[e->owner()] = e;
}

void ISP::send(Message *m) {
	EmailAccount *ac = _accounts[m->to()];
	if (ac == NULL) {
		cout << "Delivery failed, to recipient: " << m->to().name() << endl;
		return;
	}
	else {
		Message tmp = *m;
		Message *clone = new Message(tmp);
		ac->receive(clone);
	}
}

ISP::ISP() {}


int main() {
	

	//system("pause");
	return 0;
}