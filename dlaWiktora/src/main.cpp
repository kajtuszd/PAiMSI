#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <vector>



const int numOfFigures = 32;
const int boardLength = 8;
const int fieldNum = 56;
sf::Vector2f freeSpace(28,28);




sf::Sprite figures[numOfFigures];
std::string position = "";


void test(sf::Event event)
{

    if(event.type == sf::Event::Resized)
   		std::cout << " Resized window " << std::endl;
    
    if(event.type == sf::Event::LostFocus)
    	std::cout << " Lost focus " << std::endl;

    if(event.type == sf::Event::GainedFocus)
    	std::cout << " Gained focus " << std::endl;

    if(event.type == sf::Event::KeyPressed)
 		std::cout <<  " Key pressed " << std::endl;

 	if (event.type == sf::Event::MouseEntered)
		std::cout << "The mouse cursor has entered the window" << std::endl;

	if (event.type == sf::Event::MouseLeft)
	    std::cout << "the mouse cursor has left the window" << std::endl;

}




void loadPosition()
{
	std::vector< std::vector<int> > chessBoard = 
	{{-1,-2,-3,-4,-5,-3,-2,-1,},
     {-6,-6,-6,-6,-6,-6,-6,-6,},
     { 0, 0, 0, 0, 0, 0, 0, 0,},
     { 0, 0, 0, 0, 0, 0, 0, 0,},
     { 0, 0, 0, 0, 0, 0, 0, 0,},
     { 0, 0, 0, 0, 0, 0, 0, 0,},
     { 6, 6, 6, 6, 6, 6, 6, 6,},
     { 1, 2, 3, 4, 5, 3, 2, 1}};

    int count = 0;
	for (int i = 0; i < boardLength; ++i)
	{
		for (int j = 0; j < boardLength; ++j)
		{
			int field = chessBoard[i][j];          // przewijane pole
			if(!field) continue;                   
			int x = abs(field)-1;    // wczytanie do zmiennej numeru odpowiadajacego za reprezentacje odpowiedniej figury
			int y = field>0?1:0;     // jezeli wartosc aktualnego pola jest wieksza od zera
			
			/* wczytanie tekstury o odpowiednim rozmiarze */ 
 			figures[count].setTextureRect(sf::IntRect(fieldNum*x, fieldNum*y, fieldNum, fieldNum));
 			/* ustawienie tekstury */
			figures[count].setPosition(fieldNum*j, fieldNum*i);
			count++;
		}		
	}

}




int main()
{

    sf::RenderWindow window(sf::VideoMode(504, 504), "Chessboard");
	
	/* inicjalizacja tekstur */    
    sf::Texture tex1, tex2;

    /* tex1 odpowiada za plansze, tex2 za figury */

    if(!tex1.loadFromFile("pic/board.png"))
    	std::cout << "Error while opening file" << std::endl;

    if(!tex2.loadFromFile("pic/figures.png"))
    	std::cout << "Error while opening file" << std::endl;


    /* ustawienie obrazka do tekstury od planszy */
    sf::Sprite board;
    board.setTexture(tex1);
    tex1.setSmooth(true);

    /* ustawienie obrazkow do tekstury od figur  */
    for(int i=0; i<numOfFigures; i++)
    {
    	figures[i].setTexture(tex2);
    }

    tex2.setSmooth(true);
    loadPosition();


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) // zamkniecie okna 
        {	    	
			
			if (event.type == sf::Event::Closed)
			    window.close();
        	
      //  	test(event);
        }

        window.clear();
        window.draw(board);
        for (int i = 0; i < numOfFigures; ++i)
        {
        	figures[i].move(freeSpace);
        }
        for (int i = 0; i < numOfFigures; ++i)
        {
        	window.draw(figures[i]);
        }
   		for (int i = 0; i < numOfFigures; ++i)
        {
        	figures[i].move(-freeSpace);
        }

        window.display();

    	//sf::sleep(sf::milliseconds(550));
    }





    return 0;
} 
