/**
 *
 * @author Bao Truong
 */

#include "core/tree.hpp"

Tree::Tree(Tree* p) : EventEmitter()
{
    setParent(p);
}

Tree::~Tree()
{    
}

Tree* Tree::getParent()
{
    return m_parentPtr;
}

void Tree::setParent(Tree* _node)
{    
    if (this->getParent() != _node)
    {
        if (this->getParent() != nullptr)
        {
            this->getParent()->removeChildNode(this);
        }
        m_parentPtr = _node;
        if (this->getParent() != nullptr)
        {
            this->getParent()->appendChildNode(this);
        }
    }
}

static int i = 0;

void Tree::appendChildNode(Tree* _node)
{
    m_nodeList.insert((std::pair<std::string, Tree*>){std::to_string(i), _node});
    i++;
}

void Tree::removeChildNode(Tree* _node)
{

}

std::string Tree::getName()
{
    return "Node Name";
}

Tree* Tree::getChild(const std::string childName)
{
    const auto it = m_nodeList.find(childName);
    if (it != m_nodeList.end())
    {
        return (*it).second;
    }
    return nullptr;
}

StringUMap<Tree*> Tree::getNodeTree()
{   
    return m_nodeList;
}

void Tree::forEachChild(std::function<void(Tree*)> callback) const
{
    for (const auto& pair : m_nodeList)
    {
        if (pair.second)
        {
            callback(pair.second);
        }
    }
}