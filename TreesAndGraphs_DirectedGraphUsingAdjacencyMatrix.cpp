#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <set>

using namespace std;

#define DEPTH_WISE 1
#define BREADTH_WISE 2

class Graphs 
{
private:
	const int MAX_SIZE;
	bool** adjacencyMatrix;
	char* label;
	int totalVertices;

	void print_DepthWise(char rootNode, unordered_map<char, bool>& isVisited)
	{
		cout << rootNode << " ";
		isVisited[rootNode] = true;
		set<char> neighbors = getNeighbors(rootNode);

		if (neighbors.size() == 0)
			return;

		for (char n : neighbors) 
		{
			if (isVisited.find(n) != isVisited.end() && isVisited[n])	// if already visited, skip it
				continue;

			print_DepthWise(n, isVisited);
		}
	}

	void print_BreadthWise(queue<char>& queue, unordered_map<char, bool>& isVisited)
	{
		char element = queue.front();
		set<char> neighbors = getNeighbors(element);
		queue.pop();

		cout << element << " ";

		for (char n : neighbors) 
		{
			if (isVisited.find(n) != isVisited.end() && isVisited[n])	// if already visited, skip it
				continue;
			
			queue.push(n);
			isVisited[n] = true;
		}

		if (queue.size() > 0)
			print_BreadthWise(queue, isVisited);
	}

public:
	Graphs(int size) : MAX_SIZE(size)
	{
		label = new char[MAX_SIZE];
		adjacencyMatrix = new bool* [MAX_SIZE];
		for (int i = 0; i < MAX_SIZE; ++i)
		{
			adjacencyMatrix[i] = new bool[MAX_SIZE];

			for (int j = 0; j < MAX_SIZE; ++j)
				adjacencyMatrix[i][j] = false;
		}

		totalVertices = 0;
	}

	void addVertex(char label)
	{
		if (totalVertices == MAX_SIZE)			// size full
			return;

		int newVertexIndex = totalVertices;
		this->label[newVertexIndex] = label;

		++totalVertices;
		for(int i = 0; i<totalVertices; ++i)
		{
			adjacencyMatrix[i][newVertexIndex] = false;
			adjacencyMatrix[newVertexIndex][i] = false;
		}
	}

	void addEdge(char from, char to) 
	{
		int from_pos = find(from);
		int to_pos = find(to);

		if (from_pos == -1 || to_pos == -1)
			return;

		adjacencyMatrix[from_pos][to_pos] = true;
	}

	int find(char c) 
	{
		int position = -1;

		for (int i = 0; i < totalVertices; ++i)
			if (label[i] == c)
			{
				position = i;
				break;
			}
		return position;
	}

	set<char> getNeighbors(char label) 
	{
		int node_pos = find(label);
		set<char> neighbors;

		if (node_pos == -1)						// return empty set
			return neighbors;

		for (int i = 0; i < totalVertices; ++i)
			if (adjacencyMatrix[node_pos][i] == true)
				neighbors.insert(this->label[i]);

		return neighbors;
	}

	void removeEdge(char from, char to)
	{
		int from_pos = find(from);
		int to_pos = find(to);

		if (from_pos == -1 || to_pos == -1)
			return;

		adjacencyMatrix[to_pos][from_pos] = false;
	}

	void removeVertex(char label)				// Shift layer by layer
	{
		int label_pos = find(label);
		if (label == -1)
			return;
		
		// remove all the paths.
		for (int i = label_pos+1; i < totalVertices; ++i) 
		{
			for (int j = 0; j <= i; ++j) 
			{
				if (j == label_pos)
					continue;

				if(j < label_pos)
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

	void print(int mode) 
	{
		if (mode != BREADTH_WISE && mode != DEPTH_WISE || totalVertices == 0)
			return;

		unordered_map<char, bool> isVisited;

		if (mode == BREADTH_WISE) 
		{
			queue<char> my_queue;
			my_queue.push(label[0]);
			print_BreadthWise(my_queue, isVisited);
		}
		if (mode == DEPTH_WISE)
			print_DepthWise(label[0], isVisited);

		cout << "\n";
	}


};

int main() {

	Graphs my_graph(10);
	my_graph.addVertex('A');
	my_graph.addVertex('B');
	my_graph.addVertex('C');
	my_graph.addVertex('D');
	my_graph.addVertex('E');

	my_graph.addEdge('A', 'B');
	my_graph.addEdge('A', 'D');
	my_graph.addEdge('B', 'D');
	my_graph.addEdge('B', 'C');
	my_graph.addEdge('B', 'E');
	my_graph.addEdge('C', 'E');
	
	cout << "\nprinting Depth_wise: ";
	my_graph.print(DEPTH_WISE);


	cout << "\nprinting Breadth_wise: ";
	my_graph.print(BREADTH_WISE);

	/*
	set<char> neigh = my_graph.getNeighbors('B');
	cout << "Neighbors of B\n";
	for (char n : neigh)
		cout << n << " ";

	my_graph.removeVertex('B');
	neigh.clear();
	neigh = my_graph.getNeighbors('B');

	cout << "\nNeighbors of B\n";
	for (char n : neigh)
		cout << n << " ";
*/
	cout << "\nCompleted. Press any key to continue";
	cin.get();
	cout << endl;
	return 0;
}