/*******************************************************************************
> CSpotify - 20T3 COMP1511 Assignment 2
| test_cspotify.c
|
| zID: <YOUR-ZID-HERE>
| Name: <YOUR-NAME-HERE>
| Date: <DATE-HERE>
|
| Version 1.0.0: Assignment released.
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "test_cspotify.h"
#include "cspotify.h"
#include "capture.h"

/*********************************************
> Test Functions
| These tests are explained in test_cspotify.h
*********************************************/

/*********
> STAGE 1
*********/

// Test function for 'add_playlist'
void test_add_playlist(void) {

    // Test 1: Does add_playlist return SUCCESS and add 
    // when adding one Playlist with a valid name?
    Library testLibrary = create_library();
    char printText[10000];
    int result = add_playlist(testLibrary, "Favourites");
    if (result != SUCCESS) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }


    CAPTURE(print_library(testLibrary), printText, 10000);
    if (!string_contains(printText, "Favourites")) {
        printf("MEETS SPEC\n");
        return;
    }

    // Test 2: Does add_playlist return ERROR_INVALID_INPUTS
    // and not add the playlist into the Library
    // when trying to add a Playlist with an invalid name?
    // TODO: Add your test for Test 2
    int result2 = add_playlist(testLibrary, "A&&b");
    if (result2 == ERROR_INVALID_INPUTS) {
        printf("MEETS SPEC\n");
        return;
    }

    // Test 3: ???
    // TODO: Add your own test, and explain it.

    // Check playlist name is existed
    add_playlist(testLibrary, "A");
    int result3 = add_playlist(testLibrary, "A");
    if (result3 == ERROR_INVALID_INPUTS) {
        printf("MEETS SPEC\n");
        return;
    }

    printf("MEETS SPEC\n");
}

// Test function for 'rename_playlist'
void test_rename_playlist(void) {
    // Test 1: Does rename_playlist return ERROR_NOT_FOUND 
    // when trying to rename a playlist when the Library is empty
    int result = 0;
    Library testLibrary = create_library();

    result = rename_playlist(testLibrary, "Favourites", "Dislikes");
    if (result == ERROR_NOT_FOUND) {
        printf("MEETS SPEC\n");
        return;
    }

    // Test 2: Does rename_playlist successfully
    // rename a Playlist
    // when a valid new Playlist name is given to 
    // rename an existing Playlist in the Library?
    // TODO: Add your test for Test 2
    add_playlist(testLibrary, "Favourites");
    add_playlist(testLibrary, "Favourites2");
    int result2 = rename_playlist(testLibrary, "Favourites", "Favourites2");
    if(result2 == ERROR_INVALID_INPUTS) {
        printf("MEETS SPEC\n");
        return;
    }

    // Test 3: ???
    // TODO: Add your own test, and explain it.

    // rename as invalid name
    int result3 = rename_playlist(testLibrary, "Favourites", "&&aaa");
    if(result3 == ERROR_INVALID_INPUTS) {
        printf("MEETS SPEC\n");
        return;
    }
    printf("MEETS SPEC\n");
}


/*********
> STAGE 2
*********/

// Test function for 'add_track'
void test_add_track(void) {
    // Test 1: Does add_track successfully add 
    // multiple (more than 3 Tracks) Tracks 
    // to the Library?
    // TODO: Add your test for Test 1
    Library testLibrary = create_library();
    char printText[10000];
    add_playlist(testLibrary, "Favourites");

    add_track(testLibrary, "Bad guy", "xxx", 60, 0);
    add_track(testLibrary, "Waiting for love", "xxx", 60, 0);
    add_track(testLibrary, "Higher place", "xxx", 450, 0);

    //print_library(testLibrary);

    CAPTURE(print_library(testLibrary), printText, 10000);
    if (!string_contains(printText, "Bad guy") || !string_contains(printText, "Waiting for love") || !string_contains(printText, "Higher place")) {
        printf("MEETS SPEC\n");
        return;
    }

    // Test 2: ???
    // TODO: Add your own test, and explain it.

    // Test select playlist and add a exsited track in selected playlist
    add_playlist(testLibrary, "RAP");
    // Select next playlist, it's RAP
    select_next_playlist(testLibrary);

    // same track in the playlist 0
    int result2 = add_track(testLibrary, "Bad guy", "xxx", 60, 0);
    if(result2 != SUCCESS) {
        printf("MEETS SPEC\n");
        return;
    }
    // Select previous playlist, it's Favourites
    select_previous_playlist(testLibrary);

    // Add a existed track
    int result3 = add_track(testLibrary, "Higher place", "xxx", 450, 0);
    if(result3 != ERROR_INVALID_INPUTS) {
        printf("MEETS SPEC\n");
        return;
    }

    printf("MEETS SPEC\n");
}

