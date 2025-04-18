#include <iostream>
#include <memory>

// MusicPlayer interface (Component)
class MusicPlayer {
public:
    virtual ~MusicPlayer() = default;
    virtual void play() const = 0;
};

// Concrete component: MP3Player (Base class)
class MP3Player : public MusicPlayer {
public:
    void play() const override {
        std::cout << "Playing MP3 song.\n";
    }
};

// Base decorator (Decorator class)
class MusicPlayerDecorator : public MusicPlayer {
protected:
    std::shared_ptr<MusicPlayer> decoratedPlayer;
    
public:
    MusicPlayerDecorator(std::shared_ptr<MusicPlayer> player) : decoratedPlayer(player) {}
    virtual void play() const override {
        decoratedPlayer->play();
    }
};

// Concrete decorator: SoundEffectDecorator
class SoundEffectDecorator : public MusicPlayerDecorator {
public:
    SoundEffectDecorator(std::shared_ptr<MusicPlayer> player) : MusicPlayerDecorator(player) {}

    void play() const override {
        MusicPlayerDecorator::play(); // Play the base MP3
        std::cout << "Adding sound effects to the music.\n";
    }
};

// Concrete decorator: EqualizerDecorator
class EqualizerDecorator : public MusicPlayerDecorator {
public:
    EqualizerDecorator(std::shared_ptr<MusicPlayer> player) : MusicPlayerDecorator(player) {}

    void play() const override {
        MusicPlayerDecorator::play(); // Play the base MP3
        std::cout << "Applying equalizer settings.\n";
    }
};

// Concrete decorator: VideoEffectDecorator
class VideoEffectDecorator : public MusicPlayerDecorator {
public:
    VideoEffectDecorator(std::shared_ptr<MusicPlayer> player) : MusicPlayerDecorator(player) {}

    void play() const override {
        MusicPlayerDecorator::play(); // Play the base MP3
        std::cout << "Adding video effects to the music.\n";
    }
};

// Client code to demonstrate the use of decorators
int main() {
    // Create a basic MP3 player
    std::shared_ptr<MusicPlayer> mp3Player = std::make_shared<MP3Player>();

    // Decorate the MP3 player with sound effects
    std::shared_ptr<MusicPlayer> playerWithEffects = std::make_shared<SoundEffectDecorator>(mp3Player);
    
    // Further decorate with equalizer
    std::shared_ptr<MusicPlayer> playerWithAllEffects = std::make_shared<EqualizerDecorator>(playerWithEffects);

    // Further decorate with video effects
    playerWithAllEffects = std::make_shared<VideoEffectDecorator>(playerWithAllEffects);

    // Now play the music with all decorators applied
    playerWithAllEffects->play();

    return 0;
}
//g++ decorator.cpp -o decorator