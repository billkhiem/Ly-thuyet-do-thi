#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
#define MAX 100

struct GRAPH
{
	int n;
	vector<vector<int>> a;
};

bool checkCoKhuyen(GRAPH G)
{
	for (int i = 0; i < G.n; i++)
		if (G.a[i][i] != 0)
			return true;
	return false;
}
bool checkVohuong(GRAPH G)
{
	for (int i = 0; i < G.n; i++)
		for (int j = 0; j < G.n; j++)
			if (G.a[i][j] != G.a[j][i])
				return false;
	return true;
}

void lietkeCanh(GRAPH G)
{
	if (checkVohuong(G))
	{
		cout << "Cac canh do thi vo huong: ";
		for (int i = 0; i < G.n; i++)
		{
			if (checkCoKhuyen(G))
				cout << "(" << i << ", " << i << "); ";
			for (int j = i + 1; j < G.n;j++)
				if (G.a[i][j]!=0)
					cout << "(" << i << ", " << j << "); ";
		}
	}
	else
	{
		cout << "Cac canh do thi co huong: ";
		for (int i = 0; i < G.n; i++)
			for (int j = 0; j < G.n;j++)
				if (G.a[i][j]!=0)
					cout << "(" << i << ", " << j << "); ";
	}
	cout << endl;
}

int demCanh(GRAPH G)
{
	int canh = 0;
	if (checkVohuong(G))
	{
		cout << "Cac canh do thi vo huong: ";
		for (int i = 0; i < G.n; i++)
		{	
			for (int j = i; j < G.n; j++)
				if (G.a[i][j] != 0)
					canh += G.a[i][j];
		}
	}
	else
	{
		cout << "Cac canh do thi co huong: ";
		for (int i = 0; i < G.n; i++)
			for (int j = 0; j < G.n; j++)
				if (G.a[i][j] != 0)
					canh+=G.a[i][j];
	}
	return canh;
}

void convertDirecttoIndirect(GRAPH &G)
{
	if (!checkVohuong(G))
	{
		if (checkCoKhuyen(G))
		{
			for (int i = 0; i < G.n; i++)
				if (G.a[i][i] != 0)
					G.a[i][i] *= 2;
		}
		for (int i = 0; i < G.n; i++)
			for (int j = 0; j < G.n;j++)
				if (G.a[i][j] != G.a[j][i])
				{
					if (G.a[i][j]>G.a[j][i])
						G.a[j][i] = G.a[i][j];
					else
						G.a[i][j] = G.a[j][i];
				}
					
	}
}

void eraseEdge(GRAPH &G, int u, int v)
{
	if (checkVohuong(G))
	{
		G.a[u][v] = 0;
		G.a[v][u] = 0;
	}
	else
	{
		G.a[u][v] = 0;
	}
}
void addEdge(GRAPH &G, int u, int v,int w)
{
	if (checkVohuong(G))
	{
		if (G.a[u][v] == 0)
		{
			G.a[u][v] = w;
			G.a[v][u] = w;
		}
		
	}
	else
	{
		if (G.a[u][v] == 0)
		{
			G.a[u][v] = w;
		}
	}
}
void addVertex(GRAPH &G)
{
	vector<int> v;
	v.resize(G.n);
	G.a.push_back(v);
}
void eraseVertex(GRAPH &G, int v)
{
	G.a[v].clear();
	G.a.erase(G.a.begin()+v);
	
}
void changeWeight(GRAPH &G, int u, int v,int w)
{
	if (checkVohuong(G))
	{
		if (G.a[u][v] != 0)
		{
			G.a[u][v] = w;
			G.a[v][u] = w;
		}
	}
	else
	{
		if (G.a[u][v] == 0)
		{
			G.a[u][v] = w;
		}
	}
}
void dinhKe(GRAPH G, int k)
{
	cout << "Cac dinh ke voi dinh " << k << endl;
	for (int i = 0; i < G.n; i++)
		if (G.a[k][i] != 0)
			cout << i << " ";
	cout << endl;
}
int deg(GRAPH G, int k)
{
	int bac = 0;
	if (checkVohuong(G))
	{
		for (int i = 0; i < G.n; i++)
			if (G.a[k][i] != 0)
				bac += G.a[k][i];
	}
	else
	{
		for (int i = 0; i < G.n; i++)
			if (G.a[k][i] != 0)
				bac += G.a[k][i];
		for (int i = 0; i < G.n; i++)
			if (G.a[i][k] != 0)
				bac += G.a[i][k];
		if (checkCoKhuyen(G))
			bac--;
	}
	return bac;
}


void main()
{
	ifstream ifs("dothi.txt");
	if (ifs.fail())
	{
		ifs.close();
		cout << "Open file failed. Exit!";
		return;
	}
	GRAPH G;
	ifs >> G.n;
	G.a.resize(G.n);
	for (int i = 0; i < G.n; i++)
	{
		G.a[i].resize(G.n);
		for (int j = 0; j < G.n; j++)
			ifs >> G.a[i][j];
	}
	ifs.close();

	
}