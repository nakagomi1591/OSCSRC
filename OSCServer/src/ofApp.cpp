#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0, 0, 0);
	//�w�肵��IP�A�h���X�ƃ|�[�g�ԍ��ŃT�[�o�[�ɐڑ�
	sender.setup(HOST, PORT);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	//���݂̃}�E�X�̏ꏊ�ɉ~��`��
	ofSetColor(255, 255, 255);
	ofCircle(mouseX, mouseY, 10);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
	//OSC���b�Z�[�W�̏���
	ofxOscMessage m;
	//OSC�A�h���X�̎w��
	m.setAddress("/mouse/position");
	//OSC�����Ƃ��āA���݂̃}�E�X�̍��W(x, y)�𑗐M
	m.addIntArg(x);
	m.addIntArg(y);
	//���b�Z�[�W�𑗐M
	sender.sendMessage(m);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	//OSC���b�Z�[�W�̏���
	ofxOscMessage m;
	//OSC�A�h���X�̎w��
	m.setAddress("/mouse/button");
	//OSC�����Ƃ��āA�}�E�X���"down"�𑗐M
	m.addStringArg("down");
	//OSC�����Ƃ��āA���݂̃}�E�X�̍��W(x, y)�𑗐M
	m.addIntArg(x);
	m.addIntArg(y);
	sender.sendMessage(m);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	//OSC���b�Z�[�W�̏���
	ofxOscMessage m;
	//OSC�A�h���X�̎w��
	m.setAddress("/mouse/button");
	//OSC�����Ƃ��āA�}�E�X���"up"�𑗐M
	m.addStringArg("up");
	//OSC�����Ƃ��āA���݂̃}�E�X�̍��W(x, y)�𑗐M
	m.addIntArg(x);
	m.addIntArg(y);
	sender.sendMessage(m);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
