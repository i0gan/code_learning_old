 # cspotify



## How to compile

## Intro

This only modifies two files, one is `cspotify.c`, and the other is `test_ cspotify.c`. 

The environment is actually developed under Linux. 

In the  build folder, there are compiled binary files, and the test images are  in test_ img folder. 



### env

```
gcc
make
```

if you have installed above tools on you operating system, then you can compile it.

### Compile cspotify

```sh
make
```

### Compile test program

```sh
make test
```

### clean

```sh
make clean
```



```
ssh : z5286488@vscode.cse.unsw.edu.au
pass: HAcjyy2599
1511 autotest-stage 01 ass2_cspotify
```



## Stage1

### cspotify.c

```
add_playlist
print_library
rename_playlist
library
```

#### library

```c
struct library {
    struct playlist *head;
    int selected_playlist_pos; // Add a flag to realize which playlist selected
};
```



#### add_playlist

```c
    Playlist playlist = library->head;
    int name_length = strlen(playlistName);
    char ch = 0;
    // check name is valid
    for(int i = 0; i < name_length; ++i) {
        ch = playlistName[i];
        if((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            continue;
        else
          return ERROR_INVALID_INPUTS;
    }
    // add playlist in the library
    // if have non playlist in the library
    if(playlist == NULL) {
        library->head = (Playlist)malloc(sizeof (struct playlist));
        // get current playlist
        playlist = library->head;
        // set playlist selected
        library->selected_playlist_pos = 0;

    }else {
        do{ // loop to the end of playlist linklist and check name is existed
            if(!strcmp(playlist->name, playlistName))
                return ERROR_INVALID_INPUTS;
            if(playlist->next)
                playlist = playlist->next;
        }while(playlist->next);
        // compare last playlist name
        if(!strcmp(playlist->name, playlistName))
            return ERROR_INVALID_INPUTS;

        // add next playlist
        playlist->next = (Playlist)malloc(sizeof (struct playlist));
        // get current playlist
        playlist = playlist->next;
    }

    playlist->tracks = NULL;
    playlist->next = NULL;
    strncpy(playlist->name, playlistName, MAX_LEN);
    return SUCCESS;
```



#### print_library

```c
void print_library(Library library) {
    Playlist playlist = library->head;
    int pos = 0;
    // check library playlist is null
    if(playlist == NULL) return;
    for(pos = 0; playlist; ++pos) {
        // print selected playlist
        if(pos == library->selected_playlist_pos)
            print_selected_playlist(pos, playlist->name);
        else
            print_playlist(pos, playlist->name);
        playlist = playlist->next;
    }
}
```



#### rename_playlist

```c
int rename_playlist(Library library, char playlistName[MAX_LEN],
    char newPlaylistName[MAX_LEN]) {
    Playlist playlist = library->head;
    char ch = 0;
    int is_found = 0;
    int new_name_length = strlen(newPlaylistName);
    // check name is valid
    for(int i = 0; i < new_name_length; ++i) {
        ch = newPlaylistName[i];
        if((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            continue;
        else
          return ERROR_INVALID_INPUTS;
    }
    // check library playlist is null
    if(playlist == NULL) return ERROR_NOT_FOUND;

    // check new playlist name is existed
    do {
        // print selected playlist
        if(!strcmp(playlist->name, newPlaylistName)) {
            return ERROR_INVALID_INPUTS;
        }
        playlist = playlist->next;
    }while (playlist);

     // reset playlist ptr
    playlist = library->head;
    do {
        // print selected playlist
        if(!strcmp(playlist->name, playlistName)) {
            strncpy(playlist->name, newPlaylistName, MAX_LEN);
            is_found = 1;
        }
        playlist = playlist->next;
    }while (playlist);
    if(is_found == 0)
        return ERROR_NOT_FOUND;

    return SUCCESS;
}
```



### test_cspotify.c

```
test_add_playlist
test_rename_playlist
```

#### test_add_playlist

