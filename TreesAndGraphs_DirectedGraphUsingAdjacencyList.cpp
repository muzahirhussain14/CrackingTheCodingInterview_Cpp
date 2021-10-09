#include<iostream>
#include<list>
#include<set>
#include<unordered_map>
#include<queue>

using namespace std;

#define DEPTH_WISE		0
#define BREADTH_WISE	1

class Graph
{
private:
	int size;
	char *label;
	list<char> *vertices;
	int totalVerticeses;

	void printDepthWise(char c, unordered_map<char, bool>& visited)
	{
		cout << c << " ";
		set<char> neigh = getNeighbors(c);
		visited[c] = true;

		for (char i : neigh)
		{
			if (visited.find(i) != visited.end() && visited[i] == true)
				continue;

			printDepthWise(i, visited);
		}
	}

	void printBreadthWise(queue<char>& my_queue, unordered_map<char, bool>& visited)
	{
		char label = my_queue.front();
		cout << label << " ";

		my_queue.pop();
		set<char> neigh = getNeighbors(label);

		for (char i : neigh) 
		{
			if (visited.find(i) != visited.end() && visited[i] == true)
				continue;

			my_queue.push(i);
			visited[i] = true;
		}

		if (my_queue.size() > 0)
			printBreadthWise(my_queue, visited);
	}

public:
	Graph(int s)
	{
		size = s;
		vertices = new list<char>[size];
		label = new char[size];
		totalVerticeses = 0;
	}

	void addVertex(char l)
	{
		if (totalVerticeses == size)
			return;

		label[totalVerticeses++] = l;
	}

	void addEdge(char from, char to)
	{
		int from_pos = find(from);
		int to_pos = find(to);

		if (to_pos != -1 && from_pos != -1) 
		{
			vertices[from_pos].push_back(to);
		}
	}
	
	int find(char l)
	{
		for (int i = 0; i < totalVerticeses; ++i)
			if (label[i] == l)
				return i;
		return -1;
	}

	set<char> getNeighbors(char l)
	{
		int pos = find(l);
		set<char> neighbors;

		if (pos == -1)
			return neighbors;

		for (char i : vertices[pos])
			neighbors.insert(i);

		return neighbors;
	}

	bool doesPathExist(char from, char to)
	{
		int to_pos = find(to);
		int from_pos = find(from);

		if (to_pos != -1 || from_pos != -1)
			return false;

		for (char i : vertices[to_pos])
			if (i == to)
				return true;

		return false;
	}

	void print(int mode) 
	{
		if(mode == BREADTH_WISE)
		{
			queue<char> my_queue;
			unordered_map<char, bool> visited;
			my_queue.push(label[0]);
			visited[label[0]] = true;
			printBreadthWise(my_queue, visited);
		}

		if(mode == DEPTH_WISE)
		{
			unordered_map<char, bool> visited;
			printDepthWise(label[0], visited);
		}
	}
};

int main() 
{
	Graph my_graph(10);
	my_graph.addVertex('A');
	my_graph.addVertex('B');
	my_graph.addVertex('C');
	my_graph.addVertex('D');
	my_graph.addVertex('E');

	my_graph.addEdge('A', 'B');
	my_graph.addEdge('A', 'D');
	my_graph.addEdge('B', 'D');
	my_graph.addEdge('B', 'C');
	my_graph.addEdge('C', 'E');

	my_graph.print(BREADTH_WISE);


	cout << "\nDone. Press any key to continue";	cin.get();
	cout << endl;
	return 0;
}
