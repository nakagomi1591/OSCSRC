#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

//�|�[�g�ԍ���ݒ�
#define PORT 8000

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
	void dumpOSC(ofxOscMessage m); //OSC���b�Z�[�W���o��

private:
	//OSC���b�Z�[�W����M����C���X�^���X
	ofxOscReceiver receiver;
	//�}�E�X���W
	int remoteMouseX, remoteMouseY;
	//�}�E�X�{�^���̏�� ("up", "down")
	string mouseButtonState;
	//string oscString;		
};
