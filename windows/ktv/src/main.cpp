/*
 * Author: Xulvguo (I0gan)
 * Creation time: 2020-06-??
 * Update time:   2020-06-20
 *
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <graphics.h>
#include <mmsystem.h>
#include <shellapi.h>
#include <afxcom_.h>
#include <digitalv.h>
#include <io.h>
#include <direct.h>
#include <time.h>
#include <cstring>
#include <cassert>

#pragma comment(lib, "winmm.lib")

#define DEBUG // Debug
#ifdef DEBUG 
#define SONG_PATH "../build/song/"		        // Default load songs path
#define PLAY_LIST_FILE "../build/res/play_list" // Default load play list file path
#define ALL_LIST_FILE "../build/res/all_list"   // Default load all list file path
#define PASSWORD_FILE "../build/res/passwd"     // Default load passwd file path
#define RES_PATH "../build/res/"			    // Default load res path
#else
#define SONG_PATH "song/"		 // Default load songs path
#define PLAY_LIST_FILE "res/play_list" // Default load data file path
#define ALL_LIST_FILE "res/all_list"   // Default load data file path
#define PASSWORD_FILE "res/passwd"     // Default load data file path
#define RES_PATH "res/"	               // Default load res path
#endif

#define DEFAULT_PASSWORD "123456"
// Define key dec code 
#define KEY_RIGHT 77
#define KEY_LEFT  75
#define	KEY_UP    72
#define	KEY_DOWN  80
#define	KEY_BLANK 32
#define KEY_RETURN 13
#define KEY_BACKSPACE 8

// Debug for output
class dbg {
public:
	void operator<<(int v) {
		char value[16];
		sprintf(value, "%15d", v);
		MessageBox(0, value, "DEBUG", 0);
	}

	void operator<<(const unsigned int v) {
		char value[16];
		sprintf(value, "%15d", v);
		MessageBox(0, value, "DEBUG", 0);
	}

	void operator<<(char v) {
		char value[16];
		sprintf(value, "%c", v);
		MessageBox(0, value, "DEBUG", 0);
	}

	void operator<<(const std::string &v) {
		MessageBox(0, v.c_str(), "DEBUG", 0);
	}
	void operator<<(const char *v) {
		MessageBox(0, v, "DEBUG", 0);
	}

};

/*
 * Forwardlist container
 */
template<class T>
struct ForwardListData {
	T value_;
	ForwardListData<T> *next_ptr_;	
};

template<class T>
class ForwardList {
public:
	inline ForwardList () : header_(NULL) , tail_(NULL), size_(0){ }
	inline ForwardList(const ForwardList<T> &t) : header_(NULL) , tail_(NULL), size_(0) {
		this->merge(t);
	}
	inline void operator =(const ForwardList<T> &t) {
		this->free();
		this->merge(t);
	}

	inline ~ForwardList () {
		this->free();
	}
	// Get element by []
	inline T operator [](const unsigned int index) const{
		return at(index);
	}
	// Merge t to this container
	inline void merge(const ForwardList<T> &t) {
		if(t.size() == 0) {
			return ;
		}
		ForwardListData<T> *data_ptr = NULL;
		ForwardListData<T> *next_data_ptr = NULL;
		data_ptr = t.header_;
		while(data_ptr) {
			this->push_back(data_ptr->value_);
			data_ptr = data_ptr->next_ptr_;
		}
	}
	// Set element by index
	inline void set(const unsigned int index, const T &t) {
		assert(this->size_ >= index + 1);
		ForwardListData<T> *data_ptr = NULL;
		ForwardListData<T> *next_data_ptr = NULL;
		data_ptr = this->header_;
		next_data_ptr = data_ptr->next_ptr_;
		
		unsigned int i = 0;
		while(i < index) {
			data_ptr = data_ptr->next_ptr_;
			next_data_ptr = data_ptr->next_ptr_;
			++ i;
		}
		data_ptr->value_ = t;
	}
	// Get element by index
	inline T get(const unsigned int index) const {
		return at(index);
	}

