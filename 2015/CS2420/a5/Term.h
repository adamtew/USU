#ifndef TERM_H
#define TERM_H

#include <algorithm>
#include <string>
#include <sstream>
#include <iomanip>
using  namespace std;

class Term
{ public:
  long int wt;
  string word;
  Term(string t="no word",long int w=0) : word(t), wt(w) {  };
  // { word = t;
  //   wt  = w;
  // }
  string toString() {
   stringstream ss;
   ss << "Wt:" << setw(10) << wt << " \t" << word <<endl;
   return ss.str();
  }


    friend ostream& operator<<(ostream& os, const Term& term)
    {
      os << term.word << " " << term.wt;
      return os;
    }

    Term & operator=(const Term & rhs)
  { 
    Term copy = rhs;
    swap( *this, copy );
    return *this;
  }
  bool operator<(Term & t2) { return wt < t2.wt; }
  bool operator>(Term & t2)
  {
    return wt > t2.wt;
  }
  bool operator==(Term & t2) { return wt == t2.wt; }


};

#endif