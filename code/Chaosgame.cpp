// Include important C++ libraries here
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

// Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

float getx(float xval[], float recentPoint, int count)
{

    int temp = count;
    float calc = xval[temp];

    float x1 = calc;
    float x2 = recentPoint;

    // Calculate middle of vertex and last point
    float val = (x1 + x2) / 2.0;


    return val;
}

float gety(float yval[], float recentPoint, int count)
{
    

    int temp = count;

    float calc = yval[temp];


    float y1 = calc;
    float y2 = recentPoint;

    // Calculate middle of vertex and last point
    float val = (y1 + y2) / 2.0;

    return val;
}

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
    messageText.setCharacterSize(30);

    //Choose a color
    messageText.setFillColor(Color::White);

    // Position the text
    FloatRect textRect = messageText.getLocalBounds();
    messageText.setOrigin(textRect.left +
        textRect.width / 2.0f,
        textRect.top +
        textRect.height / 2.0f);
    messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);

	vector<VertexArray> vertexArrays;


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
                    cout << "X:" << event.mouseButton.x << endl;
                    cout <<"Y:" << event.mouseButton.y << endl;
                    cout << " " << endl;
					clicked.x = event.mouseButton.x;
					clicked.y = event.mouseButton.y;
				}
			}
    
		}
        int x1, x2, x3, x4;
        int y1, y2, y3, y4;
    if (event.mouseButton.button == sf::Mouse::Left)
		{
        x1 = 100.0;
        y1 = 300.0;

        x2 = 600.0;
        y2 = 300.0;

        x3 = 350.0;
        y3 = 10.0;

        x4 = clicked.x;
        y4 = clicked.y;
        }

        // Use to hold points if needed
        float* cordsX = new float[100];
        float* cordsY = new float[100];



        cordsX[0] = x1;
        cordsX[1] = x2;
        cordsX[2] = x3;
        cordsX[3] = x4;

        cordsY[0] = y1;
        cordsY[1] = y2;
        cordsY[2] = y3;
        cordsY[3] = y4;

        // Array that holds the main verticies
        float MainCordsX[3] = { x1, x2, x3 };
        float MainCordsY[3] = { y1, y2, y3 };



        bool stop = false;
        int total = 0;

        while (!stop)
        {
            int count = rand() % 3;
            float lastXPoint = cordsX[3];
            float lastYPoint = cordsY[3];
            for (int index = 0; index < 5; index++)
            {
                // Vertex array to hold points
                VertexArray points(Points, 5);

                // Calls funtion to get new coordinates for vector
                float XCord = getx(MainCordsX, lastXPoint, count);
                float YCord = gety(MainCordsY, lastYPoint, count);

                if (index %2 == 0)
                {
                    points[index].position = Vector2f(XCord, YCord);
                    points[index].color = Color::Green;
                }
                
                else
                {
                    points[index].position = Vector2f(XCord, YCord);
                    points[index].color = Color::Magenta;
                }
            

                // Makes it so the last coordinate plotted is used in next get function
                lastXPoint = XCord;
                lastYPoint = YCord;

                count = rand() % 3;


                // Trying to add more variables to make random
                //count++;


                //cout << " " << lastXPoint;// << " " << cordsY[index + 3];
                ///window.draw(points);
                vertexArrays.push_back(points);
                total++;

            }
            stop = true;
            delete[] cordsX;
            delete[] cordsY;
        }

        // These are just to test verticies - remove when needed
        window.clear();
        Vertex point(Vector2f(x1, y1), Color::Blue);
        window.draw(&point, 1, Points);

        Vertex point2(Vector2f(x2, y2), Color::Yellow);
        window.draw(&point2, 1, Points);

        Vertex point3(Vector2f(x3, y3), Color::Magenta);
        window.draw(&point3, 1, Points);



        for (int i = 0; i < vertexArrays.size(); i++)
        {
            window.draw(vertexArrays.at(i));
        }

        window.display();

    
    }
	
	return 0;
}