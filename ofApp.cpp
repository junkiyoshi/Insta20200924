#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	this->font.loadFont("fonts/Kazesawa-Bold.ttf", 20, true, true, true);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	int radius = 100;
	for (int x = -230; x <= 230; x += 230) {

		for (int y = -230; y <= 230; y += 230) {

			ofPushMatrix();
			ofTranslate(x, y);

			vector<glm::vec2> vertices;
			for (float deg = 0; deg < 360; deg += 0.3) {

				auto location = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
				auto noise_value = ofNoise(x + location.x * 0.1, y + location.y * 0.1, ofGetFrameNum() * 0.0035);

				if (noise_value > 0.5) {

					location *= ofMap(noise_value, 0.5, 1.0, 1.0, 0.3);
				}

				vertices.push_back(location);
			}

			ofFill();
			ofSetColor(239);
			ofBeginShape();
			ofVertices(vertices);
			ofEndShape(true);

			ofNoFill();
			ofSetColor(39);
			ofBeginShape();
			ofVertices(vertices);
			ofEndShape(true);

			string word = "Yes!";
			this->font.drawString(word, this->font.stringWidth(word) * -0.5, this->font.stringHeight(word) * 0.5);

			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}