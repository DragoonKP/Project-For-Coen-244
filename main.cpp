//
//  main.cpp
//  Project.v03
//
//  Created by Kishanlal on 2017-03-16.
//  Copyright © 2017 Kishanlal. All rights reserved.
//

#include <iostream>
#include "Graphs.hpp"
#include "Nodes.hpp"
#include "Edges.hpp"
#include "DirectedGraph.hpp"
#include "UndirectedGraph.hpp"
#include <vector>
using namespace std;

void TestDirectGraph() ;
void TestUndirected() ;
void TestInput () ;
void testppt() ;
void TestingSet() ;
void somehtin() ;
void testNodes() ; // prototype

int main() {
    
    
    
  //  TestingSet() ; // we are going to test the set and get .
    // HERE we are going to test the set and get function of each graphs.
    // TestUndirected() ;
    // TestDirectGraph() ;
    
    // TestInput () ;
    testppt() ;
    //testNodes() ;
    //somehtin() ;
    
    
    return 0 ;
}
void TestingSet() {
    // first i set up a couple of nodes and edges
    Nodes N1( "1","100") ;// node with id 1 and value 100,
    Nodes N2("2","200")  ; // nodes with ID 2 and value 200 ;
    Nodes N3("3","300" ) ;
    Nodes N4("4" ,"400") ;
    Nodes N5("5","500" ) ;
    Nodes N6("Testing" , "Yahoo") ;
    vector<Nodes> nodes{N1,N2,N4,N5} ; // create a couple of vector of type Nodes .
    vector<Nodes> thenodes { N1,N6} ;
    Edges E1(N1,N2) ; // 1,2
    Edges E2(N2,N4) ;// 1,4
    Edges E3(N2,N5) ;// 2,5
    Edges E4(N1,N3) ; // 1,3
    Edges E5 (N1,N5) ; // 1,5
    Edges E6(N2,N1) ; // 2,1
    Edges E7 (N2,N4) ; // 2,4
    vector<Edges> EDGES {E1,E3,E6,E7} ; // create a couple of vector of type edges
    vector <Edges> theEdges{E3,E4,E6} ;
    Graph * G1; // pointer Graaph
    Graph * G2;
    DirectedGraph Graph1 ; // empty graphs.
    UndirectedGraph Graph2 ;
    
    G1 = &Graph1; // reference G1 is directed
    G2 = &Graph2;
    
    G1->setNodes(nodes) ; //testing set methods.
    G2->setNodes(thenodes) ;
    G1->setEdges(EDGES) ;
    G2->setEdges(theEdges) ;
    
    G1->Display() ;
    G2->Display() ; // display method
    
    cout << "Testing get functions\n" << endl ;
    vector<Edges> newedges =  G1->getEdges() ; // return the edges . Assign the proper return type
    for (int i = 0 ; i < newedges.size() ; i++) {
        cout << newedges[i] ;
        // edges
    }
    cout << "\n\n\n" ; // Nodes
    vector<Nodes> newNodes = G1->getNodes() ;
    for(int i = 0 ; i <newNodes.size() ; i++) {
        cout << newNodes[i] ;
    }// edges
    cout << "Testing the get function for the node and edges" << endl ;
    cout << E1.getNode1() << endl ; // E1 = N1,N2
    cout << E1.getNode2() << endl;  // node 1 and node 2 ;
    cout << N1.getValue() << endl;
    cout << N1.getID() << endl;
    cout << "Testing the edges return " << endl;
    
    Edges E10 ;
    E10.setEdges("!", "heyhey") ; // set the edges
    cout << E10;
    
    Nodes n10 ;
    n10.setNodes("1000", "testing:") ;
    cout << n10 << endl ;
}
void TestUndirected() {
    Nodes N1("1","100"); Nodes N2("2","200");  Nodes N3("3","300") ; Nodes N6("6","600") ;
    Edges E1("1","2") ; Edges E2("3","5") ;
    Edges E3(N3,N6) ;
    // Edges E1(N1,N2) ;
    
    vector<Nodes> mynodes{N1,N2,N3} ;// polymorphism using nodes types in vectors .
    vector<Edges> Myedges{E1 } ; // creating a edge with only one edge
    
    cout << E1 ; // testing the operator
    cout << N1 ;
    
    Graph * G1 ; // use of polymorphism
    UndirectedGraph My_Graph(mynodes,Myedges) ;
    G1 = &My_Graph ; // assign My_graph adress to the graph pointer
    
    G1-> Display() ;
    cout << "\n\n" ;
    //My_Graph.AddEdges(E2) ;
    G1->AddEdges(E2) ; // 5 to 3 should also exists
    G1->AddNode("10","90") ; // adding nodes
    G1->AddEdges("3","6") ;
    //G1->AddEdges(E3) ;
    
    My_Graph.Display();
    cout << "\nTesting print a path" << endl;
    
    My_Graph.printpath("3") ;
    cout << "\n\n" ;
    //  G1->printpath("4") ; // node doesn't exist
    G1-> printpath(N3) ;
    
    
    cout << "\nTesting remove edge " << endl;
    string a="1" ,b="2" , c = "90" ;
    Edges E6 (a,b) ;// 1,2
    G1->RemoveEdge(a,b) ;
    G1->RemoveEdge(b,c) ;
    
    G1->Display() ;
    
    cout <<"\nTesting Remove node" << endl;
    G1->RemoveNode(N3) ;
    G1->RemoveNode("125") ; // node doesn't exist
    
    G1->Display() ;
    
    cout << "Testing find value of a node " << endl;
    G1->FindValue(N1) ; // 1, 100
    G1->FindValue(c) ; // 90
    G1->FindValue(a) ; // not found a = 1
    
    G1->AddEdges(a, b) ; // 1,2
    G1->Display() ;
    //
    //       cout << "Testing to print the path from a certain node" << endl;
    //    cout << "\n\n\n\n\n" ;
    //    G1->printpath("1") ;
    
    cout << "\n\n\n\n" ;
    ////
    cout << "testing the search graph by an edge" <<endl;
    G1->SearchEdge(a,b) ; // 1,2
    G1->SearchEdge(E1) ; // 1,2
    G1->SearchEdge(E2) ; // should not exist
    ////
    cout << "testing the overload function for node,graph, edge" << endl;
    cout << My_Graph ;
    cout << "\n" << E1 << "\n" << N1 << endl ;
    //
    cin >>My_Graph ;
    cout << My_Graph ;
    //
}

