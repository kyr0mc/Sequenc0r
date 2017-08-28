#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // do some initialization
    
    // the rate at which the program runs (FPS)
    ofSetFrameRate(60);
    button_height = 35;
    button_width = 35;
    
    ofSetWindowShape(800,480);
    ofSetBackgroundAuto(false);
    ofBackground(0,0,0);
    ofEnableAlphaBlending();

    // initialize all buttons
    button_bpmUp.load("upArrowButton.png","upArrowButton.png");
    button_bpmUp.setPosition(float(ofGetWidth()*0.0545), float(ofGetHeight()*0.0125));
    button_bpmUp.setSize(button_width, button_height);

    button_r1up.load("upArrowButton.png","upArrowButton.png");
    button_r1up.setPosition(float(ofGetWidth()*0.0545), float(ofGetHeight()*0.0965));
    button_r1up.setSize(button_width, button_height);

    button_r2up.load("upArrowButton.png","upArrowButton.png");
    button_r2up.setPosition(float(ofGetWidth()*0.0545), float(ofGetHeight()*0.1865));
    button_r2up.setSize(button_width, button_height);
    
    button_r3up.load("upArrowButton.png","upArrowButton.png");
    button_r3up.setPosition(float(ofGetWidth()*0.0545), float(ofGetHeight()*0.2765));
    button_r3up.setSize(button_width, button_height);

    button_r4up.load("upArrowButton.png","upArrowButton.png");
    button_r4up.setPosition(float(ofGetWidth()*0.0545), float(ofGetHeight()*0.3765));
    button_r4up.setSize(button_width, button_height);
    
    button_r5up.load("upArrowButton.png","upArrowButton.png");
    button_r5up.setPosition(float(ofGetWidth()*0.0545), float(ofGetHeight()*0.4665));
    button_r5up.setSize(button_width, button_height);
    
    button_r1touch.load("barButton.png","barButton.png");
    button_r1touch.setPosition(float(ofGetWidth()*0.915), float(ofGetHeight()*0.46));
    button_r1touch.setSize(button_width+5, button_height+10);

    button_r2touch.load("barButton.png","barButton.png");
    button_r2touch.setPosition(float(ofGetWidth()*0.825), float(ofGetHeight()*0.46));
    button_r2touch.setSize(button_width+5, button_height+10);
    
    button_r3touch.load("barButton.png","barButton.png");
    button_r3touch.setPosition(float(ofGetWidth()*0.748), float(ofGetHeight()*0.46));
    button_r3touch.setSize(button_width+5, button_height+10);
    
    button_r4touch.load("barButton.png","barButton.png");
    button_r4touch.setPosition(float(ofGetWidth()*0.68), float(ofGetHeight()*0.46));
    button_r4touch.setSize(button_width+5, button_height+10);

    button_r5touch.load("barButton.png","barButton.png");
    button_r5touch.setPosition(float(ofGetWidth()*0.625), float(ofGetHeight()*0.46));
    button_r5touch.setSize(button_width+5, button_height+10);

    //Load Samples
    sample1.load(ofToDataPath("kick_02.wav"));
    sample2.load(ofToDataPath("snare_03.wav"));
    sample3.load(ofToDataPath("hihat_02.wav"));
    sample4.load(ofToDataPath("clap_01.wav"));
    sample5.load(ofToDataPath("click_01.wav"));
    
    ofSoundStreamSetup(1, 0, 44100, 512, 3);
 
    ofTrueTypeFont::setGlobalDpi(72);
    verdana14.load("verdana.ttf", 14, true, true);
    verdana14.setLineHeight(18.0f);
    verdana14.setLetterSpacing(1.037);
    
    originX = ofGetWidth() * 0.6;
    originY = ofGetHeight() * 0.5;
    
    //rings
    //5
    ring5X = originX - ring5Sx / 2;
    ring5Y = originY - ring5Sy /2;
    //4
    ring4X = originX - ring4Sx / 2;
    ring4Y = originY - ring4Sy / 2;
    //3
    ring3X = originX - ring3Sx / 2;
    ring3Y = originY - ring3Sy / 2;
    //2
    ring2X = originX - ring2Sx / 2;
    ring2Y = originY - ring2Sy / 2;
    //1
    ring1X = originX - ring1Sx / 2;
    ring1Y = originY - ring1Sy / 2;
}

