class PeekingIterator : public Iterator {
private:
    int next_val;
    bool has_next;

public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        has_next = Iterator::hasNext();
        if (has_next) {
            next_val = Iterator::next();
        }
    }
    
    int peek() {
        return next_val;
    }
    
    int next() {
        int current = next_val;
        has_next = Iterator::hasNext();
        if (has_next) {
            next_val = Iterator::next();
        }
        return current;
    }
    
    bool hasNext() const {
        return has_next;
    }
};