	// Get element by index
	inline T at(const unsigned int index) const{
		assert(this->size_ >= index + 1);
		ForwardListData<T> *data_ptr;
		ForwardListData<T> *next_data_ptr;
		data_ptr = this->header_;
		next_data_ptr = data_ptr->next_ptr_;
		
		unsigned int i = 0;
		while(i < index) {
			data_ptr = data_ptr->next_ptr_;
			next_data_ptr = data_ptr->next_ptr_;
			++ i;
		}
		return data_ptr->value_;
	}
	// Delete element by index
	inline void erase (const unsigned int index) {
		assert(this->size_ >= index + 1);
		ForwardListData<T> *data_ptr;
		ForwardListData<T> *find_data_ptr;
		data_ptr = this->header_;
		unsigned int i = 1;
		if(index > 0) {
			while(i < index ) {
				data_ptr = data_ptr->next_ptr_;
				++ i;
			}
			find_data_ptr = data_ptr->next_ptr_;
			data_ptr->next_ptr_ = find_data_ptr->next_ptr_;
		
		}else {
			find_data_ptr = this->header_;
			this->header_ = find_data_ptr->next_ptr_;
		}
		delete find_data_ptr;
		-- this->size_;
	}
	// Delete all
	inline void erase () {
		this->free();
	}
	// Push a element to back
	inline void push_back(const T &t) {
		if(this->header_ == NULL) {
			this->header_ = new ForwardListData<T>;
			this->tail_ = this->header_;
		}else {
			this->tail_->next_ptr_ = new ForwardListData<T>;
			this->tail_ = this->tail_->next_ptr_;
		}
		this->tail_->value_ = t;
		this->tail_->next_ptr_ = NULL;
		++this->size_;
	}
	// Get number of element
	inline unsigned int size() const {
		return this->size_;
	}
private:
	ForwardListData<T> *header_;
	ForwardListData<T> *tail_;
	unsigned int size_;
	inline void free() {
		if(this->size_ == 0) return;
		ForwardListData<T> *data_ptr = NULL;
		ForwardListData<T> *next_data_ptr = NULL;
		data_ptr = this->header_;
		next_data_ptr = data_ptr->next_ptr_;
		while(data_ptr) {
			delete data_ptr;
			data_ptr = next_data_ptr;
			if(data_ptr != NULL) {
				next_data_ptr = data_ptr->next_ptr_;
			}
		}
		this->header_ = NULL;
		this->tail_ = NULL;
		this->size_ = 0;
	}
};


/*
 * Declare part
 *
*/

struct Song {
    std::string name;
	std::string publish_time;
	std::string author;
	std::string type;
	void operator=(const Song &song) {
		this->name = song.name;
		this->publish_time = song.publish_time;
		this->author = song.author;
		this->type = song.type;
	}
};

struct FileSong {
    char name[512];
	char publish_time[512];
	char author[512];
	char type[512];
};

enum ManageProcess {
	manage_login = 0,
	manage_main,
	manage_quit
};

enum ManageModifyProcess {
	manage_modify_none = 0,
	manage_modify_author,
	manage_modify_public_time,
	manage_modify_type,
	manage_modify_password
};

// Global Data
namespace data {
MCI_OPEN_PARMS mci_open;
MCIERROR mci_error;
UINT device_id;
MCI_PLAY_PARMS mci_play;
MCI_STATUS_PARMS mci_status_parms;
IMAGE image_play_bg;
IMAGE image_manage_bg;
ForwardList<Song> all_songs_list;
ForwardList<Song> play_songs_list;
ForwardList<Song> searched_songs_list;
bool is_show_all_songs_list = false;
bool is_input = false;
std::string input_content;
bool is_search = false;
bool is_mannge_mode = false;

int play_list_current_song_index = 0;
int play_list_select_song_index = 0;
int all_songs_list_selected_index = 0;
int searched_song_list_selected_index = 0;

namespace play {
    std::string song_name;
	int song_total_lenth = 0;
	int song_current_position = 0;
	bool is_play = false;
	int volume = 800;
}
namespace manage {
	ManageProcess process = manage_login;
	bool is_error = false;
	bool is_modify = false;
	int input_password_error_times = 0;
	ManageModifyProcess modify_process = manage_modify_none;
	struct Song modify_song;
}
}

bool openSong(const std::string &name);
bool closeSong();
bool suspendSong();
bool stopSong();
int getSongLenth();
bool setSongPlayPosition(int pos);
int getSongPlayPosition();
bool setVolume(int value);
void getSongsByDir(std::string dir);

void initUi();
void drawPlayUi();
void drawManageUi();
void controller();
std::string getNextSongName();
std::string getPrevSongName();
void playNextSong();
void playPrevSong();
void playSongByIndex(unsigned int index);
void playSongByName(std::string name);
void addSongToPlayList(int index);
void delSongFromPlayList(int index);
void addSearchedSongToPlayList(int index);
bool checkPassword(const std::string &passwd);
void SyncAllSongsList();
void UpdateAllSongs();

// Open song by song name
bool openSong(const std::string &name) {

	char str[128] = {0};
	
	::data::mci_open.lpstrDeviceType = "mpegvideo";
	::data::mci_open.lpstrElementName = name.c_str();
	::data::mci_error = mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&::data::mci_open);
	if(::data::mci_error) {
		mciGetErrorString(::data::mci_error, str, 128);
		//MessageBox(0, "open song failed! ", 0, 0);
		return false;
		//goto END;
	}
    ::data::device_id = ::data::mci_open.wDeviceID;
	return true;
}

// Close song
bool closeSong() {
    mciSendCommand(::data::device_id, MCI_CLOSE, NULL, NULL);
    if(::data::mci_error) {
		std::cout << "send MCI_CLOSE failed\n";
		return false;
	}
	return true;
}

