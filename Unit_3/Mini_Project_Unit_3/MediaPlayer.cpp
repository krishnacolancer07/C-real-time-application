#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Base Class
class Media
{
protected:
    string title;

public:
    Media(string t)
    {
        title = t;
    }

    virtual void play() = 0;
    virtual void pause() = 0;
    virtual void stop() = 0;
    virtual void showDetails() = 0;

    virtual ~Media() {}
};

// Audio Class
class Audio : public Media
{
public:
    Audio(string t) : Media(t) {}

    void play()
    {
        cout << "Playing Audio: " << title << endl;
    }

    void pause()
    {
        cout << "Audio Paused: " << title << endl;
    }

    void stop()
    {
        cout << "Audio Stopped: " << title << endl;
    }

    void showDetails()
    {
        cout << "Audio File: " << title << endl;
    }
};

// Video Class
class Video : public Media
{
public:
    Video(string t) : Media(t) {}

    void play()
    {
        cout << "Playing Video: " << title << endl;
    }

    void pause()
    {
        cout << "Video Paused: " << title << endl;
    }

    void stop()
    {
        cout << "Video Stopped: " << title << endl;
    }

    void showDetails()
    {
        cout << "Video File: " << title << endl;
    }
};

// Image Class
class Image : public Media
{
public:
    Image(string t) : Media(t) {}

    void play()
    {
        cout << "Displaying Image: " << title << endl;
    }

    void pause()
    {
        cout << "Image View Paused: " << title << endl;
    }

    void stop()
    {
        cout << "Image Closed: " << title << endl;
    }

    void showDetails()
    {
        cout << "Image File: " << title << endl;
    }
};

int main()
{
    vector<Media*> playlist;

    playlist.push_back(new Audio("Song.mp3"));
    playlist.push_back(new Video("Movie.mp4"));
    playlist.push_back(new Image("Photo.jpg"));

    cout << "===== MEDIA PLAYER =====" << endl;

    for (Media* m : playlist)
    {
        m->showDetails();
        m->play();
        m->pause();
        m->stop();
        cout << "------------------------" << endl;
    }

    for (Media* m : playlist)
    {
        delete m;
    }

    return 0;
}
