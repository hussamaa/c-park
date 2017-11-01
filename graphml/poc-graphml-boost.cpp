#include <iostream>
#include <boost/graph/graphml.hpp>

struct nodept
{
  std::string invariant;
  std::string invariant_scope;
  bool violation;
  bool frontier;
  bool entry;
  bool sink;
};

struct edgept
{
  std::string sourcecode;
  uint32_t startline;
  uint32_t startoffset;
  uint32_t endline;
  uint32_t endoffset;
  bool enterLoopHead;
  std::string control;
  std::string assumption;
  std::string assumption_scope;
  std::string assumption_resultaction;
  std::string enterFunction;
  std::string returnFromFunction;
};

int main(){

  std::cout << "teste" << std::endl;

  using namespace boost;

  typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, nodept, edgept> grapht;

  grapht g(0);
  typedef grapht::vertex_descriptor vertexdt;
  typedef grapht::edge_descriptor edgedt;

  vertexdt vdn1 = add_vertex(g);
  g[vdn1].violation = 1;

  vertexdt vdn2 = add_vertex(g);
  g[vdn2].violation = 1;

  vertexdt vdn3 = add_vertex(g);
  g[vdn3].violation = 0;

  edgedt e1 = add_edge(vdn1, vdn2, g).first;
  g[e1].endline=10;
  g[e1].startline=3;

  edgedt e2 = add_edge(vdn2, vdn3, g).first;

  dynamic_properties dp;
  write_graphml(std::cout, g, dp, true);

  typedef boost::property_map<grapht, vertex_index_t>::type IndexMap;
  IndexMap index = get(vertex_index, g);

  typedef boost::property_map<grapht, edge_index_t>::type IndexEdgeMap;

  std::cout << "edges(g) = ";
    boost::graph_traits<grapht>::edge_iterator ei, ei_end;
    for (tie(ei, ei_end) = edges(g); ei != ei_end; ++ei)
    {
        std::cout << "(" << g[index[source(*ei, g)]].violation
                  << "," << g[index[target(*ei, g)]].violation << ") ";
    }
  std::cout << std::endl;

  return 0;
}
