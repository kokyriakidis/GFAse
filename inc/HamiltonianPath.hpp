#ifndef GFASE_HAMILTONIAN_PATH_HPP
#define GFASE_HAMILTONIAN_PATH_HPP

#include "bdsg/hash_graph.hpp"

#include <vector>
#include <unordered_set>
#include <limits>

using bdsg::HandleGraph;
using handlegraph::handle_t;
using handlegraph::nid_t;
using std::vector;
using std::unordered_set;
using std::numeric_limits;

namespace gfase {

struct HamilonianProblemResult {
public:
    HamilonianProblemResult() = default;
    ~HamilonianProblemResult() = default;
    
    bool is_solved = false;
    vector<handle_t> hamiltonian_path;
    bool is unique = false;
    vector<handle_t> unique_prefix;
}

// empty vectors for starts or ends indicdate that any start or end node is allowed
// allowed starts and ends are oriented
HamilonianProblemResult find_hamiltonian_path(const HandleGraph& graph,
                                              const unordered_set<nid_t>& target_nodes,
                                              const unordered_set<nid_t>& prohibited_nodes,
                                              const unordered_set<handle_t>& allowed_starts,
                                              const unordered_set<handle_t>& allowed_ends,
                                              size_t max_iters = numeric_limits<size_t>::max());

}

#endif // GFASE_HAMILTONIAN_PATH_HPP