// Play song
bool playSong() {
    ::data::mci_error = mciSendCommand(::data::device_id, MCI_PLAY, 0, (DWORD) &::data::mci_play);
    if(::data::mci_error) {
		std::cout << "send MCI_PLAY failed\n";
		return false;
	}
	return true;
}
// Suspend song
bool suspendSong() {
    ::data::mci_error = mciSendCommand(::data::device_id, MCI_STOP, NULL, NULL);
    if(::data::mci_error) {
		std::cout << "send MCI_STOP failed\n";
		return false;
	}
	return true;
}
// Stop song
bool stopSong() {
    ::data::mci_error = mciSendCommand(::data::device_id, MCI_STOP, NULL, NULL);
    if(::data::mci_error) {
		std::cout << "send MCI_STOP failed\n";
		return false;
	}
    ::data::mci_error = mciSendCommand(::data::device_id, MCI_SEEK, MCI_SEEK_TO_START, NULL);
    if(::data::mci_error) {
		std::cout << "send MCI_SEEK failed\n";
		return false;
	}
	return true;
}
// Get length of song
int getSongLenth() {
    ::data::mci_status_parms.dwItem = MCI_STATUS_LENGTH;
    ::data::mci_error = mciSendCommand(::data::device_id, MCI_STATUS, MCI_WAIT | MCI_STATUS_ITEM, (DWORD)&::data::mci_status_parms);
    if(::data::mci_error) {
		std::cout << "send MCI_STATUS failed\n";
		return false;
	}
    return ::data::mci_status_parms.dwReturn;
}
// Set song play postion
bool setSongPlayPosition(int pos) {
    ::data::mci_play.dwFrom = pos;
    ::data::mci_error = mciSendCommand(::data::device_id, MCI_PLAY, MCI_FROM, (DWORD)&::data::mci_play);
    if(::data::mci_error) {
		printf("send MCI_PLAY failed\n");
		return false;
	}
	return true;
}
// Get position of song
int getSongPlayPosition() {
    ::data::mci_status_parms.dwItem = MCI_STATUS_POSITION;
    ::data::mci_error = mciSendCommand(::data::device_id, MCI_STATUS, MCI_WAIT | MCI_STATUS_ITEM, (DWORD)&::data::mci_status_parms);
    if(::data::mci_error) {
		std::cout << "send MCI_STATUS failed\n";
		return -1;
	}
    return ::data::mci_status_parms.dwReturn;
}
// Volume control 0 - 1000
bool setVolume(int value) {
	MCI_DGV_SETAUDIO_PARMS mciSetAudioParms;
	mciSetAudioParms.dwItem = MCI_DGV_SETAUDIO_VOLUME;
	mciSetAudioParms.dwValue = value;
	mciSetAudioParms.dwOver = 0;
    mciSendCommand(::data::device_id, MCI_SETAUDIO, MCI_DGV_SETAUDIO_VALUE |
		MCI_DGV_SETAUDIO_ITEM, (DWORD)&mciSetAudioParms);

    if(::data::mci_error) {
		std::cout << "send MCI_SETAUDIO failed\n";
		return false;
	}
	return true;
}

// Search all '.mp3' file by dir
void LoadAllSongsByDir(std::string dir) {
	
	long file;
	struct _finddata_t find;
	//_chdir(dir.c_str());
	if(-1 == (file = _findfirst((std::string(SONG_PATH) + "*.*").c_str(), &find))) {
		std::cout << "none\n";
		return ;
	}
	while(0 == _findnext(file, &find)) {
			
			if(strstr(find.name, ".mp3")) {
				char time_str[128] = {0};
				struct tm *tp;
				struct Song song;
				tp = gmtime(&find.time_create);
				strftime(time_str, sizeof(time_str), "%Y-%m-%d", tp);
				song.publish_time = time_str;
				song.name = find.name;
				song.author = "Unknown";
				song.type = "Unknown";
				::data::all_songs_list.push_back(song);

		}
	}
	_findclose(file); 
}
// Load songs
void loadSongs() {
	// Load play list from data file
	
	LoadAllSongsByDir(SONG_PATH); //Load all songs
	UpdateAllSongs();
	FILE *play_list_file = NULL;
	struct FileSong file_song_data;
	int read_len = 0;
	do {
		
		play_list_file = fopen(PLAY_LIST_FILE, "rb");
		// If not have then crate it
		if(!play_list_file) {
			play_list_file = fopen(PLAY_LIST_FILE, "wb");
			if(play_list_file) {
				fclose(play_list_file);
			}
			break;
		}
		
		// Read data file
		do {
			read_len = fread(reinterpret_cast<void *>(&file_song_data), 1, sizeof(file_song_data), play_list_file);
			if(read_len == sizeof(file_song_data)) {
				struct Song song;
				song.name = file_song_data.name;
				song.author = file_song_data.author;
				song.publish_time = file_song_data.publish_time;
				song.type = file_song_data.type;
				::data::play_songs_list.push_back(song);
			}
		}while(read_len == sizeof(file_song_data));
		fclose(play_list_file);
	} while(false);
}

int checkInAllList(const std::string &name) {
	for(int index = 0; index < ::data::all_songs_list.size(); ++index) {
			if(name == ::data::all_songs_list.at(index).name)
				return index;
	}
	return -1;
}