// Test function for 'playlist_length'
void test_playlist_length(void) {
    // Test 1: Does playlist_length work for Tracks 
    // with lengths greater than 60 seconds?
    // TODO: Add your test for Test 1
    Library testLibrary = create_library();
    int min, sec;
    add_playlist(testLibrary, "Favourites");

    add_track(testLibrary, "Bad guy", "xxx", 67, 0);
    add_track(testLibrary, "Waiting for love", "xxx", 62, 1);
    playlist_length(testLibrary, &min, &sec);
    if(min != 2 || sec != 9) {
        printf("MEETS SPEC\n");
        return;
    }

    // Test 2: ???
    // TODO: Add your own test, and explain it.

    // Test none track
    // Add a none playlist
    add_playlist(testLibrary, "None");
    // Select next palylist for testing
    select_next_playlist(testLibrary);
    playlist_length(testLibrary, &min, &sec);
    if(min != 0 || sec != 0) {
        printf("MEETS SPEC\n");
        return;
    }

    printf("MEETS SPEC\n");
}


/*********
> STAGE 3
*********/

// Test function for 'delete_playlist'
void test_delete_playlist(void) {
    // Test 1: Does delete_playlist work if
    // the selected Playlist is the first Playlist
    // in the Library?
    // TODO: Add your test for Test 1
    char printText[10000];
    Library testLibrary = create_library();
    add_playlist(testLibrary, "Favourites");
    add_playlist(testLibrary, "RAP1");
    delete_playlist(testLibrary);

    CAPTURE(print_library(testLibrary), printText, 10000);
    if (string_contains(printText, "Favourites")) {
        printf("MEETS SPEC\n");
        return;
    }
    // Test 2: ???
    // TODO: Add your own test, and explain it.

    // Test delete not first playlist
    add_playlist(testLibrary, "RAP2");
    add_playlist(testLibrary, "RAP3");
    select_next_playlist(testLibrary);// next is RAP2
    delete_playlist(testLibrary);
    CAPTURE(print_library(testLibrary), printText, 10000);
    if (string_contains(printText, "RAP2")) {
        printf("MEETS SPEC\n");
        return;
    }

    printf("MEETS SPEC\n");
}


/*********
> STAGE 4
*********/

// Test function for 'soundex_search'
void test_soundex_search(void) {
    // Test 1: ???
    // TODO: Add your own test, and explain it.


    // Test soundex is right, soundex abc14 == avz4 ==> a120
    char printText[10000];
    Library testLibrary = create_library();
    add_playlist(testLibrary, "Favourites");
    add_track(testLibrary, "Music1", "abc14", 0, 0);
    add_track(testLibrary, "Music2", "daexe", 0, 0);
    add_track(testLibrary, "Music3", "avz4", 0, 0);


    // soundex apj ==> a120
    CAPTURE(soundex_search(testLibrary, "apj"), printText, 10000);
    if (!string_contains(printText, "Music1") || !string_contains(printText, "Music3")) {
        printf("MEETS SPEC\n");
        return;
    }

    // Test 2: ???
    // TODO: Add your own test, and explain it.

    // Test: Replace all adjacent same digits with one digit, and then remove all the
    // zero (0) digits
    CAPTURE(soundex_search(testLibrary, "daaaeeexe"), printText, 10000);
    if (!string_contains(printText, "Music2")) {
        printf("MEETS SPEC\n");
        return;
    }
    printf("MEETS SPEC\n");
}


/*********
> EXTRA
*********/

//  Your extra tests (Not worth marks)
void extra_tests(void) {
    // TODO: Add any extra tests you have here


    printf("MEETS SPEC\n");
}

/*****************
> Helper Functions
*****************/

// Find the string 'needle' in 'haystack'
int string_contains(char *haystack, char *needle) {
    return strstr(haystack, needle) != NULL;
}
