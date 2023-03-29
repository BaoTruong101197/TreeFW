/**
 *
 * @author Bao Truong
 */

#include "core/node.hpp"

Node::Node(const FieldNode& _fieldNode) : Tree()
{
    
}

Node::~Node()
{   
}

std::string Node::getName() const
{
    return "Node";
}