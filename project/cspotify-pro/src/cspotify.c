/*******************************************************************************
> CSpotify - 20T3 COMP1511 Assignment 2
| cspotify.c
|
| zID: <YOUR-ZID-HERE>
| Name: <YOUR-NAME-HERE>
| Date: <DATE-HERE>
| Program Description:
| <INSERT DESCRIPTION>
|
| Version 1.0.0: Assignment released.
|
 *******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cspotify.h"

/******************************************************************************/
// TODO: Add any other #defines you need.

/******************************************************************************/
// 'struct library' represents a library, which represents the state of the
// entire program. It is mainly used to point to a linked list of 
// playlists, though you may want to add other fields to it.
//
// You may choose to add or change fields in this struct.
struct library {
    struct playlist *head;
    int selected_playlist_pos; // Add a flag to realize which playlist selected
};

// 'struct playlist' represents a playlist. 
// You may choose to add or change fields in this struct.
struct playlist {
    char name[MAX_LEN];
    struct track *tracks;
    struct playlist *next;
};

// 'struct trackLength' represents the length of a track. 
// You may choose to add or change fields in this struct.
struct trackLength {
    int minutes;
    int seconds;
};

// 'struct track' represents a track. 
// You may choose to add or change fields in this struct.
struct track {
    char title[MAX_LEN];
    char artist[MAX_LEN];
    struct trackLength length;
    struct track *next;
};

/******************************************************************************/
// TODO: Add any other structs you define here.


/******************************************************************************/
// TODO: Add prototypes for any extra functions you create here.
void soundex_encode(char words[MAX_LEN], char soundex[MAX_LEN]);

// Function prototypes for helper functions. 
static void print_playlist(int number, char playlistName[MAX_LEN]);
static void print_selected_playlist(int number, char playlistName[MAX_LEN]);
static void print_track(char title[MAX_LEN], char artist[MAX_LEN], int minutes, int seconds);

/******************************************************************************/
// You need to implement the following functions.
// In other words, write code to make the function work as described 
// in cspotify.h

/*********
> STAGE 1
*********/

// Create a new Library and return a pointer to it.
Library create_library(void) {
    Library newLibrary = malloc(sizeof(struct library));
    newLibrary->head = NULL;
    return newLibrary;
}

