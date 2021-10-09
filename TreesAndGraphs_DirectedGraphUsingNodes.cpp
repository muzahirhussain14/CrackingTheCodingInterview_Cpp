#include <iostream>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

#define DEPTHWISE		1
#define BREADTHWISE		0

class Edge;
class Node 
{
public:
	char data;
	list<Edge> edges;

	Node()
	{
	}

	Node(char d)
	{
		data = d;
	}
};

class Edge
{
public:
	int value;
	Node to;

	Edge(int val, Node toNode)
	{
		to = toNode;
		value = val;
	}
};

class Graphs
{
private:
	unordered_map<char, Node> nodes;

	void printDepthWise(char node, unordered_map<char, bool>& visited) 
	{
		if (visited[node] == false)
		{
			Node n = this->nodes[node];
			cout << n.data << " ";
			visited[n.data] = true;
		
			for (Edge e : n.edges) 
			{
				printDepthWise(e.to.data, visited);
			}
		}
	}

	bool doesPathExist(char to, unordered_map<char, bool>& visited, queue<char>& queue_holder)
	{
		char node_val = queue_holder.front();
		queue_holder.pop();

		if (node_val == to)
			return true;

		else 
		{
			for (Edge n : nodes[node_val].edges) 
			{
				if (visited.find(n.to.data) != visited.end())				// if already visited
					continue;
				
				visited[n.to.data] = true;
				queue_holder.push(n.to.data);
			}
		}

		if(queue_holder.size() > 0)
			return doesPathExist(to, visited, queue_holder);

	}

public:
	void insertVertex(char data)
	{
		if (nodes.find(data) != nodes.end())				// no duplicates
			return;

		Node n(data);
		nodes[data] = n;
	}

	void insertEdge(int edge_val, char from, char to)
	{
		if (nodes.find(to) == nodes.end() ||				// if verteces doesnot exist
			nodes.find(from) == nodes.end())
			return;
	
		Edge edge(edge_val, nodes[to]);
	
		Node from_node = nodes[from];
		from_node.edges.push_back(edge);
		nodes[from] = from_node;									// update the dictionary element with updated paths

	}

	void printAllVertices()
	{	
		for (auto n : this->nodes)
		{
			cout << n.first << " ";
		}
		cout << "\n";	
	}

	set<char> getNeighbors(char node)
	{
		set<char> result;
		if (this->nodes.find(node) == this->nodes.end())
			return result;

		Node n = nodes[node];
		for (Edge edge : n.edges) 
			result.insert(edge.to.data);

		return result;
	}

	void print(int mode, char starting)
	{
		unordered_map<char, bool> visited;

		if (mode == DEPTHWISE)
			printDepthWise(starting, visited);
	}

	bool doesPathExist(char from, char to)
	{
		if (nodes.find(to) == nodes.end() ||				// if verteces doesnot exist
			nodes.find(from) == nodes.end())
			return false;

		unordered_map<char, bool> visited;
		queue<char> my_queue;
		my_queue.push(nodes[from].data);
		visited[nodes[from].data] = true;

		return doesPathExist(to, visited, my_queue);
	}
};


int main() 
{
	Graphs my_graph;
	my_graph.insertVertex('A');
	my_graph.insertVertex('B');
	my_graph.insertVertex('C');
	my_graph.insertVertex('D');
	my_graph.insertVertex('E');

	my_graph.insertEdge(0, 'A', 'B');
	my_graph.insertEdge(0, 'A', 'D');
	my_graph.insertEdge(0, 'B', 'C');
	my_graph.insertEdge(0, 'B', 'D');
	my_graph.insertEdge(0, 'B', 'E');
	my_graph.insertEdge(0, 'C', 'E');
	my_graph.insertEdge(0, 'D', 'E');

	my_graph.printAllVertices();


	cout << "\nNeighbors\n";
	set<char> result = my_graph.getNeighbors('B');
	for (char i : result) 
	{
		cout << i << "  ";
	}

	cout << "\n";
	my_graph.print(DEPTHWISE, 'A');


	cout << "\nDoes Path Exist: " << (my_graph.doesPathExist('D', 'C') ? "Yes" : "No") << "\n";

	cout << endl;
	return 0;
}