void UpdateAllSongs() {
	FILE *all_list_file = NULL;
	struct FileSong file_song_data;
	int read_len = 0;
	int pos = -1;
	do {
		all_list_file = fopen(ALL_LIST_FILE, "rb");
		// If not have then crate it
		if(!all_list_file) {
			all_list_file = fopen(ALL_LIST_FILE, "wb");
			if(all_list_file) {
				fclose(all_list_file);
			}
			break;
		}
		// Read data file
		do {
			read_len = fread(reinterpret_cast<void *>(&file_song_data), 1, sizeof(file_song_data), all_list_file);
			if(read_len == sizeof(file_song_data)) {
				struct Song song;
				song.name = file_song_data.name;
				song.author = file_song_data.author;
				song.publish_time = file_song_data.publish_time;
				song.type = file_song_data.type;
				if((pos = checkInAllList(song.name)) != -1) {
					::data::all_songs_list.set(pos, song);
				}
			}
		}while(read_len == sizeof(file_song_data));
		fclose(all_list_file);
	} while(false);
}

void initUi() {
    loadimage(&::data::image_play_bg, (std::string(RES_PATH) + "play_bg.jpg").c_str(), 640, 480, true);
	loadimage(&::data::image_manage_bg, (std::string(RES_PATH) + "manage_bg.jpg").c_str(), 640, 480, true);
}

// Draw ui
void drawPlayUi() {
	//cleardevice();
    char show_length[128] = {0};
	char show_volume[64] = {0};
    int song_total_length = ::data::play::song_total_lenth / 1000;
    int song_current_position = ::data::play::song_current_position / 1000;
	
    int curent_line_position = 0;
	if(song_total_length != 0) {
		curent_line_position = (10 + (song_current_position * (630) / song_total_length));
	}
	putimage(0, 0, &::data::image_play_bg);
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	
	if(::data::play_songs_list.size() < 1) {
		outtextxy( 180, 380, "Play list have not songs,Plz press key a to add");
	}
    sprintf(show_length, "%d s / %d s", song_current_position, song_total_length);
    sprintf(show_volume, "volume: %d | 100", ::data::play::volume / 10);
	outtextxy(500, 440, show_volume);
	// Draw song name
    outtextxy(20, 420, ::data::play::song_name.c_str());
    outtextxy(540, 420, show_length);

	line(10, 400, 630, 400);
	
	// Draw song process
    fillcircle(curent_line_position, 400, 5);
	
	// Draw play list
	int times = 1;
	outtextxy(40, 20, "--------- Play song list ---------");
    for(int index = 0; index < ::data::play_songs_list.size(); ++index) {
		std::string song_name = data::play_songs_list.at(index).name;
        if(index == ::data::play_list_select_song_index && !::data::is_show_all_songs_list) {
			settextcolor(0x5555FF);
        }else if(index == ::data::play_list_current_song_index){
			settextcolor(0xAACC00);
		}else {
			settextcolor(WHITE);
		}
		outtextxy( 20, 40 + 20 * times, song_name.c_str());
		++times;
		if(times > 10) {
			break;
		}
	}

	// Draw state of play
    if(true == ::data::play::is_play) {
		line(310, 430, 310, 440);
		line(320, 430, 320, 440);
		ellipse(300, 420, 330, 450);
	}else {
		line(310, 435, 320, 445);
		line(310, 435, 320, 425);
		ellipse(300, 420, 330, 450);
	}
	//MessageBox(0, "debug", "aa", 0); while(true);
	// Draw all songs list
	if(::data::is_show_all_songs_list && !::data::is_input ) {
		times = 0;
		settextcolor(0xAACC00);
		outtextxy( 400, 20, "--------- Add Songs ---------");
		for(int index = 0; index < ::data::all_songs_list.size(); ++index) {
			std::string song_name = data::all_songs_list.at(index).name;
			if(index == ::data::all_songs_list_selected_index)
				settextcolor(0x5555FF);
			else
				settextcolor(0xAACC00);

			outtextxy( 360, 40 + 20 * index, song_name.c_str());
			++times;
			if(times > 10) {
				break;
			}
		}
	}else if(!::data::is_input && ::data::is_search){ // Draw search result list
		times = 0;
		settextcolor(0xAACC00);
		outtextxy( 400, 20, "--------- Search Result ---------");
		for(int index = 0; index < ::data::searched_songs_list.size(); ++index) {
			std::string song_name = data::searched_songs_list.at(index).name;
			if(index == ::data::searched_song_list_selected_index)
				settextcolor(0x5555FF);
			else
				settextcolor(0xAACC00);

			outtextxy( 360, 40 + 20 * index, song_name.c_str());
			++times;
			if(times > 10) {
				break;
			}
		}
	} else if(data::play_songs_list.size() > 0) { // Draw playing music info
		settextcolor(0xAACC00);
		struct Song song = ::data::play_songs_list.at(::data::play_list_current_song_index);
		outtextxy( 400, 40, "--------- Song info ---------");
		outtextxy( 360, 80,  ("Name : " + song.name).c_str());
		outtextxy( 360, 100, ("Author: " + song.author).c_str());
		outtextxy( 360, 120, ("Type  : " + song.type).c_str());
		outtextxy( 360, 140, ("Publish Time: " + song.publish_time).c_str());
	}

	if(::data::is_input && ::data::is_search) {
		settextcolor(WHITE);
		outtextxy( 360, 360, ("Search: " +::data::input_content).c_str());
	}
}

