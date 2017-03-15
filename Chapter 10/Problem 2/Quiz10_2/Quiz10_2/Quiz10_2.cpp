// Quiz10_2.cpp : Defines the entry point for the console application.
//
// Composition (Note <-> MusicMaker) / Aggregation (MusicMaker <-> BeepManager)

#include "stdafx.h"
#include "stdlib.h"
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

class BeepManager {
private:
	int frequency;
public:
	BeepManager() {
		frequency = 0;
	}

	void playBeep(float seconds) {
		Beep(frequency, seconds * 1000);
	}

	void setFrequency(int f) {
		frequency = f;
	}
};

class MusicMaker{
private:
	class Note {
	private:
		int frequency;
		float seconds;
	public:
		Note() {

		}

		Note(int freq, float secs) {
			frequency = freq;
			seconds = secs;
		}

		//Rests (frequency is 0)
		Note(float secs) {
			seconds = secs;
		}

		int getFrequency() {
			return frequency;
		}

		float getDuration() {
			return seconds;
		}
	};
	
	std::vector<Note> notes;
	BeepManager beepManager;

public:
	MusicMaker() {
		beepManager = BeepManager();
		notes = {};
	}

	void addNote(int f, float d) {
		if (notes.size() == 0) {
			notes = {Note(f,d)};
			return;
		}
		notes.resize(notes.size() + 1);
		notes[notes.size() - 1] = Note(f,d);
	}

	void addRest(float d) {
		if (notes.size() == 0) {
			notes = { Note(d) };
			return;
		}
		notes.resize(notes.size() + 1);
		notes[notes.size() - 1] = Note(d);
	}

	void removeNote(int index) {
		if (index >= 0 && index < notes.size()) {
			notes.erase(notes.begin() + index);
		}
	}

	void insertNote(int f, float d, int index) {
		if (index >= 0 && index <= notes.size()) {
			notes.insert(notes.begin() + index, Note(f,d));
		}
	}

	void insertRest(float d, int index) {
		insertNote(0,d,index);
	}

	void changeNote(int f, float d, int index) {
		notes[index] = Note(f, d);
	}

	void changeNote(float d, int index) {
		notes[index] = Note(d);
	}

	void playSong() {
		for (int i = 0; i < notes.size(); i++) {
			if (notes[i].getFrequency() != 0) {
				beepManager.setFrequency(notes[i].getFrequency());
				beepManager.playBeep(notes[i].getDuration());
			}
			else {
				beepManager.setFrequency(0);
				Sleep(notes[i].getDuration()*1000);
			}
		}
	}
};

int main()
{
	MusicMaker m = MusicMaker();
	m.addNote(261.626,.5);
	m.addNote(293.665, .5);
	m.addNote(329.628, .5);
	m.addNote(349.228, .5);
	m.addNote(391.995, .5);
	m.addRest(2.0);
	m.addNote(261.626, .5);
	m.addNote(293.665, .5);
	m.addNote(329.628, .5);
	m.addNote(349.228, .5);
	m.addNote(391.995, .5);
	m.addNote(440.000, .5);
	m.addNote(493.883, .5);
	m.addNote(523.251, .5);
	m.playSong();
    return 0;
}

