//
//  Nodes.cpp
//  Project.v03
//
//  Created by Kishanlal on 2017-03-22.
//  Copyright © 2017 Kishanlal. All rights reserved.
//

#include "Nodes.hpp"

Nodes::Nodes (){}

Nodes::Nodes(string My_Id,string My_value) : Id(My_Id),value(My_value){
    //cout << "constructor called" ;
}
// using member initialization list.

Nodes::Nodes(string value1) : Id(value1),value("0"){} ;
// using member initialization list

Nodes::Nodes(const Nodes& My_node) {
    Id = My_node.Id;
    value = My_node.value ;
}
Nodes::~Nodes(){};


// Accesor and mutators

void Nodes:: setNodes (string My_Id,string My_value) { // canot use member initialization here because not a constructor
    Id = My_Id ;
    value = My_value ;
}

string Nodes::getID() const {
    return Id ;
}
string Nodes :: getValue() const {
    return value ;
}

// operator overloading
const Nodes& Nodes::operator=(const Nodes& My_node) {
    if(&My_node==this) { // avoid self assignment
        return *this ;
    }
    Id = My_node.Id ;
    value = My_node.value ;
    return *this ;
}
const Nodes& Nodes::operator=(const string& value) { // assign the value of the string to the id
  //  cout << "assigb string "<<endl;
    if(this->Id ==value) {return *this; } // check if id is the same if the same then returns as we already have it .
    Id= value ;
    this->value = "0" ; // set the value to 0 as only the id is given
    return *this ;
}

ostream& operator<<(ostream& Output , const Nodes & My_node) {
    Output<< "The node ID : " << My_node.getID() << " with Value: " << My_node.getValue() << endl;
    return Output ;
}

istream& operator>>(istream& Input, Nodes&  My_node) {
    cout << "enter id " << endl;
    Input >> My_node.Id ;
    
    cout << "enter the weight or value of the node " << endl;
    Input >> My_node.value ; 
    
    return Input ;
}


