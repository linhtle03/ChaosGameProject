// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
	// Create a video mode object
	VideoMode vm(1920, 1080);

	// Create and open a window for the game
	RenderWindow window(vm, "Sierpinski Triangle", Style::Default);

	bool paused = true;

    // Draw some text
    Text messageText;
    // We need to choose a font
    Font font;
    font.loadFromFile("fonts/KOMIKAP_.ttf");
    // Set the font to our message
    messageText.setFont(font);
    // Assign the actual message
    messageText.setString("Please pick your first point");
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
        
	CircleShape cir(10);
	cir.setRadius(4);


	vector<Vector2f> vertices;   ///push_back stuff into us!
	vector<Vector2f> points;

	Vector2f clicked;

	
    while (window.isOpen())
	{

		if (paused)
		{
			// Draw our message
			window.draw(messageText);
			window.display();
		}
		/*
		****************************************
		Handle the players input
		****************************************
		*/
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed)
			{
				paused = false;
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					std::cout << "the left button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;

					clicked.x = event.mouseButton.x;
					clicked.y = event.mouseButton.y;
				}
			}
    
		}

        if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		/*
		****************************************
		Update the scene
		****************************************
		*/
		cir.setPosition(clicked.x, clicked.y);
		cir.setFillColor(Color::White);
		/*
		****************************************
		Draw the scene
		****************************************
		*/

		///loop through vectors and draw each coordinate
		// Clear everything from the last run frame
		window.clear();
		// Draw our game scene here
		window.draw(cir);
		window.display();

    }
	
	return 0;
}