//--------------------------------------------------------------
void ofApp::update(){
//    cout <<  "theta" << theta << endl;
//    cout <<  "r1" << r1 << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){

    secondsPerBeat = 60/bpm;
    
    float notes[] = {c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15, c16};
    
    framesPerBeat = (ofGetFrameRate()* secondsPerBeat);
    
    //draw semi-transparent background
    ofSetColor(0, 0, 0, 3);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    
    //draw control buttons
    //BPM
    ofSetColor(255, 255, 255, 150);
    button_bpmUp.draw();
    ofSetColor(255);
    verdana14.drawString("BPM", 10, 20);
    ofDrawBitmapString(" "+ofToString(bpm), 80, 20); // going in reverse?
    //ofDrawTriangle(55, 40, 60, 10, 65, 40);
    ofSetColor(0, 0, 0, 50);
    ofDrawRectangle(80, 10, 60, 20);
    ofSetColor(c1*2, c1*1.5, c1*3, 50);
    ofDrawRectangle(51, 10, 20, 35);
    
    //increase r1 subdiv
    ofSetColor(255);
    button_r1up.draw();
    verdana14.drawString("ring1", 10, 60);
    ofDrawBitmapString(" "+ofToString(r1+1), 80, 60);
    //ofDrawTriangle(55, 80, 60, 50, 65, 80);//up(b1)
    ofSetColor(0, 0, 0, 50);
    ofDrawRectangle(80, 44, 20, 20);//number display mask
    ofSetColor(notes[r1]*1.05, notes[r1]*3.0, notes[r1]*1.1, 50);
    ofDrawRectangle(51, 48, 20, 40);//button
    
    //increase r2 subdiv
    ofSetColor(255);
    button_r2up.draw();
    verdana14.drawString("ring2", 10, 105);
    ofDrawBitmapString(" "+ofToString(r2+1), 80, 105);
    //ofDrawTriangle(55, 125, 60, 95, 65, 125);//up(b2)
    ofSetColor(0, 0, 0, 50);
    ofDrawRectangle(80, 89, 20, 20);//number display mask
    ofSetColor(notes[r2]*0.8, notes[r2]*3.2, notes[r2]*3.0, 50);
    ofDrawRectangle(51, 92, 20, 40);//button
    
    //increase r3 subdiv
    ofSetColor(255);
    button_r3up.draw();
    verdana14.drawString("ring3", 10, 150);
    ofDrawBitmapString(" "+ofToString(r3+1), 80, 155);
    //ofDrawTriangle(55, 170, 60, 140, 65, 170);//up(b3)
    ofSetColor(0, 0, 0, 50);
    ofDrawRectangle(80, 134, 20, 20);//number display mask
    ofSetColor(notes[r3]*1.2,notes[r3]*1.5, notes[r3]*5.3, 50);
    ofDrawRectangle(51, 138, 20, 40);//button
    
    //increase r4 subdiv
    ofSetColor(255);
    button_r4up.draw();
    verdana14.drawString("ring4", 10, 195);
    ofDrawBitmapString(" "+ofToString(r4+1), 80, 195);
    //ofDrawTriangle(55, 215, 60, 185, 65, 215);//up(b4)
    ofSetColor(0, 0, 0, 50);
    ofDrawRectangle(80, 185, 20, 30);//number display mask
    ofSetColor(notes[r4]*5, notes[r4]*2.2,notes[r4]*3.5, 50);
    ofDrawRectangle(51, 182, 20, 40);//button
    
    //button5
    ofSetColor(255);
    button_r5up.draw();
    verdana14.drawString("ring5", 10, 240);
    ofDrawBitmapString(" "+ofToString(r5+1), 80, 240);
    //ofDrawTriangle(55, 260, 60, 230, 65, 260);//up(b1)
    ofSetColor(0, 0, 0, 50);
    ofDrawRectangle(80, 224, 20, 30);//number display mask
    ofSetColor(notes[r5]*3.75, notes[r5]*4.75, notes[r5]*5, 50);
    ofDrawRectangle(51, 227, 20, 40);//button
    
    //draw rings with buttons
    //r1
    ofSetColor(notes[r1]*1.05, notes[r1]*3.0, notes[r1]*1.1);
    ringOneColors = (notes[r1]*1.05, notes[r1]*3.0, notes[r1]*1.1);
    ofDrawEllipse(x, y, 10, 5);
    ofSetColor(255,255,255,5);
    button_r1touch.draw();
    //r2
    
    ofSetColor(notes[r2]*0.8, notes[r2]*3.2, notes[r2]*3.0);
    ringTwoColors = (notes[r2]*0.8, notes[r2]*3.2, notes[r2]*3.0);
    ofDrawEllipse(x2, y2, 20, 10);
    ofSetColor(255,0,0,5);
    button_r2touch.draw();
    
    //r3
    ofSetColor(notes[r3]*1.2,notes[r3]*1.5, notes[r3]*5.3);
    ringThreeColors = (notes[r3]*1.2,notes[r3]*1.5, notes[r3]*5.3);
    ofDrawEllipse(x3, y3, 30, 15);
    ofSetColor(0,0,255,5);
    button_r3touch.draw();
    
    //r4
    ofSetColor(notes[r4]*5, notes[r4]*2.2,notes[r4]*3.5);
    ringFourColors = (notes[r4]*5, notes[r4]*2.2,notes[r4]*3.5);
    ofDrawEllipse(x4, y4, 40, 20);
    ofSetColor(0,255,255,5);
    button_r4touch.draw();
    
    //r5
    ofSetColor(notes[r5]*3.75, notes[r5]*4.75, notes[r5]*5);
    ringFiveColors = (notes[r5]*3.75, notes[r5]*4.75, notes[r5]*5);
    ofDrawEllipse(x5, y5, 50, 25);
    //ofDrawBox(x5, y5, 50, 25);
    ofSetColor(0,255,0,5);
    button_r5touch.draw();
    
    theta += ofRadToDeg(framesPerBeat/60000);
    
    //periodicity of blackouts
    c1 = ofMap(fmod(theta, TWO_PI), 0, TWO_PI, 0, 200);// wholenotes
    c2 = ofMap(fmod(theta, PI), 0, TWO_PI, 0, 220);//halfnotes
    c3 = ofMap(fmod(theta, (TWO_PI/3)), 0, TWO_PI, 0, 255); // 3rds
    c4 = ofMap(fmod(theta, (PI/2.0)), 0, TWO_PI, 0, 200); // quarternotes
    c5 = ofMap(fmod(theta, ((18*PI)/45.0)), 0, TWO_PI, 0, 200);// quintuplets
    c6 = ofMap(fmod(theta, (PI/3)), 0, TWO_PI, 0, 255);//6ths
    c7 = ofMap(fmod(theta, (TWO_PI/7)), 0, TWO_PI, 0, 255);//7ths
    c8 = ofMap(fmod(theta, (TWO_PI/8)), 0, TWO_PI, 0, 255);//8ths
    c9 = ofMap(fmod(theta, (TWO_PI/9)), 0, TWO_PI, 0, 255);//9ths
    c10 = ofMap(fmod(theta, (TWO_PI/10)), 0, TWO_PI, 0, 255);//10ths
    c11 = ofMap(fmod(theta, (TWO_PI/11)), 0, TWO_PI, 0, 255);//11ths
    c12 = ofMap(fmod(theta, (TWO_PI/12)), 0, TWO_PI, 0, 255); //12ths
    c13 = ofMap(fmod(theta, (TWO_PI/13)), 0, TWO_PI, 0, 255); //13ths
    c14 = ofMap(fmod(theta, (TWO_PI/14)), 0, TWO_PI, 0, 255); //14ths
    c15 = ofMap(fmod(theta, (TWO_PI/15)), 0, TWO_PI, 0, 255); //15ths
    c16 = ofMap(fmod(theta, (TWO_PI/16)), 0, TWO_PI, 0, 255); //16ths
    
    x = cos(theta) * radius + originX;
    x2 = cos(theta) * (radius*1.8) + originX;
    x3 = cos(theta) * (radius*3) + originX;
    x4 = cos(theta) * (radius*4.45) + originX;
    x5 = cos(theta) * (radius*6) + originX;
    
    y = sin(theta) * (radius*1.2) + originY;
    y2 = sin(theta) * (radius*2) + originY;
    y3 = sin(theta) * (radius*3) + originY;
    y4 = sin(theta) * (radius*4) + originY;
    y5 = sin(theta) * (radius*5) + originY;
    
    //prevFrameRate = ofGetFrameRate();
    if(r1 > 16) {
        r1 = 1;
    }
    if (r2 > 16) {
        r2 = 1;
    }
    if (r3 > 16) {
        r3 = 1;
    }
    if (r4 > 16) {
        r4 = 1;
    }
    if(r5 > 16) {
        r5 = 1;
    }
    if (bpm > 160)
        bpm = 60;
}



