// Quiz6_7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <array>
#include <ctime>

using namespace std;

enum class Suit
{
	SPADES,
	HEARTS,
	DIAMONDS,
	CLUBS,
};

enum CardValue {
	V_2,
	V_3,
	V_4,
	V_5,
	V_6,
	V_7,
	V_8,
	V_9,
	V_10,
	V_JACK,
	V_QUEEN,
	V_KING,
	V_ACE,
};

struct Card {
	Suit suit;
	CardValue cardValue;
};

void printCard(const Card card);
void printDeck(const array<Card, 52> array);
void swapCards(Card &cardOne, Card &cardTwo);
void shuffleDeck(array<Card, 52>& deck);
bool playBlackJack(array<Card, 52> &deck);

int main()
{
	array<Card, 52> deck;
	int cardIndex = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			deck[cardIndex].suit = static_cast<Suit>(i);
			if (j == 0) { deck[cardIndex].cardValue = CardValue::V_ACE; }
			else { deck[cardIndex].cardValue = static_cast<CardValue>(j - 1); }
			cardIndex++;
		}
	}
	printDeck(deck);
	shuffleDeck(deck);
	playBlackJack(deck);
	return 0;
}

void printCard(const Card card) {
	char c2;
	switch (card.suit) {
	case Suit::SPADES:
		c2 = 'S';
		break;
	case Suit::HEARTS:
		c2 = 'H';
		break;
	case Suit::DIAMONDS:
		c2 = 'D';
		break;
	case Suit::CLUBS:
		c2 = 'C';
		break;
	default:
		c2 = 'S';
		break;
	}
	char c1;
	switch (card.cardValue) {
	case CardValue::V_2:	 c1 = '2';	break;
	case CardValue::V_3:	 c1 = '3';	break;
	case CardValue::V_4:	 c1 = '4';	break;
	case CardValue::V_5:	 c1 = '5';	break;
	case CardValue::V_6:	 c1 = '6';	break;
	case CardValue::V_7:	 c1 = '7';	break;
	case CardValue::V_8:	 c1 = '8';	break;
	case CardValue::V_9:	 c1 = '9';	break;
	case CardValue::V_10:	 c1 = 'T';	break;
	case CardValue::V_JACK:	 c1 = 'J';	break;
	case CardValue::V_QUEEN: c1 = 'Q';	break;
	case CardValue::V_KING:	 c1 = 'K';	break;
	case CardValue::V_ACE:	c1 = 'A';	break;
	}
	cout << c1 << c2;
}

void printDeck(const array<Card, 52> array) {
	for (const auto &card : array) {
		printCard(card);
		cout << ", ";
	}
	cout << endl << endl;
}

void swapCards(Card &cardOne, Card &cardTwo) {
	Card temp = cardOne;
	cardOne = cardTwo;
	cardTwo = temp;
}

void shuffleDeck(array<Card, 52>& deck) {
	srand(time(0));
	for (int i = 0; i < 51; i++) {
		int rando1 = rand() % 52;
		swapCards(deck[i], deck[rando1]);
	}
}

int getCardValue(Card card) {
	switch (card.cardValue) {
	case CardValue::V_2:
		return 2;
		break;
	case CardValue::V_3:
		return 3;
		break;
	case CardValue::V_4:
		return 4;
		break;
	case CardValue::V_5:
		return 5;
		break;
	case CardValue::V_6:
		return 6;
		break;
	case CardValue::V_7:
		return 7;
		break;
	case CardValue::V_8:
		return 8;
		break;
	case CardValue::V_9:
		return 9;
		break;
	case CardValue::V_ACE:
		return 11;
		break;
	default:
		return 10;
		break;
	}
}

bool playBlackJack(array<Card, 52> &deck) {
	Card* cardPtr = &deck[0];
	int playerScore;
	int dealerScore;

	dealerScore = getCardValue(*cardPtr++);
	playerScore = getCardValue(*cardPtr++);
	playerScore += getCardValue(*cardPtr++);

	cout << "Before we start, when asked whether to hit or stand:\nTo hit, you may enter 'h', or 'hit'.\nTo stand, you may enter 's', or 'stand'.\n===============================\n\n";
	bool chooseHit = true;
	
	while (true) {
		while (true) {
			char input;
			cout << "Your current total is : " << playerScore << "\nWould you like to hit or stand? ";
			cin >> input;
			if (input == 'h') {
				cin.ignore(255, '\n');
				break;
			}
			else if (input == 's') {
				cin.ignore(255, '\n');
				chooseHit = false;
				break;
			}
			else {
				cout << "Please try entering that again.\n";
				cin.ignore(255, '\n');
				cin.clear();
			}
		}

		if (chooseHit) {
			cout << "You got: ";
			printCard(*cardPtr);
			cout << endl;
			playerScore += getCardValue(*cardPtr++);
			if (playerScore > 21) {
				cout << "You bust with " << playerScore << " points! You lose!\n";
				return false;
			}
		}
		else {
			break;
		}
	}

	int count = 0;
	while (dealerScore < 17) {
		cout << "The dealer hits!\n";
		count++;
		dealerScore += getCardValue(*cardPtr++);
		if (dealerScore > 21) {
			cout << "Dealer busts with " << dealerScore << " points! You win!\n";
			return true;
		}
	}

	cout << "The dealer hits " << count << " times and stands with " << (count + 1) << " cards.\n\n==================================\n\n";

	cout << "Your points: " << playerScore << endl;
	cout << "Dealer's points: " << dealerScore << endl;
	if (playerScore > dealerScore) {
		cout << "You win!\n";
		return true;
	}
	else {
		cout << "You lose!\n";
	}
}