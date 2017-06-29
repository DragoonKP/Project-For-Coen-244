//
//  Edges.hpp
//  Project.v03
//
//  Created by Kishanlal on 2017-03-23.
//  Copyright © 2017 Kishanlal. All rights reserved.
//

#ifndef Edges_hpp
#define Edges_hpp
#include <iostream>
#include "Nodes.hpp"
#include <vector>
#include<string>
using std:: cout ; using std:: endl; using std::vector;
using std::istream ;using std::pair ; using std::string; using std::make_pair;


class Edges {
    private :
    pair <string,string> My_Edges ; // pass Nodes.ID for the first link to the second link (x,y)
    string Magnitude ; // weigth between the path .
    string value1 , value2 ; // values of the nodes in the edges
    //(x,y)
    
   // pair<Nodes,Nodes> My_edge ; I wanted to pass the objects nodes but for will pass the ID only
    public :
    Edges () ;
    Edges(string,string,string) ; // had the path + the weight
    Edges (string,string) ; // will need to convert this to nodes with values of 0 , if no id exist as nodes now have values // Edges (string ,string,stirng,string) 
    Edges (Nodes&,Nodes&) ; // id + value
    Edges (const Edges& ) ; // copy constructor
    ~Edges() ; // destuctor
    
    // Accessing functions :
    void setEdges( string, string,string) ;
    void setEdges(string, string) ; 

    string getfirstNode() const; // return id of the first node (Node1,Node2)
    string getSecondNode() const;
    string getMagnitude() const ;
    
    string getValue1() const ;
    string getValue2() const ;
    
    Nodes getNode1() const ;
    Nodes getNode2() const ;
    
    // operator overloading to make life simpler
    const Edges &operator=(const Edges&) ; // Operator overload assign
    //ostream overload
    
    friend ostream& operator<<(ostream& ,const Edges& ) ;
    friend istream& operator>>(istream&, Edges& ) ; // input edge

    
    
};
#endif /* Edges_hpp */
