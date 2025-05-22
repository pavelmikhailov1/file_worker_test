
#include <queue>
#include <map>
#include <string>
#include <vector>

/**
 * @class AhoCorasick
 * @brief Implementation of the Aho-Corasick algorithm for multi-pattern string searching.
 *
 * This class allows adding multiple search patterns (tokens) and then efficiently
 * finding all occurrences of those patterns in a given text using a trie and failure links.
 */
class AhoCorasick {
public:
    /**
     * @brief Destructor. Frees all dynamically allocated memory.
     */
    ~AhoCorasick();

    /**
     * @brief Adds a pattern (token) to the search structure.
     * 
     * @param pattern The string pattern to be added.
     * @param countPtr A pointer to a counter variable that will be incremented
     *                 each time this pattern is found in the text.
     *
     * Each time the pattern appears in the input text, the value at countPtr will be incremented.
     */
    void addToken(const std::string& pattern, size_t* countPtr);

    /**
     * @brief Builds the failure links for the Aho-Corasick automaton.
     *
     * Must be called after all patterns are added and before running a search.
     */
    void build();

    /**
     * @brief Searches the input text for all occurrences of added patterns.
     * 
     * @param text The input string in which to search for pattern matches.
     *
     * Increments the appropriate counters for each pattern match found in the text.
     */
    void search(const std::string& text);

private:
    /**
     * @struct Node
     * @brief Internal structure representing a trie node in the Aho-Corasick automaton.
     */
    struct Node {
        std::map<char, Node*> children;   ///< Transitions for each character.
        Node* fail = nullptr;             ///< Failure link for fallback transitions.
        std::vector<size_t*> outputs;     ///< Pointers to counters for patterns ending at this node.
    };

    /**
     * @brief Recursively deallocates memory for a node and all its descendants.
     * 
     * @param node Pointer to the root of the subtree to delete.
     */
    void clear(Node* node);

    Node* root = new Node;  ///< Root of the trie.
};
