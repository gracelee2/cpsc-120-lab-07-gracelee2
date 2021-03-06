// Grace Lee
// CPSC 120-01
// 2021-10-28
// grace1@csu.fullerton.edu
// @gracelee2
//
// Lab 08-01
//
// This lab calculates card tricks
//

/// \file
/// The Fitch Cheny 5 Card Trick

// If you'd like to use sleep(), this header file is needed
#include <unistd.h>

#include <iostream>
#include <string>
#include <vector>

#include "mind_reader_functions.h"

using namespace std;

/// Main function that uses the functions defined in mind_reader_functions.cc
/// to perform the magic needed for the Fitch Cheny 5 Card Trick.
int main(int argc, char const* argv[]) {
  vector<string> args = vector<string>(argv, argv + argc);
  if (args.size() < 5) {
    cout << "Please provide five arguments, a rectangle's length and width.\n";
    cout << "For example:\n";
    cout << "./rectangle_area 23 17\n";
    try {
      cout << args.at(0) << "3 4"
           << "\n";
    } catch (exception const& problem) {
      cout << problem.what();
      return 1;
    }
    return 1;
  }
  // It may be a good idea to put a lot of cout statements through out this
  // program so you can see how the values change. Once you have everything
  // working you can remove the cout statements.

  // TODO: Convert argv to a vector<string>. Name this variable args
  // TODO: Check to make sure there are enough arguments on the command line
  // for your program to continue. You need to have at least 5 arguments to
  // continue. If there aren't enough arguments, print out a message saying
  // as much and return 1 to exit.

  // TODO: Declare 4 string variables: base_card, card_one, card_two, and
  // card_three.
  string base_card;
  string card_one;
  string card_two;
  string card_three;
  try {
    base_card = stoi(args.at(1));
    card_one = stoi(args.at(2));
    card_two = stoi(args.at(3));
    card_three = stoi(args.at(4));
  } catch (exception const& problem) {
    cout << problem.what();
    return 1;
  }



  // TODO: Copy the values from args into the appropriate variables. Remember
  // that args.at(0) is the name of the program and args.at(1) is the base_card.
  // Don't forget to wrap all calls to .at() with a try and catch.

  // TODO: Declare a variable of type string named secret_card_suit
  string secret_card_suit;
  // TODO: Use Suit() to assign base_card's suit to secret_card_suit
  secret_card_suit = Suit(base_card);
  // TODO: Declare an integer named base_value
  int base_value = 0;
  // TODO: Use NumericValue() and FaceValue() to find the numeric value of
  // base_card. Assign the numeric_value to base_card.
  //base_card = NumericValue(FaceValue(to_string(base_card)));
  int steps = 0;
  // TODO: Declare an integer named steps
  // TODO: Use FitchCheneySecretSteps() along with the other three cards to
  // calculate the secret number of steps. Assign this value to steps.
  steps = FitchCheneySecretSteps(card_one, card_two, card_three);
  // TODO: Declare an integer named secret_card_value
  int secret_card_value = 0;
  // TODO: Use FitchCheneySecretCardValue() with base_value and steps. Assign
  // the return value to secret_card_value.
  secret_card_value = FitchCheneySecretCardValue(base_value, steps);
  // TODO: Declare a string variable named secret_card_value_string
  string secret_card_value_string;
  // Use NumericValueToFaceValue to convert secret_card_value to a string and
  // assign it to secret_card_value_string
  secret_card_value_string = NumericValueToFaceValue(secret_card_value);

  // At this point you have the secret card's value calculated in
  // secret_card_value_string and the secret card's suit stored in
  // secret_card_suit. If you want you can build up the drama by slowly
  // revealing the card. You may wish to print out that the computer knows what
  // color the card is (red or black), what suit it is, and that it is a court
  // card (JQK) or a number card (2, 3, 4, 5, 6, 7, 8, 9, 10). You may use the
  // function sleep() to slow the computer down so the spectator can see the
  // computer printing out the messages.

  // TODO: Print out "Your card is " along with the value and suit of the card.
  // See the example output in the README for guidance.
  cout << "Your card is " << secret_card_value_string << "\n";
  return 0;
}
