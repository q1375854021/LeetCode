#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <queue>

class Edge;
class Node;


// 创立并查集
class UnionSet{
    public:
        int n;
        std::vector<int> father;

        UnionSet(){
            n = 1000;
            father.reserve(n);
            for(int i=0; i<n;i++){
                father[i] = i;
            }
        }

        int find(int u){
            if(u == father[u]){
                return u;
            }
            else{
                return find(father[u]);
            }
        }

        bool isSameset(int u, int v){
            u = find(u);
            v = find(v);
            return u==v;
        }

        void UnionTwoSet(int u, int v){
            u = find(u);
            v = find(v);
            if(u == v) return;
            father[v] = u;
        }

};


class Node{
    public:
        int value;
        int in;
        int out;
        std::vector<Node *> nexts;
        std::vector<Edge *> edges;
        Node():value(0),in(0),out(0){};
        Node(int value):value(value),in(0),out(0){};
};

class Edge{
    public:
        int weight;
        Node *from;
        Node *to;
        Edge(int weight, Node *from, Node *to):weight(weight),from(from),to(to){};
};

class Graph{
    public:
        std::unordered_map<int, Node *> nodes;
        std::unordered_set<Edge *> edges;
        Graph(){};
        ~Graph(){};
        Graph * graph_set(std::vector<std::vector<int>> &points){
            Graph *graph = new Graph();
            int weight = 0;
            int from = 0;
            int to = 0;
            for(auto m=0; m<points.size()-1; m++){      // from
                for(auto mt = m+1; mt < points.size(); mt++){   //to
                    std::vector<int> mt_point = points[mt];
                    std::vector<int> m_point = points[m];
                    from = m;
                    to = mt;
                    weight = std::abs( (mt_point[1]-m_point[1])) +  std::abs(mt_point[0]-m_point[0]);
                    if(graph->nodes.find(from) == graph->nodes.end()){  // 如果这个点没有出现过
                        graph->nodes[from] = new Node(from);
                    }
                    if(graph->nodes.find(to) == graph->nodes.end()){  // 如果这个点没有出现过
                        graph->nodes[to] = new Node(to);
                    }
                    // 找到from和to对应的两个节点 以及创建新边
                    Node *from_node = graph->nodes[from];
                    Node *to_node = graph->nodes[to];
                    Edge *new_edge = new Edge(weight,from_node,to_node);
                    from_node->out++;
                    from_node->nexts.emplace_back(to_node);
                    from_node->edges.emplace_back(new_edge);
                    to_node->in++;
                    graph->edges.insert(new_edge);

                    // // 构建无向图
                    // std::vector<int> mt_point1 = points[mt];
                    // std::vector<int> m_point1 = points[m];
                    // from = m;
                    // to = mt;
                    // weight = std::abs(mt_point1[1]-m_point1[1])+ std::abs(mt_point1[0]-m_point1[0]);
                    // if(graph->nodes.find(from) == graph->nodes.end()){  // 如果这个点没有出现过
                    //     graph->nodes[from] = new Node(from);
                    // }
                    // if(graph->nodes.find(to) == graph->nodes.end()){  // 如果这个点没有出现过
                    //     graph->nodes[to] = new Node(to);
                    // }
                    // // 找到from和to对应的两个节点 以及创建新边
                    // Node *from_node1 = graph->nodes[from];
                    // Node *to_node1 = graph->nodes[to];
                    // Edge *new_edge1 = new Edge(weight,from_node1,to_node1);
                    // from_node1->out++;
                    // from_node1->nexts.emplace_back(to_node1);
                    // from_node1->edges.emplace_back(new_edge1);
                    // to_node1->in++;
                    // graph->edges.insert(new_edge1);
                }
            }
            return graph;
        }

        std::unordered_set<Edge *> *krustalMST(Graph *graph){
            // 首先创立并查集
            UnionSet my_unionset;
            // 创立小根堆
            auto comp = [](Edge *a, Edge *b){return a->weight > b->weight;};
            std::priority_queue<Edge *, std::vector<Edge *>, decltype(comp)> myqueue(comp);

            // 然后把所有的边都放在小根堆里
            for(auto &m: graph->edges){
                myqueue.push(m);
            }

            // 然后开始遍历
            std::unordered_set<Edge *> *result = new std::unordered_set<Edge *>();
            while(!myqueue.empty()){
                Edge *edge = myqueue.top();
                myqueue.pop();
                if(my_unionset.isSameset(edge->from->value, edge->to->value)){
                    continue;
                }
                else{
                    result->insert(edge);
                    my_unionset.UnionTwoSet(edge->from->value, edge->to->value);
                }
            }
            return result;
        }
};


class Solution {
public:
    int minCostConnectPoints(std::vector<std::vector<int>>& points) {
        Graph *my_graph = new Graph();
        my_graph = my_graph->graph_set(points);
        std::unordered_set<Edge *> *result = my_graph->krustalMST(my_graph);
        int weight = 0;
        for(auto &m: *result){
            weight = weight + m->weight;
        }
        return weight;
    }
};


int main()
{   
    std::vector<std::vector<int>> points = {{3,12}, {-2,5}, {-4,1}};
    Solution solution;
    int Length = solution.minCostConnectPoints(points);
    std::cout << Length;
    return 0;
}
