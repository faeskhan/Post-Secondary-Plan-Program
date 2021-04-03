#include <iostream>
#include <fstream>
#include <string>

void DFT (int v, int size, std::string labels[], bool visited[], bool adj[][20]){
std::cout<<" "<<labels[v];
visited[v] = true; 
for(int i = 0; i < size; ++i){
if (adj[v][i]){
  if (!visited[i]){
  DFT(i, size, labels, visited, adj);
  }
}
}
}
int main() { 
    std::string fileName = "./prereqs.txt";
    std::ifstream fin(fileName.c_str());
    int numNodes;
    fin>>numNodes;

    std::string labels[numNodes];
    for (int i = 0; i < numNodes; ++i){
        fin>>labels[i];
    }

    int numEdges; 
    fin>>numEdges; 

    bool adj[20][20];
    for(int i = 0; i < numNodes; ++i){
        for(int j = 0; j < numNodes; ++j){
            adj[i][j] = false;
        }
    }

    int from, to;
    for (int i = 0; i < numEdges; ++i) { 
        fin>>from; 
        fin>>to;
        adj[from][to] = true; 
    }

    std::cout<<"Vertices: "<<std::endl;
    for(int i = 0; i < numNodes; ++i){
        std::cout<<"[" <<i<< ":"<<labels[i]<<"] ";
    }
        std::cout<<std::endl;
        std::cout<<"Edges: "<<std::endl;

        for(int i = 0; i < numNodes; ++i){
            std::cout<<labels[i]<<" -> ";
            for(int j = 0; j < numNodes; ++j){
                if (adj[i][j]){
                    std::cout<<labels[j]<<" ";
                }
            }
            std::cout<<std::endl;
        }
        
        bool visited[numNodes];
        for(int i = 0; i < numNodes; ++i){
        visited[i] = false; 
        }
        std::cout<<"Topological Sort found: "<<std::endl;
        DFT(1, numNodes, labels, visited, adj);
        std::cout<<std::endl;
    return 0;
}