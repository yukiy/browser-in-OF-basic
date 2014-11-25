#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	browser.setup(ofGetWidth(), ofGetHeight());

    //---load from absolute path
    browser.loadURL("file:///Workspaces/openFrameworks/of_v0.8.4_osx_release/apps/SFPC_personal/browser/bin/data/www/test.html");

    
//  //---load from URL
//	browser.loadURL("http://www.google.com");

    
//  //---write HTML
//  browser.loadURL("data:text/html,<h1>Hello World</h1>");

}


//--------------------------------------------------------------
void ofApp::update(){
	ofxAwesomium::updateCore();
	browser.update();
	
	ofSetWindowTitle(browser.getTitle());
}


//--------------------------------------------------------------
void ofApp::draw(){
	if(browser.getIsLoading()) {
		ofSetColor(0);
		ofDrawBitmapString("Loading...", 10, 15);
	}
    
    ofSetColor(255);
	browser.draw(0, 0);
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	browser.keyPressed(key);

//    //---directory write js
//    browser.doJavaScript("document.body.bgColor = '#FF0000';"); //directory run js

    
//    //---execute javascript function
//    browser.doJavaScript("changeBgColor()"); //test.js

    
    //---load js file and execute
    ofBuffer buffer = ofBufferFromFile("www/inject.js");
    browser.doJavaScript(buffer);

}


//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	browser.keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	browser.mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	browser.mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	browser.mousePressed(x, y, button);

    JSValue data = browser.doJavaScript("g_data");
    
    cout << data.ToString() << endl;
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	browser.mouseReleased(x, y, button);
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
