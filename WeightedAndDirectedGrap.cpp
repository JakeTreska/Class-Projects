#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

template<typename T>
class graph{
public:
graph();
void addVertex(const T& label);
void removeVertex(const T& label);
void addEdge(const T& source, const T& target, double value);
void removeEdge(const T& source, const T& target);
void print_edges_table();
void print_vertex_table();
unsigned int vertex_size();
unsigned int num_of_edges();
vector<double>& vAdjacent(const T& source);
bool isEdge(const T& source, const T& target);
void breadth_First_Print(unsigned int sVertex);
unsigned int nConnectedComponent();
bool isConnected();
void Depth_First_Print(unsigned int sVertex);
void printPath(const T& label, const T& source);
void shortest_distance(const T& label,const T& target);
void shortest_path(const T& label,const T& target);
private:
  vector<T> labels;
  vector<vector<double> > edges;  // space is required between 2 >> signs
  unsigned int iVertex(const T& label);
  double Minimum_Distance(vector<double>& a, vector<bool>& b);
};


template<typename T>
graph<T>::graph(){
  labels = vector<T>();
  edges = vector<vector<double> >();
}

template<typename T>
unsigned int graph<T>::iVertex(const T& label){
  for(unsigned int i = 0; i < labels.size(); i++){
    if(labels[i] == label) return i;
  }
  return UINT32_MAX;
}

template<typename T>
void graph<T>:: print_vertex_table(){
  for(unsigned int i = 0; i < labels.size(); i++){
    cout<<labels[i]<<"  ";
  }
cout<<endl;
}

template<typename T>
void graph<T>:: print_edges_table(){
  for(int i = 0; i < edges.size(); i++){
    for(int j = 0; j < edges[i].size(); j++){
      cout<<edges[i][j]<<" ";
    }
    cout<<endl;
  }
}

template<typename T>
unsigned int graph<T>:: vertex_size(){
  return labels.size();
}

template<typename T>
unsigned int graph<T>:: num_of_edges(){
  unsigned int total = 0;
  for(int i = 0; i < edges.size(); i++){
    for(int j = 0; j < edges[i].size(); j++){
      if(edges[i][j] != -1)
        total += 1;
    }
  }
  return total;
}

template<typename T>
void graph<T>:: addVertex(const T& label){
  if(find(labels.begin(),labels.end(),label) == labels.end()){
    labels.push_back(label);
    edges.push_back(vector<double>());
  }
  if(labels.size() == 1){
    edges[0].push_back(-1);
  }
  else{
    for(int i = 0; i < labels.size() - 1; i++){
      edges[i].push_back(-1);
    }
    int size = edges.size() - 1;
    for(int i = 0; i < labels.size(); i++){
      edges[size].push_back(-1);
    }
  }
}

template<typename T>
void graph<T>:: addEdge(const T& label, const T& source, double value){
  unsigned int iSource = iVertex(label);
  unsigned int iTarget = iVertex(source);
  assert(iSource != UINT32_MAX && iTarget != UINT32_MAX);
  vector<double>& vVector = edges[iSource];
  if(iTarget < vVector.size()){
    vVector[iTarget] = value;
  }
}

template<typename T>
void graph<T>:: removeVertex(const T& label){
  unsigned int iSource  = iVertex(label);
  for(int i = iSource; i < vertex_size() - 1; i++){
    swap(labels[i],labels[i+1]);
    swap(edges[i],edges[i+1]);
  }
  labels.erase(labels.begin() + labels.size() - 1);
  edges.erase(edges.begin() + edges.size() - 1);
  for(int i = 0; i < labels.size(); i++){
    for(int j = iSource; j < edges[i].size() - 1; j++){
      edges[i][j] = edges[i][j+1];
    }
    edges[i].erase(edges[i].begin() + edges[i].size() - 1);
  }
}

template<typename T>
void graph<T>:: removeEdge(const T& label, const T& source){
  unsigned int iSource = iVertex(label);
  unsigned int iTarget = iVertex(source);
  assert(iSource != UINT32_MAX && iTarget != UINT32_MAX);
  vector<double>& vVector = edges[iSource];
  if(iTarget < vVector.size()){
    vVector[iTarget] = -1;
  }
}

template<typename T>
vector<double>& graph<T>:: vAdjacent(const T& source){
  unsigned int iSource = iVertex(source);
  assert(iSource != UINT32_MAX);
  return edges[iSource];
}

template<typename T>
bool graph<T>:: isEdge(const T& source, const T& target){
  unsigned int iSource = iVertex(source);
  unsigned int iTarget = iVertex(target);
  assert(iSource != UINT32_MAX && iTarget != UINT32_MAX);
  return (edges[iSource][iTarget] != - 1);
}

template<typename T>
void graph<T>:: breadth_First_Print(unsigned int sVertex){
  cout<<"Breadth First Traversal:  ";
  queue<unsigned int> q;
  vector<bool> visited(vertex_size(),false);
  q.push(sVertex);
  visited[sVertex] = true;
  while(!q.empty()){
    unsigned int v = q.front();
    q.pop();
    cout<<labels[v]<<" ";
    for(int i = 0; i < edges[v].size(); i++){
      if(edges[v][i] != -1){
        if(!visited[i]){
          q.push(i);
          visited[i] = true;
        }
      }
    }
  }
  cout<<endl;
}

