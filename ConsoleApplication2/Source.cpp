#include <iostream>
#include <iomanip>

template<class T>
class Stack {
private:
	template<class T>
	class Element {
	public:
		T m_value;
		Element* m_prev;
	
		Element(T value):m_value(value), m_prev(NULL){}

		~Element() { if (m_prev) delete m_prev; }
	};

	Element<T>* m_ptr;
public:
	Stack():m_ptr(NULL){}

	void push(T value) {
		Element<T>* new_element = new Element<T>(value);
		if (m_ptr == NULL) {
			m_ptr = new_element;
			return;
		}
		new_element->m_prev=m_ptr;
		m_ptr = new_element;
	}

	void print() {
		if (m_ptr == NULL) {
			std::cout << "Stack is empty.";
			return;
		}
		Element<T>* el = m_ptr;
		while (el) {
			std::cout << el->m_value << " ";
			el = el->m_prev;
		}
	}

	T peek() {
		if (m_ptr == NULL) return 0;
		return m_ptr->m_value;
	}

	T pop() {
		if (m_ptr == NULL) return 0;
		T val = m_ptr->m_value;
		Element<T>* p = m_ptr->m_prev;
		m_ptr->m_prev = NULL;
		delete m_ptr;
		m_ptr = p;
		return val;
	}

	~Stack() { delete m_ptr; }
};

int main() {
	Stack<int> stack;
	stack.push(5);
	stack.push(20);
	stack.push(10);
	stack.push(15);
	stack.print();
	stack.pop();
	std::cout << std::endl;
	stack.print();
	while (stack.pop());
	std::cout << std::endl;
	stack.print();


	std::cin.seekg(0);
	std::cin.ignore();
	return 0;
}