#include <iostream>
#include <map>
#include <vector>

class ilist
{
  public:
    ilist(int k, int v)
    {
        key = k;
        value = v;
    }
    void setnext(ilist *val)
    {
        next = val;
    }
    void setpre(ilist *val)
    {
        pre = val;
    }
    int value;
    int key;
    ilist *next;
    ilist *pre;
};

ilist *MakeList(int k, int v)
{
    auto ilist = new class ilist(k, v);
    return ilist;
}

void deletelist(ilist *head)
{
    while (head != nullptr)
    {
        auto temp = head->next;
        delete head;
        head = temp;
    }
}

class LRUCache
{
  public:
    LRUCache(int capacity)
    {
        head = MakeList(0, 0);
        tail = MakeList(0, 0);
        head->setnext(tail);
        tail->setpre(head);
        list_size = 0;
        cap = capacity;
    }

    int get(int key)
    {
        if (imap.count(key) == 0)
        {
            return -1;
        }
        else
        {
            auto node = imap[key];
            auto pre = node->pre;
            auto next = node->next;
            pre->next = next;
            next->pre = pre;
            node->next = head->next;
            head->next->pre = node;
            node->pre = head;
            head->next = node;
            return node->value;
        }
    }

    void put(int key, int value)
    {
        if (imap.count(key) != 0)
        {
            auto node = imap[key];
            auto pre = node->pre;
            auto next = node->next;
            pre->next = next;
            next->pre = pre;
            node->next = head->next;
            head->next->pre = node;
            node->pre = head;
            head->next = node;
            node->value = value;
        }
        else
        {
            auto t = new ilist(key, value);
            if (list_size < cap)
            {

                auto next = head->next;
                head->setnext(t);
                t->setpre(head);
                t->setnext(next);
                next->setpre(t);
                list_size++;
                imap[key] = t;
            }
            else if (list_size == cap)
            {
                auto prepre = tail->pre->pre;
                auto d = prepre->next;
                imap.erase(d->key);
                delete d;
                prepre->next = tail;
                tail->pre = prepre;
                t->next = head->next;
                t->next->pre = t;
                head->next = t;
                t->pre = head;
                imap[key] = t;
            }
        }
    }
    ilist *head;
    ilist *tail;
    int list_size;
    int cap;
    std::map<int, ilist *> imap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    LRUCache cache(2 /* capacity */);

    cache.put(1, 1);
    cache.put(2, 2);
    std::cout <<cache.get(1) <<std::endl;    // returns 1
    cache.put(3, 3); // evicts key 2
    std::cout << cache.get(2) <<std::endl;    // returns -1 (not found)
    cache.put(4, 4); // evicts key 1
    std::cout << cache.get(1) <<std::endl;    // returns -1 (not found)
    std::cout << cache.get(3) << std::endl;    // returns 3
    std::cout << cache.get(4) << std::endl;    // returns 4
}
