//
//  Graphs.cpp
//  project1_v.01
//
//  Created by Kishanlal on 2017-02-21.
//  Copyright © 2017 Kishanlal. All rights reserved.
//
#include "Graphs.hpp"



Graph :: Graph () {
    cout << "Empty graph created " << endl ;
}
Graph :: Graph(Nodes firstnode,Edges firstEdge){
    All_Nodes.push_back(firstnode) ;
    All_Edges.push_back(firstEdge) ;
    ConvertEdge(firstEdge) ; // convert the edge into nodes
    
    cout << "Graphs with node and edge created " << endl ;
}

Graph :: Graph(vector<Nodes> MultiNodes, vector<Edges> MultiEdges):All_Nodes(MultiNodes),All_Edges(MultiEdges) {
    for(int i = 0 ;i < MultiEdges.size() ; i++) {
        ConvertEdge(MultiEdges[i]) ;
    }// convert it to keep the values of the edges.
    AvoidDuplicate() ; // avoid any duplicates while constructing the graph
 //   cout <<"Multi nodes/edges graph created " << endl ;  // to do the failure
}

Graph::Graph(const Graph& My_graph) {
    All_Edges = My_graph.All_Edges ;
    All_Nodes = My_graph.All_Nodes ;
   // ConvertEdge() ;
    for(int i = 0 ;i < All_Edges.size() ; i++) {
        ConvertEdge(All_Edges[i]) ;
    } // convert it to keep the values of the nods.
    AvoidDuplicate() ;
}
Graph :: ~Graph () {
    All_Edges.clear() ;
    All_Nodes.clear() ;
}

void Graph::operator=(const Graph& My_graph ){
    All_Edges = My_graph.All_Edges ;
    All_Nodes = My_graph.All_Nodes ;
    for(int i = 0 ; i < All_Edges.size();i++){
    ConvertEdge(All_Edges[i]) ;
    }
    AvoidDuplicate() ;
}


// Accesing functions :

vector<Nodes> Graph:: getNodes() const {
    return All_Nodes ;
}

vector<Edges> Graph::getEdges() const {
    return All_Edges ; 
}

void Graph:: setNodes(vector<Nodes>& The_Nodes) {
    All_Nodes = The_Nodes ;
    AvoidDuplicate() ;
}


//  bool function to verify if the node or edge was already added . usefull for to reuse the code for other purposes as well
bool Graph::CheckIdNode(const Nodes& TheNode) {
    for (int i = 0 ; i < All_Nodes.size() ; i++) {
        if(All_Nodes.at(i).getID() == TheNode.getID()) {
            return true ;
        }
    }
    return false ;
}

bool Graph:: CheckIDNode( string value) { // pass the id to verify if a node already exist before adding
    for (int i = 0 ; i < All_Nodes.size() ; i++ ) { // this is done to try and avoid as many duplicate as possible should avoid all of them but i already have a avoid duplicate function so will add it .
        if(All_Nodes.at(i).getID() == value){
            return true ;
        }
    }
    return false ;
}

// check the edges of the graph
bool Graph:: checkEdges(const Edges & The_Edge) {
    for (int i = 0 ; i < All_Edges.size() ; i++) {
        if(All_Edges.at(i).getfirstNode()==The_Edge.getfirstNode() && All_Edges.at(i).getSecondNode() == The_Edge.getSecondNode()) {
            return true;
        }
    }
    return false ;
}

bool Graph:: checkEdges(const string value1, const string value2) {
    for ( int i = 0 ; i < All_Edges.size() ; i++) {
        if( All_Edges.at(i).getfirstNode() == value1 && All_Edges.at(i).getSecondNode() == value2) {
            //cout << "Already exist" << endl ; for testing
            return true ;
        }
    }
    return false ;
}

// Add and remove Nodes from a graph

void Graph:: AddNode(Nodes& My_node) { // pass the actual object
    if(CheckIDNode(My_node.getID()) == false ) { // avoid pushing a already exisitng node
    All_Nodes.push_back(My_node) ;
    }
       else {
           cout << "the id of that node already exists " << endl ;
       }
    //AvoidDuplicate() ; // from my proposition i had this not required because of bool
}// If we want to add a node we check if the node already exist and then add it if it doesn't

void Graph :: AddNode(string value1, string value2) {
    Nodes N1(value1,value2) ; // create an object for node
    if(CheckIDNode(value1) == false) { // avoid pushing a already exisiting nodes
    All_Nodes.push_back(N1) ; // add the object to the vectors of nodes.
}
   // AvoidDuplicate() ;
}

void Graph:: RemoveNode(Nodes& the_Node) {
    string a,b ;
    for (int i = 0 ; i < All_Nodes.size() ; i++ ) {
        if( All_Nodes.at(i).getID() == the_Node.getID() ) {
            // erase element at index i
            All_Nodes.erase(All_Nodes.begin() + i) ;
            
        }
    }
   // cout << "No node found to remove" << endl;
    // need to remove the edges connected to that node
    
    for (int j = 0; j<All_Edges.size() ; j++) {
        a= All_Edges.at(j).getfirstNode() ;
        b=All_Edges.at(j).getSecondNode() ;

        if(a== the_Node.getID() || b==the_Node.getID()) {
            All_Edges.erase(All_Edges.begin() +j) ;
            j = j-1 ; // goes back one index to keep increment
        }
    }
}

