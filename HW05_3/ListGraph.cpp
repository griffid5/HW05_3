/*****
* File : ListGraph.cpp
* Author : David Griffith
* Date : 11/29/2012
* Purpose: Subclass to ListGraph.h
* 
* @note This file is (c) 2012. It is licensed under the
* CC BY 3.0 license (http://creativecommons.org/licenses/by/3.0/),
* which means you are free to use, share, and remix it as long as you
* give attribution. Commercial uses are allowed.
*/

# include "Graph.h"
# include "ListGraph.h"
# include <vector>

class ListGraph : public Graph {
	ListGraph::ListGraph(int numNodes) {
	
	}

	ListGraph::~ListGraph() {

	}
	
	// Modifier
	void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight) {

	}

	// Inspectors
	ListGraph:: EdgeWeight(NodeID u, NodeID v) const {
		return list;
	}
	
	std::list<NWPair> getAdj(NodeID u) const {
		return num_neighbors;
	}

	ListGraph:: unsigned degree(NodeID u) const {
		return numNodes;
	}

	ListGraph::unsigned Size() const {
		return numNodes;
	}

	ListGraph::unsigned numEdges() const {
		return num_edges;
	}


}