#include <iostream>
using namespace std;

class Song {
public:
	int id;
	string name;
	float duration;

	Song* next;
	Song* prev;

	Song(int i, string n, float d) {
		id = i;
		name = n;
		duration = d;
		next = NULL;
		prev = NULL;
	}
};

class Playlist {
private:
	Song* head;
	Song* current;

public:
	Playlist() {
		head = NULL;
		current = NULL;
	}

	void addSong(int id, string name, float duration) {
		Song* newSong = new Song(id, name, duration);

		if (head == NULL) {
			head = newSong;
			current = newSong;
			return;
		}

		Song* temp = head;
		while (temp->next != NULL)
			temp = temp->next;

		temp->next = newSong;
		newSong->prev = temp;
	}

	void deleteSong(string name) {
		Song* temp = head;

		while (temp != NULL && temp->name != name)
			temp = temp->next;

		if (temp == NULL) return;

		if (temp == head) {
			head = temp->next;
			if (head != NULL)
				head->prev = NULL;
			delete temp;
			return;
		}

		if (temp->next != NULL)
			temp->next->prev = temp->prev;

		if (temp->prev != NULL)
			temp->prev->next = temp->next;

		delete temp;
	}

	void playNext() {
		if (current != NULL && current->next != NULL)
			current = current->next;

		cout << "Now Playing: " << current->name << endl;
	}

	void playPrev() {
		if (current != NULL && current->prev != NULL)
			current = current->prev;

		cout << "Now Playing: " << current->name << endl;
	}

	void reversePlaylist() {
		Song* temp = NULL;
		Song* currentNode = head;

		while (currentNode != NULL) {
			temp = currentNode->prev;
			currentNode->prev = currentNode->next;
			currentNode->next = temp;
			currentNode = currentNode->prev;
		}

		if (temp != NULL)
			head = temp->prev;
	}

	void display() {
		Song* temp = head;

		cout << "\nPlaylist:\n";
		while (temp != NULL) {
			cout << temp->id << " " << temp->name << " " << temp->duration << endl;
			temp = temp->next;
		}
	}
};

int main() {
	Playlist p;

	p.addSong(1, "SongA", 3.5);
	p.addSong(2, "SongB", 4.2);
	p.addSong(3, "SongC", 2.8);

	p.display();

	p.playNext();
	p.playNext();
	p.playPrev();

	p.deleteSong("SongB");

	cout << "\nAfter Deletion:\n";
	p.display();

	p.reversePlaylist();

	cout << "\nAfter Reverse:\n";
	p.display();

	return 0;
}