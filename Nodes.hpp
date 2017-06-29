//
//  Nodes.hpp
//  Project.v03
//
//  Created by Kishanlal on 2017-03-22.
//  Copyright © 2017 Kishanlal. All rights reserved.
//

#ifndef Nodes_hpp
#define Nodes_hpp
#include<iostream>
#include <vector> 
#include<string>

using std::string; using std::vector; using std::cout ; using std::endl;
using std::ostream ;using std::istream;

class Nodes {
    private :
    string Id ; // the location of the Node
    string value; // the weight or how much is the node worth
    
    // contains ID and value .
    public :
    
    Nodes() ; // empty nodes.
    Nodes(string,string) ; // id , value
    Nodes(string) ; // nodes with only an id no values ;
    Nodes( const Nodes& ) ; // copy constructor
    ~Nodes () ;
    
    void setNodes(string,string) ; // set nodes with ID and value
    
    // Accessor of the Node class ;
    string getID () const ; // return the ID of the
    string getValue() const ; // return the value of the node
    //    const Edges &operator=(const Edges&) ; // Operator overload assign

    const Nodes& operator=(const Nodes&) ;
    const Nodes& operator=( const string &) ; // only Id no value ; no const because the value of the string can change
    
  
    friend std::ostream& operator<<(std::ostream& , const Nodes& ) ;
    friend istream& operator>>(istream&, Nodes& ) ; // input edge

   //void operator =(string&) ; // void operator=(const Nodes&) ;
   // bool overload to check if the nodes are the same in id and value ,
  //

};



#endif /* Nodes_hpp */
