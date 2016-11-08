#include<vector>
#include<iostream>
#include<cassert>
using namespace std;

size_t parent(size_t i)
{
    return i/2;
}

size_t leftChild(size_t i)
{
    return i*2;
}

size_t rightChild(size_t i)
{
    return i*2+1;
}

template <typename T>
class BinaryHeap
{
public:
    BinaryHeap()
    {
        T dummy;
        v.push_back(dummy);
        size=1;
    }

    void shiftUp(size_t i)
    {
        size_t p = parent(i);
        while(i > 1 && v[i]>v[p])
        {
            swap(v[i], v[p]);
            i = p;
            p=parent(i);
        }
    }
    void push(T el)
    {
        v.push_back(el);
        size++;
        shiftUp(size-1);
    }

    void heapify(size_t i)
    {
        while(true)
        {
            size_t largest = i;
            size_t l = leftChild(i);
            size_t r = rightChild(i);
            if (l < size && v[largest] < v[l]) largest = l;
            if (r < size && v[largest] < v[r]) largest = r;
            if (largest == i) break;
            else
            {
                swap(v[i], v[largest]);
                i = largest;
            }
        }
    }

    T top() const
    {
        assert(size > 1);
        return v[1];
    }

    T pop()
    {
        assert(size > 1);
        swap(v[1], v[v.size()-1]);
        v.pop_back();
        size--;
        heapify(1);

    }
///Do tuk
    BinaryHeap(vector<T> vec)
    {
        T dummy;
        v.push_back(dummy);
        size = 1;
        size_t n = vec.size();
        int i;
        for ( i = 0 ; i < n; i++)
        {
            v.push_back(vec[i]);
            size++;
        };
        for(i = n; i > 0 ; i--) heapify(i);
    }

    void sort()
///breaks the structure's properties
///only used to show how a similar approach can be used in a sorting algorithm

    {
        int temp = size;
        for (int i = size-1; i > 1; i--)
        {
            swap(v[1], v[i]);
            size--;
            heapify(1);
        }
        size = temp;
    }

    void fix()
///Restores the structures properties
    {
        for(int i = size; i > 0 ; i--) heapify(i);
    }

    friend ostream& operator<<(ostream& out, const BinaryHeap& bh)
    {
        int n = bh.v.size();
        for (int i = 1 ; i < n; i++) out<<bh.v[i]<<" ";
        return out;
    }


private:
    vector<T> v;
    size_t size;
};


int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(4);
    v.push_back(5);
    v.push_back(2);
    v.push_back(3);
    BinaryHeap<int> b(v);
    b.sort();
    cout<<b<<endl;
    b.fix();
    cout<<b<<endl;

    return 0;
}
