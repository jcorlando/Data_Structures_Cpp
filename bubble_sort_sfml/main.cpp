#include <SFML/Graphics.hpp>

int randomh = 0, part = 1;
int itera = 0;
int major = 0, cont = 0, lims = 799;

struct data
{
    int height;
    int posx;
}  line[800];

int main()
{
    sf::RenderWindow appWindow( sf::VideoMode(800, 600), "Bubble Sort" );
    sf::Event appEvent;

    sf::RectangleShape rectangle( sf::Vector2f(2,178) );
    rectangle.setFillColor( sf::Color(235, 149, 13) );

    srand(time(NULL));


    while( appWindow.isOpen() )
    {
        while( appWindow.pollEvent( appEvent ) )
        {
            if( appEvent.type == sf::Event::Closed ) appWindow.close();
        }


        if( part==2 )
        {
            if( line[itera].height < line[itera+1].height )
            {
                major = line[itera].height;
                line[itera].height = line[itera+1].height;
                line[itera+1].height = major;
            }
        }


        if( part==1 )
        {
            for (int i = 0; i < 800; i++)
            {
                randomh = 1 + rand()%(600);
                line[i].posx = i;
                line[i].height = randomh;
                if(i==799) part=2;
            }
        }


        appWindow.clear(sf::Color::Black);
        for (int i = 0; i < 800; i++)
        {
            rectangle.setFillColor( sf::Color(235,149,13) );
            rectangle.setPosition( line[i].posx, 600 );
            rectangle.setSize( sf::Vector2f(2, line[i].height) );
            rectangle.setRotation(180);
            appWindow.draw(rectangle);
        }
        
        appWindow.display();
        itera++;
        if(itera >= lims)
        {
            itera = 0;
            cont++;
            lims--;
        }
    }
    return 0;
}
