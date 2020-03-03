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

	int loadCounter = 0;
	bool loading = false;

	void setup(int width, int height)
	{
		size.set(width, height);
	}

	void setFromDir(string path, int stride)
	{
		buf.clear();
		loading = true;
		loadCounter = 0;

		cout << "file sorting..." << endl;
		ofDirectory dir;
		dir.listDir(path);
		dir.sort();
		files.clear();
		files = dir.getFiles();

		for (int i = 0; i < files.size(); i += stride)
		{
			string path = files[i].getAbsolutePath();
			cout << "load :" << path << endl; 
			buf.push_back(ofBufferFromFile(path, true));
		}

		numFile = buf.size();
	}

	float loadUpdate()
	{
		if (!loading) return 1;

		if (loadCounter == files.size())
		{
			loading = false;
		}
		else if (loadCounter < files.size())
		{
			string path = files[loadCounter].getAbsolutePath();
			buf.push_back(ofBufferFromFile(path, true));
			loadCounter++;

			return loadCounter / float(files.size());
		}
		return 1;
	}

	void draw(float pos)
	{
		if (files.size() == 0) return;
		int index = ofMap(pos, 0.0, 1.0, 0, numFile - 1, true);
		turbo.load(img, buf[index]);
		img.draw(0, 0, ofGetWidth(), ofGetHeight());
	}
};