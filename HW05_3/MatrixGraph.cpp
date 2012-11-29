/*****
* File : MatrixGraph.cpp
* Author : David Griffith
* Date : 11/29/2012
* Purpose: Subclass to MatrixGraph.h
* 
* @note This file is (c) 2012. It is licensed under the
* CC BY 3.0 license (http://creativecommons.org/licenses/by/3.0/),
* which means you are free to use, share, and remix it as long as you
* give attribution. Commercial uses are allowed.
*/

# include "Graph.h"
# include "MatrixGraph.h"

class MatrixGraph : public Graph {
	MatrixGraph::MatrixGraph(unsigned num_nodes) {

	}

	MatrixGraph::~MatrixGraph() {

	}
	
	// Modifier
	void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight) {

	}

	// Inspectors
	MatrixGraph::EdgeWeight(NodeID u, NodeID v) const {
		return list;
	}
	
	std::list<NWPair> getAdj(NodeID u) const {
		return num_neighbors;
	}

	MatrixGraph:: unsigned degree(NodeID u) const {
		return num_nodes;
	}

	MatrixGraph:: unsigned Size() const {
		return num_nodes;
	}

	MatrixGraph:: unsigned numEdges() const {
		return num_edges;
	}


}