void drawManageUi() {
	putimage(0, 0, &::data::image_manage_bg);
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	
	if(::data::manage::input_password_error_times > 2) {
		::data::is_mannge_mode = false;
		::data::manage::is_error = false;
		::data::is_input = false;
		::data::manage::input_password_error_times = 0;
		return;
	}

	// Show password status
	if(::data::is_input && ::data::manage::process == manage_login) {
		std::string show_text = "PASSWORD: ";
		for(int i = 0; i < ::data::input_content.size(); ++i) {
			show_text += '*';
		}
		outtextxy(200, 300, show_text.c_str());
	}
	// Show password error
	if(::data::is_input && ::data::manage::is_error && ::data::manage::process == manage_login) {
		outtextxy(200, 280, "Password is error, Try again!");
	}
	// Check password
	if(!::data::is_input && ::data::manage::process == manage_login) {
		if(checkPassword(::data::input_content)) {
			::data::manage::process = manage_main;
			::data::is_input = false;
			::data::manage::is_error = false;
		}else {
			::data::manage::is_error = true;
			::data::is_input = true;
			::data::input_content.erase();
			::data::manage::input_password_error_times ++;
		}
	}
	// Main page
	if(::data::manage::process == manage_main) {
		settextcolor(0xAACC00);
		outtextxy(20, 20, "--------- All Songs ---------");
		for(int index = 0; index < ::data::all_songs_list.size(); ++index) {
			std::string song_name = data::all_songs_list.at(index).name;
			if(index == ::data::all_songs_list_selected_index)
				settextcolor(0x5555FF);
			else
				settextcolor(0xAACC00);
			outtextxy( 20, 40 + 20 * index, song_name.c_str());
			if(index > 10) {
				break;
			}
		}
		settextcolor(0xCCCC00);
		struct Song song = ::data::all_songs_list.at(::data::all_songs_list_selected_index);
		outtextxy( 400, 300, "--------- Song info ---------");
		outtextxy( 360, 320,  ("Name : " + song.name).c_str());
		outtextxy( 360, 340, ("Author: " + song.author).c_str());
		outtextxy( 360, 360, ("Type  : " + song.type).c_str());
		outtextxy( 360, 380, ("Publish Time: " + song.publish_time).c_str());

		// Show Input Text
		if(::data::is_input && ::data::manage::modify_process == manage_modify_author) {
			settextcolor(WHITE);
			outtextxy( 280, 440, ("Author: " +::data::input_content).c_str());
		}else if(::data::is_input && ::data::manage::modify_process == manage_modify_public_time) {
			settextcolor(WHITE);
			outtextxy( 280, 440, ("Publish Time: " +::data::input_content).c_str());
		}else if(::data::is_input && ::data::manage::modify_process == manage_modify_type) {
			settextcolor(WHITE);
			outtextxy( 280, 440, ("Type: " +::data::input_content).c_str());
		}
		
		if(!::data::is_input && ::data::manage::modify_process == manage_modify_author) {
			::data::manage::modify_song.name = ::data::all_songs_list.at(::data::all_songs_list_selected_index).name;
			::data::manage::modify_song.author = ::data::input_content;
			::data::is_input = true;
			::data::manage::modify_process = manage_modify_public_time;
			::data::input_content.erase();
		}else if(!::data::is_input && ::data::manage::modify_process == manage_modify_public_time) {
			
			::data::manage::modify_song.publish_time = ::data::input_content;
			::data::is_input = true;
			::data::manage::modify_process = manage_modify_type;
			::data::input_content.erase();
		}else if(!::data::is_input && ::data::manage::modify_process == manage_modify_type) {
			::data::manage::modify_song.type = ::data::input_content;
			::data::all_songs_list.set(::data::all_songs_list_selected_index, ::data::manage::modify_song);
			//dbg() << show;
			::data::manage::modify_process = manage_modify_none;
			::data::input_content.erase();
			SyncAllSongsList();
		}
	}
}

bool checkPassword(const std::string &passwd) {
	char buf[128] = {0};
	std::string file_password;
	FILE *passwd_file_ptr = NULL;
	passwd_file_ptr = fopen(PASSWORD_FILE, "r");
	if(!passwd_file_ptr) {
		passwd_file_ptr = fopen(PASSWORD_FILE, "w");
		if(passwd_file_ptr) {
			fprintf(passwd_file_ptr, DEFAULT_PASSWORD);
			fclose(passwd_file_ptr);
		}
		return passwd == DEFAULT_PASSWORD;
	}
	while(!feof(passwd_file_ptr)) {
		int read_len = fread(buf, 1, sizeof(buf), passwd_file_ptr);
		file_password += std::string(buf, read_len);
	}
	return file_password == passwd;
}

