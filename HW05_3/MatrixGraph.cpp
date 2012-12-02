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

# include "MatrixGraph.h"

MatrixGraph::MatrixGraph(unsigned num_nodes) {
		num_edges = 0;
		M.resize(num_nodes);
		for(int i = 0; i < num_nodes; i++) {
			M.resize(num_nodes);
			M.at(i).push_back(0.0);
		}
	}

	MatrixGraph::~MatrixGraph() {

	}

	

   /*
   * Add a weighted, undirected edge between nodes u and v.
   * 
   * Preconditions: 
   *     u and v are legal labels (i.e. 0 <= u < M.size(), 0 <= v < M.size())
   *     u != v
   *     There is no edge between u and v.
   *     weight > 0
   */
   // @note The main idea of this method comes from our textbook, section 17.3
   // Program 17.1 GRAPHinsertE...
	void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight) {
		if ((0 <= u < M.size() && 0 <= v < M.size()) && (u != v) && (weight > 0) && (M.at(u).at(v) == 0) && (M.at(v).at(u) == 0)) {
			M.at(u).at(v) = weight;
			M.at(v).at(u) = weight;
			num_edges++;
		}
	}

   /*
   * Get the weight between nodes u and v; return 0 if there is no edge.
   *
   * Preconditions: 
   *     u and v are legal labels (i.e. 0 <= u < M.size(), 0 <= v < M.size())
   */
	EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const {
		if (0 <= u < M.size() && 0 <= v < M.size()) {
			return M.at(u).at(v);
		}
		else 
			return 0;
	}

   /*
   * Return a list of NodeID/EdgeWeight pairs describing the nodes adjacent to edge u.
   *
   * Preconditions: u is a legal label.
   */
   // @note The general idea of this method comes from https://github.com/ScottDVincent/HW05_vincensd_v2/
	std::list<NWPair> MatrixGraph::getAdj(NodeID u) const {
		if (0 <= u < M.size()) {
			EList list; 
			for(int i = 0; i < M.at(u).size(); i++) {
				if (M.at(u).at(i) != 0 ) {
					NWPair pair(i, M.at(u).at(i));
					if (pair.second != 0) 
						list.push_back(pair);
				}
			}
			return list;
		}
	}

   /*
   * Return the degree (i.e. the number of neighorbs) of node u.
   *
   * Preconditions: u is a legal label;
   */
	unsigned MatrixGraph::degree(NodeID u) const {
		if (0 <= u < M.size()) {
			return getAdj(u).size();
		}
	}

   /*
   * Return the number of nodes in the graph.
   */
	unsigned MatrixGraph::size() const {
		return M.size();
	}

   /* 
   * Return the number of edges in the graph.
   */
	unsigned MatrixGraph::numEdges() const {
		return num_edges;
	}
