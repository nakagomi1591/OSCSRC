#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//�w�肵���|�[�g�Őڑ�
	receiver.setup(PORT);

	//�l��������
	mouseX = 0;
	mouseY = 0;
	mouseButtonState = "";

	ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
	//���ݏ��ԑ҂���OSC���b�Z�[�W�����邩�m�F
	while (receiver.hasWaitingMessages())
	{
		//���̃��b�Z�[�W���擾
		ofxOscMessage m;
		receiver.getNextMessage(&m);

		//�}�E�X�̈ʒu���擾
		if (m.getAddress() == "/mouse/position") {
			remoteMouseX = m.getArgAsInt32(0);
			remoteMouseY = m.getArgAsInt32(1);

		}
		//�}�E�X�{�^���̏�Ԃ��擾
		else if (m.getAddress() == "/mouse/button") {
			mouseButtonState = m.getArgAsString(0);
		}

		//OSC���b�Z�[�W�����̂܂܃R���\�[���ɏo��
		dumpOSC(m);
	}
}

//OSC���b�Z�[�W���R���\�[���ɏo�͂���֐�
void ofApp::dumpOSC(ofxOscMessage m) {
	string msg_string;
	msg_string = m.getAddress();
	for (int i = 0; i<m.getNumArgs(); i++) {
		msg_string += " ";
		if (m.getArgType(i) == OFXOSC_TYPE_INT32)
			msg_string += ofToString(m.getArgAsInt32(i));
		else if (m.getArgType(i) == OFXOSC_TYPE_FLOAT)
			msg_string += ofToString(m.getArgAsFloat(i));
		else if (m.getArgType(i) == OFXOSC_TYPE_STRING)
			msg_string += m.getArgAsString(i);
	}
	cout << msg_string << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
	int radius;
	if (mouseButtonState == "down") {
		//�}�E�X�{�^����������Ă�����A�Ԃ��~��`��
		radius = 20;
		ofSetColor(255, 127, 0);
	}
	else {
		//�}�E�X�{�^����������Ă��Ȃ���΁A���~��`��
		radius = 10;
		ofSetColor(0, 127, 255);
	}
	ofCircle(remoteMouseX, remoteMouseY, radius);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
