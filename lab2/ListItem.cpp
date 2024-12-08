#include "ListItem.h" 

//  онструктор класса Node
// »нициализирует узел списка с заданным значением и устанавливает указатели Prev и Next в nullptr
Node::Node(int value)
    : Data(value), Prev(nullptr), Next(nullptr) {}
