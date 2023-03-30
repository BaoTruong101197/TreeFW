/**
 *
 * @author Bao Truong
 */

#include "core/field_node.hpp"

FieldNode::FieldNode(Tree * p)
{
    m_parentPtr = p;
}

FieldNode::~FieldNode() 
{
}

Tree* FieldNode::getParent() const
{
    return m_parentPtr;
}