#pragma once

#include "ofMain.h"
#include "ofxTurboJpeg.h"

class linearFrame_turbo {
public:
	ofVec2f size;
	vector<ofFile> files;
	vector<ofBuffer> buf;
	int file_stride;
	int numFile = 0;
	ofImage img;
	ofxTurboJpeg turbo;

	void setup(int width, int height)
	{
		size.set(width, height);
	}

	void setFromDir(string path, int stride)
	{
		ofDirectory dir;
		dir.listDir(path);
		files.clear();
		files = dir.getFiles();

		for (int i = 0; i < files.size(); i += stride)
		{
			cout << "load :" << i / stride << endl;
			string path = files[i].getAbsolutePath();
			buf.push_back(ofBufferFromFile(path, true));
		}

		numFile = buf.size();
	}

	void draw(float pos)
	{
		if (files.size() == 0) return;
		int index = ofMap(pos, 0.0, 1.0, 0, numFile - 1, true);
		
		turbo.load(img, buf[index]);
		img.draw(0, 0, ofGetWidth(), ofGetHeight());
	}
};