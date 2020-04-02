#pragma once

#include <vector>
#include <curses.h>

#include "vect.h"
#include "matrix.h"
#include "math.h"
#include "mesh.h"

class GraphicsEngine {
	public:
		~GraphicsEngine();
		
		void init();
		void start();
		void draw();
		void drawLine(int x1, int y1, int x2, int y2, short c);
		void drawPoint(int x, int y, short c);

		void clearBuffer();
		void renderBuffer();

		void eventResize();
		void updatePerspective();

	private:
		int width;
		int height;

		int drawWidth;
		int drawHeight;

		std::vector<std::vector<short>> buffer;

		Matrix4D perspective;
		Matrix4D view;

		double nearPlane = 0.1;
		double farPlane = 1000;
		double FOV = M_PI/2.0;

		Mesh mesh;
};
