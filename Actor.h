#pragma once
#include "ofMain.h"

class Actor {
public:
	Actor();
	Actor(ofColor color);
	~Actor();

	void think(vector<unique_ptr<Actor>>& particles);
	void update();
	void draw();
	glm::vec3 separate(vector<unique_ptr<Actor>>& particles);
	glm::vec3 align(vector<unique_ptr<Actor>>& particles);
	glm::vec3 cohesion(vector<unique_ptr<Actor>>& particles);
	glm::vec3 seek(glm::vec3 target);
	void applyForce(glm::vec3 force);

	glm::vec3 get_location();
	glm::vec3 get_last_log();

private:
	glm::vec3 location;
	glm::vec3 velocity;
	glm::vec3 acceleration;
	glm::vec3 param;
	deque<glm::vec3> log_list;

	float range;
	float max_force;
	float max_speed;
	int len;
	ofColor color;
};