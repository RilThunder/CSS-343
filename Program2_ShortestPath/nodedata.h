#ifndef NODEDATA_H
#define NODEDATA_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// simple class containing one string to use for testing
// not necessary to comment further

class nodedata {
	friend ostream & operator<<(ostream &, const nodedata &);

public:
	nodedata();          // default constructor, data is set to an empty string
	~nodedata();
	nodedata(const string &);      // data is set equal to parameter
	nodedata(const nodedata &);    // copy constructor
	nodedata& operator=(const nodedata &);

	// set class data from data file
	// returns true if the data is set, false when bad data, i.e., is eof
	bool setData(ifstream &file);

	bool operator==(const nodedata &) const;
	bool operator!=(const nodedata &) const;
	bool operator<(const nodedata &) const;
	bool operator>(const nodedata &) const;
	bool operator<=(const nodedata &) const;
	bool operator>=(const nodedata &) const;

private:
	string data;
};

#endif
