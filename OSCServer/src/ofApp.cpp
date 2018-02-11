#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0, 0, 0);
	//指定したIPアドレスとポート番号でサーバーに接続
	sender.setup(HOST, PORT);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	//現在のマウスの場所に円を描画
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
	//OSCメッセージの準備
	ofxOscMessage m;
	//OSCアドレスの指定
	m.setAddress("/mouse/position");
	//OSC引数として、現在のマウスの座標(x, y)を送信
	m.addIntArg(x);
	m.addIntArg(y);
	//メッセージを送信
	sender.sendMessage(m);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	//OSCメッセージの準備
	ofxOscMessage m;
	//OSCアドレスの指定
	m.setAddress("/mouse/button");
	//OSC引数として、マウス状態"down"を送信
	m.addStringArg("down");
	//OSC引数として、現在のマウスの座標(x, y)を送信
	m.addIntArg(x);
	m.addIntArg(y);
	sender.sendMessage(m);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	//OSCメッセージの準備
	ofxOscMessage m;
	//OSCアドレスの指定
	m.setAddress("/mouse/button");
	//OSC引数として、マウス状態"up"を送信
	m.addStringArg("up");
	//OSC引数として、現在のマウスの座標(x, y)を送信
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
