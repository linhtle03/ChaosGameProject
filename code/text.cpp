// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <iostream>

// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
// Draw some text
   int score = 0;
   Text messageText;
   Text scoreText;
   // We need to choose a font
   Font font;
   font.loadFromFile("fonts/KOMIKAP_.ttf");
   // Set the font to our message
   messageText.setFont(font);
   scoreText.setFont(font);
   // Assign the actual message
   messageText.setString("Click anywhere to start");
   scoreText.setString("Score = 0");
   // Make it really big
   messageText.setCharacterSize(75);
   scoreText.setCharacterSize(100);
}