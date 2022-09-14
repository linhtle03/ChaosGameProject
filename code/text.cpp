// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <iostream>

// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
    bool paused = true;
    // Draw some text
    Text messageText;
    // We need to choose a font
    Font font;
    font.loadFromFile("fonts/KOMIKAP_.ttf");
    // Set the font to our message
    messageText.setFont(font);
    // Assign the actual message
    messageText.setString("Click to start");
    // Make it really big
    messageText.setCharacterSize(75);

    //Choose a color
    messageText.setFillColor(Color::White);

    // Position the text
    FloatRect textRect = messageText.getLocalBounds();
    messageText.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
        
    if (paused) {
       // Draw our message
       window.draw(messageText);
    }
    window.display();
    return 0;
}