void SyncAllSongsList() {
	// Sync data to file
	FILE *data_file = NULL;
	struct FileSong file_song_data;
	data_file = fopen(ALL_LIST_FILE, "wb");
	if(!data_file) return ;
	for(int idx = 0; idx < ::data::all_songs_list.size(); ++idx) {
		memset(&file_song_data, 0, sizeof(file_song_data));
		struct Song song = ::data::all_songs_list.at(idx);
		memcpy(&file_song_data.name, song.name.data(), song.name.length());
		memcpy(&file_song_data.author, song.author.data(), song.author.length());
		memcpy(&file_song_data.publish_time, song.publish_time.data(), song.publish_time.length());
		memcpy(&file_song_data.type, song.name.data(), song.type.length());
		fwrite(&file_song_data, 1, sizeof(file_song_data), data_file);
	}
	fclose(data_file);
}
void searchSongsInAll() {
	::data::searched_songs_list.erase();
	for(int index = 0; index < ::data::all_songs_list.size(); ++index) {
		struct Song song = ::data::all_songs_list.at(index);
		if(strstr(song.name.c_str(), ::data::input_content.c_str())) {
			::data::searched_songs_list.push_back(song);
		}
	}
}

// Key control
void controller() {
	char ch = getch();
	// Input
	if(::data::is_input) {
		switch(ch) {
		case KEY_RETURN: {
			::data::is_input = false;
			if(::data::is_search) {
				searchSongsInAll();
			}
						 } break;
		case KEY_BACKSPACE: {
			if(::data::input_content.size() > 0) {
				::data::input_content.resize(::data::input_content.size() - 1);
			}
						 } break;
		default: {
			::data::input_content += ch;
			}
		}
		return ;
	}
	//dbg() << 1;
	// Control
	switch(ch) {
	case KEY_BLANK: {
		if(::data::is_mannge_mode) break;
        if(true == ::data::play::is_play) {
			suspendSong();
            ::data::play::is_play = false;
		}else {
			playSong();
            ::data::play::is_play = true;
		}
			 } break;
	case KEY_UP: {
		if(::data::is_mannge_mode) break;
		playPrevSong();
				 } break;
	case KEY_DOWN: {
		if(::data::is_mannge_mode) break;
		playNextSong();
				   } break;
	case KEY_LEFT: {
		if(::data::is_mannge_mode) break;
        ::data::play::song_current_position -= 10000;
        setSongPlayPosition(::data::play::song_current_position);
				   } break;
	case KEY_RIGHT: {
		if(::data::is_mannge_mode) break;
        ::data::play::song_current_position += 10000;
        setSongPlayPosition(::data::play::song_current_position);
					} break;
	case KEY_RETURN: {
		if(::data::is_mannge_mode) {
			if(::data::manage::process == manage_main && ::data::manage::modify_process == manage_modify_none) {
				::data::is_input = true;
				::data::manage::modify_process = manage_modify_author;
				::data::input_content.erase();
			}
			break;
		}
		// Add song from all songs list
		if(::data::is_show_all_songs_list){
			addSongToPlayList(::data::all_songs_list_selected_index);
			break;
		}
		// Add song from search songs list
		if(::data::is_search) {
			addSearchedSongToPlayList(::data::searched_song_list_selected_index);
			break;
		}
		playSongByIndex(::data::play_list_select_song_index);
					 } break;
	case 'w': {
		if(::data::is_mannge_mode) {
			if(::data::manage::process = manage_main) {
				::data::all_songs_list_selected_index --;
				if(::data::all_songs_list_selected_index < 0)
					::data::all_songs_list_selected_index =  static_cast<int>(::data::all_songs_list.size()) - 1;
				break;
			}
			break;
		}

		// All songs list select control
		if(::data::is_show_all_songs_list) {
			::data::all_songs_list_selected_index --;
			if(::data::all_songs_list_selected_index < 0)
				::data::all_songs_list_selected_index =  static_cast<int>(::data::all_songs_list.size()) - 1;
			break;
		}

		// Search select control
		if(::data::is_search) {
			::data::searched_song_list_selected_index --;
			if(::data::searched_song_list_selected_index < 0)
				::data::searched_song_list_selected_index =  static_cast<int>(::data::searched_songs_list.size()) - 1;
			break;
		}

		// Default play songs list select control
		::data::play_list_select_song_index --;
		if(::data::play_list_select_song_index < 0)
			::data::play_list_select_song_index =  static_cast<int>(::data::play_songs_list.size()) - 1;
			  } break;
	case 's': {
		if(::data::is_mannge_mode) {
			if(::data::manage::process = manage_main) {
				::data::all_songs_list_selected_index ++;
				if(::data::all_songs_list_selected_index > static_cast<int>(::data::all_songs_list.size()) - 1) {
					::data::all_songs_list_selected_index = 0;
				}
			}
			
			break;
		}
		// All songs list select control
		if(::data::is_show_all_songs_list) {
			::data::all_songs_list_selected_index ++;
			if(::data::all_songs_list_selected_index > static_cast<int>(::data::all_songs_list.size()) - 1) {
			 ::data::all_songs_list_selected_index = 0;
			}
			break;
		}
		// Search select control
		if(::data::is_search) {
			::data::searched_song_list_selected_index ++;
			if(::data::searched_song_list_selected_index > static_cast<int>(::data::searched_songs_list.size()) - 1) {
			 ::data::searched_song_list_selected_index = 0;
			}
			break;
		}

		// Default play songs list select control
		::data::play_list_select_song_index ++;
		if(::data::play_list_select_song_index > static_cast<int>(::data::play_songs_list.size()) - 1) {
			::data::play_list_select_song_index = 0;
		}
			  } break;
	case 'a': {
		if(::data::is_mannge_mode) break;
		::data::is_show_all_songs_list = true;
			  } break;
	case 'd': {
		if(::data::is_mannge_mode) break;
		if(!::data::is_show_all_songs_list) {
			delSongFromPlayList(::data::play_list_select_song_index);
		}
			  } break;
	case 'q': {
		if(::data::is_show_all_songs_list)
			::data::is_show_all_songs_list = false;
		if(::data::is_search)
			::data::is_search = false;
		if(::data::is_mannge_mode)
			::data::is_mannge_mode = false;
			  } break;
		if(::data::is_mannge_mode) {}
	case 'f': {
		if(::data::is_mannge_mode) break;
		// Search songs function
		::data::is_input = true;
		::data::is_search = true;
		::data::searched_song_list_selected_index = 0;
		::data::input_content.erase();
		} break;
	case 'j': {
		if(::data::is_mannge_mode) break;
		// Reduce volume
		if(::data::play::volume > 0)
			::data::play::volume -= 100;
		setVolume(::data::play::volume);
			  } break;
	case 'k': {
		if(::data::is_mannge_mode) break;
		// Incrase volume
		if(::data::play::volume < 1000)
			::data::play::volume += 100;
		setVolume(::data::play::volume);
			  } break;
	case 'm': {
		if(::data::is_mannge_mode) break;
		if(::data::play::is_play) {
			suspendSong();
            ::data::play::is_play = false;
		}
		::data::manage::process = manage_login;
		::data::manage::input_password_error_times = 0;
		::data::is_mannge_mode = true;
		::data::is_input = true;
		::data::input_content.erase();
			} break;
	default: break;
	}

}

