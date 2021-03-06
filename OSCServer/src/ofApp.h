#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

#define HOST "localhost" //送信先ホストのIPを設定
#define PORT 8000 //送信先のポート番号を設定

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

private:
	//OSCメッセージの送信者
	ofxOscSender sender;
};