//--------------------------------------------------------------
void ofApp::audioOut(float *buffer, int buffer_size, int n_channels) {
    cout << "r5Touched  " << r1Touched << endl;
    
    if (ringOneColors <= (20,20,20)){
        if(r5Touched == true) {
            for (int i = 0; i < buffer_size; i++) {
                buffer[i] = sample1.play();
            }
        }
    }
    if (ringOneColors > (20,20,20)){
        sample1.trigger();
    }
    
    
    if (ringTwoColors <= (20,20,20)){
        if(r4Touched == true) {
            for (int i = 0; i < buffer_size; i++) {
                buffer[i] += sample2.play();
            }
        }
    }
    if (ringTwoColors > (20,20,20)){
        sample2.trigger();
    }
    
    
    if (ringThreeColors <= (20,20,20)){
        if(r3Touched == true) {
            for (int i = 0; i < buffer_size; i++) {
                buffer[i] += sample3.play();
            }
        }
    }
    if (ringThreeColors > (20,20,20)){
        sample3.trigger();
    }
    
    
    if (ringFourColors <= (20,20,20)){
        if(r2Touched == true) {
            for (int i = 0; i < buffer_size; i++) {
                buffer[i] += sample4.play();
            }
        }
    }
    if (ringFourColors > (20,20,20)){
        sample4.trigger();
    }
    
    
    if (ringFiveColors <= (20,20,20)){
        if(r1Touched == true) {
            for (int i = 0; i < buffer_size; i++) {
                buffer[i] += sample5.play();
            }
        }
    }
    if (ringFiveColors > (20,20,20)){
        sample5.trigger();
    }
    
    
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
    
    if(button_bpmUp.pressed(x,y)) {
        bpm += 1;
        //r1 += 1;
    }
    if(button_r1up.pressed(x,y)) {
        r1 += 1;
    }
    if(button_r2up.pressed(x,y)) {
        r2 += 1;
    }
    if(button_r3up.pressed(x,y)) {
        r3 += 1;
    }
    if(button_r4up.pressed(x,y)) {
        r4 += 1;
    }
    if(button_r5up.pressed(x,y)) {
        r5 += 1;
    }
    
    if(button_r1touch.pressed(x,y)){
        r1Touched = true;
    }
    if(button_r2touch.pressed(x,y)){
        r2Touched = true;
    }
    if(button_r3touch.pressed(x,y)){
        r3Touched = true;
    }
    if(button_r4touch.pressed(x,y)){
        r4Touched = true;
    }
    if(button_r5touch.pressed(x,y) && r5Touched == false){
        r5Touched = true;
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    if(button_r5touch.released(x,y)){
        r5Touched = false;
    }
    if(button_r4touch.released(x,y)){
        r4Touched = false;
    }
    if(button_r3touch.released(x,y)){
        r3Touched = false;
    }
    if(button_r2touch.released(x,y)){
        r2Touched = false;
    }
    if(button_r1touch.released(x,y)){
        r1Touched = false;
    }
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

//--------------------------------------------------------------