```c
void test_add_playlist(void) {

    // Test 1: Does add_playlist return SUCCESS and add 
    // when adding one Playlist with a valid name?
    Library testLibrary = create_library();

    int result = add_playlist(testLibrary, "Favourites");
    if (result != SUCCESS) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }

    char printText[10000];
    CAPTURE(print_library(testLibrary), printText, 10000);
    if (!string_contains(printText, "Favourites")) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }

    // Test 2: Does add_playlist return ERROR_INVALID_INPUTS
    // and not add the playlist into the Library
    // when trying to add a Playlist with an invalid name?
    // TODO: Add your test for Test 2
    result = add_playlist(testLibrary, "A&&b");
    if (result != ERROR_INVALID_INPUTS) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }

    // Test 3: ???
    // TODO: Add your own test, and explain it.
    add_playlist(testLibrary, "A");
    result = add_playlist(testLibrary, "A");
    // Check playlist name is existed
    if (result != ERROR_INVALID_INPUTS) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }
    printf("MEETS SPEC\n");
}
```

#### test_rename_playlist

```c
void test_rename_playlist(void) {
    // Test 1: Does rename_playlist return ERROR_NOT_FOUND 
    // when trying to rename a playlist when the Library is empty
    Library testLibrary = create_library();

    int result = rename_playlist(testLibrary, "Favourites", "Dislikes");
    if (result != ERROR_NOT_FOUND) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }

    // Test 2: Does rename_playlist successfully
    // rename a Playlist
    // when a valid new Playlist name is given to 
    // rename an existing Playlist in the Library?
    // TODO: Add your test for Test 2
    add_playlist(testLibrary, "Favourites");
    add_playlist(testLibrary, "Favourites2");
    result = rename_playlist(testLibrary, "Favourites", "Favourites2");
    if(result != ERROR_INVALID_INPUTS) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }

    // Test 3: ???
    // TODO: Add your own test, and explain it.

    // rename as invalid name
    result = rename_playlist(testLibrary, "Favourites", "&&aaa");
    if(result != ERROR_INVALID_INPUTS) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }
    printf("MEETS SPEC\n");
}
```

## Stage2

### cspotify.c

```
select_next_playlist
select_previous_playlist
add_track
print_library
playlist_length
```

#### select_next_playlist

```c
void select_next_playlist(Library library) {
    Playlist playlist = library->head;
    int pos = 0;
    if(playlist == NULL) return;
    // check library playlist is null
    for(pos = 0; playlist; ++pos) {
        // judge if can set as next pos
        if(pos - 1 >= library->selected_playlist_pos) {
            library->selected_playlist_pos += 1;
            return;
        }
        playlist = playlist->next;
    }
    // set selected playlist pos as first playlist pos
    library->selected_playlist_pos = 0;
}
```



#### select_previous_playlist

```c
void select_previous_playlist(Library library) {
    Playlist playlist = library->head;
    int last_pos = 0;
    // check library playlist is null
    if(playlist == NULL) return;
    // get last playlist pos
    for(last_pos = -1; playlist; ++last_pos) {
        playlist = playlist->next;
    }
    if(library->selected_playlist_pos > 0)
        library->selected_playlist_pos --;
    else
        // set selected playlist as last playlist pos
        library->selected_playlist_pos = last_pos;
}
```



#### add_track

```c
int add_track(Library library, char title[MAX_LEN], char artist[MAX_LEN], 
              int trackLengthInSec, int position) {
    Playlist playlist = library->head;
    Track tracks = NULL;
    Track last_tracks = NULL;
    Track tmp_tracks = NULL; // tmp tracks
    int playlist_len = 0;
    int pos = 0;
    // check library playlist is null
    if(playlist == NULL) return ERROR_NOT_FOUND;
    // get selected playlist
    for(pos = 0; playlist; ++pos) {
        if(pos == library->selected_playlist_pos)
            break;
        playlist = playlist->next;
    }

    // get length of playlist and compare title if is exsited
    tracks = playlist->tracks;
    for(playlist_len = 0; tracks; ++playlist_len) {
        if(!strcmp(tracks->title, title))
            return ERROR_INVALID_INPUTS;
        tracks = tracks->next;
    }

    if(position > playlist_len || position < 0)
        return ERROR_INVALID_INPUTS;

    // new track
    // add to head of tracks
    if(position == 0) {
         tmp_tracks = malloc(sizeof (struct track));
         last_tracks = playlist->tracks;
         playlist->tracks = tmp_tracks;
         tmp_tracks->next = last_tracks;

    }else {
        // reset tracks as head
        tracks = playlist->tracks;
        for(pos = 0; tracks; ++pos) {
            if(pos >= position)
                break;
            last_tracks = tracks;
            tracks = tracks->next;
        }
        tmp_tracks = (Track)malloc(sizeof (struct track)); // insert a track into playlist
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
```



