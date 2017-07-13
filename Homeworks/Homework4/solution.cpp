#include <iostream>
#include <string>

using namespace std;

class Engineer
{
public:
	Engineer(string name_ = "", size_t years = 0) :name(name_), yearsOfService(years)
	{}

	virtual ~Engineer() = default;

	virtual size_t getSalary() const
	{
		return yearsOfService * 2 + 500;
	}

	string getName() const
	{
		return name;
	}

	void setName(const string &name_)
	{
		name = name_;
	}

	size_t getYearsOfService() const
	{
		return yearsOfService;
	}

	void setYearsOfService(size_t years)
	{
		yearsOfService = years;
	}

	virtual Engineer *clone() const
	{
		return new Engineer(*this);
	}

protected:
	string name;
	size_t yearsOfService;
};


class Mentor :virtual public Engineer
{
public:
	Mentor(string name_ = "", size_t years = 0, size_t interns = 0) :Engineer(name_, years), numberOfInterns(interns)
	{}

	virtual size_t getSalary() const override
	{
		return numberOfInterns * 3 + 100;
	}

	size_t getNumberOfInterns() const
	{
		return numberOfInterns;
	}

	void setNumberOfInterns(size_t interns)
	{
		numberOfInterns = interns;
	}

	virtual Engineer *clone() const override
	{
		return new Mentor(*this);
	}

private:
	size_t numberOfInterns;
};

class QA :virtual public Engineer
{
public:
	QA(string name_ = "", size_t years = 0, size_t tests = 0) :Engineer(name_, years), numberOfTests(tests)
	{}

	virtual size_t getSalary() const override
	{
		return numberOfTests + 200;
	}

	size_t getNumberOfTests() const
	{
		return numberOfTests;
	}

	void setNumberOfTests(size_t tests)
	{
		numberOfTests = tests;
	}

	virtual Engineer *clone() const override
	{
		return new QA(*this);
	}

private:
	size_t numberOfTests;
};

class Manager :public Mentor, public QA
{
public:
	Manager(string name_ = "", size_t years = 0, size_t interns = 0, size_t tests = 0, string title_ = "", size_t projects = 0)
		:Engineer(name_, years), Mentor(name_, years, interns), QA(name_, years, tests), title(title_), numberOfProjects(projects)
	{}

	virtual size_t getSalary() const override
	{
		return numberOfProjects * 3 + 1000;
	}

	size_t getNumberOfProjects() const
	{
		return numberOfProjects;
	}

	void setNumberOfProjects(size_t projects)
	{
		numberOfProjects = projects;
	}

	string getTitle() const
	{
		return title;
	}

	void setTitle(string title_)
	{
		title = title_;
	}

	virtual Engineer *clone() const override
	{
		return new Manager(*this);
	}

private:
	string title;
	size_t numberOfProjects;
};

class Company
{
public:
	Company() :size(0), capacity(2), engineers(new Engineer*[capacity])
	{}

	Company(const Company &other)
	{
		copy(other);
	}

	Company &operator=(const Company &other)
	{
		if (this != &other)
		{
			del();
			copy(other);
		}
		return *this;
	}

	~Company()
	{
		del();
	}

	size_t totalSalary() const
	{
		size_t total = 0;
		for (size_t i = 0; i < size; i++)
		{
			total += engineers[i]->getSalary();
		}
		return total;
	}

	void add(const Engineer *eng)
	{
		if (size == capacity)
		{

			Engineer **temp = new Engineer*[capacity *= resize];
			for (size_t i = 0; i < size; i++)
			{
				temp[i] = engineers[i];
			}
			delete[] engineers;
			engineers = temp;
		}
		engineers[size++] = eng->clone();
	}

private:
	size_t size;
	size_t capacity;
	Engineer** engineers;
	static const float resize;

	void copy(const Company &other)
	{
		size = other.size;
		capacity = other.capacity;
		engineers = new Engineer*[capacity];
		for (size_t i = 0; i < size; i++)
		{
			engineers[i] = other.engineers[i]->clone();
		}
	}

	void del()
	{
		for (size_t i = 0; i < size; i++)
		{
			delete engineers[i];
		}
		delete[] engineers;
	}
};

const float Company::resize = 1.618f;

int main()
{
	Engineer eng("Gosho", 15);
	cout << eng.getName() << endl << eng.getYearsOfService() << endl << eng.getSalary() << endl << endl;
	Mentor ment("Pesho", 5, 3);
	cout << ment.getName() << endl << ment.getYearsOfService() << endl << ment.getNumberOfInterns() << endl << ment.getSalary() << endl << endl;
	QA qa("Ivan", 10, 300);
	cout << qa.getName() << endl << qa.getYearsOfService() << endl << qa.getNumberOfTests() << endl << qa.getSalary() << endl << endl;
	Manager man("Boss", 20, 10, 500, "CTO", 5);
	cout << man.getName() << endl << man.getYearsOfService() << endl << man.getNumberOfInterns() << endl << man.getNumberOfTests() << endl
		<< man.getTitle() << endl << man.getNumberOfProjects() << endl << man.getSalary() << endl << endl;

	Company copy;
	cout << copy.totalSalary() << endl;
	{
		Company comp;
		comp.add(&eng);
		comp.add(&ment);
		cout << comp.totalSalary() << endl;
		comp.add(&qa);
		comp.add(&man);
		cout << comp.totalSalary() << endl;

		copy = comp;
	}
	cout << copy.totalSalary() << endl;

	cin.get();
	return EXIT_SUCCESS;
}

