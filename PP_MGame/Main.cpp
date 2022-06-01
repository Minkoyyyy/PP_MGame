#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>


#pragma comment(lib,"OpenGL32")

using namespace std;
static void error_callback(int error, const char* description)
{
	fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{
	GLFWwindow* window;
	float PxPoint = -0.45f;
	float PxPoint2 = -0.4f;
	float yPoint = -0.05f;
	float yPoint2 = 0.05f;
	float ExPointp1 = 0.5f;
	float ExPointp2 = 0.6f;
	float ExPointp3 = 0.55f;

	bool End = false;
	glfwSetErrorCallback(error_callback);
	//반드시 한 번은 호출
	if (!glfwInit())
		exit(EXIT_FAILURE);
	//창 정보 객체 생성 
    window= glfwCreateWindow(1920, 1080, "PP_Game", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	//창 생성
	glfwMakeContextCurrent(window);
	while (!glfwWindowShouldClose(window)) //닫기 버튼 누르면 창 꺼짐
	{   
		//색 정보 설정 
		glClearColor(1.0f, 1.0f, 1.0f, 1.0);
		//설정한 색 정보를 사용해 덧 씌우기
		glClear(GL_COLOR_BUFFER_BIT);
		if (GetAsyncKeyState(VK_UP))
		{
			yPoint = 0.2f;
			yPoint2 = 0.3f;
			
		}
		else
		{
			yPoint = 0.0f;
			yPoint2 = 0.1f;
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			yPoint = -0.1f;
			yPoint2 = -0.2f;
		}
		glPointSize(10);
		glBegin(GL_QUADS);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(PxPoint , yPoint);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(PxPoint2, yPoint);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(PxPoint2, yPoint2);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(PxPoint , yPoint2);
		glEnd();
		
		glPointSize(10);
		glLineWidth(10.10);
		glBegin(GL_LINES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(-0.5f, -0.4f);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(0.5f, -0.4f);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(0.5f, 0.5f);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex2f(-0.5f, 0.5f);
		glEnd();
		
		glPointSize(10);
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.1f, -0.4f);
		glVertex2f(0.0f, -0.4f);
		glVertex2f(-0.05f, 0.1f);
		glEnd();

		glPointSize(10);
		glBegin(GL_TRIANGLES);
		glVertex2f(0.1f, 0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.05f, 0.0f);
		glEnd();

		

		
		
		//창의 색상 버퍼를 교체함
		glfwSwapBuffers(window);
		//이벤트를 확인하고 창 상태를 업데이트 함
		glfwPollEvents();
		
		
		
	}
	glfwDestroyWindow(window);
	glfwTerminate();//할당했던 자원들 정리.
	exit(EXIT_SUCCESS);

	puts("!!게임종료!!");



}