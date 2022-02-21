#include <iostream>
#include <string>
#ifndef POLYLIST_H
#define POLYLIST_H
using namespace std;
class PlaylistNode
{
  public:
          PlaylistNode();
          PlaylistNode(string id, string songname, string artist, int length );
          void InsertAfter(PlaylistNode* ptr);
          void SetNext(PlaylistNode* ptr);
          string GetID();
          string GetSongName();
          string GetArtistName();
          int GetSongLength();
          PlaylistNode* GetNext();
          void PrintPlaylistNode();

  private:
          string uniqueID;
          string songName;
          string artistName;
          int songLength;
          PlaylistNode* nextNodeptr;
};

class Playlist 
{
  private: 
          PlaylistNode *head;
          PlaylistNode *tail;
  public:
        Playlist ();
        void AddSong (string id, string songname, string artistname, int length);
        bool RemoveSong (string id);
        void PrintList();
        bool ChangePosition (int oldPos, int newPos);
        int TotalTime();
        void SongsByArtist(string artistName);
};
#endif