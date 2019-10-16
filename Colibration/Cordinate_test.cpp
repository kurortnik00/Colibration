#include <SFML/Graphics.hpp>
#include "BodyBasics.h"
#include <iostream>
#include <Windows.h>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using namespace std;


int main(){
	CBodyBasics application;
	application.Run();

	enum {
	SPINEBASE,
	SPINEMID,
	NECK,
	HEAD,
	SHOULDERLEFT,
	ELBOWLEFT,
	WRISTLEFT,
	HANDLEFT,
	SHOULDERRIGHT,
	ELBOWRIGHT,
	WRISTRIGHT,
	HANDRIGHT,
	HIPLEFT,
	KNEELEFT,
	ANKLELEFT,
	FOOTLEFT,
	HIPRIGHT,
	KNEERIGHT,
	ANKLERIGHT,
	FOOTRIGHT,
	SPINESHOULDER,
	HANDTIPLEFT,
	THUMBLEFT,
	HANDTIPRIGHT,
	THUMBRIGHT,
	};


	sf::CircleShape _shape;
	float _radius = 30;

	_shape.setFillColor(sf::Color(0, 0, 0));
	_shape.setRadius(_radius);
	_shape.setOutlineThickness(10);
	_shape.setOutlineColor(sf::Color(250, 150, 100));


	sf::RenderWindow _mainWindow;
	_mainWindow.create(sf::VideoMode(1920, 1200), "Pang!"/*, sf::Style::Fullscreen*/);
	

	while (true)
	{


		float x = (application.SkeletPointsXY(HANDRIGHT).x + application.SkeletPointsXY(WRISTRIGHT).x + application.SkeletPointsXY(HANDTIPRIGHT).x + application.SkeletPointsXY(THUMBRIGHT).x)/4;
		float y = (application.SkeletPointsXY(HANDRIGHT).y + application.SkeletPointsXY(WRISTRIGHT).y + application.SkeletPointsXY(HANDTIPRIGHT).y + application.SkeletPointsXY(THUMBRIGHT).y)/4;
		float z = (application.DepthSkeletonPoints(HANDRIGHT) + application.DepthSkeletonPoints(WRISTRIGHT) + application.DepthSkeletonPoints(HANDTIPRIGHT)+ application.DepthSkeletonPoints(THUMBRIGHT) + application.DepthSkeletonPoints(ELBOWRIGHT))/5;

		float X =((1920-x*1920/640)-0)*4.4/4.4; // + 550;				//640 - const from kinect, probably the size of with depth sensor
		float Y = (y * 1200 / 280 - 0)*3.2/3.2;// +323;				//280 - const from kinect, probably the size of heith depth sensor

		_mainWindow.clear(sf::Color(0, 0, 0));
		if (z >= 0)
		{
			_shape.setPosition(X,Y);
			_mainWindow.draw(_shape);
			_mainWindow.display();
		}
		cout << X << "  " <<  Y << "  " << z << "\n";


		sf::Event currentEvent;
		_mainWindow.pollEvent(currentEvent);
		if (currentEvent.type == sf::Event::Closed) break;

		Sleep(100);
	} 
}

