//
//  UndirectedGraph.hpp
//  Project.v03
//
//  Created by Kishanlal on 2017-03-25.
//  Copyright © 2017 Kishanlal. All rights reserved.
//

#ifndef UndirectedGraph_hpp
#define UndirectedGraph_hpp
#include "Graphs.hpp"

using std::ostream ;

class UndirectedGraph : public Graph{
    private :
    
    void ReverseEdges() ; // reverse edge function is specific to undirected graphs only .
    
    public :
    UndirectedGraph () ;
    UndirectedGraph (vector<Nodes>,vector<Edges>) ;
    UndirectedGraph (Nodes,Edges)  ;
    UndirectedGraph (const UndirectedGraph&) ; // copy constructor ;
    
    // mutator :
    void setEdges(vector<Edges>&) ;
    
    void Display() ; //displaay undirected graph + graph stuff .
// set egdes

    
    void AddEdges(Edges & ) ;
    void AddEdges(string,string) ; // need to reverse the edge as well .
    void RemoveEdge(string,string) ; // need to remove both from 1->2 and 2->1
    void RemoveEdge(const Edges&) ;
    
    // operator overloading 
    
    // assign operator
    const UndirectedGraph& operator=(const UndirectedGraph&) ;
    
    // ostream overlaod
    friend ostream& operator<<(ostream& , const UndirectedGraph& );
    friend istream& operator>>(istream&, UndirectedGraph& ) ; // input edge

};


#endif /* UndirectedGraph_hpp */
