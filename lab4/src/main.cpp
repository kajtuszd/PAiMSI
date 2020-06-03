#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <list>
#include <cstdlib>
#include "Figure.h"
#include "Spot.h"
#include "Board.h"
#include "Move.h"
#include "AI.h"
#include "Game.h"





int main()
{
    
    sf::Sprite yellowFrame, redFrame, greenFrame;
    Game game;


    bool isSelectedFigure = false;
    bool isFrameDisplayed = false;
    bool isMoved = false;


    Figure *toMove;       /* wskaznik do ruszanej figury */
    game.initializePlayers();


    sf::Sprite brd = game.getBoardSprite();                
 	std::list <Figure*> fig = std::move(game.getBoard().returnFigures());      /* lista przechowujaca aktualne figury */

    yellowFrame = game.getBoard().getYellowFrame();  
    redFrame = game.getBoard().getRedFrame();
    greenFrame = game.getBoard().getGreenFrame();


    std::vector<sf::Sprite> greenFrames;   
    std::vector<sf::Sprite> redFrames;  

    Board brrd = game.getBoard();


    sf::RenderWindow window(sf::VideoMode(504,504),"Chess");

    

    while(window.isOpen())
    {
        window.clear();                     /* czyszczenie okna */


        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);  /* pobranie pozycji myszki */
    	sf::Event event;

        while(window.pollEvent(event))
    	{
    		if(event.type == sf::Event::Closed)
    		{	
    			window.close();
    		}
    	
            while(sf::Mouse::isButtonPressed(sf::Mouse::Left)) /* nacisniety lewy przycisk myszy */
            {
                isFrameDisplayed = true;                             /* odznaczenie, że wybrano pole */
            	isMoved = false;
                for (std::list<Figure*>::iterator i = fig.begin(); i != fig.end(); i++)  /* przewijanie wszystkich figur */ 
                {
                    sf::Vector2f frameposition(mousePosition);                            /* wektor float */
                    sf::Vector2f equaliseframe = game.getBoard().adjustFrameSize(frameposition);      /* wyrownanie pozycji ramki */
                    yellowFrame.setPosition(equaliseframe);          /* ustawienie pozycji ramki */

                    sf::Vector2f vect(mousePosition);
                    if( (*i)->picture.getGlobalBounds().contains(vect))  /* sprawdzenie czy wskazane pole zawiera figure */
                    {
                        window.draw(brd);
                        window.draw(yellowFrame);
                        for (std::list<Figure*>::iterator i = fig.begin(); i != fig.end(); ++i)  
                        {   
                            window.draw( (*i)->picture);    
                        }


                        window.display();
	                    isSelectedFigure = true; 
                        toMove = (*i);   /* przekazanie iterowanej figury do wskaznika */
                		game.readHumanStartSpot((equaliseframe.y-28)/56, (equaliseframe.x-28)/56);
                		 
                		std::vector<Spot> placesWhereCanMove = game.returnPlacesFigureCanMove(toMove); /* wektor przechowujacy miejsca */
                		std::vector<sf::Vector2f> frameVectors = game.changeSpotsToVectors(placesWhereCanMove); /* wektor z wektorami do ramek */
                		greenFrames = game.getGreenFrames(frameVectors);

                		std::vector<Spot> placesWhereCanCapture = game.returnPlacesFigureCanCapture(toMove); /* wektor przechowujacy miejsca */
                		std::vector<sf::Vector2f> redframeVectors = game.changeSpotsToVectors(placesWhereCanCapture); /* wektor z wektorami do ramek */
                		redFrames = game.getRedFrames(redframeVectors);

                        placesWhereCanMove.insert(placesWhereCanMove.end(), placesWhereCanCapture.begin(), placesWhereCanCapture.end());
                        game.readPlacesFigureCanMove(placesWhereCanMove);


                    }
                }
            }

            while(sf::Mouse::isButtonPressed(sf::Mouse::Right) && isSelectedFigure == true) /* nacisniety prawy przycisk myszy */
            {
            	if(isMoved == false)
            	{
	                isFrameDisplayed = false;
	                sf::Vector2i newmousePosition = sf::Mouse::getPosition(window);
	                sf::Vector2f newVect(newmousePosition);
	                sf::Vector2f equaliser = game.getBoard().adjustFrameSize(newVect); 

	                game.readHumanEndSpot((equaliser.y-28)/56, (equaliser.x-28)/56);


                    if(game.isMoveValid())
                    {
                        fig = std::move(game.getBoard().returnFigures());      /* lista przechowujaca aktualne figury */

    	                if(game.makeMove())
                        {
        	               toMove->picture.setPosition(equaliser);
                        }


		                if(toMove->name == "pawn")
		                {
		                	if(game.returnEnd().y == 0 || game.returnEnd().y == 7)
		                	{
		                		int num = 3; /* domyslnie pionek zamieniany jest na krolowa */
		                		game.getBoard().chooseFigureToSwap(toMove,num);
		                		Spot spot = game.returnEnd();
		                		game.getBoard().swapPawn(spot,toMove,num); 		                	
                            }
		                }
                  

                        int cp = game.getBoard().rateBoard(1); // 1 cpu
                        int hu = game.getBoard().rateBoard(0); // 0 human

                        std::cout << "computer " << cp << std::endl;
                        std::cout << "human " << hu << std::endl;


		                game.getBoard().printFigures();

		                isMoved = true;
                        game.initializeAI(); //////////////////////////

                    }

            	}   
            }
        }

                                          /* rysowanie wszystkich obiektow */
        window.draw(brd);
        if(isFrameDisplayed && isSelectedFigure)
        {
            window.draw(yellowFrame);
            for (std::vector<sf::Sprite>::iterator i = greenFrames.begin(); i != greenFrames.end(); ++i)
            {
	        	window.draw(*i);
            } 
            for (std::vector<sf::Sprite>::iterator i = redFrames.begin(); i != redFrames.end(); ++i)
            {
	        	window.draw(*i);
            }
        }

        for (std::list<Figure*>::iterator i = fig.begin(); i != fig.end(); ++i)  
        {	
            window.draw( (*i)->picture);    
        }
    	window.display();
    	sf::sleep(sf::milliseconds(1));
    
    } 

}

