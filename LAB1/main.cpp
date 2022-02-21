#include "Playlist.h"
#include <string>
void PrintMenu(string title);
using namespace std;
int main()
{
  string plTitle;
  cout << "Enter playlist's title:" << endl;
  getline(cin, plTitle);
  PrintMenu(plTitle);
  return 0;
}
//implementation

void PrintMenu(string title)
{
  Playlist list;
  string id;
  string sname;
  string aname;
  int length;
  int oldPos;
  int newPos;
  char choice;
  while (true)
  {
    cout << endl << title << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl << endl;
    cout << "Choose an option:" << endl;
    cin >> choice;
    cin.ignore(); 
    
    if (choice == 'q' || choice == 'Q')
    {
      exit(1);
    }
    
    else if (choice == 'a' || choice == 'A')
    {
      cout << "ADD SONG" << endl;
      cout << "Enter song's unique ID:" << endl;
      cin >> id;
      cin.ignore();
      cout << "Enter song's name:" << endl;
      getline(cin, sname);
      cout << "Enter artist's name:" << endl;
      getline(cin, aname);
      cout << "Enter song's length (in seconds):" << endl;
      cin >> length;
      list.AddSong(id, sname, aname, length);
    }
    
    else if (choice == 'd' || choice == 'D')
    {
      cout << "REMOVE SONG" << endl;
      cout << "Enter song's unique ID:" << endl;
      cin >> id;
      list.RemoveSong(id);
    }
    
    else if (choice == 'c' || choice == 'C')
    {
      cout << "CHANGE POSITION OF SONG" << endl;
      cout << "Enter song's current position:" << endl;
      cin >> oldPos;
      cout << "Enter new position for song:" << endl;
      cin >> newPos;
      list.ChangePosition(oldPos, newPos);
    }
    else if (choice == 's' || choice == 'S')
    {
      cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
      cout << "Enter artist's name:" << endl;
      getline(cin, aname);
      list.SongsByArtist(aname);
    }
      
      else if (choice == 't' || choice == 'T')
      {
        cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
        cout << "Total time: " << list.TotalTime() << " seconds" << endl;
      }
      
      else if (choice == 'o' || choice == 'O')
      {
        cout << title << " - OUTPUT FULL PLAYLIST" << endl;
        list.PrintList();
      }
      
      else
      {
        cout << "Invalid menu choice! Please try again." << endl;
      }
  }
} // end of PrintMenu function

