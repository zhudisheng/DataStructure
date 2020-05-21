#include <iostream>
#include <cstring>
#include "Object.h"
#include "linklist.h"
using namespace std;
using namespace ZXRLib;

struct Node
{
    int value;
    Node* next;
};
Node* create_list(int v,int len)
{
    Node* ret = NULL;
    Node* slider = NULL;

    for(int i = 0;i < len;i++)
    {
        Node* n = new Node();
        n->value = v++;
        n->next = NULL;
        if(slider == NULL)
        {
            slider = n;
            ret = n;
        }
        else
        {
            slider->next = n;
            slider = n;
        }
    }
    return ret;
}
void destroy_list(Node* list)
{
    while(list)
    {
        Node* del = list;
        list = list->next;
        delete del;
    }
}
void print_list(Node* list)
{
    while(list)
    {
        cout << list->value << "->";
        list = list->next;
    }
    cout << "NULL"<<endl;
}
Node* reverse(Node* list)
{
    if((list == NULL)||(list->next == NULL))
    {
        return list;
    }
    else
    {
        Node *guard = list->next;
        Node *ret = reverse(list->next);
        guard->next = list;
        list->next = NULL;
        return ret;
    }
}
Node* merge(Node* list1,Node* list2)
{
    if(list1 == NULL)
    {
        return list2;
    }
    else if(list2 == NULL)
    {
        return list1;
    }
    else if(list1->value < list2->value)
    {
        /*
        Node* list1_ = list1->next;
        Node* list = merge(list1_,list2);
        list1->next = list;
        return list1;
        */
        return (list1->next=merge(list1->next,list2),list1);
    }
    else
    {
        /*
        Node* list2_ = list2->next;
        Node* list = merge(list1,list2_);
        list2->next = list;
        return list2;
        */
        return (list2->next=merge(list1,list2->next),list2);
    }

}
void r_printf_even(Node* list)
{
    if(list != NULL)
    {
        r_printf_even(list->next);
        if((list->value % 2) == 0)
        {
            cout << list->value << endl;
        }
    }
}
template <int SIZE>
class QueueSolution
{
protected:
    enum{N = SIZE +2};
    struct Pos:public Object
    {
        Pos(int px = 0,int py = 0):x(px),y(py){}
        int x;
        int y;
    };
    int m_chessboard[N][N];
    Pos m_direction[3];
    LinkList<Pos> m_solution;
    int m_count;
    void init()
    {
        m_count = 0;
        for(int i = 0; i< N;i+=(N-1))
        {
            for(int j = 0;j < N;j++)
            {
                m_chessboard[i][j] = 2;
                m_chessboard[j][i] = 2;
            }
        }
        for(int i = 1;i <= SIZE;i++)
        {
            for(int j = 1;j <= SIZE;j++)
            {
                m_chessboard[i][j] = 0;
            }
        }
        m_direction[0].x = -1;
        m_direction[0].y = -1;
        m_direction[1].x = 0;
        m_direction[1].y = -1;
        m_direction[2].x = 1;
        m_direction[2].y = -1;

    }
    void print()
    {
        for(m_solution.move(0);!m_solution.end();m_solution.next())
        {
             cout << "(" << m_solution.current().x << "," << m_solution.current().y << ")";
        }
        cout << endl;
        for(int i = 0;i < N;i++)
        {
            for(int j = 0;j < N;j++)
            {
                switch (m_chessboard[i][j]) {
                case 0: cout << " " ; break;
                case 1: cout << "#" ; break;
                case 2: cout << "*" ; break;
                }
            }
            cout << endl;
        }
        cout  <<endl;
    }

    bool check(int x,int y,int d)
    {
        bool flag = true;
        do
        {
            x += m_direction[d].x;
            y += m_direction[d].y;
            flag = flag &&(m_chessboard[x][y] == 0);

        }while(flag);
        return (m_chessboard[x][y] == 2);
    }
    void run(int j)
    {
        if(j <= SIZE)
        {
            for(int i = 1;i <= SIZE;i++)
            {
                if(check(i,j,0)&&check(i,j,1)&&check(i,j,2))
                {
                    m_chessboard[i][j] = 1;
                    m_solution.insert(Pos(i,j));
                    run(j+1);

                    m_chessboard[i][j] = 0;
                    m_solution.remove(m_solution.length()-1);
                }
            }
        }
        else
        {
            m_count++;
            print();
        }
    }
 public:
    QueueSolution()
    {
        init();
    }
    void run()
    {
        run(1);
        cout << "Total:" << m_count << endl;
    }

};
void HanoiTower(int n,char a,char b,char c) // a ==>src b ==>middle c ==>dst
{
    if(n == 1)
    {
        cout << a << "-->" << c << endl;
    }
    else
    {
        HanoiTower(n-1,a,c,b);
        HanoiTower(1,a,b,c);
        HanoiTower(n-1,b,a,c);
    }

}
void permutation(char *s,char *e)
{
    if(*s == '\0')
    {
        cout  << e << endl;
    }
    else
    {
        int len = strlen(s);
        for(int i = 0;i < len;i++)
        {
            if((i==0)||(s[i]!=s[0]))
            {

                swap(s[0],s[i]);
                permutation(s+1,e);
                swap(s[0],s[i]);
            }
        }
    }
}
int main()
{
    QueueSolution<4> qs;
    qs.run();

    //char s[] = "cba";
    //permutation(s,s);
    /*
    Node *list = create_list(2,5);
    print_list(list);
    r_printf_even(list);
    destroy_list(list);
    */
    //HanoiTower(3,'a','b','c');
    /*
    Node *list1 = create_list(1,5);
    Node *list2 = create_list(2,6);
    print_list(list1);
    print_list(list2);
    Node *list = merge(list1,list2);
    print_list(list);
    destroy_list(list);
    destroy_list(list1);
    destroy_list(list2);
    */
    return 0;
}
