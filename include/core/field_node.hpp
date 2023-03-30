/**
 *
 * @author Bao Truong
 */

#include "std/unordered_map.hpp"
#include "core/event_emitter.hpp"

#pragma one

class Tree;

class FieldNode 
{
public:
    FieldNode(Tree * p = nullptr);

    ~FieldNode();

    Tree* getParent() const;
private:
    Tree* m_parentPtr {nullptr};
    StringUMap<Tree*> m_fieldList;
    EventEmitter<> events;
};