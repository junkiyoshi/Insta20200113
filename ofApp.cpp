#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openframeworks");

	ofBackground(239);
	ofEnableDepthTest();

	auto actor = make_unique<Actor>(ofColor(255, 0, 0));
	this->actor_list.push_back(move(actor));

	this->number_of_particle = 500;
	for (int i = 0; i < this->number_of_particle; i++) {

		auto actor = make_unique<Actor>();
		this->actor_list.push_back(move(actor));
	}
}

//--------------------------------------------------------------
void ofApp::update() {

	for (auto& actor : this->actor_list) {

		actor->think(this->actor_list);
	}

	for (auto& actor : this->actor_list) {

		actor->update();
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.lookAt(this->actor_list.front()->get_location());
	this->cam.setPosition(this->actor_list.front()->get_last_log() + glm::vec3(0, 0, 100));
	this->cam.begin();

	for (auto& actor : this->actor_list) {

		actor->draw();
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(1280, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}