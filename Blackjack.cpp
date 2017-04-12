#include "Deckstructure.hpp"
#include "Sprites.hpp"

int main(){
	std::vector<Hand> Player;
	Hand		  Dealer;
	Deck		Library(1);
	Deck		Discard(0);
	int x = 1; int y = 1;
	int dxy = 1;


	Library.Shuffle();
	
	sf::ContextSettings	settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(1100, 650), "SFML works!", sf::Style::Close | sf::Style::Titlebar, settings);

	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Blue);

     	sf::Texture texture;
       	if (!texture.loadFromFile("deck.png"))
   	{
	      // error...
   	}

   sf::Sprite sprite;
   sprite.setTexture(texture); 

	// Run the program until the window closes
	while (window.isOpen()){
		// Poll events with the next line and following loop
		sf::Event event;
		while (window.pollEvent(event)){
			if (event.type == sf::Event::Closed) window.close();
		}
		if(x == 300){ dxy = -1; }
		if(x == 1){ dxy = 1;}
		x += dxy;
		y += dxy;
		sprite.setPosition(x,y);
		window.setTitle("BlackJack!");
		window.clear(sf::Color(25,150,7)); // Removing this line makes the background look like a scarabled version of what was behind it
		window.draw(sprite); // Self-explanatory - draws the shape above
		window.display(); // Without this the screen is an exact copt of what is behind similar to a screenshot
	}

	return 0;
}
