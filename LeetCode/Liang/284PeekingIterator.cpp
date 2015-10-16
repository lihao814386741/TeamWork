// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
	Data* data;
public:
	Iterator(const vector<int>& nums);
	Iterator(const Iterator& iter);
	virtual ~Iterator();
	// Returns the next element in the iteration.
	int next();
	// Returns true if the iteration has more elements.
	bool hasNext() const;
};

class Buffer {
public:
    bool isValid = false;
    int value;
};

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    _peekBuffer = new Buffer();
	}
	
	~PeekingIterator() {
	    delete _peekBuffer;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if (_peekBuffer->isValid) {
            return _peekBuffer->value;
        }
        
        if (Iterator::hasNext()) {
            _peekBuffer->value = Iterator::next();
            _peekBuffer->isValid = true;
            return _peekBuffer->value;
        }
        
        return Iterator::next();
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if (_peekBuffer->isValid) {
	        _peekBuffer->isValid = false;
	        return _peekBuffer->value;
	    } else {
	        return Iterator::next();   
	    }
	}

	bool hasNext() const {
	    if (_peekBuffer->isValid) {
	        return true;
	    }
	    
	    return Iterator::hasNext();
	}
private:
    Buffer *_peekBuffer;
};