#### print_library

```c
void print_library(Library library) {
    Playlist playlist = library->head;
    int pos = 0;
    Track tracks = NULL;
    // check library playlist is null
    if(playlist == NULL) return;
    for(pos = 0; playlist; ++pos) {
        // print selected playlist
        if(pos == library->selected_playlist_pos)
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
```



#### playlist_length

```c
void playlist_length(Library library, int *playlistMinutes, int *playlistSeconds) {
    Track tracks = NULL;
    int pos = 0;
    Playlist playlist = library->head;
    *playlistMinutes = 0;
    *playlistSeconds = 0;
    // check library playlist is null
    if(playlist == NULL)
        return ;

    // get selected playlist
    for(pos = 0; playlist; ++pos) {
        if(pos == library->selected_playlist_pos)
            break;
        playlist = playlist->next;
    }
    tracks = playlist->tracks;

    // calc total of munites and seconds
    for(; tracks; ) {
        //print_track(tracks->title, tracks->artist, tracks->length.minutes, tracks->length.seconds);
        *playlistMinutes += tracks->length.minutes;
        *playlistSeconds += tracks->length.seconds;
        tracks = tracks->next;
    }
}
```



### test_cspotify.c

```
test_add_track
test_playlist_length
```

#### test_add_track

```c
void test_add_track(void) {
    // Test 1: Does add_track successfully add 
    // multiple (more than 3 Tracks) Tracks 
    // to the Library?
    // TODO: Add your test for Test 1
    Library testLibrary = create_library();
    add_playlist(testLibrary, "Favourites");

    add_track(testLibrary, "Bad guy", "xxx", 60, 0);
    add_track(testLibrary, "Waiting for love", "xxx", 60, 0);
    add_track(testLibrary, "Higher place", "xxx", 450, 0);

    //print_library(testLibrary);
    char printText[10000];
    CAPTURE(print_library(testLibrary), printText, 10000);
    if (!string_contains(printText, "Bad guy") || !string_contains(printText, "Waiting for love") || !string_contains(printText, "Higher place")) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }

    // Test 2: ???
    // TODO: Add your own test, and explain it.

    // Test select playlist and add a exsited track in selected playlist
    add_playlist(testLibrary, "RAP");
    // Select next playlist, it's RAP
    select_next_playlist(testLibrary);

    // same track in the playlist 0
    int result = add_track(testLibrary, "Bad guy", "xxx", 60, 0);
    if(result != SUCCESS) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }
    // Select previous playlist, it's Favourites
    select_previous_playlist(testLibrary);

    // Add a existed track
    result = add_track(testLibrary, "Higher place", "xxx", 450, 0);
    if(result != ERROR_INVALID_INPUTS) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }

    printf("MEETS SPEC\n");
}
```



#### test_playlist_length

```c
void test_playlist_length(void) {
    // Test 1: Does playlist_length work for Tracks 
    // with lengths greater than 60 seconds?
    // TODO: Add your test for Test 1
    Library testLibrary = create_library();
    add_playlist(testLibrary, "Favourites");

    add_track(testLibrary, "Bad guy", "xxx", 67, 0);
    add_track(testLibrary, "Waiting for love", "xxx", 62, 1);
    int min, sec;
    playlist_length(testLibrary, &min, &sec);
    if(min != 2 || sec != 9) {
        printf("DOES NOT MEET SPEC\n");
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
        printf("DOES NOT MEET SPEC\n");
        return;
    }

    printf("MEETS SPEC\n");
}
```



## Stage3

### cspotify.c

```
print_library
delete_track
delete_playlist
delete_library
```

#### print_library

add a line code at first line

```c
if(!library) return; // check library is null
```



#### delete_track

```c
void delete_track(Library library, char track[MAX_LEN]) {
    Track tracks = NULL;
    Track next_track = NULL;
    Track last_track = NULL;
    int pos = 0;
    Playlist playlist = library->head;
    // check library playlist is null
    if(playlist == NULL)
        return ;

    // get selected playlist
    for(pos = 0; playlist; ++pos) {
        if(pos == library->selected_playlist_pos)
            break;
        playlist = playlist->next;
    }

    tracks = playlist->tracks;
    // check head is null
    if(!tracks) return;
    // delete tracks
    // check is head
    if(!strcmp(tracks->title, track)) {
        next_track = tracks->next;
        free(tracks);
        playlist->tracks = next_track;
    }else {

        last_track = tracks;
        for(; tracks; ) {
            next_track = tracks->next;
            if(!strcmp(track, tracks->title)) {
                last_track->next = next_track;
                free(tracks);
                break;
            }
            last_track = tracks;
            tracks = next_track;
        }
    }
}
```

