#include "Dictionary.h"
#include <iostream>

DictionaryWrapper::DictionaryWrapper(size_t initialSize, double loadFactor)
{
    _dictionary = new HashTable(initialSize, loadFactor);
}

void DictionaryWrapper::Add(const std::string& key, const std::string& value)
{
    _dictionary->Insert(key, value);
}

void DictionaryWrapper::Remove(const std::string& key)
{
    _dictionary->Remove(key);
}

std::string DictionaryWrapper::Find(const std::string& key)
{
    return _dictionary->Find(key);
}


