


class Iterator {
	hasNext();
	next();
}


class SortedIterator implements Iterator {
	vector<int> start;
	int lastElement;
	SortedIterator(List<Iterator> list){
		lastElement = -1;
		start.assingm(list.size());
	}
	bool hasNext() {
		bool existNext = false;

		for(int i = 0; i < list.size(); i++) {
			std::iterator = lowerBound(list.begin() + start[i], list.end(), lastElement);
			if(iterator != list.end()) {
				existNext = true;
				break;
			} 
		}
		return existNext;
	}
	int next() {
		int nextElement = 0;
		for(int i = 0; i < list.size(); i++) {
			std::iterator = lowerBound(list.begin() + start[i], list.end(), lastElement);
			if(iterator != list.end()) {
				start[i]++;
				nextElement = *iterator;
				lastElement = nextElement;
				break;
			}
		}
		return nextElement;
	}
};

