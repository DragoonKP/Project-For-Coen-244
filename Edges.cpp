//
//  Edges.cpp
//  Project.v03
//
//  Created by Kishanlal on 2017-03-23.
//  Copyright © 2017 Kishanlal. All rights reserved.
//

#include "Edges.hpp"

Edges :: Edges() {
    
}

Edges::Edges(string first,string second,string Weight) : My_Edges(make_pair(first,second)), Magnitude(Weight),value1("0"),value2("0") {}

Edges::Edges(string first, string second): My_Edges(make_pair(first,second)), Magnitude("0"),value1("0"),value2("0") {}
// using member initialization list

Edges :: Edges(Nodes& node1,Nodes& node2) {
    string a,b;
    a= node1.getID() ;
    b=node2.getID() ;
    
    value1 = node1.getValue() ;
    value2 = node2.getValue() ;
    
    My_Edges = make_pair(a, b) ;
    
    
}
Edges :: Edges (const Edges & Edge2) {
    //string a, b ;
   // cout << "Edges copy constructor"  << endl;
    this->My_Edges = make_pair (Edge2.My_Edges.first, Edge2.My_Edges.second );
    this->value1 = Edge2.value1 ;
    this->value2 = Edge2.value2  ;
    
}
// assign operator overload
const Edges& Edges :: operator=(const Edges& Edge2) {
    //cout << "assignment opperator "  << endl;
    My_Edges = make_pair(Edge2.getfirstNode(),Edge2.getSecondNode()) ;
    value1 = Edge2.value1 ;
    value2 = Edge2.value2 ;
    return *this ;
}
Edges :: ~Edges () {} ; 


void Edges :: setEdges(string value1, string value2,string value3) {
    My_Edges = make_pair(value1,value2) ;
    Magnitude= value3;
}
void Edges::setEdges(string value1 , string value2) {
    My_Edges = make_pair(value1, value2) ;
    Magnitude = "0" ;
}

string Edges :: getfirstNode() const{ // returns the first node of the edge
    return My_Edges.first ;
}
string Edges:: getSecondNode() const{
    return My_Edges.second ;
}
string Edges::getMagnitude() const {
    return Magnitude ;
}

string Edges::getValue1() const {
    return value1 ;
}
string Edges::getValue2() const{
    return value2 ; 
}
Nodes Edges::getNode1() const{
    
    Nodes N1(My_Edges.first,value1) ;
    return N1 ;
}
Nodes Edges::getNode2() const{
   const Nodes N2 (My_Edges.second,value2) ;
    return N2; 
}
ostream& operator<<(ostream& Output,const Edges& My_edge){
    Output<<"Edges : (" << My_edge.getfirstNode()<<","<< My_edge.getSecondNode()<<")" << endl;
    
   /* if(My_edge.Magnitude!="0") {
        Output << " with Magnitude " << My_edge.Magnitude << endl;
    } */
    return Output ;
}

istream& operator >> (istream & Input, Edges& MY_Edge) {
 //   Nodes N1 ;
    string a,b, c;
    cout << "enter the first node ID " << endl ;
    Input >> a ;
    
    
    cout << "Enter the second node ID " << endl;
    Input >> b ;
    

    
    MY_Edge.My_Edges = make_pair(a, b) ;
    
                            
                            
    
    return Input ;
}
