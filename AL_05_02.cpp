#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {

	int t;	// number of test cases
	cin >> t;

	while (t > 0) {
		string GraphType;
		cin >> GraphType;
		string Edge;

		if (GraphType == "gw" || GraphType == "g") {
			cout << "graph {\n";
			Edge = " -- ";
		}
		else if (GraphType == "dw" || GraphType == "d") {
			cout << "digraph {\n";
			Edge = " -> ";
		}

		int n;	// number of nodes
		cin >> n;
		cin.ignore();
		string Node;

		for (int i = 0; i < n; i++) {

			getline(cin, Node);
			istringstream stream(Node);
			string temp;	// node name or weight
			stream >> temp;
			cout << temp << Edge;
			stream >> temp;
			cout << temp;

			if (GraphType == "gw" || GraphType == "dw") {
				stream >> temp;
				cout << " [label = " << temp << "];\n";
			}
			else {
				cout << ";\n";
			}
		}

		cout << "}\n";
		t--;
	}
}