/**
 *
 * @author Bao Truong
 */

#include "core/node.hpp"

#pragma one

class Tree;

class Component : public Node
{
public:
    explicit Component(const FieldNode & _fieldNode = {});
};