#### delete_playlist

```c
void delete_playlist(Library library) {
    Track tracks = NULL;
    Track next_track = NULL;
    int pos = 0;
    Playlist playlist = library->head;
    Playlist last_playlist = NULL;
    // check library playlist is null
    if(playlist == NULL)
        return ;
    // get selected playlist
    for(pos = 0; playlist; ++pos) {
        if(pos == library->selected_playlist_pos)
            break;
        last_playlist = playlist;
        playlist = playlist->next;
    }

    // unlink playlist
    // if is head
    if(library->selected_playlist_pos == 0) {
        library->head= library->head->next;
    }else {
        last_playlist->next = playlist->next;
        if(playlist->next == NULL) {
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
```



#### delete_library

```c
void delete_library(Library library) {
    Track tracks = NULL;
    Track next_track = NULL;
    Playlist playlist = library->head;
    // check library playlist is null
    if(playlist == NULL) {
        library->selected_playlist_pos = 0;
        return ;
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
```



### test_cspotify.c

```
test_delete_playlist
```

#### test_delete_playlist

```c
void test_delete_playlist(void) {
    // Test 1: Does delete_playlist work if
    // the selected Playlist is the first Playlist
    // in the Library?
    // TODO: Add your test for Test 1
    Library testLibrary = create_library();
    add_playlist(testLibrary, "Favourites");
    add_playlist(testLibrary, "RAP1");
    delete_playlist(testLibrary);
    char printText[10000];
    CAPTURE(print_library(testLibrary), printText, 10000);
    if (string_contains(printText, "Favourites")) {
        printf("DOES NOT MEET SPEC\n");
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
        printf("DOES NOT MEET SPEC\n");
        return;
    }

    printf("MEETS SPEC\n");
}
```



## Stage4

### cspotify.c

```
cut_and_paste_track
soundex_search
```



#### cut_and_paste_track

```c
int cut_and_paste_track(Library library, char trackTitle[MAX_LEN], 
                        char destPlaylist[MAX_LEN]) {
    if(library == NULL) return ERROR_NOT_FOUND;
    Playlist playlist = library->head;
    Playlist target_playlist = library->head;
    Track tracks = NULL;
    Track next_track = NULL;
    Track last_track = NULL;
    Track op_track = NULL;
    int pos = 0;


    if(library->head == NULL) return ERROR_NOT_FOUND;

    for(; target_playlist; ) {
        if(!strcmp(target_playlist->name, destPlaylist))
            break;
        target_playlist = target_playlist->next;
    }
    if(!target_playlist) {
        return ERROR_NOT_FOUND;
    }

    // get selected playlist
    for(pos = 0; playlist; ++pos) {
        if(pos == library->selected_playlist_pos)
            break;
        playlist = playlist->next;
    }

    // unlink from selected playlist
    tracks = playlist->tracks;
    // check head is null
    if(!tracks) return ERROR_NOT_FOUND;
    // check is head
    if(!strcmp(tracks->title, trackTitle)) {
        next_track = tracks->next;
        // assign op_track as cuted track
        op_track = tracks;
        op_track->next = NULL;
        playlist->tracks = next_track;
    }else {
        last_track = tracks;
        for(; tracks; ) {
            next_track = tracks->next;
            if(!strcmp(tracks->title, trackTitle)) {
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

    if(!op_track)
        return ERROR_NOT_FOUND;

    // add this track to target playlist
    tracks = target_playlist->tracks;
    if(tracks == NULL) {
        target_playlist->tracks = op_track;
    }else {
        for(; tracks->next; ) {
            tracks = tracks->next;
        }
        tracks->next = op_track;
    }
    return SUCCESS;
}
```



#### soundex_search

