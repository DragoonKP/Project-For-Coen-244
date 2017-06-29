//
//  UndirectedGraph.cpp
//  Project.v03
//
//  Created by Kishanlal on 2017-03-25.
//  Copyright © 2017 Kishanlal. All rights reserved.
//

#include "UndirectedGraph.hpp"

UndirectedGraph::UndirectedGraph() {
    cout << "empty Undirected Graph created" << endl;
}

UndirectedGraph::UndirectedGraph(vector<Nodes> My_node,vector<Edges> My_edge) : Graph(My_node,My_edge) { ReverseEdges();} ;

UndirectedGraph::UndirectedGraph(Nodes My_node,Edges My_edge) : Graph(My_node,My_edge) {ReverseEdges();} ;

UndirectedGraph::UndirectedGraph(const UndirectedGraph& This_graph) {
    All_Edges = This_graph.All_Edges ;
    All_Nodes = This_graph.All_Nodes ;
    ReverseEdges();
}

const UndirectedGraph& UndirectedGraph::operator=(const UndirectedGraph& My_graph){
//    cout << "Assigadkfnadfnakdfaldkfj;ldkfjakld" << endl;
    All_Edges = My_graph.All_Edges ;
    All_Nodes = My_graph.All_Nodes ;
    ReverseEdges() ;
    return *this;
}


// 1,2 (2,1)
void UndirectedGraph::ReverseEdges() {
    string a,b, c= "0" ; // reverse all the edges . to begin with . then we will have a bool function for any additional edges.
   const size_t d = All_Edges.size() ; // const size
    for (int i = 0 ; i < d ; i++ ) { // size is dynamic so if I put Edge.size() it will keep pushing back some values as the sizee keep growing .
        
        a = All_Edges[i].getfirstNode() ;
        b = All_Edges[i].getSecondNode()  ;
        c= All_Edges[i].getMagnitude() ;
        
        Edges E1 (b,a) ; // create an edge with values in reverse order.
        //cout << a <<  " " << b << endl  ;
        if( checkEdges(E1) == false ){
        All_Edges.push_back(E1) ;
        }
        a.clear() ; // clear anything stored in the strings
        b.clear() ;
        c="0" ; // set back the maginitude to 0
    }
}


void UndirectedGraph::setEdges(vector<Edges>& The_edge) {
    All_Edges=The_edge ;
    const size_t size = The_edge.size() ;
  //  cout << size;
    for (int i = 0 ; i < size ; i++){
        Edges E1 = The_edge[i] ;
        cout << E1  ;
        ConvertEdge(E1) ;
     // convert the edge as im not passing by the base class .
}
    
    ReverseEdges() ;
    
}

void UndirectedGraph::AddEdges(Edges& The_edge) {
    
   Nodes Node1 =  The_edge.getNode1() ;
    Nodes Node2 = The_edge.getNode2() ;
    Edges E1 (Node2,Node1) ; // reverse edge
   // cout << Node1 << endl << Node2;
    if(checkEdges(The_edge)==false) {
        All_Edges.push_back((The_edge)) ;
    }
    if(checkEdges(E1) ==false){
        All_Edges.push_back(E1) ;
    }
    
    ConvertEdge(E1) ;

}

void UndirectedGraph::AddEdges(string value1, string value2) { // add edge (1,2) and magnitude is 0 ;

     if(checkEdges(value1, value2)== false){ // if it doesn't exist we add it 
        Edges E3(value1,value2) ;
        All_Edges.push_back(E3) ;
    }
    if(checkEdges(value2, value1)==false) { // if the reverse doesn't exist we add it
        Edges E4(value2,value1) ;
        All_Edges.push_back(E4) ;
    }
    ConvertEdge() ;
}


void UndirectedGraph::RemoveEdge(const Edges& My_edges) {
    string a,b;
    for (int i = 0 ; i < All_Edges.size() ;i++) {
        a = All_Edges.at(i).getfirstNode() ;
        b = All_Edges.at(i).getSecondNode() ;
        
        if(a == My_edges.getfirstNode() && b == My_edges.getSecondNode()) {
            All_Edges.erase(All_Edges.begin() + i) ;
            i=i-1;// move back an index
        }
        if(a==My_edges.getSecondNode() && b==My_edges.getfirstNode()) {
            All_Edges.erase(All_Edges.begin() + i) ;
            i = i-1 ;
        }
    }
}
void UndirectedGraph::RemoveEdge(string value1, string value2) {
    string a , b ;
    for ( int i = 0 ; i < All_Edges.size() ; i++)  {
        
        a = All_Edges.at(i).getfirstNode() ;
        b = All_Edges.at(i).getSecondNode() ;
        if(a==value1 && b ==value2 ) {
            All_Edges.erase(All_Edges.begin() + i) ; // erase the pair at index i .
           i=i-1; // goes back one step of the iteration 
        }
        // the only thing that changes is for undirected graph this function becomes
        if(a==value2 && b==value1) {
            All_Edges.erase(All_Edges.begin() + i ) ;
            i=i-1; // go back one index 
        }
    }

}

void UndirectedGraph::Display() {
    cout << "This is a undirected Graph" << endl;
    cout << "The nodes are : " << endl ; 
    for (int i = 0 ; i < All_Nodes.size() ; i++ ) {
        cout <<All_Nodes.at(i) ;
    }

    
    cout << "\nEdges : " << endl ; // links only the ID not the values as the value is fixed for each nodes we can inquire about them later to
    for (int i = 0 ; i < All_Edges.size() ; i++ ) {
        cout << All_Edges.at(i) ; 
    }
}

ostream& operator<<(ostream& Output, const UndirectedGraph& My_graph){
    Output << "This is the output of an undirected Graph" << endl;
    Output << "The node are : " << endl;
    
    
    for (int i = 0 ; i < My_graph.All_Nodes.size() ; i++ ) {
        Output << "ID: " << My_graph.All_Nodes.at(i).getID() ;
        Output << "  Value: " << My_graph.All_Nodes.at(i).getValue() << endl;
    }
    Output << "\nEdges : " << endl ; // links only the ID not the values as the value is fixed for each nodes we can inquire about them later to
    for (int i = 0 ; i < My_graph.All_Edges.size() ; i++ ) {
        Output << "(" << My_graph.All_Edges.at(i).getfirstNode() << " , " ;
        Output << My_graph.All_Edges.at(i).getSecondNode() << ")" << endl ;
    }

    
    return Output ;
    
}

istream& operator>>(istream& Input, UndirectedGraph& My_graph){
    
    size_t a=0;
    size_t b=0;
    Nodes N1;
    Edges E1 ;
    My_graph.All_Nodes.clear()  ;
    My_graph.All_Edges.clear() ;
    
    cout <<" enter the number of Nodes" << endl ;
    Input >> a;
    for (int i = 0 ; i <a; i++ ) { // node
        Input>> N1 ;
        My_graph.All_Nodes.push_back(N1) ; }
    
    cout << "enter the number of edges " << endl;
    Input >> b; // instead of resizing we can use this
    
    for( int i = 0 ; i <b ; i++ ) { // set the edges
        Input >> E1 ;
        My_graph.All_Edges.push_back(E1) ;
        
    }
    
   My_graph.AvoidDuplicate() ;
    My_graph.ReverseEdges() ; 
    return  Input ;
}








