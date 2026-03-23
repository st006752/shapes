template <typename Item>
class Storage {
private:
    Item* array;
    size_t size;
    size_t capacity;

public:
    Storage(size_t start_capacity = 10) : size(0), capacity(start_capacity) {
        array = new Item[capacity];
    }
    void initialize(size_t start_capacity) {
        capacity = start_capacity;
        array = new Item[capacity];
        size = 0;
    }
    ~Storage() {
        delete[] array;
    }


    void add_item(const Item& item) {
        if (size == capacity) {

            capacity *= 2;
            Item* new_array = new Item[capacity];
            for (size_t i = 0; i < size; ++i) {
                new_array[i] = array[i];
            }
            delete[] array;
            array = new_array;
        }
        array[size] = item;
        ++size;
    }


    Item& get_item(size_t index) const {
        return array[index];
    }


    size_t get_size() const {
        return size;
    }
};