```c
void soundex_search(Library library, char artist[MAX_LEN]) {
    if(!library) return; // check library is null

    char is_encode = 0;
    char encode_words[MAX_LEN] = {0};
    char soundex[MAX_LEN] = {0};
    char search_soundex[MAX_LEN] = {0};
    int encode_words_len = 0;

    int i = 0, j = 0;
    char ch = 0;
    char prev, prev_output;
    char map[] = {
        //a  b   c   d   e   f   g   h   i   j   k   l   m
        '0','1','2','3','0','1','2','0','0','2','2','4','5',
        //n  o   p   q   r   s   t   u   v   w   x   y   z
        '5','0','1','2','6','2','3','0','1','0','2','0','2'
        };
    // encode search artist
    strncpy(encode_words, artist, MAX_LEN);
    ENCODE:
    // to lower
    encode_words_len = strlen(encode_words);
    for(i = 0; i < encode_words_len; ++i)
        if(encode_words[i] >= 'A' && encode_words[i] <= 'Z')
            encode_words[i] += 'a' - 'A';
    // init memory as 0
    memset(soundex, 0, MAX_LEN);
    for(i = 0, j = 0, prev = '?', prev_output = '?'; i < encode_words_len; ++i) {
        ch = encode_words[i];
        if(i == 0) {
            soundex[j++] = ch;
            continue;
        }

        if(ch >= 'a' && ch <= 'z' && ch != prev) {
            prev = ch;
            char m = map[ch - 'a'];
            if(m != '0' && m != prev_output) {
                soundex[j++] = m;
                prev_output = m;
            }
        }
    }
    for(int i = j; i < 4; ++i)
        soundex[j++] = '0';
    soundex[j] = '\0';
    if(is_encode) {
        goto FINISH;
    }

    strncpy(search_soundex, soundex, MAX_LEN);
    // search in library
    Playlist playlist = library->head;
    int pos = 0;
    Track tracks = NULL;
    // check library playlist is null
    if(playlist == NULL) return;
    for(pos = 0; playlist; ++pos) {
        // print tracks in playlist
        tracks = playlist->tracks;
        for(; tracks; ) {
            is_encode = 1;
            strncpy(encode_words, tracks->artist, MAX_LEN);
            goto ENCODE;
            FINISH:
            if(!strcmp(search_soundex, soundex))
                print_track(tracks->title, tracks->artist, tracks->length.minutes, tracks->length.seconds);
            tracks = tracks->next;
        }
        playlist = playlist->next;
    }
}
```



### test_cspotify.c

```
test_soundex_search
```



#### test_soundex_search

```c
void test_soundex_search(void) {
    // Test 1: ???
    // TODO: Add your own test, and explain it.


    // Test soundex is right, soundex abc14 == avz4 ==> a120
    Library testLibrary = create_library();
    add_playlist(testLibrary, "Favourites");
    add_track(testLibrary, "Music1", "abc14", 0, 0);
    add_track(testLibrary, "Music2", "daexe", 0, 0);
    add_track(testLibrary, "Music3", "avz4", 0, 0);

    char printText[10000];
    // soundex apj ==> a120
    CAPTURE(soundex_search(testLibrary, "apj"), printText, 10000);
    if (!string_contains(printText, "Music1") || !string_contains(printText, "Music3")) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }

    // Test 2: ???
    // TODO: Add your own test, and explain it.

    // Test: Replace all adjacent same digits with one digit, and then remove all the
    // zero (0) digits
    CAPTURE(soundex_search(testLibrary, "daaaeeexe"), printText, 10000);
    if (!string_contains(printText, "Music2")) {
        printf("DOES NOT MEET SPEC\n");
        return;
    }
    printf("MEETS SPEC\n");
}
```



## Stage5

### cspotify.c

```
add_filtered_playlist
reorder_playlist
```



#### add_filtered_playlist

