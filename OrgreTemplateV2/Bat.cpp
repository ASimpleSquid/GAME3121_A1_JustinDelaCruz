#include "Bat.h"

void Bat::reset()
{
	translate = Ogre::Vector3(0, 0, 0);
	
}

Bat::Bat()
{
}

Bat::Bat(Ogre::Entity* ent, Ogre::SceneManager* scnMgr)
{
	node = scnMgr->getRootSceneNode()->createChildSceneNode();
	node->setPosition(0, -10, 0);
	node->setScale(0.2f, 0.05f, 1.0f);
	node->attachObject(ent);
	border = 102;
	velocity = 200;
	reset();

	pos = node->getPosition();
}

Bat::~Bat()
{
}

Ogre::Vector3 Bat::getPosition()
{
	return pos;
}

void Bat::setPosition(Ogre::Vector3 p)
{
	pos = p;
}

Ogre::SceneNode* Bat::getShape()
{
	return node;
}

Ogre::int32 Bat::getSpeed()
{
	return speed;
}

void Bat::setSpeed(Ogre::int32 x)
{
	speed = x;
}

void Bat::update(const Ogre::FrameEvent& evt)
{
	
		node->translate(translate * evt.timeSinceLastFrame);
		translate = Ogre::Vector3(0, 0, 0);
	
}

void Bat::moveLeft()
{
	if (node->getPosition().x > -border)
		translate = Ogre::Vector3(-velocity, 0, 0);
}

void Bat::moveRight()
{
	if (node->getPosition().x < border)
		translate = Ogre::Vector3(velocity, 0, 0);
}
