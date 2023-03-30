/**
 *
 * @author Bao Truong
 */

#include "core/node.hpp"

Node::Node(const FieldNode& _fieldNode) : Tree()
{
    appendToDefaultNode(_fieldNode);
}

Node::~Node()
{   
}

void Node::appendToDefaultNode(const FieldNode& _fieldNode)
{
    setParent(_fieldNode.getParent());
}

std::string Node::getName() const
{
    return "Node";
}