template<typename T>
unsigned int graph<T>:: nConnectedComponent(){
  queue<unsigned int> q;
  vector<bool> visited(vertex_size(),false);
  unsigned int count = 0;
  for(unsigned int i = 0; i < vertex_size(); i++){
    if(!visited[i]){
      count++;
      q.push(i);
      visited[i] = true;
      while(!q.empty()){
        unsigned int v = q.front();
        q.pop();
        for(int i = 0; i < edges[v].size(); i++){
          if(edges[v][i] != -1){
            if(!visited[i]){
              q.push(i);
              visited[i] = true;
            }
          }
        }
      }
    }
  }
  return count;
}


template<typename T>
bool graph<T>:: isConnected(){
  return nConnectedComponent() == 1;
}


template<typename T>
void graph<T>:: Depth_First_Print(unsigned int sVertex){
  cout<<"Depth First Traversal:  ";
  stack<unsigned int> s;
  vector<bool> visited(vertex_size(),false);
  s.push(sVertex);
  visited[sVertex] = true;
  while(!s.empty()){
    unsigned int v = s.top();
    s.pop();
    cout<<labels[v]<<" ";
    for(int i = edges[v].size() - 1; i >= 0; i--){
      if(edges[v][i] != -1){
        if(!visited[i]){
          s.push(i);
          visited[i] = true;
        }
      }
    }
  }
  cout<<endl;
}

template<typename T>
void graph<T>:: printPath(const T& label, const T& target){
  unsigned int source = iVertex(label);
  unsigned int destination = iVertex(target);
  cout<<"path from "<<labels[source]<<" to "<<labels[destination]<<": ";
  stack<unsigned int> s;
  vector<bool> visited(vertex_size(),false);
  s.push(source);
  visited[source] = true;
  vector<int> predecessor(vertex_size(),-1);
  while(!s.empty()){
    unsigned int v = s.top();
    s.pop();
    for(int i = edges[v].size() - 1; i >= 0; i--){
      if(edges[v][i] != -1){
        if(!visited[i]){
          s.push(i);
          visited[i] = true;
          predecessor[i] = v;
        }
      }
    }
  }
  while(destination != -1){
    cout<<labels[destination]<<" ";
    destination = predecessor[destination];
  }
}

template<typename T>
double graph<T>:: Minimum_Distance(vector<double>& a, vector<bool>& b){
  double min = UINT32_MAX;
  double h;
  for(int i = 0; i < a.size(); i++){
    if(b[i] == false && a[i] <= min){
      min = a[i];
      h = i;
    }
  }
  return h;
}


template<typename T>
void graph<T>:: shortest_distance(const T& label, const T& target){
  int iSource = iVertex(label);
  int iTarget = iVertex(target);
  vector<double> distance(vertex_size(),UINT32_MAX);
  vector<bool> set(vertex_size(),false);
  distance[iSource] = 0;
  for(int i = 0; i < distance.size(); i++){
    double s = Minimum_Distance(distance,set);
    set[s] = true;
    for(int j = 0; j < distance.size(); j++){
      if(!set[j] && edges[s][j] != -1 && distance[s] != UINT32_MAX && distance[s] + edges[s][j] < distance[j]){
        distance[j] = distance[s] + edges[s][j];
      }
    }
  }
  for(int k = 0; k < distance.size(); k++){
    cout<<labels[k]<<"    "<<distance[k]<<endl;
  }
  cout<<"the shortest distance from "<<label<<" to "<<target<<" is: "<<distance[iTarget]<<endl;
}

template<typename T>
void graph<T>::shortest_path(const T& label, const T& target){
  int iSource = iVertex(label);
  int iTarget = iVertex(target);
  vector<double> distance(vertex_size(),UINT32_MAX);
  vector<bool> set(vertex_size(),false);
  vector<double> parent(vertex_size());
  // for(int i = 0; i < vertex_size(); i++){
  //   parent[i] = i;
  // }
  distance[iSource] = 0;
  for(int i = 0; i < distance.size(); i++){
    double s = Minimum_Distance(distance,set);
    set[s] = true;
    for(int j = 0; j < distance.size(); j++){
      if(!set[j] && edges[s][j] != -1 && distance[s] != UINT32_MAX && distance[s] + edges[s][j] < distance[j]){
        distance[j] = distance[s] + edges[s][j];
        parent[j] = s;
      }
    }
  }
  int counter = 0;
  for(int k = 0; k < parent.size(); k++){
    double node = parent[k];
    cout<<labels[k]<<"    "<<distance[k]<<" ";
    cout<<labels[k]<<"-";
    while(iSource != node){
      cout<< labels[node]<<"-";
      node = parent[node];
    }
    cout<< labels[node];
    cout<<endl;
  }
}

/*
-1 5 -1 -1 -1 5
-1 -1 5 -1 -1 -1
-1 -1 -1 5 -1 -1
-1 -1 -1 -1 -1 -1
-1 -1 -1 -1 -1 -1
-1 -1 -1 -1 5 -1
*/

int main(){
graph<string> a;
a.addVertex("a");
a.addVertex("b");
a.addVertex("c");
a.addVertex("d");
a.addVertex("e");
a.addVertex("f");
a.addEdge("a","b",5);
a.addEdge("a","f",5);
a.addEdge("b","c",5);
a.addEdge("c","d",5);
a.addEdge("f","e",5);
// a.removeVertex("a");
a.print_vertex_table();
cout<<endl;
a.print_edges_table();
a.shortest_distance("a","d");
a.shortest_path("a","d");
// a.printPath("b","d");
// cout<<a.isConnected()<<endl;
// a.breadth_First_Print(0);
// a.Depth_First_Print(0);
// a.printPath(0,3);
// cout<<a.num_of_edges()<<endl;
}
