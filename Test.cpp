/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Orel Zamler
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include <stdexcept>
#include "mat.hpp"
using namespace ariel;

#include <stdlib.h>     /* srand, rand */
#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));

    // Obvious test direcly from the assigment sheets:
    CHECK(nospaces(mat(13, 5, '@', '-')) == nospaces("@@@@@@@@@@@@@\n"
                                                    "@-----------@\n"
                                                    "@-@@@@@@@@@-@\n"
                                                    "@-----------@\n"
                                                    "@@@@@@@@@@@@@"));

    CHECK(nospaces(mat(3, 5, '$', '+')) == nospaces("$$$\n"
                                                    "$+$\n"
                                                    "$+$\n"
                                                    "$+$\n"
                                                    "$$$"));

    CHECK(nospaces(mat(1, 1, '#', ')')) == nospaces("#"));

    // Additional test in the same format:
    CHECK(nospaces(mat(9, 9, '(', ')')) == nospaces("(((((((((\n"
                                                    "()))))))(\n"
                                                    "()((((()(\n"
                                                    "()()))()(\n"
                                                    "()()()()(\n"
                                                    "()()))()(\n"
                                                    "()((((()(\n"
                                                    "()))))))(\n"
                                                    "((((((((("));

    CHECK(nospaces(mat(9, 7, '*', '+')) == nospaces("*********\n"
                                                    "*+++++++*\n"
                                                    "*+*****+*\n"
                                                    "*+*+++*+*\n"
                                                    "*+*****+*\n"
                                                    "*+++++++*\n"
                                                    "*********"));

    CHECK(nospaces(mat(7, 9, '$', '#')) == nospaces("$#####$\n"
                                                    "$#$$$#$\n"
                                                    "$#$#$#$\n"
                                                    "$#$#$#$\n"
                                                    "$#$#$#$\n"
                                                    "$#$$$#$\n"
                                                    "$#####$\n"
                                                    "$$$$$$$"));

    CHECK(nospaces(mat(7, 7, '~', '@')) == nospaces("~~~~~~~\n"
                                                    "~@@@@%~\n"
                                                    "~@~~~@~\n"
                                                    "~@~@~@~\n"
                                                    "~@~~~@~\n"
                                                    "~@@@@@~"));

    CHECK(nospaces(mat(5, 7, '-', '+')) == nospaces("-----\n"
                                                    "-+++-\n"
                                                    "-+-+-\n"
                                                    "-+-+-\n"
                                                    "-+-+-\n"
                                                    "-+++-\n"
                                                    "-----"));

    CHECK(nospaces(mat(7, 5, '*', '^')) == nospaces("*******\n"
                                                    "*^^^^^*\n"
                                                    "*^***^*\n"
                                                    "*^^^^^*\n"
                                                    "*******"));

    CHECK(nospaces(mat(5, 5, '+', '*')) == nospaces("+++++\n"
                                                    "+***+\n"
                                                    "+*+*+\n"
                                                    "+***+\n"
                                                    "+++++"));

    CHECK(nospaces(mat(5, 3, '$', '+')) == nospaces("&&&&&\n"
                                                    "&+++&\n"
                                                    "&&&&&"));
    // Numbers and letters
    CHECK(nospaces(mat(3, 5, '0', '~')) == nospaces("000\n"
                                                    "0~0\n"
                                                    "0~0\n"
                                                    "0~0\n"
                                                    "000"));

    CHECK(nospaces(mat(3, 3, '0', '9')) == nospaces("000\n"
                                                    "090\n"
                                                    "000"));

    // Empty case(<0,0> otherwise it belongs to the bad input test)
    CHECK(nospaces(mat(0, 0, '$', '+')) == nospaces(""));

    // Single col
    CHECK(nospaces(mat(1, 3, '$', '+')) == nospaces("$\n"
                                                    "$\n"
                                                    "$"));
    // Single row
    CHECK(nospaces(mat(3, 1, '$', '+')) == nospaces("$$$"));

    CHECK(nospaces(mat(1, 1, '$', '+')) == nospaces("$\n"
                                                    "$"));
    // Capital letter
    CHECK(nospaces(mat(1, 1, 'D', '+')) == nospaces("D"));

    CHECK(nospaces(mat(3, 1, '$', '+')) == nospaces("$$$"));
    // Same simbol
    CHECK(nospaces(mat(3, 3, '$', '$')) == nospaces("$$$\n"
                                                    "$$$\n"
                                                    "$$$"));


}

// Note: Both number need to be even!
TEST_CASE("Bad input") {

    CHECK_THROWS(mat(10, 5, '$', '%'));

    // Even input(row mod 2 == 0 or col mod 2 == 0)
    for(int i = 1; i < 10; i++){
        int randomInt = rand()%10;
        // <Even, Odd>
        CHECK_THROWS(mat(2 * randomInt + 2, 2 *randomInt + 1, '$', '%'));
        // <Odd, Even>
        CHECK_THROWS(mat(2* randomInt + 1, 2 * randomInt + 2, '$', '%'));
        // <Even, Even>
        CHECK_THROWS(mat(2 *randomInt + 2 , 2 *randomInt + 2, '$', '%'));
        CHECK_THROWS(mat(2 *randomInt + 2 , 2 *randomInt + 4, '$', '%'));
        // One number far greater then the other
        //CHECK_THROWS(mat(2 * randomInt + 1, 10 * randomInt + 1, '$', '%'));
        //CHECK_THROWS(mat(10 * randomInt + 1, 2 * randomInt + 1, '$', '%'));
        // Nagetive input
        CHECK_THROWS(mat((-2) * randomInt -1, (-2) * randomInt -3, '$', '%'));
        CHECK_THROWS(mat((-2) * randomInt -1, (2) * randomInt + 1, '$', '%'));
        CHECK_THROWS(mat((2) * randomInt +1, (-2) * randomInt -1, '$', '%'));

    }
    // More nagetive input were one is positive
    CHECK_THROWS(mat(-1, 3, '$', '%'));
    CHECK_THROWS(mat(-2, 1, '$', '%'));

    // Empty case(row = 0 or col = 0 but not both)
    for(int i = 1; i < 10; i++){
        // Checking both legal(Odd) and even values with zero
        CHECK_THROWS(mat(0, i, '$', '%'));
        CHECK_THROWS(mat(i, 0, '$', '%'));
    }


    // Wrong input???????????????????????? string instad og int and such...                                            <==============================
}


/* Add more test cases here */
//TEST_CASE("Unique cases") {
    // CHECK(nospaces(mat(3, 3, '', '+')) == nospaces("="));                        ask if an enpty symbols are a posibility??     <=======================

    // CHECK(nospaces(mat(0, 0, '$', '')) == nospaces("&&&\n"
    //                                                "&&\n"
    //                                                "&&&\n"));

    // CHECK(nospaces(mat(0, 0, '', '')) == nospaces(""));
//}

