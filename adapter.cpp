#include <iostream>
#include <memory>

// Target interface
class MediaPlayer {
public:
    virtual ~MediaPlayer() = default;
    virtual void play(const std::string& audioType, const std::string& fileName) const = 0;
};

// Adaptee class (existing functionality)
class AdvancedMediaPlayer {
public:
    virtual ~AdvancedMediaPlayer() = default;
    virtual void playVlc(const std::string& fileName) const {
        std::cout << "Playing VLC file: " << fileName << "\n";
    }
    virtual void playMp4(const std::string& fileName) const {
        std::cout << "Playing MP4 file: " << fileName << "\n";
    }
};

// Adapter class
class MediaAdapter : public MediaPlayer {
private:
    std::shared_ptr<AdvancedMediaPlayer> advancedPlayer;

public:
    MediaAdapter(const std::string& audioType) {
        advancedPlayer = std::make_shared<AdvancedMediaPlayer>();
    }

    void play(const std::string& audioType, const std::string& fileName) const override {
        if (audioType == "vlc") {
            advancedPlayer->playVlc(fileName);
        } else if (audioType == "mp4") {
            advancedPlayer->playMp4(fileName);
        } else {
            std::cout << "Invalid media type: " << audioType << "\n";
        }
    }
};

// Concrete Target class
class AudioPlayer : public MediaPlayer {
private:
    std::shared_ptr<MediaAdapter> mediaAdapter;

public:
    void play(const std::string& audioType, const std::string& fileName) const override {
        if (audioType == "mp3") {
            std::cout << "Playing MP3 file: " << fileName << "\n";
        } else if (audioType == "vlc" || audioType == "mp4") {
            MediaAdapter adapter(audioType);
            adapter.play(audioType, fileName);
        } else {
            std::cout << "Unsupported media type: " << audioType << "\n";
        }
    }
};

// Client code
int main() {
    std::shared_ptr<MediaPlayer> player = std::make_shared<AudioPlayer>();

    player->play("mp3", "song.mp3");
    player->play("vlc", "movie.vlc");
    player->play("mp4", "video.mp4");
    player->play("avi", "unsupported.avi");

    return 0;
}
// g++ adapter.cpp -o adapter