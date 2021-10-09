/*
Build Order: You are given a list of projects and a list of dependencies (which is a list of pairs of
projects, where the second project is dependent on the first project). All of a project's dependencies
must be built before the project is. Find a build order that will allow the projects to be built. If there
is no valid build order, return an error.

EXAMPLE
Input:
projects: a, b, c, d, e, f
dependencies: (a, d), (f, b), (b, d), (f, a), (d, c)
Output: f, e, a, b, d, c
*/


#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
#include<set>

using namespace std;

#define		DEPTH_WISE		0
#define		BREADTH_WISE	1

class Graphs 
{
private:
	const int MAX_SIZE;
	bool** adjacencyMatrix;
	char* label;
	int totalVertices;

	void print_depthwise(char vertex, unordered_map<char, bool>& isVisited)
	{
		cout << vertex << "  ";
		isVisited[vertex] = true;

		set<char> neighbors = this->get_neighbor(vertex);
		if (neighbors.size() > 0)
		{
			for (char ch : neighbors)
			{
				if (isVisited.find(ch) == isVisited.end())
				{
					print_depthwise(ch, isVisited);
				}
			}
		}
	}

	void print_breadthwise(queue<char>& my_queue, unordered_map<char, bool>& isVisited)
	{
		char vertex = my_queue.front();

		cout << vertex << "  ";
		my_queue.pop();

		set<char> neighbors = this->get_neighbor(vertex);
		
		for (char ch : neighbors)
		{
			if (isVisited.find(ch) == isVisited.end())		// if not visited, enqueue it
			{
				my_queue.push(ch);
				isVisited[ch] = true;
			}
		}

		if (my_queue.size() > 0)
			print_breadthwise(my_queue, isVisited);
	}

	set<char> nodes_with_no_incoming_edges()
	{
		set<char> result;

		for (int i = 0; i < totalVertices; ++i)
		{
			char node = this->label[i];
			int node_pos = this->findVertex(node);
			bool flag = true;

			for (int j = 0; j < totalVertices; ++j)
			{
				if (adjacencyMatrix[j][node_pos] == true)
				{
					flag = false;
					break;
				}
			}

			if (flag)
			{
				result.insert(node);
			}
		}

		return result;
	}


public:

	Graphs(int size) : MAX_SIZE(size)
	{
		totalVertices = 0;
		label = new char(MAX_SIZE);
		adjacencyMatrix = new bool*[MAX_SIZE];
		
		for (int i = 0; i < MAX_SIZE; ++i)
		{
			adjacencyMatrix[i] = new bool[MAX_SIZE];

			for (int j = 0; j < MAX_SIZE; ++j)
				adjacencyMatrix[i][j] = false;
		}
	}

	int findVertex(char d)
	{
		for (int i = 0; i < totalVertices; ++i)
			if (label[i] == d)
				return i;

		return -1;
	}

	void addVertex(char data)
	{
		if (totalVertices == MAX_SIZE)
			return;

		label[totalVertices] = data;

		for (int i = 0; i < totalVertices; ++i)
		{
			adjacencyMatrix[i][totalVertices] = false;
			adjacencyMatrix[totalVertices][i] = false;
		}

		++totalVertices;
	}

	void addEdge(char from, char to)
	{
		int pos_to = this->findVertex(to);
		int pos_from = this->findVertex(from);

		if (pos_to == -1 || pos_from == -1)
			return;

		adjacencyMatrix[pos_from][pos_to] = true;
	}

	void removeEdge(char from, char to)
	{
		int pos_to = this->findVertex(to);
		int pos_from = this->findVertex(from);

		if (pos_to == -1 || pos_from == -1)
			return;

		adjacencyMatrix[pos_from][pos_to] = false;
	}

	void print(int mode)
	{
		unordered_map<char, bool> isVisted;
		if (mode == DEPTH_WISE)
			print_depthwise(label[0], isVisted);
		

		else if (mode == BREADTH_WISE)
		{
			queue<char> my_queue;
			my_queue.push(label[0]);

			print_breadthwise(my_queue, isVisted);
		}
	}

	void removeVertex(char label)				// Shift layer by layer
	{
		int label_pos = findVertex(label);
		if (label == -1)
			return;

		// remove all the paths.
		for (int i = label_pos + 1; i < totalVertices; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				if (j == label_pos)
					continue;

				if (j < label_pos)
				{
					adjacencyMatrix[i - 1][j] = adjacencyMatrix[i][j];
					adjacencyMatrix[j][i - 1] = adjacencyMatrix[j][i];
				}
				else
				{
					adjacencyMatrix[i - 1][j - 1] = adjacencyMatrix[i][j];
					adjacencyMatrix[j - 1][i - 1] = adjacencyMatrix[j][i];
				}

			}
		}

		// Remove label
		for (int i = label_pos + 1; i < totalVertices; ++i)
			this->label[i - 1] = this->label[i];

		--totalVertices;
	}

	set<char> get_neighbor(char vertex)
	{
		int pos_vertex = this->findVertex(vertex);
		set<char> neigh;

		if (pos_vertex == -1)
			return neigh;

		for (int i = 0; i < totalVertices; ++i)
		{
			if (adjacencyMatrix[pos_vertex][i] == true)
				neigh.insert(this->label[i]);
		}

		return neigh;
	}

	vector<char>* get_BuildOrder()
	{
		vector<char>* build_order = new vector<char>;
		
		while (totalVertices > 0)
		{
			// 1) Get nodes with no incoming edges
			set<char> result = this->nodes_with_no_incoming_edges();

			if (result.size() == 0)		// Error, if vertices are still there but there is no vertex with no incoming nodes, then thats error.
				return NULL;

			// 2) Put these nodes to a set and remove the out-going edges from these nodes
			for (char ch : result)
			{
				build_order->push_back(ch);
				set<char> neighbors = this->get_neighbor(ch);

				for (char n : neighbors)
				{
					this->removeEdge(ch, n);
				}
				this->removeVertex(ch);		// instead of removing we could take a "is_visited" dictionary and insert true against the project_name 
			}
		}

		return build_order;
	}
};

int main()
{
	//projects: a, b, c, d, e, f
	//dependencies : (a, d), (f, b), (b, d), (f, a), (d, c)

	Graphs my_graph(10);
	my_graph.addVertex('a');
	my_graph.addVertex('b');
	my_graph.addVertex('c');
	my_graph.addVertex('d');
	my_graph.addVertex('e');
	my_graph.addVertex('f');
	my_graph.addVertex('g');

	my_graph.addEdge('f', 'c');
	my_graph.addEdge('f', 'b');
	my_graph.addEdge('f', 'a');
	my_graph.addEdge('b', 'a');
	my_graph.addEdge('c', 'a');
	my_graph.addEdge('b', 'e');
	my_graph.addEdge('a', 'e');
	my_graph.addEdge('d', 'g');

	cout << "Depth-wise: \n";	 my_graph.print(DEPTH_WISE);
	cout << "\nBreadth-wise: \n";	 my_graph.print(BREADTH_WISE);
	
	vector<char>* build_order = my_graph.get_BuildOrder();

	if (build_order == NULL)
	{
		// Failed case
	}
	else
	{
		cout << "\nBuild-Order: ";
		for (char ch : *build_order)
		{
			cout << ch << " ";
		}
	}
	delete build_order;

	cout << endl;
	return 0;
}