// Add a new Playlist to the Library.
int add_playlist(Library library, char playlistName[MAX_LEN]) {
    Playlist playlist = library->head;
    char ch = 0;
    int i = 0;
    int name_length = strlen(playlistName);
    // check name is valid
    for(i = 0; i < name_length; ++i) {
        ch = playlistName[i];
        if((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            continue;
        else
          return ERROR_INVALID_INPUTS;
    }
    // add playlist in the library
    // if have non playlist in the library
    if (playlist == NULL) {
        library->head = malloc(sizeof (struct playlist));
        // get current playlist
        playlist = library->head;
        // set playlist selected
        library->selected_playlist_pos = 0;
    } else {
        while(1) { // loop to the end of playlist linklist and check name is existed
            if (!strcmp(playlist->name, playlistName))
                return ERROR_INVALID_INPUTS;
            if (playlist->next)
                playlist = playlist->next;
            else
                break;
        };

        // compare last playlist name
        if (!strcmp(playlist->name, playlistName))
            return ERROR_INVALID_INPUTS;
        // add next playlist
        playlist->next = malloc(sizeof (struct playlist));
        // get current playlist
        playlist = playlist->next;
    }
    playlist->tracks = NULL;
    playlist->next = NULL;
    strncpy(playlist->name, playlistName, MAX_LEN);
    return SUCCESS;
}

// Print out the Library.
void print_library(Library library) {
    if (!library) return; // check library is null
    Playlist playlist = library->head;
    int pos = 0;
    Track tracks = NULL;
    // check library playlist is null
    if(playlist == NULL) return;
    for(pos = 0; playlist; ++pos) {
        // print selected playlist
        if (pos == library->selected_playlist_pos)
            print_selected_playlist(pos, playlist->name);
        else
            print_playlist(pos, playlist->name);
        // print tracks in playlist
        tracks = playlist->tracks;
        for(; tracks; ) {
            print_track(tracks->title, tracks->artist, tracks->length.minutes, tracks->length.seconds);
            tracks = tracks->next;
        }
        playlist = playlist->next;
    }
}

// Rename the name of an existing Playlist.
int rename_playlist(Library library, char playlistName[MAX_LEN],
    char newPlaylistName[MAX_LEN]) {
    Playlist playlist = library->head;
    char ch = 0;
    int is_found = 0;
    int new_name_length = strlen(newPlaylistName);
    // check name is valid
    for(int i = 0; i < new_name_length; ++i) {
        ch = newPlaylistName[i];
        if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            continue;
        else
          return ERROR_INVALID_INPUTS;
    }
    // check library playlist is null
    if (playlist == NULL) return ERROR_NOT_FOUND;
    // check new playlist name is existed
    while(1) {
        // print selected playlist
        if (!strcmp(playlist->name, newPlaylistName)) {
            return ERROR_INVALID_INPUTS;
        }
        if (!(playlist = playlist->next))
            break;
    }
    // reset playlist ptr
    playlist = library->head;
    while(1) {
        // print selected playlist
        if(!strcmp(playlist->name, playlistName)) {
            strncpy(playlist->name, newPlaylistName, MAX_LEN);
            is_found = 1;
        }
        if (!(playlist = playlist->next))
            break;
    }
    if (is_found == 0)
        return ERROR_NOT_FOUND;
    return SUCCESS;
}


/*********
> STAGE 2
*********/

// Selects the next Playlist in the Library.
void select_next_playlist(Library library) {
    Playlist playlist = library->head;
    int pos = 0;
    if (playlist == NULL) return;
    // check library playlist is null
    for(pos = 0; playlist; ++pos) {
        // judge if can set as next pos
        if (pos - 1 >= library->selected_playlist_pos) {
            library->selected_playlist_pos += 1;
            return;
        }
        playlist = playlist->next;
    }
    // set selected playlist pos as first playlist pos
    library->selected_playlist_pos = 0;
}

// Selects the previous Playlist in the Library.
void select_previous_playlist(Library library) {
    Playlist playlist = library->head;
    int last_pos = 0;
    // check library playlist is null
    if (playlist == NULL) return;
    // get last playlist pos
    for(last_pos = -1; playlist; ++last_pos) {
        playlist = playlist->next;
    }
    if (library->selected_playlist_pos > 0)
        library->selected_playlist_pos --;
    else
        // set selected playlist as last playlist pos
        library->selected_playlist_pos = last_pos;
}

// Add a new Track to the selected Playlist.
int add_track(Library library, char title[MAX_LEN], char artist[MAX_LEN], 
              int trackLengthInSec, int position) {
    Playlist playlist = library->head;
    Track tracks = NULL;
    Track last_tracks = NULL;
    Track tmp_tracks = NULL; // tmp tracks
    int playlist_len = 0;
    int pos = 0;
    // check library playlist is null
    if (playlist == NULL) return ERROR_NOT_FOUND;
    // get selected playlist
    for(pos = 0; playlist; ++pos) {
        if(pos == library->selected_playlist_pos)
            break;
        playlist = playlist->next;
    }

    // get length of playlist and compare title if is exsited
    tracks = playlist->tracks;
    for(playlist_len = 0; tracks; ++playlist_len) {
        if (!strcmp(tracks->title, title) && !strcmp(tracks->artist, artist))
            return ERROR_INVALID_INPUTS;
        tracks = tracks->next;
    }
    if (position > playlist_len || position < 0)
        return ERROR_INVALID_INPUTS;
    if (trackLengthInSec <= 0)
        return ERROR_INVALID_INPUTS;
    // new track
    // add to head of tracks
    if (position == 0) {
        tmp_tracks = malloc(sizeof (struct track));
        last_tracks = playlist->tracks;
        playlist->tracks = tmp_tracks;
        tmp_tracks->next = last_tracks;
    }else {
        // reset tracks as head
        tracks = playlist->tracks;
        for(pos = 0; tracks; ++pos) {
            if (pos >= position)
                break;
            last_tracks = tracks;
            tracks = tracks->next;
        }
        // insert a track into playlist
        tmp_tracks = malloc(sizeof (struct track));
        tmp_tracks->next = tracks;
        last_tracks->next = tmp_tracks;
    }
    // set base info
    tmp_tracks->length.minutes = trackLengthInSec / 60;
    tmp_tracks->length.seconds = trackLengthInSec % 60;
    strncpy(tmp_tracks->title, title, MAX_LEN);
    strncpy(tmp_tracks->artist, artist, MAX_LEN);
    return SUCCESS;
}

// Calculate the total length of the selected Playlist in minutes and seconds.
void playlist_length(Library library, int *playlistMinutes, int *playlistSeconds) {
    if(library == NULL) return;
    Track tracks = NULL;
    int pos = 0;
    Playlist playlist = library->head;
    *playlistMinutes = 0;
    *playlistSeconds = 0;
    // check library playlist is null
    if (playlist == NULL) {
        *playlistMinutes = -1;
        *playlistSeconds = -1;
        return;
    }
    // get selected playlist
    for(pos = 0; playlist; ++pos) {
        if (pos == library->selected_playlist_pos)
            break;
        playlist = playlist->next;
    }
    tracks = playlist->tracks;
    // calc total of munites and seconds
    for(; tracks; ) {
        *playlistMinutes += tracks->length.minutes;
        *playlistSeconds += tracks->length.seconds;
        tracks = tracks->next;
    }
    *playlistMinutes += (*playlistSeconds / 60);
    *playlistSeconds %= 60;
}


/*********
> STAGE 3
*********/

// Delete the first instance of the given track in the selected Playlist
// of the Library.
void delete_track(Library library, char track[MAX_LEN]) {
    Track tracks = NULL;
    Track next_track = NULL;
    Track last_track = NULL;
    int pos = 0;
    Playlist playlist = library->head;
    // check library playlist is null
    if (playlist == NULL)
        return ;
    // get selected playlist
    for(pos = 0; playlist; ++pos) {
        if (pos == library->selected_playlist_pos)
            break;
        playlist = playlist->next;
    }
    tracks = playlist->tracks;
    // check head is null
    if (!tracks) return;
    // delete tracks
    // check is head
    if (!strcmp(tracks->title, track)) {
        next_track = tracks->next;
        free(tracks);
        playlist->tracks = next_track;
    } else {
        last_track = tracks;
        for(; tracks; ) {
            next_track = tracks->next;
            if (!strcmp(track, tracks->title)) {
                last_track->next = next_track;
                free(tracks);
                break;
            }
            last_track = tracks;
            tracks = next_track;
        }
    }
}

// Delete the selected Playlist and select the next Playlist in the Library.
void delete_playlist(Library library) {
    Track tracks = NULL;
    Track next_track = NULL;
    int pos = 0;
    Playlist playlist = library->head;
    Playlist last_playlist = NULL;
    // check library playlist is null
    if (playlist == NULL)
        return;
    // get selected playlist
    for(pos = 0; playlist; ++pos) {
        if (pos == library->selected_playlist_pos)
            break;
        last_playlist = playlist;
        playlist = playlist->next;
    }
    // unlink playlist
    // if is head
    if (library->selected_playlist_pos == 0) {
        library->head= library->head->next;
    }else {
        last_playlist->next = playlist->next;
        if (playlist->next == NULL) {
            library->selected_playlist_pos = 0;
        }
    }
    tracks = playlist->tracks;
    free(playlist);

    // delete tracks
    for(; tracks; ) {
        next_track = tracks->next;
        // set next as null
        tracks->next = NULL;
        free(tracks);
        tracks = next_track;
    }
}

// Delete an entire Library and its associated Playlists and Tracks.
void delete_library(Library library) {
    Track tracks = NULL;
    Track next_track = NULL;
    Playlist playlist = library->head;
    // check library playlist is null
    if (playlist == NULL) {
        library->selected_playlist_pos = 0;
        // free library
        free(library);
        return;
    }
    library->head= library->head->next;
    tracks = playlist->tracks;
    free(playlist);
    // delete tracks
    for(; tracks; ) {
        next_track = tracks->next;
        // set next as null
        tracks->next = NULL;
        free(tracks);
        tracks = next_track;
    }
    // continue delete until library->head == NULL
    delete_library(library);
}


/*********
> STAGE 4
*********/

// Cut the given track in selected Playlist and paste it into the given 
// destination Playlist.
int cut_and_paste_track(Library library, char trackTitle[MAX_LEN], 
                        char destPlaylist[MAX_LEN]) {
    if (library == NULL) return ERROR_NOT_FOUND;
    Playlist playlist = library->head;
    Playlist target_playlist = library->head;
    Track tracks = NULL;
    Track next_track = NULL;
    Track last_track = NULL;
    Track op_track = NULL;
    int pos = 0;
    if (library->head == NULL) return ERROR_NOT_FOUND;
    for(; target_playlist; ) {
        if (!strcmp(target_playlist->name, destPlaylist))
            break;
        target_playlist = target_playlist->next;
    }
    if (!target_playlist) {
        return ERROR_NOT_FOUND;
    }
    // get selected playlist
    for(pos = 0; playlist; ++pos) {
        if (pos == library->selected_playlist_pos)
            break;
        playlist = playlist->next;
    }
    // unlink from selected playlist
    tracks = playlist->tracks;
    // check head is null
    if (!tracks) return ERROR_NOT_FOUND;
    // check is head
    if (!strcmp(tracks->title, trackTitle)) {
        next_track = tracks->next;
        // assign op_track as cuted track
        op_track = tracks;
        op_track->next = NULL;
        playlist->tracks = next_track;
    } else {
        last_track = tracks;
        for(; tracks; ) {
            next_track = tracks->next;
            if (!strcmp(tracks->title, trackTitle)) {
                last_track->next = next_track;
                // assign op_track as cuted track
                op_track = tracks;
                op_track->next = NULL;
                break;
            }
            last_track = tracks;
            tracks = next_track;
        }
    }
    if (!op_track)
        return ERROR_NOT_FOUND;
    // add this track to target playlist
    tracks = target_playlist->tracks;
    if (tracks == NULL) {
        target_playlist->tracks = op_track;
    } else {
        for(; tracks->next; ) {
            tracks = tracks->next;
        }
        tracks->next = op_track;
    }
    return SUCCESS;
}

// Print out all Tracks with artists that have the same Soundex Encoding 
// as the given artist.
void soundex_search(Library library, char artist[MAX_LEN]) {
    if (!library) return; // check library is null
    // search in library
    Playlist playlist = library->head;
    int pos = 0;
    Track tracks = NULL;
    char soundex[MAX_LEN] = {0};
    char search_soundex[MAX_LEN] = {0};
    soundex_encode(artist, search_soundex);
    // check library playlist is null
    if (playlist == NULL) return;
    for(pos = 0; playlist; ++pos) {
        // print tracks in playlist
        tracks = playlist->tracks;
        for(; tracks; ) {
            soundex_encode(tracks->artist, soundex);
            if (!strcmp(search_soundex, soundex))
                print_track(tracks->title, tracks->artist, tracks->length.minutes, tracks->length.seconds);
            tracks = tracks->next;
        }
        playlist = playlist->next;
    }
}


/*********
> STAGE 5
*********/

// Move all Tracks matching the Soundex encoding of the given artist 
// to a new Playlist.
int add_filtered_playlist(Library library, char artist[MAX_LEN]) {
    // add playlist named by artist
    Playlist playlist = library->head;
    Playlist artist_playlist = NULL;
    int name_length = strlen(artist);
    char ch = 0;
    char search_soundex[MAX_LEN] = {0};
    char soundex[MAX_LEN] = {0};
    int i = 0;
    int pos = 0;
    Track tracks = NULL;
    Track tmp_tracks = NULL;
    Track last_tracks = NULL;
    // new playlist tracks
    Track artist_tracks = NULL;
    // check name is valid
    for(i = 0; i < name_length; ++i) {
        ch = artist[i];
        if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z'))
            continue;
        else
          return ERROR_INVALID_INPUTS;
    }
    // add playlist in the library
    // if have non playlist in the library
    if (playlist == NULL) {
        library->head = malloc(sizeof (struct playlist));
        // get current playlist
        playlist = library->head;
        // set playlist selected
        library->selected_playlist_pos = 0;
    }else {
        while(1){ // Loop to the end of playlist linklist and check name is existed
            if (!strcmp(playlist->name, artist))
                return ERROR_INVALID_INPUTS;
            if (playlist->next)
                playlist = playlist->next;
            if (!playlist->next)
                break;
        }
        // compare last playlist name
        if (!strcmp(playlist->name, artist))
            return ERROR_INVALID_INPUTS;
        // add next playlist
        playlist->next = malloc(sizeof (struct playlist));
        // get current playlist
        playlist = playlist->next;
    }
    artist_playlist = playlist;
    artist_playlist->tracks = NULL;
    artist_playlist->next = NULL;
    strncpy(artist_playlist->name, artist, MAX_LEN);
    soundex_encode(artist, search_soundex);
    // search in library
    playlist = library->head;
    // check library playlist is null
    if (playlist == NULL || !playlist->next) return SUCCESS;
    // search same soundex in libirary, except new playlist
    for(pos = 0; playlist->next; ++pos) {
        tracks = playlist->tracks;
        for(; tracks; ) {
            soundex_encode(tracks->artist, soundex);
            if (!strcmp(search_soundex, soundex)) {
                // unlink from old playlist
                // check is head
                if(tracks == playlist->tracks) {
                    playlist->tracks = tracks->next;
                }else {
                    last_tracks->next = tracks->next;
                }
                // link to new playlist
                artist_tracks = artist_playlist->tracks;
                tmp_tracks = tracks->next;
                tracks->next = NULL;
                if (!artist_tracks) {
                    artist_playlist->tracks = tracks;
                }else {
                    for(; artist_tracks->next; )
                        artist_tracks = artist_tracks->next;
                    artist_tracks->next = tracks;
                }
                tracks = tmp_tracks;
                continue;
            }
            last_tracks = tracks;
            tracks = tracks->next;
        }
        playlist = playlist->next;
    }
    return SUCCESS;
}

// Reorder the selected Playlist in the given order specified by the order array.
void reorder_playlist(Library library, int order[MAX_LEN], int length) {
    if (library == NULL) return;
    Playlist playlist = library->head;
    Track tracks = NULL;
    Track tracks_arr[MAX_LEN] = {NULL};
    int i = 0;
    int playlist_tracks_len = 0;
    if (library->head == NULL) return;
    // get selected playlist
    for(i = 0; playlist; ++i) {
        if (i == library->selected_playlist_pos)
            break;
        playlist = playlist->next;
    }
    // check is valid and store
    tracks = playlist->tracks;
    // calc total of munites and seconds
    for(i = 0; tracks; ++i) {
        tracks_arr[i] = tracks;
        tracks = tracks->next;
    }
    playlist_tracks_len = i;

    // check is valid length
    if (length != playlist_tracks_len)
        return;
    // check is valid sort num
    for(i = 0; i < playlist_tracks_len; ++i)
        if (order[i] >= playlist_tracks_len)
            return;
    tracks = NULL;
    for(i = 0; i < length; ++i) {
        if(i == 0) {
            playlist->tracks = tracks_arr[order[0]];
            tracks = playlist->tracks;
            tracks->next = tracks_arr[order[1]];
            tracks->next = tracks;
            continue;
        }
        if (!tracks_arr[order[i]])
            break;
        if (tracks) {
            tracks->next = tracks_arr[order[i]];
            tracks = tracks->next;
        }
    }
    tracks->next = NULL;
}


/*****************
> Helper Functions
*****************/

static void print_playlist(int number, char playlistName[MAX_LEN]) {
    printf("[ ] %d. %s\n", number, playlistName);
}

static void print_selected_playlist(int number, char playlistName[MAX_LEN]) {
    printf("[*] %d. %s\n", number, playlistName);
}

static void print_track(char title[MAX_LEN], char artist[MAX_LEN], int minutes, int seconds) {
    printf("       - %-32s    %-24s    %02d:%02d\n", title, artist,
           minutes, seconds);
}

void soundex_encode(char words[MAX_LEN], char soundex[MAX_LEN]) {
    char encode_words[MAX_LEN];
    int encode_words_len = 0;
    int i = 0, j = 0;
    char ch = 0, m = 0;
    char prev, prev_output;
    char map[] = {
        //a  b   c   d   e   f   g   h   i   j   k   l   m
        '0','1','2','3','0','1','2','0','0','2','2','4','5',
        //n  o   p   q   r   s   t   u   v   w   x   y   z
        '5','0','1','2','6','2','3','0','1','0','2','0','2'
        };
    // encode search artist
    strncpy(encode_words, words, MAX_LEN);
    // to lower
    encode_words_len = strlen(encode_words);
    for(i = 0; i < encode_words_len; ++i)
        if (encode_words[i] >= 'A' && encode_words[i] <= 'Z')
            encode_words[i] += 'a' - 'A';
    // init memory as 0
    memset(soundex, 0, MAX_LEN);
    for(i = 0, j = 0, prev = '?', prev_output = '?'; i < encode_words_len; ++i) {
        ch = encode_words[i];
        if (i == 0) {
            soundex[j++] = ch;
            continue;
        }
        if (ch >= 'a' && ch <= 'z' && ch != prev) {
            prev = ch;
            m = map[ch - 'a'];
            if (m != '0' && m != prev_output) {
                soundex[j++] = m;
                prev_output = m;
            }
        }
    }
    for(i = j; i < 4; ++i)
        soundex[j++] = '0';
    soundex[j] = '\0';
}
