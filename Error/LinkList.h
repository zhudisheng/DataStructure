#ifndef LINKLIST_H
#define LINKLIST_H
#include "List.h"
#include "Exception.h"
namespace ZXRLib{

template<typename T>
class LinkList:public List<T>
{
protected:
    struct Node:public Object
    {
        T value;
        Node* next;
    };
    //mutable Node m_header;
    mutable struct:public Object {
        char reserved[sizeof(T)];
        Node* next;
    }m_header;
    int m_length;
    Node* position(int i) const
    {
        Node* ret = reinterpret_cast<Node*>(&m_header);
        for(int p = 0;p < i;p++)
        {
            ret = ret->next;
        }
        return ret;
    }
public:
    LinkList()
    {
        m_header.next = NULL;
        m_length = 0;
    }
    bool insert(const T&e)
    {
        return insert(m_length,e);
    }
    bool insert(int i,const T&e)
    {
        bool ret = ((0<=i)&&(i<=m_length));
        if(ret)
        {
            Node *node = new Node();
            if(node != NULL)
            {
                //Node* current = &m_header;
                Node* current = position(i);
                /*
                for(int p=0;p<i;p++)
                {
                    current = current->next;
                }
                */
                node->value = e;
                node->next = current->next;
                current->next = node;
                m_length++;
            }
            else
            {
               THROW_EXCEPTION(NoEnoughMemoryException,"No memory to insert new element...");
            }
        }
    }
    bool remove(int i)
    {
        bool ret = ((0<=i)&&(i<m_length));
        if(ret)
        {
            Node* current = position(i);
            /*
            Node* current = &m_header;
            for(int p=0;p<i;p++)
            {
                current = current->next;
            }
            */
            Node* toDel = current->next;
            current->next = toDel->next;
            delete toDel;
            m_length--;
        }
    }
    bool set(int i,const T&e)
    {
        bool ret = ((0<=i)&&(i<m_length));
        if(ret)
        {
            position(i)->next->value = e;
            /*
            Node* current = &m_header;
            for(int p = 0;p < i;p++)
            {
                current = current->next;
            }
            current->next->value = e;
            */
        }
        return ret;
    }
    T get(int i)const
    {
        T ret;
        if(get(i,ret))
        {
            return ret;
        }
        else
        {
            THROW_EXCEPTION(IndexOutOFBoundsException,"Invalid parameter i to get element...");
        }
    }
    bool get(int i,T&e)const
    {
        bool ret = ((0<=i)&&(i<m_length));
        if(ret)
        {
            e = position(i)->next->value;
            /*
            Node* current = &m_header;
            for(int p = 0;p < i;p++)
            {
                current = current->next;
            }
            e = current->next->value;
            */

        }
        return ret;
    }
    int find(const T& e)const
    {
        int ret = -1;
        int i = 0;
        Node* node = m_header.next;
        while(node)
        {
            if(node->value == e )
            {
                ret = i;
                break;
            }
            else
            {
                node = node->next;
                i++;
            }
        }
        return ret;
    }
    int length()const
    {
        return m_length;
    }
    void clear()
    {
        while(m_header.next)
        {
            Node*toDel = m_header.next;
            m_header.next = toDel->next;
            delete toDel;
        }
        m_length = 0;
    }
    ~LinkList()
    {
        clear();
    }

};
}
#endif // LINKLIST_H
