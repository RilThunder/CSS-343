#include "nodedata.h"

//------------------- constructors/destructor  -------------------------------
nodedata::nodedata() { data = ""; }                         // default

nodedata::~nodedata() 
{ 


}            // needed so strings are deleted properly

nodedata::nodedata(const nodedata& nd) { data = nd.data; }  // copy

nodedata::nodedata(const string& s) { data = s; }    // cast string to NodeData

//------------------------- operator= ----------------------------------------
nodedata& nodedata::operator=(const nodedata& rhs) {
	if (this != &rhs) {
		data = rhs.data;
	}
	return *this;
}

//------------------------- operator==,!= ------------------------------------
bool nodedata::operator==(const nodedata& rhs) const {
	return data == rhs.data;
}

bool nodedata::operator!=(const nodedata& rhs) const {
	return data != rhs.data;
}

//------------------------ operator<,>,<=,>= ---------------------------------
bool nodedata::operator<(const nodedata& rhs) const {
	return data < rhs.data;
}

bool nodedata::operator>(const nodedata& rhs) const {
	return data > rhs.data;
}

bool nodedata::operator<=(const nodedata& rhs) const {
	return data <= rhs.data;
}

bool nodedata::operator>=(const nodedata& rhs) const {
	return data >= rhs.data;
}

//------------------------------ setData -------------------------------------
// returns true if the data is set, false when bad data, i.e., is eof

bool nodedata::setData(ifstream &file) {
	getline(file, data);
	return true; 
}

//-------------------------- operator<< --------------------------------------
ostream& operator<<(ostream& output, const nodedata& nd) {
	output << nd.data;
	return output;
}