```c
int add_filtered_playlist(Library library, char artist[MAX_LEN]) {
    // add playlist named by artist
    Playlist playlist = library->head;
    Playlist artist_playlist = NULL;
    int name_length = strlen(artist);
    char ch = 0;
    // check name is valid
    for(int i = 0; i < name_length; ++i) {
        ch = artist[i];
        if((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
            continue;
        else
          return ERROR_INVALID_INPUTS;
    }

    // add playlist in the library
    // if have non playlist in the library
    if(playlist == NULL) {
        library->head = (Playlist)malloc(sizeof (struct playlist));
        // get current playlist
        playlist = library->head;
        // set playlist selected
        library->selected_playlist_pos = 0;

    }else {
        do{ // Loop to the end of playlist linklist and check name is existed
            if(!strcmp(playlist->name, artist))
                return ERROR_INVALID_INPUTS;
            if(playlist->next)
                playlist = playlist->next;
        }while(playlist->next);
        // compare last playlist name
        if(!strcmp(playlist->name, artist))
            return ERROR_INVALID_INPUTS;
        // add next playlist
        playlist->next = (Playlist)malloc(sizeof (struct playlist));
        // get current playlist
        playlist = playlist->next;
    }
    artist_playlist = playlist;
    artist_playlist->tracks = NULL;
    artist_playlist->next = NULL;
    strncpy(artist_playlist->name, artist, MAX_LEN);


    // *******   soundex encode   *******
    char is_encode = 0;
    char encode_words[MAX_LEN] = {0};
    char soundex[MAX_LEN] = {0};
    char search_soundex[MAX_LEN] = {0};
    int encode_words_len = 0;
    int i = 0, j = 0;
    char prev, prev_output;
    char map[] = {
        //a  b   c   d   e   f   g   h   i   j   k   l   m
        '0','1','2','3','0','1','2','0','0','2','2','4','5',
        //n  o   p   q   r   s   t   u   v   w   x   y   z
        '5','0','1','2','6','2','3','0','1','0','2','0','2'
        };
    ch = 0;

    // encode search artist
    strncpy(encode_words, artist, MAX_LEN);
    ENCODE:
    // to lower
    encode_words_len = strlen(encode_words);
    for(i = 0; i < encode_words_len; ++i)
        if(encode_words[i] >= 'A' && encode_words[i] <= 'Z')
            encode_words[i] += 'a' - 'A';
    // init memory as 0
    memset(soundex, 0, MAX_LEN);
    for(i = 0, j = 0, prev = '?', prev_output = '?'; i < encode_words_len; ++i) {
        ch = encode_words[i];
        if(i == 0) {
            soundex[j++] = ch;
            continue;
        }

        if(ch >= 'a' && ch <= 'z' && ch != prev) {
            prev = ch;
            char m = map[ch - 'a'];
            if(m != '0' && m != prev_output) {
                soundex[j++] = m;
                prev_output = m;
            }
        }
    }
    for(int i = j; i < 4; ++i)
        soundex[j++] = '0';
    soundex[j] = '\0';
    if(is_encode) {
        goto FINISH;
    }

    strncpy(search_soundex, soundex, MAX_LEN);

    // search in library
    playlist = library->head;
    int pos = 0;
    Track tracks = NULL;
    Track tmp_tracks = NULL;
    Track last_tracks = NULL;
    // new playlist tracks
    Track artist_tracks = NULL;
    // check library playlist is null
    if(playlist == NULL || !playlist->next) return SUCCESS;
    // search same soundex in libirary, except new playlist
    for(pos = 0; playlist->next; ++pos) {
        if(pos == library->selected_playlist_pos)
            print_selected_playlist(pos, playlist->name);
        else
            print_playlist(pos, playlist->name);
        tracks = playlist->tracks;
        for(; tracks; ) {
            is_encode = 1;
            strncpy(encode_words, tracks->artist, MAX_LEN);
            goto ENCODE;
            FINISH:
            if(!strcmp(search_soundex, soundex)) {
                print_track(tracks->title, tracks->artist, tracks->length.minutes, tracks->length.seconds);
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
                if(!artist_tracks) {
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
```



#### reorder_playlist

```c
void reorder_playlist(Library library, int order[MAX_LEN], int length) {
    if(library == NULL) return;
    Playlist playlist = library->head;
    Track tracks = NULL;
    Track tracks_arr[MAX_LEN] = {NULL};

    int i = 0;
    int playlist_tracks_len = 0;
    if(library->head == NULL) return;
    // get selected playlist
    for(i = 0; playlist; ++i) {
        if(i == library->selected_playlist_pos)
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
    if(length != playlist_tracks_len)
        return;

    // check is valid sort num
    for(i = 0; i < playlist_tracks_len; ++i)
        if(order[i] >= playlist_tracks_len)
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
        if(!tracks_arr[order[i]])
            break;
        if(tracks) {
            tracks->next = tracks_arr[order[i]];
            tracks = tracks->next;
        }
    }
    tracks->next = NULL;
}
```







refer doc: https://cgi.cse.unsw.edu.au/~cs1511/20T3/assignments/ass2/index.html