void Graph::RemoveNode(string the_ID) {
    string a,b ;
    for (int i = 0 ; i < All_Nodes.size() ; i++ ) {
        if( All_Nodes.at(i).getID() == the_ID ) {
            All_Nodes.erase(All_Nodes.begin() + i) ; // erase element at index i
          //  return ; // return stops the loop
        }
    }
    for (int j = 0; j<All_Edges.size() ; j++) {
        a= All_Edges.at(j).getfirstNode() ; // loops around the edges and check if the node is in any edge
        b= All_Edges.at(j).getSecondNode() ; // get second node
        if(a== the_ID || b==the_ID) { // if first or second place of path is in the if then will erase the edge as the path no longer exist this is for graphs in general .
            All_Edges.erase(All_Edges.begin() +j) ;
            j = j-1 ; // goes back one index to keep increment
        }
        
    }
    
  //  cout << "No node found to remove" << endl;
}
// void Graph::RemoveNode(string id, string weight) ;
//if we want to implement something to remove the nodes based on a magnitude



// convert the edges
void Graph :: ConvertEdge() {
    string a,b  ;
    Nodes NewNode ;
    for (int j = 0 ; j < All_Edges.size() ; j++) {
        a = All_Edges.at(j).getfirstNode() ;
        b = All_Edges.at(j).getSecondNode() ;
        if(CheckIDNode(a) == false) {
            NewNode = a ;
            All_Nodes.push_back(NewNode) ;
        }
        if(CheckIDNode(b) ==false ) {
            NewNode = b ;
            All_Nodes.push_back(b) ;
        }
    } // copies all the points into one vector Vertices.
}
void Graph::ConvertEdge(Edges& the_edges){
    string a,b,c,d ; // Id of the nodes.
    
    a = the_edges.getfirstNode() ;
    b = the_edges.getValue1() ;
    c = the_edges.getSecondNode() ;
    d = the_edges.getValue2() ;
    Nodes N1 (a,b) ;
    Nodes N2(c,d) ;

    if(CheckIDNode(a) == false ) {
       // cout << "ajkldfha" <<endl;
        All_Nodes.push_back(N1) ;
    }
    if(CheckIDNode(c)==false) {
        //cout << N2  << endl ;
        All_Nodes.push_back(N2) ;
    }
    
    
}

// Avoid doubles nodes
void Graph:: AvoidDuplicate() {
    int a=0, b=0;
    // linear way of removing element .
    for ( a = 0 ; a < All_Nodes.size() ; a++ ) {
        for (b = a+1 ; b < All_Nodes.size() ; b++ ) { // loop over the vector until its end starting from the next index of i .
            //     cout << a << " " << b << endl ; for testing
            if( All_Nodes.at(a).getID()==All_Nodes.at(b).getID()) { // check if [1,1,2,3 ] check element at index 1 is the same as index 2 ....
                All_Nodes.erase(All_Nodes.begin() + b) ;// erase element at index i ; // erase at index b ;
                a = 0 ; b = 0 ; // set a and b to beginning of vector to start linear search again .
                
            }
            else {continue ; }
        }
    }
}


void Graph::printlink(string value1) {
    string a,b ;
    
    for (int i =0 ; i < All_Edges.size() ; i++){
                a = All_Edges.at(i).getfirstNode() ;
                b= All_Edges.at(i).getSecondNode() ;
        
                if (a==value1) {
                    cout << "(" << value1 << " -> " << b  <<")"<< endl  ;
                }
            }

}

void Graph::printpath(const Nodes& The_Node) { // list the path it leads
    
    
    string a,b ;
    // Edges (a,b)
    printlink(The_Node.getID()) ;

    for(size_t i= 0 ; i<All_Edges.size() ; i++ ) {
        a = All_Edges[i].getfirstNode();
        b = All_Edges[i].getSecondNode() ;
        
        if(a == The_Node.getID()) {
            
            Graph::printlink(b) ; // check if any other link to print it as well .
        }
    }

}

void Graph::printpath(string value1) {
    
    Graph::printlink(value1) ; // call the print link to print it

    // vector<Edges> Thepath ;
    string a , b ,c,d; // storage for path
    for (int i = 0 ; i < All_Edges.size() ;i++){
        a = All_Edges[i].getfirstNode();
        b = All_Edges[i].getSecondNode() ;
        
        if(a == value1) {
            Graph::printlink(b) ; // check if any other link to print it as well . 
        }
        
    }

    
}
void Graph::printALLpath() { // I added this function in order to be able to display all node paths
    for(int i =0 ; i < All_Nodes.size() ;i++){
        cout << All_Nodes[i] <<"The path from this is " << endl;
        printpath(All_Nodes[i]) ;
        cout << endl ; 
    }
}

void Graph::FindValue(const Nodes& My_node) {
    int A = 0 ;
    for (int i = 0 ; i < All_Nodes.size() ; i++) {
        if( My_node.getValue() == All_Nodes.at(i).getValue()) {
            cout << " Value found at Node " <<My_node ;
            ++ A  ;
        }
    }
    if(A==0){ // just to return not found if not found
        cout << "Not found " << endl;
        return ;
    }
    
}

void Graph::FindValue(string value1) {
    int A=0 ;
    for(int i = 0 ; i<All_Nodes.size() ; i++){
        if(value1 == All_Nodes.at(i).getValue() ) {
            cout << "Value found at Node " << All_Nodes.at(i) ;
            A++ ;
        }
    }
    if(A==0) {
        cout << "Not found " << endl;
        return ;
    }
    
}


void Graph::SearchEdge(string value1, string value2) {
    if(checkEdges(value1, value2) == true) {
        cout << "the edge: (" << value1<< ","<< value2<< ") exist in the graph" << endl ;
    }
    else{cout << "the edge does not exist in the graph" << endl; }
}

void Graph::SearchEdge(const Edges& My_edge) {
    if(checkEdges(My_edge) == true ) {
        cout << My_edge  << "exist in the graph " << endl;
    }
    else {
        cout << "The Edge does not exist in the graph" << endl ;
    }
}





