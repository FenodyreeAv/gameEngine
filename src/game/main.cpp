#include <iostream>
#include <myengine/myengine.h>

using namespace myengine;

struct NPC : public Component
{
	void onInitialize()
	{
		std::shared_ptr<Renderer> NPCRender = getEntity()->addComponent<Renderer>();
		std::shared_ptr<Model> cube = getCore()->getResourceList()->loadPath<Model>("..//assets//cube");
		std::shared_ptr<TextureLoad> cubeTex = getCore()->getResourceList()->loadPath<TextureLoad>("..//assets//Smiley face");
		NPCRender->setTexture(cubeTex);
		NPCRender->setModel(cube);
	}

	void onTick()
	{
		if (getCore()->getInput()->getKey('u'))
		{
			getTransform()->translate(0.0f, 0.0f, 0.1f);	
		}
		if (getCore()->getInput()->getKey('h'))
		{
			getTransform()->translate(0.1f, 0.0f, 0.0f);
		}
		if (getCore()->getInput()->getKey('j'))
		{
			getTransform()->translate(0.0f, 0.0f, -0.1f);
		}
		if (getCore()->getInput()->getKey('k'))
		{
			getTransform()->translate(-0.1f, 0.0f, 0.0f);
		}
		if (getCore()->getInput()->getKey('i'))
		{
			getTransform()->rotate(0.0f, -1.5f, 0.0f);
		}
		if (getCore()->getInput()->getKey('y'))
		{
			getTransform()->rotate(0.0f, 1.5f, 0.0f);
		}
		if (getCore()->getInput()->getKey('b'))
		{
			std::shared_ptr<ExceptionCheck> brokenComponent = getEntity()->addComponent<ExceptionCheck>();
		}
	}
};

struct Player : public Component
{
	void onInitialize()
	{
		std::shared_ptr<Renderer> playerRender = getEntity()->addComponent<Renderer>();
		std::shared_ptr<Model> cube = getCore()->getResourceList()->loadPath<Model>("..//assets//cube");
		std::shared_ptr<TextureLoad> cubeTex = getCore()->getResourceList()->loadPath<TextureLoad>("..//assets//Smiley face");
		playerRender->setTexture(cubeTex);
		playerRender->setModel(cube);
	}

	void onTick()
	{
		if (getCore()->getInput()->getKey('w'))
		{
			getTransform()->translate(0.0f, 0.0f, 0.1f);
		}
		if (getCore()->getInput()->getKey('a'))
		{
			getTransform()->translate(0.1f, 0.0f, 0.0f);
		}
		if (getCore()->getInput()->getKey('s'))
		{
			getTransform()->translate(0.0f, 0.0f, -0.1f);
		}
		if (getCore()->getInput()->getKey('d'))
		{
			getTransform()->translate(-0.1f, 0.0f, 0.0f);
		}
		if (getCore()->getInput()->getKey('e'))
		{
			getTransform()->rotate(0.0f, -1.5f, 0.0f);
		}
		if (getCore()->getInput()->getKey('q'))
		{
			getTransform()->rotate(0.0f, 1.5f, 0.0f);
		}
	} 
};

int main()
{
	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> playerEntity = core->addEntity();
	playerEntity->getTransform()->setPosition(rend::vec3(5, 0, 0));
	playerEntity->getTransform()->setScale(rend::vec3(0.5, 0.5, 0.5));
	std::shared_ptr<Player> playerComp = playerEntity->addComponent<Player>();
	std::shared_ptr<Collider> playerCollider = playerEntity->addComponent<Collider>();
	playerEntity->getComponent<Collider>()->setSize(rend::vec3(2.5, 2.5, 2.5));
	playerEntity->getComponent<Collider>()->setCentre(rend::vec3(5, 0, 0));
	playerEntity->getComponent<Collider>()->setAnchor(false);

	std::shared_ptr<Entity> NPC1 = core->addEntity();
	NPC1->getTransform()->setPosition(rend::vec3(0.5, 0, 0));
	NPC1->getTransform()->setScale(rend::vec3(0.5, 0.5, 0.5));
	std::shared_ptr<NPC> NPCComp = NPC1->addComponent<NPC>();
	std::shared_ptr<Collider> NPCCollider = NPC1->addComponent<Collider>();
	NPC1->getComponent<Collider>()->setSize(rend::vec3(2.5, 2.5, 2.5));
	playerEntity->getComponent<Collider>()->setCentre(rend::vec3(0.5, 0, 0));
	NPC1->getComponent<Collider>()->setOffset(rend::vec3(0, 0, 0));
	NPC1->getComponent<Collider>()->setAnchor(true);

	std::shared_ptr<Entity> camera = core->addEntity();
	std::shared_ptr<Entity> cameraEntity = core->addEntity();
	std::shared_ptr<Camera> cameraComp = cameraEntity->addComponent<Camera>();
	cameraEntity->getTransform()->setPosition(rend::vec3(0, 20, 0));
	cameraEntity->getTransform()->setRotation(rend::vec3(-90, 0, 0));

	std::cout << "Components & Entities Loaded" << std::endl;
	core->run();

	return 0;
}