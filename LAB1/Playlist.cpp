#include "Playlist.h"
using namespace std;
// Constructor implementation
PlaylistNode::PlaylistNode()
{
  uniqueID = "none";
  songName = "none";
  artistName = "none";
  songLength = 0;
  nextNodeptr = 0;
}
// Parameterized constructor implementation
PlaylistNode::PlaylistNode(string id, string songname, string artist, int length)
{
  uniqueID = id;
  songName = songname;
  artistName = artist;
  songLength = length;
  nextNodeptr = 0;
}

void PlaylistNode::InsertAfter(PlaylistNode* ptr)
{
  if (nextNodeptr == NULL)
  nextNodeptr = ptr;

  else 
  {
    ptr -> SetNext(nextNodeptr);
    nextNodeptr = ptr;
  }
}

void PlaylistNode::SetNext(PlaylistNode* ptr)
{
  nextNodeptr = ptr;
}

string PlaylistNode::GetID()
{
  return uniqueID;
}

string PlaylistNode::GetSongName()
{
  return songName;
};

string PlaylistNode::GetArtistName()
{
  return artistName;
}

int PlaylistNode::GetSongLength()
{
  return songLength;
}

PlaylistNode* PlaylistNode::GetNext()
{
  return nextNodeptr;
}
// Function implementation
void PlaylistNode::PrintPlaylistNode()
{
  cout << "Unique ID: " << uniqueID << endl;
  cout << "Song Name: " << songName << endl;
  cout << "Artist Name: " << artistName << endl;
  cout << "Song Length (in seconds): " << songLength << endl;
}


// Default constructor implementation
Playlist::Playlist()
{
  head = tail = 0;
}

void Playlist::AddSong(string id, string songname, string artistname, int length)
{
  PlaylistNode* n = new PlaylistNode(id, songname, artistname, length);
  if (head == 0)
  head = tail = n;
  else
  {
    tail->InsertAfter(n);
    tail = n;
  }
}

// Implementation
bool Playlist::RemoveSong(string id)
{
  if (head == NULL)
  {
    cout << "Playlist is empty" << endl;
    return false;
  }
    PlaylistNode* curr = head;
    PlaylistNode* prev = NULL;
    while (curr != NULL)
    {
      if (curr->GetID() == id)
      {
        break;
      }
        prev = curr;
        curr = curr->GetNext();
    }
        if (curr == NULL) //not found
        {
          cout << "\"" << curr->GetSongName() << "\" is not found" << endl;
          return false;
        }
          else
          {
            if (prev != NULL)
            prev->SetNext(curr->GetNext());
            
            else
            head = curr->GetNext();
            if (tail == curr)
            tail = prev;
            cout << "\"" << curr->GetSongName() << "\" removed." << endl;
            delete curr;
            return true;
          }
  }