// Add songs to play list from all songs list
void addSongToPlayList(int index) {
	struct Song song = ::data::all_songs_list.at(index);
	bool is_have = false;
	FILE *data_file = NULL;
	struct FileSong file_song_data;
	
	for(unsigned int index_ = 0; index_ < ::data::play_songs_list.size(); ++ index_) {
		if(song.name == ::data::play_songs_list.at(index_).name) {
			is_have = true;
			break;
		}
	}
	do {
		// Write data to file
		if(is_have) break;
		::data::play_songs_list.push_back(song);
		data_file = fopen(PLAY_LIST_FILE, "ab");
		if(data_file == NULL) break;
		memset(&file_song_data, 0, sizeof(file_song_data));
		memcpy(&file_song_data.name, song.name.data(), song.name.length());
		memcpy(&file_song_data.author, song.author.data(), song.author.length());
		memcpy(&file_song_data.publish_time, song.publish_time.data(), song.publish_time.length());
		memcpy(&file_song_data.type, song.name.data(), song.type.length());
		fwrite(&file_song_data, 1, sizeof(file_song_data), data_file);
		fclose(data_file);
	} while(false);
}

// Add songs to play list from searched sings list
void addSearchedSongToPlayList(int index) {
	//dbg() << index;
	struct Song song = ::data::searched_songs_list.at(index);
	bool is_have = false;
	FILE *data_file = NULL;
	struct FileSong file_song_data;
	for(unsigned int index_ = 0; index_ < ::data::play_songs_list.size(); ++ index_) {
		if(song.name == ::data::play_songs_list.at(index_).name) {
			is_have = true;
			break;
		}
	}
	do {
		if(is_have) break;
		::data::play_songs_list.push_back(song);
		data_file = fopen(PLAY_LIST_FILE, "ab");
		if(data_file == NULL) break;
		memset(&file_song_data, 0, sizeof(file_song_data));
		memcpy(&file_song_data.name, song.name.data(), song.name.length());
		memcpy(&file_song_data.author, song.author.data(), song.author.length());
		memcpy(&file_song_data.publish_time, song.publish_time.data(), song.publish_time.length());
		memcpy(&file_song_data.type, song.name.data(), song.type.length());
		fwrite(&file_song_data, 1, sizeof(file_song_data), data_file);
		fclose(data_file);
	} while(false);
}