void TestDirectGraph() {
    
    Nodes N1( "1","100") ;// node with id 1 and value 100,
    Nodes N2("2","200")  ; // nodes with ID 2 and value 200 ;
    Nodes N3("3","300" ) ;
    Nodes N4("4" ,"400") ;
    Nodes N5("5","500" ) ;
    vector<Nodes> nodes{N1,N2,N4,N5} ;
    Edges E1(N1,N2) ; // 1,2
    Edges E2(N2,N4) ;// 1,4
    Edges E3(N2,N5) ;// 2,5
    Edges E4(N1,N3) ; // 1,3
    Edges E5 (N1,N5) ; // 1,5
    Edges E6(N2,N1) ; // 2,1
    Edges E7 (N2,N4) ; // 2,4
    
    vector<Edges> EDGES {E1,E3,E6,E7} ;
    
    //  Graph G7 (nodes,EDGES) ;
    
    Graph * G1 ;
    DirectedGraph MYG4(nodes,EDGES)  ;
    G1 = & MYG4 ;
    G1->Display() ;
    
    cout << endl ;
    
    cout << "Testing the print path " << endl ;
    G1->printpath("1") ;
    cout << endl ;
    //G1->RemoveEdge(E6) ;
    cout << endl ;
    //   G1->printpath(N1) ;
    // cout << G1; // will print the location of the graph
    
    cout << "\nTesting the add nodes and remove nodes " << endl;
    G1->AddNode(N1) ; // already exist
    G1->AddNode(N3) ; // new node
    G1->RemoveNode(N1) ; // remove it will remove a bunch of edges
    G1->Display() ;
    
    cout << "\nTesting the add Edge and remove Edge " << endl;
    //MYG4.AddEdges("1","2") ; // here we lose the value of the nodes
    G1->AddEdges(E1) ;
    G1->RemoveEdge(E7) ; // 2,4
    G1->RemoveEdge("1000","20000000" ) ;// edge doesn't exist will not remove anything
    cout << "\n\n" ;
    G1->Display() ;
    
    cout << "\ntesting the find value" << endl ;
    
    G1->FindValue(N3) ; // 300
    G1->FindValue(N1) ; // we lose the value at N1 we converting the edge
    G1->FindValue("500") ;
    G1->FindValue("Testing for fun") ; // doesn't exist
    
    cout <<"\n Testing the search Edge " << endl ;
    
    G1->SearchEdge(E6) ; // 2,1
    G1->SearchEdge(E3) ; // 2, 5
    
    
    cout << "\ntesting the overload function for node,graph, edge" << endl;
    cout << MYG4 ;
    cout << "\n" << E1 << "\n" << N1 << endl ;
    
    cin >> MYG4 ;
    cout << MYG4  ;
    
    DirectedGraph NewGraph ;
    cin >> NewGraph ;
    cout << NewGraph ;
    
}

