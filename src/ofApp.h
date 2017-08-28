#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"

//Generic Button Class
class padButton {
public:
    // enumerators allow us to assign more interesting names to values of an integer
    // we could use an integer to the same effect,
    // e.g. "int button_state = 0", when our button is down
    // and "int button_state = 1", when our button is normal,
    // but enumerators allow us to instead say
    // "BUTTON_STATE button_state = BUTTON_DOWN", when our button is down,
    // "BUTTON_STATE button_state = NORMAL", when our button is normal.
    enum BUTTON_STATE {
        BUTTON_DOWN,
        NORMAL
    };
    
    // default constructor definition
    padButton()
    {
        // by default, we have a very boring button
        button_x = 0;
        button_y = 0;
        button_width = 0;
        button_height = 0;
        button_state = NORMAL;
    }
    
    // methods which button class will define
    // one for loading images for each of the button states
    void load(string state_normal, string state_down)
    {
        // load the images for our buttons
        button_image_normal.load(state_normal);
        button_image_down.load(state_down);
    }
    
    // setters, to set internal variables
    // the position
    void setPosition(int x, int y)
    {
        // set our internal variables
        button_x = x;
        button_y = y;
    }
    
    // the size
    void setSize(int w, int h)
    {
        // set our internal variables
        button_width = w;
        button_height = h;
    }
    
    // drawing the buttons
    void draw()
    {
        // allow alpha transparency
        ofEnableAlphaBlending();
        
        // if our button is normal
        if(button_state == NORMAL)
        {
            // draw the normal button image
            button_image_normal.draw(button_x,
                                     button_y,
                                     button_width,
                                     button_height);
        }
        else
        {
            // draw the down image
            button_image_down.draw(button_x,
                                   button_y,
                                   button_width,
                                   button_height);
        }
        
    }
    
    // and interaction with the button
    bool isPressed() {
        return button_state == BUTTON_DOWN;
        
    }
    // compound boolean expressions to determine,
    // is our x,y input within the bounds of the button
    // we have to check the left, the top, the right, and the bottom sides
    // of the button, respectively.
    bool pressed(int x, int y) {
        if( x > button_x && y > button_y
           && x < (button_x + button_width)
           && y < (button_y + button_height) )
        {
            button_state = BUTTON_DOWN;
            
            // return yes since the user pressed the button
            return true;
        }
        else {
            // no the user didn't press the button
            return false;
        }
    }
    
    bool released(int x, int y)
    {
        if(x > button_x && button_y
           && x < (button_x + button_width)
           && y < (button_y + button_height)) {
            // ok back to normal
            button_state = NORMAL;
            
            // we always return true since that is how our buttons work.
            return true;
        }
        return false;
    }
private:
    
    // images for drawing
    ofImage button_image_normal, button_image_down;
    
    // our position
    int button_x, button_y;
    
    // size
    int button_width, button_height;
    
    // and internal state of the button
    BUTTON_STATE button_state;
};



class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    void audioOut(float *buffer, int buffer_size, int n_channels);
    
    //declare samples
    maxiSample sample1;
    maxiSample sample2;
    maxiSample sample3;
    maxiSample sample4;
    maxiSample sample5;
    
    
    
private:
    float radius = 45;
    float originX, originY;
    
    float theta;
    
    int numCircles = 8;
    float c1 = 1;
    float c2 = 2;
    float c3 = 3;
    float c4 = 4;
    float c5 = 5;
    float c6 = 6;
    float c7 = 7;
    float c8 = 8;
    float c9 = 9;
    float c10 = 10;
    float c11 = 11;
    float c12 = 12;
    float c13 = 13;
    float c14 = 14;
    float c15 = 15;
    float c16 = 16;
    
    double ringOneColors = (0,0,0);
    double ringTwoColors = (0,0,0);
    double ringThreeColors = (0,0,0);
    double ringFourColors = (0,0,0);
    double ringFiveColors = (0,0,0);
    
    //control buttons
    
    //ring buttons
    //5
    float ring5X, ring5Y;
    float ring5Sx = 90 * 6.51; //ring size width
    float ring5Sy = 90 * 5.3; //ring size height
    //4
    float ring4X, ring4Y;
    float ring4Sx = 90 * 4.89;
    float ring4Sy = 90 * 4.25;
    //3
    float ring3X, ring3Y;
    float ring3Sx = 90 * 3.35;
    float ring3Sy = 90 * 3.17;
    //2
    float ring2X, ring2Y;
    float ring2Sx = 90 * 2.07;
    float ring2Sy = 90 * 2.13;
    //1
    float ring1X, ring1Y;
    float ring1Sx = 90 * 1.1;
    float ring1Sy = 90 * 1.08;
    
    float x, x2, x3, x4, x5;
    float y, y2, y3, y4, y5;
    
    //variables for stepping through subdivs/ color
    int r1 = 1;
    int r2 = 2;
    int r3 = 3;
    int r4 = 4;
    int r5 = 5;
    
    float bpm = 120;
    //float bps = bpm/60.0;
    float secondsPerBeat, framesPerBeat;
    //    float prevFrameRate = 0;
    
    
    ofTrueTypeFont franklinBook14;
    ofTrueTypeFont verdana14;
    
    bool                r1Touched,r2Touched,r3Touched,r4Touched,r5Touched = false;
    int                 button_width, button_height;
    int                 width,height;
    padButton           button_r1touch, button_r2touch,button_r3touch,button_r4touch,button_r5touch,button_bpmUp, button_r1up, button_r2up, button_r3up, button_r4up, button_r5up;
    
};