// Remove song from play list by index
void delSongFromPlayList(int index) {
	unsigned int size = ::data::play_songs_list.size();
	if(size < 1) return;
	do {
		// Remove one just left a song
		if(size == 1) {
			if(::data::play::is_play == true) {
				closeSong();
			}
			::data::play::song_name = "none";
			::data::play::song_current_position = 0;
			::data::play::song_total_lenth = 0;
			::data::play::is_play = false;
			::data::play_list_select_song_index = 0;
			break;
		}

		// If this song is playing, then play next song before remove
		if(::data::play_list_select_song_index == ::data::play_list_current_song_index) {
			playNextSong();
			//dbg() << ::data::play_list_select_song_index;
		}

		// Remove from last one
		if(index + 1 >= size && size > 1){
			::data::play_list_select_song_index = size - 2;
			if(::data::play_list_current_song_index > ::data::play_list_select_song_index)
				::data::play_list_current_song_index = ::data::play_list_select_song_index;
			break;
		}
		if( index < ::data::play_list_current_song_index) {
			::data::play_list_current_song_index -= 1;
			break;
		}
		//dbg() << ::data::play_list_select_song_index;
	} while(false);
	::data::play_songs_list.erase(index);

	// Sync data to file
	FILE *data_file = NULL;
	struct FileSong file_song_data;
	data_file = fopen(PLAY_LIST_FILE, "wb");
	if(!data_file) return ;
	for(int idx = 0; idx < ::data::play_songs_list.size(); ++idx) {
		memset(&file_song_data, 0, sizeof(file_song_data));
		struct Song song = ::data::play_songs_list.at(idx);
		memcpy(&file_song_data.name, song.name.data(), song.name.length());
		memcpy(&file_song_data.author, song.author.data(), song.author.length());
		memcpy(&file_song_data.publish_time, song.publish_time.data(), song.publish_time.length());
		memcpy(&file_song_data.type, song.name.data(), song.type.length());
		fwrite(&file_song_data, 1, sizeof(file_song_data), data_file);
	}
	fclose(data_file);
}

// Get next song name
std::string getNextSongName() {
	std::string ret;
    ::data::play_list_current_song_index += 1;
    if(::data::play_list_current_song_index >= (static_cast<int>(::data::play_songs_list.size()))) {
        ::data::play_list_current_song_index = 0;
	}
    ret = ::data::play_songs_list.at(::data::play_list_current_song_index).name;
	return ret;
}

// Get prev song name
std::string getPrevSongName() {
	std::string ret;
    ::data::play_list_current_song_index -= 1;
    if(::data::play_list_current_song_index < 0) {
        ::data::play_list_current_song_index = static_cast<int>(::data::play_songs_list.size()) - 1;
	}
    ret = ::data::play_songs_list.at(::data::play_list_current_song_index).name;
	return ret;
}

// Play song by index
void playSongByIndex(unsigned int index) {
	::data::play::song_name = ::data::play_songs_list.at(index).name;
	std::string current_song_path = SONG_PATH;
	current_song_path += ::data::play::song_name;
	if(::data::play::is_play == true) {
		closeSong();
	}
	openSong(current_song_path);
	playSong();
	::data::play::song_total_lenth = getSongLenth();
    ::data::play::song_current_position = 0;
	::data::play_list_current_song_index = index;
	::data::play::is_play = true;
}

// Play song by name
void playSongByName(std::string name) {
	std::string current_song_path = SONG_PATH;
	current_song_path += name;
	openSong(current_song_path);
	playSong();
	::data::play::song_total_lenth = getSongLenth();
    ::data::play::is_play = true;
    ::data::play::song_current_position = 0;
}

// Play next song
void playNextSong() {
	if(::data::play_songs_list.size() < 1) return;
    ::data::play::song_name= getNextSongName();
    std::string current_song_path = SONG_PATH;
    current_song_path.append(::data::play::song_name);
    if(::data::play::is_play == true) {
		closeSong();
	}
    openSong(current_song_path);
	playSong();
    ::data::play::song_total_lenth = getSongLenth();
    ::data::play::is_play = true;
    ::data::play::song_current_position = 0;
}

// Play prev song
void playPrevSong() {
	if(::data::play_songs_list.size() < 1) return;
    ::data::play::song_name = getPrevSongName();
    std::string current_song_path = SONG_PATH;
    current_song_path.append(::data::play::song_name);
    if(::data::play::is_play == true) {
		closeSong();
	}
    openSong(current_song_path);
	playSong();
    ::data::play::song_total_lenth = getSongLenth();
    ::data::play::is_play = true;
    ::data::play::song_current_position = 0;
}

int main(int argc, char **argv) {
	// Init graphic
	initgraph(640, 480);
	// Init ui
	initUi();
	// Load songs
	loadSongs();
	while(true) {
		//cleardevice();
		Sleep(60);
		// If play song over, then play next song
        if(::data::play::song_current_position >= ::data::play::song_total_lenth && ::data::play_songs_list.size() != 0) {
			playNextSong();
		}
		// Get play position when playing
        if(::data::play::is_play == true && ::data::play_songs_list.size() != 0) {
            ::data::play::song_current_position = getSongPlayPosition();
		}
		// Get input from keyboard
		if(_kbhit()) {
			controller();
		}
		// Draw UI
		if(::data::is_mannge_mode) {
			drawManageUi();
		}else {
			drawPlayUi();
		}
	}
	while(true);
	return 0;
}