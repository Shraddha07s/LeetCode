class MyHashMap {
private:

    struct Node {
        int key;
        int value;
        Node* next;

        Node(int key, int value) {
            this->key = key;
            this->value = value;
            next = nullptr;
        }
    };

    Node* buckets[10];

public:

    MyHashMap() {
        for (int i = 0; i < 10; i++) {
            buckets[i] = nullptr;
        }
    }

    void put(int key, int value) {
        int index = key % 10;

        Node* current = buckets[index];

        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }

            current = current->next;
        }

        Node* newNode = new Node(key, value);

        newNode->next = buckets[index];
        buckets[index] = newNode;
    }

    int get(int key) {
        int index = key % 10;

        Node* current = buckets[index];

        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }

            current = current->next;
        }

        return -1;
    }

    void remove(int key) {
        int index = key % 10;

        Node* current = buckets[index];
        Node* prev = nullptr;

        while (current != nullptr) {

            if (current->key == key) {

                if (prev == nullptr) {
                    buckets[index] = current->next;
                }

                else {
                    prev->next = current->next;
                }

                return;
            }

            prev = current;
            current = current->next;
        }
    }
};
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */