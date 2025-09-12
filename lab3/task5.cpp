#include <iostream>
#include <string>
using namespace std;

struct Node {
    string song;
    Node* next;
    Node(const string& s) : song(s), next(nullptr) {}
};

class Playlist {
private:
    Node* tail; 

public:
    Playlist() : tail(nullptr) {}

    void add_song(const string& song) {
        Node* new_node = new Node(song);
        if (!tail) {
            tail = new_node;
            tail->next = tail; 
        } else {
            new_node->next = tail->next; 
            tail->next = new_node;
            tail = new_node; 
        }
    }

    void display() const {
        if (!tail) {
            cout << "Playlist is empty.\n";
            return;
        }
        Node* current = tail->next; 
        cout << "Playlist:\n";
        do {
            cout << "- " << current->song << "\n";
            current = current->next;
        } while (current != tail->next);
    }

    void play(int n) const {
        if (!tail) {
            cout << "Playlist is empty.\n";
            return;
        }
        Node* current = tail->next;
        cout << "Playing " << n << " songs:\n";
        for (int i = 0; i < n; ++i) {
            cout << "Playing: " << current->song << "\n";
            current = current->next;
        }
    }

    ~Playlist() {
        if (!tail) return;
        Node* current = tail->next; 
        tail->next = nullptr; 
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    Playlist playlist;
    playlist.add_song("Song A");
    playlist.add_song("Song B");
    playlist.add_song("Song C");
    playlist.add_song("Song D");

    playlist.display();

    cout << "\nSimulate playing 7 songs (looping through playlist):\n";
    playlist.play(7);

    return 0;
}
