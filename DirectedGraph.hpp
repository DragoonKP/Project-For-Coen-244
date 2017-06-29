//
//  DirectedGraph.hpp
//  Project.v03
//
//  Created by Kishanlal on 2017-03-25.
//  Copyright © 2017 Kishanlal. All rights reserved.
//

#ifndef DirectedGraph_hpp
#define DirectedGraph_hpp
#include "Graphs.hpp" 

class DirectedGraph: public Graph {
    protected :
    
    public :
    DirectedGraph () ;
    DirectedGraph(Nodes,Edges) ; 
    DirectedGraph(vector<Nodes>, vector<Edges>); // vector nodes
    DirectedGraph (const DirectedGraph&) ;// copy constructor
    
    // mutator just for edges as edges in directed and undirected graph are different
    

    void setEdges(vector<Edges>&) ; // set a vecotr of edges
    
    void AddEdges(Edges&) ;
    void AddEdges(string,string) ;
    
    void RemoveEdge(const Edges&) ; // avoid the object changing with const
    void RemoveEdge(string,string) ; // calls the graph remove edge as it is that one or make the graph one an abstract case and use it here .
    void Display () ;
    
    // operator overloading
    // assign operator

    const DirectedGraph& operator=(const DirectedGraph&) ;
    
    // ostream overload
    friend ostream& operator<<(ostream& , const DirectedGraph& );
    friend istream& operator>>(istream&, DirectedGraph& ) ; // input edge



};

#endif /* DirectedGraph_hpp */
