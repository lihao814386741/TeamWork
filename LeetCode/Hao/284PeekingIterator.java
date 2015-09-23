// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html
class PeekingIterator implements Iterator<Integer> {
    private List<Integer> l;
	public PeekingIterator(Iterator<Integer> iterator) {
	    // initialize any member here.
	    l = new LinkedList<Integer> ();
	    
	    while (iterator.hasNext() == true) {
            l.add(iterator.next());	        
	    }
	}

    // Returns the next element in the iteration without advancing the iterator.
	public Integer peek() {
        return l.get(0);
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	@Override
	public Integer next() {
	    int result  = l.get(0);
	    l.remove(0);
	    return result;
	}

	@Override
	public boolean hasNext() {
	    return l.size() != 0;
	}
}
