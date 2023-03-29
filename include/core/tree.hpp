/**
 * @author Bao Truong
 */

#include "core/event_emitter.hpp"
#include "core/enums.hpp"
#include "std/unordered_map.hpp"
#include <functional>

#pragma one

class Tree 
{
public:
    Tree(Tree* ptr = nullptr);
    virtual ~Tree();

    // Setter
    void setParent(Tree* );

    // Getter
    Tree* getParent();
    virtual std::string getName();
    StringUMap<Tree*> getNodeTree();
    Tree* getChild(const std::string childName);

    // Children node
    void appendChildNode(Tree* _node);
    void removeChildNode(Tree* _node);

    void forEachChild(std::function<void(Tree*)> callback) const;

private:
    StringUMap<Tree*> m_nodeList;
    Tree* m_parentPtr {nullptr};
};