/* Implementation
bool Playlist::ChangePosition(int oldPos, int newPos)
{
  if (head == NULL)
  {
    cout << "Playlist is empty" << endl;
    return false;
  }
   
    PlaylistNode* prev = NULL;
    PlaylistNode* curr = head;
    int pos;
    if (head == tail)
    return false;
    
    for (pos = 0; curr != NULL && pos < oldPos; pos++)
    {
      prev = curr;
      curr = curr->GetNext();
    }
    if (curr != NULL) 
    {
      string currentSong = curr->GetSongName();
      if (prev == NULL)
      head = curr->GetNext();
      
      else
      {
        prev->SetNext(curr->GetNext());
      }
      
      if (curr == tail) 
      tail = prev;
      PlaylistNode* curr1 = curr;
      prev = NULL;
      curr = head;
      
      
      for (pos = 0; curr != NULL && pos < newPos; pos++)
      {
        prev = curr;
        curr = curr->GetNext();
      }
      
      if (prev == NULL)
      {
        curr1->SetNext(head);
        head = curr1;
      }
      else
      prev->InsertAfter(curr1);
      if (curr == NULL)
      tail = curr1;
      cout << "\"" << currentSong << "\" moved to position " << newPos << endl;
      return true;
    }
    
    else
    {
      cout << "Song's current position is invalid" << endl;
      return false;
    }*/
    
    bool Playlist::ChangePosition(int oldPos, int newPos)
{
    if (head == NULL) { //List is empty
        cout << "Playlist is empty" << endl; //Print error message
        return false;
    }

    if (head == tail) { //List is only one node
        return false;
    }

    //Variables used for sequential access
    PlaylistNode* curr = head;
    PlaylistNode* prev = NULL;
    PlaylistNode* temp; //Used to store oldPos and newPos temporarily
    //PlaylistNode* prevOfOldPos; //Used to maintain oldPos's place

    /*if (oldPos == newPos) { //No Swap
        return true;
    } else if (oldPos > newPos) { //Swap positions
        int tempPos = oldPos;
        oldPos = newPos;
        newPos = tempPos;
    }*/

    int counter = 1;
    while (curr != NULL && counter < oldPos) {
        prev = curr;
        curr = curr->GetNext();
        counter++;
    }

    if (curr == NULL) { //oldPos > length of list
        cout << "Song's current position is invalid" << endl;
        return false;
    }

    //prevOfOldPos = prev; //Store oldPos' position for later
    if (curr == head) { //Case when oldPos = head
        head = head->GetNext(); 
    }
    else if (curr == tail) {
      tail = prev;
    } 
    if (prev) {
        prev->SetNext(curr->GetNext());
    }
    temp = curr; //Store the oldPos temporarily
    temp->SetNext(NULL);

    //Reinitialize
    curr = head;
    prev = NULL;

    counter = 1;
    while (curr != NULL && counter < newPos - 1)
    {
        prev = curr;
        curr = curr->GetNext();
        counter++;
    }

    if (curr == NULL) { //newPos > length of list
          cout << "Song's current position is invalid" << endl;
        return false;
    }

    if (newPos == 1) {
        temp->SetNext(head);
        head = temp;
    } else if (curr) {
        if (curr->GetNext() == NULL) {
            curr->SetNext(temp);
            tail = temp;
        } else {
            temp->SetNext(curr->GetNext());
            curr->SetNext(temp);
        }
    }
    /*Put oldPos node in newPos node's place
    if (prev == NULL) { //Unique Case: 1, 2 as input
        head = temp;
    } else {
        prev->SetNext(temp);
    }
    if (tail == curr) { //Unique Case: newPos = tail
        tail = temp;
    }
    temp->SetNext(curr->GetNext()); //Set next of oldPos to next of newPos (effectively finishing its replacement)

    if (prevOfOldPos == NULL) { //Put newPos at the head
        curr->SetNext(head);
        head = curr;
    } else {
        curr->SetNext(prevOfOldPos->GetNext());
        prevOfOldPos->SetNext(curr);        
    }*/
    
    cout << "\"" << temp->GetSongName() << "\" moved to position " << newPos << endl;
    return true;
}
// implementation
void Playlist::SongsByArtist(string artist)
{
  if (head == NULL)
  cout << endl << "Playlist is empty" << endl;
  
  else
  {
    PlaylistNode* curr = head;
    int i = 1;
    while (curr != NULL)
    {
      if (curr->GetArtistName() == artist)
      {
        cout << endl << i << "." << endl;
        curr->PrintPlaylistNode();
      }
      curr = curr->GetNext();
      i++;
    }
  }
}
// implementation
int Playlist::TotalTime()
{
  int total = 0;
  PlaylistNode* curr = head;
  while (curr != NULL)
  {
    total += curr->GetSongLength();
    curr = curr->GetNext();
  }
  return total;
}

// implementation
void Playlist::PrintList()
{
  if (head == NULL)
  cout << "Playlist is empty" << endl;
  
  else
  {
    PlaylistNode* curr = head;
    int i = 1;
    while (curr != NULL)
    {
      cout << i++ << "." << endl;
      curr->PrintPlaylistNode();
      curr = curr->GetNext();
      if (curr != NULL)
      cout<<endl;
    }
  }
}
