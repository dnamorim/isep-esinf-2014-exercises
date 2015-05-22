#ifndef _heap_
#define _heap_

#include <vector>
#include <algorithm>

using namespace std;

template <class T>
class heap
{
private:
	vector<T> hv;

	void percolate_up();
	void percolate_down(int i);

public:
	heap();
	heap(const vector <T> &v);
	heap(const heap &h);

	void push(const T &el);
	T pop();
	T top() const; 
	bool empty() const;

	void heapsort (vector <T> &v) ;
    void deleteRepetedElm();

	void write(ostream &out) const;
};

template <class T>
void heap<T>::percolate_up()
{
	int i = hv.size()-1, pi = (i-1) / 2;  

	while (hv[pi]<hv[i])
	{
		swap(hv[pi], hv[i]);
		i = pi; pi = (i-1)/2;
	}
}

template <class T>
void heap<T>::percolate_down(int i)
{
	int si1 = 2*i + 1, si2 = 2*i + 2, sz = hv.size();

	while ( ((si1<sz) && (hv[i]<hv[si1])) || ((si2<sz) && (hv[i]<hv[si2])) )
	{
		if ((si2>=sz) || (hv[si2]<hv[si1]))
		{
			swap(hv[si1], hv[i]);
			i = si1;
		} 
		else
		{
			swap(hv[si2], hv[i]);
			i = si2;
		}
		si1 = 2*i + 1; si2 = 2*i + 2;
	}
}

template <class T>
heap<T>::heap() : hv() {}


/*
The optimal method starts by arbitrarily putting the elements on a binary tree (represented by an array), respecting the shape property.
Then starting from the lowest level and moving upwards, shift the root of each subtree downward as in the percolate_down algorithm until the heap property is restored.
*/

template <class T>
heap<T>::heap(const vector <T> &v) : hv(v) 
{
	// make_heap(hv.begin(), hv.end()); // STL library equivalent
	int sz=hv.size(), i = sz-1;

	while (i>0)
	{
		int pi = (i-1) / 2;
		int si1 = 2*pi + 1, si2 = 2*pi + 2;

		if ( (hv[pi]<hv[si1]) || ((si2<sz) && (hv[pi]<hv[si2])) )
		{
			if ((si2>=sz) || (hv[si2]<hv[si1]))
			{
				swap(hv[si1], hv[pi]);
				i = si1;
			} else
			{
				swap(hv[si2], hv[pi]);
				i = si2;
			}
			percolate_down(i);
			cout << *this;
		}
		i=si1-1;
	}
}

template <class T>
heap<T>::heap(const heap &h) : hv(h.hv) {}

template <class T>
void heap<T>::push(const T&el) 
{
	hv.push_back(el);
	percolate_up();
}

template <class T>
T heap<T>::pop()
{
	T elem = hv.front() ;
	hv.front() = hv.back();
	hv.pop_back();
	percolate_down(0);

	return elem ;
}

template <class T>
T heap<T>::top() const 
{
	return hv[0];
}

template <class T>
bool heap<T>::empty() const
{
	return hv.empty();
}

template <class T> 
void heap<T>::heapsort (vector <T> &v)
{ 
	for (int i = 0 ; i < v.size() ; i++)
		push(v[i]) ;
    
	for (int i = 0 ; i < v.size() ; i++)
		v[i] = pop() ;
} 

template <class T>
void heap<T>::write(ostream &out) const
{
	int i=1, i2=1;
	for ( auto el : hv) 
	{
		out << el << " ";
		if (i==i2) 
		{
			i2=i*2;	i=1;
			cout << endl;
		} else i++;
	}
	out << endl;
}

template <class T>
ostream &operator<<(ostream &out, const heap<T> &h)
{
	h.write(out);
	return out;
}

template<class T>
void heap<T>::deleteRepetedElm() {
    vector<T> hv1 = hv;
    this->hv.clear();
    
    for (unsigned int i = 0; i < hv1.size(); i++) {
        typename vector<T>::iterator it;
        it = find(this->hv.begin(), this->hv.end(), hv1[i]);

        if (it == this->hv.end()) {
            push(hv1[i]);
        }
    }
    
    
}


#endif