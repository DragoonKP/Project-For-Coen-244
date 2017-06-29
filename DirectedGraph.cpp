//
//  DirectedGraph.cpp
//  Project.v03
//
//  Created by Kishanlal on 2017-03-25.
//  Copyright © 2017 Kishanlal. All rights reserved.
//

#include "DirectedGraph.hpp"

DirectedGraph :: DirectedGraph () {
    cout << "empty directed graph created" << endl ;
}
DirectedGraph::DirectedGraph(Nodes node1,Edges edge1):Graph(node1,edge1) {}

DirectedGraph::DirectedGraph(vector<Nodes> The_node,vector<Edges>The_edge ):Graph(The_node,The_edge) {}

DirectedGraph::DirectedGraph(const DirectedGraph& My_direct_Graph){
    All_Edges = My_direct_Graph.All_Edges ;
    All_Nodes = My_direct_Graph.All_Nodes ;
    AvoidDuplicate() ;
}

const DirectedGraph& DirectedGraph:: operator=(const DirectedGraph& My_graph) {
// for self assignment need to overload bool == 
    All_Edges= My_graph.All_Edges ;
    All_Nodes = My_graph.All_Nodes ;
    AvoidDuplicate() ;
    return *this;
}

// mutator
void DirectedGraph:: setEdges(vector<Edges>& The_Edges) {
    All_Edges  = The_Edges ;
    Graph:: AvoidDuplicate() ;
}
void DirectedGraph::AddEdges(Edges & The_edge) {
    
    if(checkEdges(The_edge) == true ) { return  ; } // check if the edge already exist if it does than stops the functions
    else {
        All_Edges.push_back(The_edge) ;
        ConvertEdge(The_edge) ;
    }
    
}

void DirectedGraph::AddEdges(string value1, string value2) {
    if(checkEdges(value1, value2) ==true) { // if this is true then no need to add edges .
        return ;
    }else {
        Edges Edge1  (value1,value2) ;
        All_Edges.push_back(Edge1) ;
        ConvertEdge() ;
    }
}

void DirectedGraph::RemoveEdge(const Edges& The_Edge){
    string a , b ;
    for ( int i = 0 ; i < All_Edges.size() ; i++)  {
        
        a = All_Edges.at(i).getfirstNode() ;
        b = All_Edges.at(i).getSecondNode() ;
        
        if(a==The_Edge.getfirstNode() && b ==The_Edge.getSecondNode() ) {
            All_Edges.erase(All_Edges.begin() + i) ; // erase the pair at index i .
            return ; // stop loops as edge removed
        }
    }
    cout << "No edge found to remove " << endl ;
}

void DirectedGraph::RemoveEdge(string value1, string value2) {
    string a , b ;
    for ( int i = 0 ; i < All_Edges.size() ; i++)  {
        
        a = All_Edges.at(i).getfirstNode() ;
        b = All_Edges.at(i).getSecondNode() ;
        
        if(a==value1 && b ==value2 ) {
            All_Edges.erase(All_Edges.begin() + i) ; // erase the pair at index i .
            return ; // stop loops as edge removed
        }
    }
    cout << "No edge found to remove " << endl ;
}

void DirectedGraph::Display() {
    cout << "This is a Directed Graph" << endl;
    
        cout << "Nodes :" << endl ;
        // cout << All_Nodes.size() ; for testing purposes
        
        for (int i = 0 ; i < All_Nodes.size() ; i++ ) {
            cout << All_Nodes.at(i) ;
        }
        cout << "\nEdges : " << endl ; // links only the ID not the values as the value is fixed for each nodes we can inquire about them later to
        for (int i = 0 ; i < All_Edges.size() ; i++ ) {
            cout << All_Edges.at(i) ;
        }
}

ostream& operator<<(ostream& Output , const DirectedGraph& My_graph ){
    Output << "This is the output of an Directed Graph" << endl;
    
    Output << "Nodes :" << endl ;
    // cout << All_Nodes.size() ; for testing purposes
    
    for (int i = 0 ; i < My_graph.All_Nodes.size() ; i++ ) {
        Output << "ID: " << My_graph.All_Nodes.at(i).getID() ;
        Output << "  Value: " << My_graph.All_Nodes.at(i).getValue() << endl;
    }
    Output << "\nEdges : " << endl ; // links only the ID not the values as the value is fixed for each nodes we can inquire about them later to
    for (int i = 0 ; i <My_graph.All_Edges.size() ; i++ ) {
        Output << "(" << My_graph.All_Edges.at(i).getfirstNode() << " , " ;
        Output << My_graph.All_Edges.at(i).getSecondNode() << ")" << endl ;
    }
    return Output ;
}

istream& operator>>(istream& Input, DirectedGraph& My_graph ){
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
   // we could also check if we already have a graph instead of resetting it completly we could simply add nodes,etc. 

    
    return  Input ;
}


