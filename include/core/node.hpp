/**
 * @author Bao Truong
 */

#include "core/event_emitter.hpp"
#include "std/unordered_map.hpp"
#include "core/field_node.hpp"
#include "core/tree.hpp"

#pragma one

class Node : public Tree
{
public:
    explicit Node(FieldNode& _fieldNode);
    virtual ~Node();

    // get the name of each node
    virtual std::string getName() const;

    void appendToDefaultNode(FieldNode& _fieldNode);

private:
    FieldNode m_defaultFieldNode;
    StringUMap<Node*> m_nodeListStr;
};