void TestInput () {
    //cout << "testing cin overload for node" ;
    //Nodes N1 ;
    DirectedGraph D1 ;
    //cin >> N1 ;
    //cout << N1 ;
    cout << "testing cin in in directed graph overload" << endl ;
    cin >> D1 ;
    cout << D1 ;
    cin >> D1 ; // will erase the graph and make you build another one.
    cout << D1 ;
}

void testppt() { // in printpath i would simply need to add the maginitude to display .
    Nodes N1 ("Detroit","182.4 meter"); // value  of detroit is 1 ;
    Nodes N2 ("Boston","3.3 meter") ; // value of boston is 2 ;
    Nodes N3 ("Washigton","4.5 meter") ; // value of Washignton is 3 ;
    Nodes N4 ("Newark","9.8 m") ;
    Nodes N5 ("Miami","0.5 meter") ;
    
    Nodes N6  ;
    N6 = N1; // assign N6 to N1 ;
    
    
    vector<Nodes> Node_graph{N6,N2,N3,N4,N5}  ;
    
    // Edges E1("Detroit","Newark","100") ; // Detroit -> Newark
    
    Edges E1(N1,N4) ; // Detroit -> Newark
    Edges E2(N2,N4) ; // Boston -> Newark
    Edges E3(N4,N3) ; // Newark-> Washigton
    Edges E4(N4,N5) ; // Newark ->Miami
    Edges E5(N3,N5) ; // Washignton -> Miami
    
    vector<Edges> Edge_Graph{E1,E2,E3,E4,E5} ;
    
    Graph * The_Graph ;
    UndirectedGraph MyGraph (Node_graph,Edge_Graph) ;
    The_Graph = &MyGraph ; // polymormism
    
    The_Graph->Display() ;
    
    cout << "\n\nPrint path from Detroit" << endl;
    
    The_Graph->printpath("Detroit") ;
    cout << endl ;
//    The_Graph->SearchEdge(E1)  ;
//    The_Graph->RemoveEdge(E1) ;
//    The_Graph->SearchEdge(E1) ;
    
    
    
    
    
}
void somehtin() {
    Nodes N1( "1","100") ;// node with id 1 and value 100,
    Nodes N2("2","200") ; // nodes with ID 2 and value 200 ;
    Nodes N3("3","300" ) ;
    Nodes N4("4" , "* & ") ;
    Nodes N5("Testing ","without number" ) ;// create a couple of nodes
    vector <Nodes > my_nodes {N1,N2,N3,N4,N5} ;
    
    Edges  E1(N1,N2) ;
    Edges E2 (N1,N3) ;
    Edges E3 (N2,N4) ;
    Edges E4 (N2,N5) ;
    vector<Edges> Edge_Graph{E1,E2,E3,E4} ; // couple of edges
    
    Graph * G1 ;
    UndirectedGraph gra(my_nodes,Edge_Graph) ; // undirected graph
    DirectedGraph graph2(my_nodes,Edge_Graph) ;
    G1=&graph2 ;
    //gra.printpath(N1)  ;
    gra.printALLpath() ;
    
    cout << "printing path for directed " << endl;
    G1->printALLpath() ;
    // if its empty it would write the path is : and then leave it empty . 
    //cin >> gra ;
}

void testNodes() {
    Nodes  Node1("100","900") ; // constructor
    
    
    
}




