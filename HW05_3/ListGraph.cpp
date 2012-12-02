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

# include "ListGraph.h"

	ListGraph::ListGraph(int numNodes) {
		num_edges = 0;
		edgeList.resize(numNodes);
	}

	ListGraph::~ListGraph() {

	}
	
   /*
   * Add a weighted, undirected edge between nodes u and v.
   * 
   * Preconditions: 
   *     u and v are legal labels (i.e. 0 <= u < edgeList.size(), 0 <= v < edgeList.size())
   *     u != v
   *     There is no edge between u and v.
   *     weight > 0
   */
   // @note The structure of this method comes from https://github.com/Taylor-Reid/HW05_TaylorReid/
	void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight) {
		EList::const_iterator itera;
		NWPair test; 
		if ((0 <= u < edgeList.size() && 0 <= v < edgeList.size()) && (u != v) && (weight > 0)) {
			EList::const_iterator itera;
			for (itera = edgeList.at(u).begin(); itera != edgeList.at(u).end(); itera++) {
				test = *itera;
				if (test.first == v && test.second == weight) {
					return;
				}
			}
		}
			edgeList.at(u).push_back(NWPair(v, weight));
			edgeList.at(v).push_back(NWPair(u, weight));
			num_edges++;
	}

   /*
   * Get the weight between nodes u and v; return 0 if there is no edge.
   *
   * Preconditions: 
   *     u and v are legal labels (i.e. 0 <= u < edgeList.size(), 0 <= v < edgeList.size())
   */
	EdgeWeight ListGraph:: weight(NodeID u, NodeID v) const {
		EList::const_iterator itera;
		NWPair test;
		if (u >= 0 && u < edgeList.size() && v >= 0 && v < edgeList.size() && u != v) {
			for (itera = edgeList.at(u).begin(); itera != edgeList.at(u).end(); itera++) {
				test = *itera;
				if (test.first == v) {
					return test.second;
				}
			}
		}
		return 0;
	}
	
   /*
   * Return a list of NodeID/EdgeWeight pairs describing the nodes adjacent to edge u.
   *
   * Preconditions: u is a legal label.
   */
	std::list<NWPair> ListGraph::getAdj(NodeID u) const {
		if (0 <= u < edgeList.size()) {
			return edgeList.at(u);
		}
	}

   /*
   * Return the degree (i.e. the number of neighorbs) of node u.
   *
   * Preconditions: u is a legal label;
   */
	unsigned ListGraph::degree(NodeID u) const {
		if (0 <= u < edgeList.size()) {
			return getAdj(u).size();
		}
	}

   /*
   * Return the number of nodes in the graph.
   */
	unsigned ListGraph::size() const {
		return edgeList.size();
	}
   /* 
   * Return the number of edges in the graph.
   */
	unsigned ListGraph:: numEdges() const {
		return num_edges;
	}