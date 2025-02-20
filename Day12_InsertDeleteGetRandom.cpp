class RandomizedSet {
    vector<int> values;  
    unordered_map<int, int> valToIndex;
public:
    RandomizedSet() {}

    bool insert(int val) {
        if (valToIndex.find(val) != valToIndex.end())
            return false;
        values.push_back(val);
        valToIndex[val] = values.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (valToIndex.find(val) == valToIndex.end())
            return false;

        int lastElement = values.back();
        int idx = valToIndex[val];

        values[idx] = lastElement;
        valToIndex[lastElement] = idx;

        values.pop_back();
        valToIndex.erase(val);

        return true;
    }

    int getRandom() {
        int randomIndex = rand() % values.size();
        return values[randomIndex];
    }
};
