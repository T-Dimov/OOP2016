#include<iostream>
#include<string.h>
#include<cassert>
using namespace std;
class Ticket
{
protected:
    char* show;
    double price;
    void copy(const Ticket& other)
    {
        show = new char [strlen(other.show)+1];
        strcpy(show,other.show);
        price = other.price;
    }
public:
    Ticket(const char* a,double b)
    {
        show = new char [strlen(a)+1];
        strcpy(show,a);
        price = b;
    }
    Ticket(const Ticket& other)
    {
        copy(other);
    }
    Ticket& operator=(const Ticket& other)
    {
        if(this!=&other)
        {
            delete [] show;
            copy(other);
        }
        return *this;
    }
    virtual ~Ticket()
    {
        delete [] show;
    }
    virtual double getPrice()const
    {
        return price;
    }
    virtual Ticket* clone()const
    {
        return new Ticket(*this);
    }
};
class STicket: public Ticket
{
    char* name;
    void copyST(const STicket& other)
    {
        name = new char [strlen(other.name)+1];
        strcpy(name,other.name);
    }
public:
    STicket(const char* a,double b,const char* c):Ticket(a,b)
    {
        name = new char [strlen(c)+1];
        strcpy(name,c);
    }
    STicket(const STicket& other):Ticket(other)
    {
        copyST(other);
    }
    STicket& operator=(const STicket& other)
    {
        if(this!=&other)
        {
            Ticket::operator=(other);
            delete [] name;
            copyST(other);
        }
        return *this;
    }
    ~STicket()
    {
        delete [] name;
    }
    double getPrice()const
    {
        return price/2;
    }
    virtual Ticket* clone()const
    {
        return new STicket(*this);
    }
};
class BoxOffice
{
    Ticket** arr;
    int size;
    int capacity;
    void del()
    {
        for(int i = 0; i < size; i++)
        {
            delete arr[i];
        }
        delete [] arr;
    }
    void copy(const BoxOffice& other)
    {
        size = other.size;
        capacity = other.capacity;
        arr = new Ticket* [capacity];
        for(int i=0; i<size; i++)
            arr[i]=other.arr[i]->clone();
    }
    void extend()
    {
        Ticket** temp = arr;
        capacity*=2;
        arr = new Ticket* [capacity];
        for(int i=0; i<size; i++)
            arr[i]=temp[i];
        delete [] temp;
    }
public:
    BoxOffice()
    {
        size = 0;
        capacity = 10;
        arr = new Ticket* [capacity];
    }
    BoxOffice(const BoxOffice& other)
    {
        copy(other);
    }
    ~BoxOffice()
    {
        del();
    }
    BoxOffice& operator=(const BoxOffice& other)
    {
        if(this!=&other)
        {
            del();
            copy(other);
        }
        return *this;
    }
    void add(const Ticket& a)
    {
        if(capacity == size)
            extend();
        arr[size++] = a.clone();
    }
    const Ticket* operator[](int i)const
    {
        assert(i<size);
        return arr[i]->clone();
    }
    int getSize()const
    {
        return size;
    }
};

double Money(const BoxOffice& a)
{
    int sum = 0;
    int s = a.getSize();
    for(int i=0; i<s; i++)
    {
        sum+=a[i]->getPrice();
    }
    return sum;
}

int main()
{
    BoxOffice BO;
    Ticket a("meh",10),b("test",20);
    STicket c("sdas",30,"asdasd"), d("a",40,"sds3");
    BO.add(a);
    BO.add(b);
    BO.add(c);
    BO.add(d);
    cout<<Money(BO)<<endl<<"if its 65 its correct"<<endl;
    return 0;
}
